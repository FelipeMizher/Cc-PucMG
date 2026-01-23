package Controles;

import Arquivo.ArquivoUsuario;
import Entidades.Usuario;
import Views.VisaoUsuario;

public class ControleUsuario {

    private ArquivoUsuario arqUsuarios;
    private VisaoUsuario visao;
    private Usuario usuarioLogado;

    public ControleUsuario(Usuario usuarioLogado) throws Exception {
        this.arqUsuarios = new ArquivoUsuario();
        this.visao = new VisaoUsuario();
        this.usuarioLogado = usuarioLogado;
    }

    /**
     * Inicia a execução do menu de dados do usuário.
     * @return true se a conta foi excluída, false caso contrário.
     */
    public boolean executa() {
        char opcao;
        do {
            opcao = visao.mostraMenuDadosUsuario(usuarioLogado);
            switch (opcao) {
                case '1':
                    alterarDados();
                    break;
                case '2':
                    if (excluirConta()) {
                        return true; // Informa que a conta foi excluída
                    }
                    break;
                case 'R':
                    break;
                default:
                    visao.exibeMensagem("Opção inválida!");
                    break;
            }
        } while (opcao != 'R');
        return false; // A conta não foi excluída
    }

    private void alterarDados() {
        visao.leAlteracaoUsuario(usuarioLogado);
        try {
            arqUsuarios.update(usuarioLogado);
            visao.exibeMensagem("Dados alterados com sucesso!");
        } catch (Exception e) {
            visao.exibeMensagem("Erro ao alterar os dados: " + e.getMessage());
        }
    }

    private boolean excluirConta() {
        if (visao.confirmaExclusao()) {
            try {
                // Tenta excluir o usuário. O método no ArquivoUsuario agora fará a verificação.
                if (arqUsuarios.delete(usuarioLogado.getId())) {
                    visao.exibeMensagem("Sua conta foi excluída com sucesso.");
                    return true;
                }
            } catch (Exception e) {
                // Captura a exceção específica de quando o usuário tem listas
                visao.exibeMensagem("Erro ao excluir conta: " + e.getMessage());
            }
        }
        return false;
    }
}