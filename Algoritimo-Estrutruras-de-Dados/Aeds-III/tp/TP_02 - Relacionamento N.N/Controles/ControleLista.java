package Controles;

import java.util.Comparator;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Map;
import java.util.LinkedHashMap;
import java.util.stream.Collectors;

import Arquivo.ArquivoLista;
import Arquivo.ArquivoListaProduto;
import Arquivo.ArquivoProduto;
import Entidades.Lista;
import Entidades.ListaProduto;
import Entidades.Produto;
import Entidades.Usuario;
import Menus.ConsoleUtils;
import Views.VisaoLista;

public class ControleLista {

    private ArquivoLista arqListas;
    private VisaoLista visao;
    private Usuario usuarioLogado;
    private ArquivoProduto arqProdutos;
    private ArquivoListaProduto arqListaProduto;

    public ControleLista(Usuario usuarioLogado) {
        try {
            this.arqListas = new ArquivoLista();
            this.arqProdutos = new ArquivoProduto();
            this.arqListaProduto = new ArquivoListaProduto();
        } catch (Exception e) {
            e.printStackTrace();
        }
        this.visao = new VisaoLista();
        this.usuarioLogado = usuarioLogado;
    }

    // Inicia a tela principal de "Minhas Listas"
    public void executa() {
        String opcao;
        do {
            // 1. Pega as listas do usuário
            List<Lista> listas = null;
            try {
                listas = arqListas.readAll(usuarioLogado.getId());
            } catch (Exception e) {
                visao.exibeMensagem("Erro ao ler as listas: " + e.getMessage());
                listas = new java.util.ArrayList<>();
            }

            // 2. Ordena as listas por nome
            listas.sort(Comparator.comparing(Lista::getNome));

            // 3. Mostra o menu e lê a opção
            opcao = visao.mostraMenuPrincipalListas(listas);

            switch (opcao) {
                case "N":
                    incluirLista();
                    break;
                case "R":
                    // Apenas sai do loop
                    break;
                default:
                    try {
                        int numLista = Integer.parseInt(opcao) - 1;
                        if (numLista >= 0 && numLista < listas.size()) {
                            gerenciarLista(listas.get(numLista));
                        } else {
                            visao.exibeMensagem("Opção inválida!");
                        }
                    } catch (NumberFormatException e) {
                        visao.exibeMensagem("Opção inválida!");
                    }
                    break;
            }
        } while (!opcao.equals("R"));
    }

    /**
     * Inicia a tela de detalhes para uma lista específica.
     * 
     * @param lista A lista a ser gerenciada.
     */
    private void gerenciarLista(Lista lista) {
        char opcao;
        do {
            opcao = visao.mostraMenuDetalheLista(lista);
            switch (opcao) {
                case '1':
                    gerenciarProdutosDaLista(lista); // CHAMADA PARA O NOVO MÉTODO
                    break;
                case '2':
                    alterarLista(lista);
                    break;
                case '3':
                    if (excluirLista(lista)) {
                        return; // Retorna ao menu anterior se a lista foi excluída
                    }
                    break;
                case '4':
                    try {
                        String codigo = lista.getCodigoCompartilhavel();
                        ConsoleUtils.copiarParaClipboard(codigo);
                        visao.exibeMensagem("Código \"" + codigo + "\" copiado para a área de transferência!");
                    } catch (Exception e) {
                        // Trata o erro caso o sistema não tenha interface gráfica
                        visao.exibeMensagem(
                                "Erro: Não foi possível copiar para a área de transferência neste ambiente.");
                    }
                    break;
                case 'R':
                    break;
                default:
                    visao.exibeMensagem("Opção inválida!");
                    break;
            }
        } while (opcao != 'R');
    }

    private void incluirLista() {
        Lista novaLista = visao.leLista();
        novaLista.setIdUsuario(usuarioLogado.getId());
        try {
            arqListas.create(novaLista);
            visao.exibeMensagem("Lista \"" + novaLista.getNome() + "\" criada com sucesso!");
        } catch (Exception e) {
            visao.exibeMensagem("Erro ao criar lista: " + e.getMessage());
        }
    }

    private void alterarLista(Lista lista) {
        visao.leAlteracaoLista(lista);
        try {
            arqListas.update(lista);
            visao.exibeMensagem("Lista alterada com sucesso!");
        } catch (Exception e) {
            visao.exibeMensagem("Erro ao alterar lista: " + e.getMessage());
        }
    }

    private boolean excluirLista(Lista lista) {
        if (visao.confirmaExclusao()) {
            try {
                arqListas.delete(lista.getId());
                visao.exibeMensagem("Lista excluída com sucesso!");
                return true;
            } catch (Exception e) {
                visao.exibeMensagem("Erro ao excluir lista: " + e.getMessage());
                return false;
            }
        }
        return false;
    }

    private void gerenciarProdutosDaLista(Lista lista) {
        char opcao;
        do {
            Map<ListaProduto, Produto> mapaProdutos = new LinkedHashMap<>();
            try {
                List<ListaProduto> associacoes = arqListaProduto.readByIdLista(lista.getId());
                for (ListaProduto lp : associacoes) {
                    Produto p = arqProdutos.read(lp.getIdProduto());
                    if (p != null) {
                        mapaProdutos.put(lp, p);
                    }
                }
            } catch (Exception e) {
                visao.exibeMensagem("Erro ao carregar produtos: " + e.getMessage());
            }

            Map<ListaProduto, Produto> mapaOrdenado = mapaProdutos.entrySet().stream()
                    .sorted(Map.Entry
                            .comparingByValue(Comparator.comparing(Produto::getNome, String.CASE_INSENSITIVE_ORDER)))
                    .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue, (e1, e2) -> e1,
                            LinkedHashMap::new));

