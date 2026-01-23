package Controles;

import Arquivo.ArquivoLista;
import Arquivo.ArquivoListaProduto;
import Arquivo.ArquivoProduto;
import Arquivo.ArquivoUsuario;
import Entidades.Lista;
import Entidades.ListaProduto;
import Entidades.Produto;
import Entidades.Usuario;
import Views.VisaoBuscaLista;
import java.util.ArrayList;
import java.util.List;

public class ControleBuscaLista {

    private ArquivoLista arqListas;
    private VisaoBuscaLista visao;
    private ArquivoUsuario arqUsuarios;
    private ArquivoProduto arqProdutos;
    private ArquivoListaProduto arqListaProduto;

    public ControleBuscaLista() {
        try {
            this.arqListas = new ArquivoLista();
            this.arqUsuarios = new ArquivoUsuario();
            this.arqProdutos = new ArquivoProduto();
            this.arqListaProduto = new ArquivoListaProduto();
        } catch (Exception e) {
            e.printStackTrace();
        }
        this.visao = new VisaoBuscaLista();
    }

    public void executa() {
        String codigo;
        do {
            codigo = visao.leCodigo();
            if (!codigo.equalsIgnoreCase("R")) {
                try {
                    Lista listaEncontrada = arqListas.readByCodigo(codigo);
                    
                    if (listaEncontrada != null) {
                        Usuario autor = arqUsuarios.read(listaEncontrada.getIdUsuario());

                        List<ListaProduto> associacoes = arqListaProduto.readByIdLista(listaEncontrada.getId());
                        List<String> nomesProdutos = new ArrayList<>();
                        for (ListaProduto lp : associacoes) {
                            Produto p = arqProdutos.read(lp.getIdProduto());
                            if (p != null) {
                                nomesProdutos.add(p.getNome() + " (x" + lp.getQuantidade() + ")");
                            }
                        }
                        
                        visao.mostraListaEncontrada(listaEncontrada, autor, nomesProdutos);
                    } else {
                        visao.mostraListaEncontrada(null, null, null);
                    }

                } catch (Exception e) {
                    System.out.println("Erro ao buscar a lista: " + e.getMessage());
                }
            }
        } while (!codigo.equalsIgnoreCase("R"));
    }
}