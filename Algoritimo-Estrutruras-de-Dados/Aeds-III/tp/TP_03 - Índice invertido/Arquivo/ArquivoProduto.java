package Arquivo;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import Entidades.Produto;
import Estruturas.HashExtensivel;
import Pares.ParGtinId;
import Pares.ParIDEndereco;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedHashMap;
import Estruturas.ArvoreBMais;
import Pares.ParTermoProduto;
import Utils.ProcessadorTexto;

public class ArquivoProduto extends Arquivo<Produto> {

    private static final String PATH_PREFIX = "TP_03 - Índice invertido/";

    HashExtensivel<ParGtinId> indiceGtin;
    ArvoreBMais<ParTermoProduto> indiceInvertido;

    public ArquivoProduto() throws Exception {
        super("produtos", Produto.class.getConstructor());
        indiceGtin = new HashExtensivel<>(
                ParGtinId.class.getConstructor(), 4,
                PATH_PREFIX + "Dados/produtos/indiceGtin.d.db",
                PATH_PREFIX + "Dados/produtos/indiceGtin.c.db");

        indiceInvertido = new ArvoreBMais<>(
                ParTermoProduto.class.getConstructor(), 5,
                PATH_PREFIX + "Dados/produtos/indiceInvertido.idx");
    }

    @Override
    public int create(Produto obj) throws Exception {
        if (read(obj.getGtin13()) != null) {
            throw new Exception("Produto com GTIN-13 já cadastrado.");
        }

        int id = super.create(obj);
        obj.setId(id);
        indiceGtin.create(new ParGtinId(obj.getGtin13(), id));

        if (obj.isAtivo()) {
            atualizarIndiceInvertido(null, obj);
        }

        return id;
    }

    public Produto read(String gtin) throws Exception {
        ParGtinId p = indiceGtin.read(gtin.hashCode());
        if (p == null || !p.getGtin().equals(gtin)) {
            return null;
        }
        return super.read(p.getId());
    }

    public List<Produto> readAll() throws Exception {
        List<Produto> todosProdutos = new ArrayList<>();
        arquivo.seek(TAM_CABECALHO); // Pula o cabeçalho

        while (arquivo.getFilePointer() < arquivo.length()) {
            long endereco = arquivo.getFilePointer();
            byte lapide = arquivo.readByte();
            short tam = arquivo.readShort();

            if (lapide == ' ') {
                byte[] ba = new byte[tam];
                arquivo.read(ba);
                Produto p = construtor.newInstance();
                p.fromByteArray(ba);
                todosProdutos.add(p);
            } else {
                arquivo.skipBytes(tam);
            }
        }
        return todosProdutos;
    }

    // A exclusão de um produto (inativação)
    @Override
    public boolean delete(int id) throws Exception {
        Produto p = super.read(id);
        if (p == null)
            return false;

        // Remove os termos do índice invertido antes de inativar
        atualizarIndiceInvertido(p, null);

        // Verificar se o produto está em alguma lista, se sim, não permitir exclusão
        p.setAtivo(false);
        return super.update(p);
    }

    public boolean reativar(int id) throws Exception {
        Produto p = super.read(id);
        if (p == null || p.isAtivo()) // Se já estiver ativo, não faz nada
            return false;

        p.setAtivo(true);
        boolean sucesso = super.update(p);

        // Adiciona os termos ao índice invertido após reativar
        if (sucesso) {
            atualizarIndiceInvertido(null, p);
        }
        return sucesso;
    }

    /**
     * Método auxiliar para gerenciar o índice invertido.
     * Se (pAntigo != null), remove seus termos.
     * Se (pNovo != null), adiciona seus termos.
     */
    private void atualizarIndiceInvertido(Produto pAntigo, Produto pNovo) throws Exception {
        // Remove termos do produto antigo, se fornecido
        if (pAntigo != null) {
            Map<String, Double> termosAntigos = ProcessadorTexto.calcularTF(pAntigo.getNome());
            for (String termo : termosAntigos.keySet()) {
                indiceInvertido.delete(new ParTermoProduto(termo, pAntigo.getId(), 0.0));
            }
        }

        // Adiciona termos do produto novo, se fornecido
        if (pNovo != null && pNovo.isAtivo()) {
            Map<String, Double> termosNovos = ProcessadorTexto.calcularTF(pNovo.getNome());
            for (Map.Entry<String, Double> entry : termosNovos.entrySet()) {
                indiceInvertido.create(new ParTermoProduto(entry.getKey(), pNovo.getId(), entry.getValue()));
            }
        }
    }

