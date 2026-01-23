package Controles;

import Arquivo.ArquivoUsuario;
import Entidades.Usuario;
import Views.VisaoUsuario;
import java.security.MessageDigest;

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
     * 
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
        // Cria um clone do usuário para não alterar o original se a confirmação falhar
        Usuario uClone = new Usuario(
                usuarioLogado.getId(), usuarioLogado.getNome(), usuarioLogado.getEmail(),
                usuarioLogado.getHashSenha(), usuarioLogado.getPerguntaSecreta(), usuarioLogado.getRespostaSecreta());

        visao.leAlteracaoUsuario(uClone);

        String respostaConfirmacao = visao.leRespostaParaConfirmacao();

        if (respostaConfirmacao.equals(usuarioLogado.getRespostaSecreta())) {
            try {
                // Se a senha foi alterada (não é mais a mesma hash), calcula a nova hash
                // (Usamos o email como placeholder para a nova senha no objeto)
                if (!uClone.getHashSenha().equals(usuarioLogado.getHashSenha())) {
                    String novaSenha = uClone.getHashSenha();
                    uClone.setHashSenha(hashSenha(novaSenha)); 
                }

                // Atualiza o arquivo com os dados do clone
                if (arqUsuarios.update(uClone)) {
                    // Se o update foi bem-sucedido, atualiza o objeto do usuário logado na memória
                    this.usuarioLogado = uClone;
                    visao.exibeMensagem("Dados alterados com sucesso!");
                } else {
                    visao.exibeMensagem("Erro: Não foi possível atualizar os dados.");
                }

            } catch (Exception e) {
                visao.exibeMensagem("Erro ao alterar os dados: " + e.getMessage());
            }
        } else {
            visao.exibeMensagem("Resposta secreta incorreta. As alterações foram descartadas.");
        }
    }

    private static String hashSenha(String senha) {
        try {
            senha = senha.trim();
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] bytes = md.digest(senha.getBytes("UTF-8"));
            StringBuilder sb = new StringBuilder();
            for (byte b : bytes)
                sb.append(String.format("%02x", b));
            return sb.toString();
        } catch (Exception e) {
            throw new RuntimeException(e);
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