            List<String> nomesProdutos = new ArrayList<>();
            List<ListaProduto> associacoesOrdenadas = new ArrayList<>(mapaOrdenado.keySet());

            for (ListaProduto lp : associacoesOrdenadas) {
                Produto p = mapaOrdenado.get(lp);
                String status = p.isAtivo() ? "" : " (INATIVO)";
                nomesProdutos.add(p.getNome() + " (x" + lp.getQuantidade() + ")" + status);
            }

            String entrada = visao.mostraMenuProdutosDaLista(lista, nomesProdutos).trim().toUpperCase();
            opcao = entrada.isEmpty() ? ' ' : entrada.charAt(0);

            switch (opcao) {
                case 'A':
                    acrescentarProdutoNaLista(lista);
                    break;
                case 'R':
                    break;
                default:
                    try {
                        int numProduto = Integer.parseInt(entrada) - 1;
                        if (numProduto >= 0 && numProduto < associacoesOrdenadas.size()) {
                            gerenciarProdutoSelecionado(associacoesOrdenadas.get(numProduto));
                        } else {
                            visao.exibeMensagem("Opção inválida!");
                        }
                    } catch (NumberFormatException e) {
                        visao.exibeMensagem("Opção inválida!");
                    }
                    break;
            }
        } while (opcao != 'R');
    }

    private void acrescentarProdutoNaLista(Lista lista) {
        char opcao;
        do {
            opcao = visao.mostraMenuAcrescentarProduto();
            Produto produtoSelecionado = null;
            try {
                switch (opcao) {
                    case '1':
                        System.out.print("Digite o GTIN-13: ");
                        String gtin = new Scanner(System.in).nextLine();
                        produtoSelecionado = arqProdutos.read(gtin);
                        if (produtoSelecionado == null)
                            visao.exibeMensagem("Produto não encontrado.");
                        break;
                    case '2':
                        produtoSelecionado = selecionarProdutoDeListaGeral();
                        break;
                    case 'R':
                        break;
                    default:
                        visao.exibeMensagem("Opção inválida.");
                        break;
                }

                if (produtoSelecionado != null) {
                    if (!produtoSelecionado.isAtivo()) {
                        visao.exibeMensagem("Este produto está inativo e não pode ser adicionado.");
                    } else if (visao.confirmaAcrescentar(produtoSelecionado.getNome())) {
                        int quantidade = visao.leQuantidade();
                        String obs = visao.leObservacoes();

                        ListaProduto novaAssociacao = new ListaProduto(-1, lista.getId(), produtoSelecionado.getId(),
                                quantidade, obs);
                        arqListaProduto.create(novaAssociacao);
                        visao.exibeMensagem("Produto adicionado!");
                        opcao = 'R'; // Volta para a tela de produtos da lista
                    }
                }
            } catch (Exception e) {
                visao.exibeMensagem("Erro: " + e.getMessage());
            }
        } while (opcao != 'R');
    }

    private Produto selecionarProdutoDeListaGeral() throws Exception {
        List<Produto> produtos = arqProdutos.readAll();
        produtos.removeIf(p -> !p.isAtivo()); // Remove inativos
        produtos.sort(Comparator.comparing(Produto::getNome, String.CASE_INSENSITIVE_ORDER));

        if (produtos.isEmpty()) {
            visao.exibeMensagem("Nenhum produto ativo cadastrado.");
            return null;
        }

        int paginaAtual = 1;
        int produtosPorPagina = 10;
        int totalPaginas = (int) Math.ceil((double) produtos.size() / produtosPorPagina);

        String opcao;
        do {
            int inicio = (paginaAtual - 1) * produtosPorPagina;
            int fim = Math.min(inicio + produtosPorPagina, produtos.size());
            List<Produto> produtosNaPagina = produtos.subList(inicio, fim);

            opcao = visao.mostraSelecaoPaginadaProdutos(produtosNaPagina, paginaAtual, totalPaginas);

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
                    return null;
                default:
                    try {
                        int numProduto = Integer.parseInt(opcao);
                        if (numProduto >= 1 && numProduto <= produtosNaPagina.size()) {
                            // Retorna o produto selecionado
                            return produtosNaPagina.get(numProduto - 1);
                        } else {
                            visao.exibeMensagem("Opção inválida!");
                        }
                    } catch (NumberFormatException e) {
                        visao.exibeMensagem("Opção inválida!");
                    }
                    break;
            }
        } while (true);
    }

    private void gerenciarProdutoSelecionado(ListaProduto lp) {
        try {
            Produto p = arqProdutos.read(lp.getIdProduto());
            if (p == null) {
                visao.exibeMensagem("Produto associado não encontrado. Removendo associação corrompida.");
                arqListaProduto.delete(lp.getId());
                return;
            }

            char opcao = visao.mostraMenuGerenciarProduto(p.getNome());
            switch (opcao) {
                case '1': // Alterar
                    visao.leAlteracaoProdutoDaLista(lp);
                    arqListaProduto.update(lp);
                    visao.exibeMensagem("Produto na lista alterado com sucesso!");
                    break;
                case '2': // Remover
                    System.out.print("Tem certeza que deseja remover este produto da lista? (S/N): ");
                    if (new Scanner(System.in).nextLine().trim().equalsIgnoreCase("S")) {
                        arqListaProduto.delete(lp.getId());
                        visao.exibeMensagem("Produto removido da lista.");
                    }
                    break;
                case 'R':
                    break;
                default:
                    visao.exibeMensagem("Opção inválida.");
                    break;
            }

        } catch (Exception e) {
            visao.exibeMensagem("Erro ao gerenciar produto: " + e.getMessage());
        }
    }
}