    @Override
    public boolean update(Produto obj) throws Exception {
        Produto pAntigo = super.read(obj.getId());
        if (pAntigo == null) {
            return false;
        }

        // Verifica se o nome ou o status mudou
        boolean nomeMudou = !pAntigo.getNome().equals(obj.getNome());
        boolean statusMudou = pAntigo.isAtivo() != obj.isAtivo();

        if (nomeMudou || statusMudou) {
            // Se o nome mudou ou o status mudou, o índice precisa ser atualizado.
            // Remove o índice antigo (baseado no pAntigo)
            atualizarIndiceInvertido(pAntigo, null);
            // Adiciona o novo índice (baseado no obj)
            atualizarIndiceInvertido(null, obj);
        }

        return super.update(obj);
    }

    // Busca produtos por termos de consulta, ordenados por relevância (TF-IDF).
    public List<Produto> searchByTerms(String consulta) throws Exception {
        // Debug da busca (temporario)
        //System.out.println("\n--- DEBUG: INICIANDO BUSCA ---"); // <-- DEBUG
        //System.out.println("Consulta: \"" + consulta + "\""); // <-- DEBUG

        // Processa a consulta do usuário
        Map<String, Double> termosConsulta = ProcessadorTexto.calcularTF(consulta);
        if (termosConsulta.isEmpty()) {
            //System.out.println("DEBUG: Nenhum termo válido na consulta."); // <-- DEBUG
            return new ArrayList<>(); // Retorna lista vazia se a consulta for inválida
        }
        //System.out.println("DEBUG: Termos da consulta processados: " + termosConsulta.keySet()); // <-- DEBUG

        // Coleta pontuações (TF-IDF)
        // Mapa: ID do Produto -> Pontuação de Relevância
        Map<Integer, Double> pontuacoes = new HashMap<>();

        // N = Número total de produtos (para cálculo do IDF)
        int N = readAll().size();
        if (N == 0)
            N = 1; // Evita divisão por zero
        //System.out.println("DEBUG: Total de produtos (N) = " + N); // <-- DEBUG

        for (String termo : termosConsulta.keySet()) {
            //System.out.println("  Buscando termo: '" + termo + "'"); // <-- DEBUG

            // Busca o termo no índice invertido
            ArrayList<ParTermoProduto> pares = indiceInvertido.read(new ParTermoProduto(termo, -1, 0.0));

            // n_t = Número de produtos que contêm o termo
            int n_t = pares.size();
            //System.out.println("  -> Encontrados " + n_t + " produtos para '" + termo + "'"); // <-- DEBUG

            if (n_t > 0) {
                // IDF = log(N / n_t) + 1
                double idf = Math.log((double) N / n_t) + 1.0;
                //System.out.println("  -> IDF para '" + termo + "' = " + idf); // <-- DEBUG

                // Para cada produto que contém o termo, calcula o TF-IDF
                for (ParTermoProduto par : pares) {
                    double tf = par.getTf();
                    double tfIdf = tf * idf;

                    // Acumula a pontuação
                    int idProduto = par.getIdProduto();
                    pontuacoes.put(idProduto, pontuacoes.getOrDefault(idProduto, 0.0) + tfIdf);
                    //System.out.println("    -> IDProduto: " + idProduto + " | TF: " + tf + " | Pontuação TF-IDF: " + tfIdf); // <-- DEBUG
                }
            }
        }

        //System.out.println("DEBUG: Pontuações finais: " + pontuacoes); // <-- DEBUG

        LinkedHashMap<Integer, Double> sortedMap = new LinkedHashMap<>();
        pontuacoes.entrySet().stream()
                .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
                .forEachOrdered(x -> sortedMap.put(x.getKey(), x.getValue()));

        List<Produto> produtosOrdenados = new ArrayList<>();
        for (Integer idProduto : sortedMap.keySet()) {
            Produto p = super.read(idProduto);
            if (p != null) {
                produtosOrdenados.add(p);
            }
        }

        //System.out.println("--- DEBUG: BUSCA CONCLUÍDA ---"); // <-- DEBUG
        return produtosOrdenados;
    }

    // Rotina para reindexar todos os produtos ativos do banco de dados
    // Deve ser executada uma vez para popular o índice com dados existentes
    public void reindexarProdutos() throws Exception {
        System.out.println("Iniciando reindexação... (Isso pode demorar um pouco)");
        // ATENÇÃO: Esta rotina assume que o arquivo 'indiceInvertido.idx' está vazio ou
        // foi deletado manualmente antes de executar

        List<Produto> todos = readAll();
        int contador = 0;
        for (Produto p : todos) {
            // Apenas produtos ATIVOS são indexáveis
            if (p.isAtivo()) {
                atualizarIndiceInvertido(null, p);
                contador++;
            }
        }
        System.out.println(contador + " produtos ativos foram indexados.");
    }

    @Override
    public void close() throws Exception {
        super.close();
        indiceInvertido.close();
    }
}
