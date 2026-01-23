package Controles;

import java.util.Comparator;
import java.util.List;
import Arquivo.ArquivoLista;
import Entidades.Lista;
import Entidades.Usuario;
import Menus.ConsoleUtils;
import Views.VisaoLista;

public class ControleLista {

    private ArquivoLista arqListas;
    private VisaoLista visao;
    private Usuario usuarioLogado;

    public ControleLista(Usuario usuarioLogado) {
        try {
            this.arqListas = new ArquivoLista();
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
     * @param lista A lista a ser gerenciada.
     */
    private void gerenciarLista(Lista lista) {
        char opcao;
        do {
            opcao = visao.mostraMenuDetalheLista(lista);
            switch (opcao) {
                case '1':
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
}