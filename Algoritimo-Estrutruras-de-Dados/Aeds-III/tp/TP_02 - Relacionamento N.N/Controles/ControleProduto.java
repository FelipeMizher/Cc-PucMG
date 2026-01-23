package Controles;

import java.util.Comparator;
import java.util.List;
import Arquivo.ArquivoProduto;
import Entidades.Produto;
import Views.VisaoProduto;
import java.util.ArrayList;
import Arquivo.ArquivoLista;
import Arquivo.ArquivoListaProduto;
import Entidades.Lista;
import Entidades.ListaProduto;
import Entidades.Usuario;

public class ControleProduto {

    private ArquivoProduto arqProdutos;
    private VisaoProduto visao;
    private Usuario usuarioLogado;

    public ControleProduto(Usuario usuarioLogado) throws Exception {
        this.arqProdutos = new ArquivoProduto();
        this.visao = new VisaoProduto();
        this.usuarioLogado = usuarioLogado;
    }

    public void executa() {
        char opcao;
        do {
            opcao = visao.mostraMenuProdutos();
            switch (opcao) {
                case '1':
                    buscarPorGtin();
                    break;
                case '2':
                    listarTodos();
                    break;
                case '3':
                    cadastrarProduto();
                    break;
                case 'R':
                    break;
                default:
                    visao.exibeMensagem("Opção inválida!");
                    break;
            }
        } while (opcao != 'R');
    }

    private void cadastrarProduto() {
        Produto p = visao.leProduto();

        // Se p for null, o usuário cancelou a operação
        if (p == null) {
            visao.exibeMensagem("Cadastro de produto cancelado.");
            return;
        }

        try {
            arqProdutos.create(p);
            visao.exibeMensagem("Produto cadastrado com sucesso!");
        } catch (Exception e) {
            visao.exibeMensagem("Erro ao cadastrar produto: " + e.getMessage());
        }
    }

    private void buscarPorGtin() {
        String gtin = visao.leGtin();
        try {
            Produto p = arqProdutos.read(gtin);
            if (p == null) {
                visao.exibeMensagem("Produto não encontrado.");
                return;
            }
            visualizarDetalheProduto(p);
        } catch (Exception e) {
            visao.exibeMensagem("Erro ao buscar produto: " + e.getMessage());
        }
    }

    private void alterarProduto(Produto p) {
        visao.leAlteracaoProduto(p);
        try {
            arqProdutos.update(p);
            visao.exibeMensagem("Produto alterado com sucesso!");
        } catch (Exception e) {
            visao.exibeMensagem("Erro ao alterar produto: " + e.getMessage());
        }
    }

    private void listarTodos() {
        try {
            List<Produto> produtos = arqProdutos.readAll();

            produtos.sort(Comparator.comparing(Produto::isAtivo).reversed()
                    .thenComparing(Produto::getNome, String.CASE_INSENSITIVE_ORDER));

            int paginaAtual = 1;
            int produtosPorPagina = 10;
            int totalPaginas = (int) Math.ceil((double) produtos.size() / produtosPorPagina);

            if (totalPaginas == 0) {
                visao.exibeMensagem("Nenhum produto cadastrado.");
                return;
            }

            String opcao;
            do {
                int inicio = (paginaAtual - 1) * produtosPorPagina;
                int fim = Math.min(inicio + produtosPorPagina, produtos.size());
                List<Produto> produtosNaPagina = produtos.subList(inicio, fim);

                opcao = visao.mostraListaPaginadaProdutos(produtosNaPagina, paginaAtual, totalPaginas);

                switch (opcao.toUpperCase()) {
                    case "A":
                        if (paginaAtual > 1)
                            paginaAtual--;
                        break;
                    case "B":
                        if (paginaAtual < totalPaginas)
                            paginaAtual++;
                        break;
                    case "R":
                        break;
                    default:
                        try {
                            int numProduto = Integer.parseInt(opcao);
                            if (numProduto >= 1 && numProduto <= produtosNaPagina.size()) {
                                visualizarDetalheProduto(produtosNaPagina.get(numProduto - 1));
                            } else {
                                visao.exibeMensagem("Opção inválida!");
                            }
                        } catch (NumberFormatException e) {
                            visao.exibeMensagem("Opção inválida!");
                        }
                        break;
                }
            } while (!opcao.equalsIgnoreCase("R"));
        } catch (Exception e) {
            visao.exibeMensagem("Erro ao listar produtos: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private void visualizarDetalheProduto(Produto p) {
    try {
        ArquivoListaProduto arqLP = new ArquivoListaProduto();
        ArquivoLista arqListas = new ArquivoLista();
        List<ListaProduto> associacoes = arqLP.readByIdProduto(p.getId());
        List<String> minhasListas = new ArrayList<>();
        int outrasListasCount = 0;

        for (ListaProduto lp : associacoes) {
            Lista lista = arqListas.read(lp.getIdLista());
            if (lista != null) {
                if (lista.getIdUsuario() == usuarioLogado.getId()) {
                    minhasListas.add(lista.getNome());
                } else {
                    outrasListasCount++;
                }
            }
        }
        
        char opcao;
        do {
            opcao = visao.mostraMenuDetalheProdutoCompleto(p, minhasListas, outrasListasCount);
            switch(opcao) {
                case '1':
                    alterarProduto(p);
                    p = arqProdutos.read(p.getId());
                    break;
                case '2':
                    if (p.isAtivo()) {
                        arqProdutos.delete(p.getId()); // Inativa
                        visao.exibeMensagem("Produto inativado com sucesso.");
                    } else {
                        arqProdutos.reativar(p.getId());
                        visao.exibeMensagem("Produto reativado com sucesso.");
                    }
                    p = arqProdutos.read(p.getId());
                case 'R': break;
                default: visao.exibeMensagem("Opção inválida."); break;
            }
        } while (opcao != 'R');

    } catch (Exception e) {
        visao.exibeMensagem("Erro ao exibir detalhes do produto: " + e.getMessage());
        e.printStackTrace();
    }
}
}