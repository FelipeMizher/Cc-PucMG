package Views;

import java.util.Scanner;

import Entidades.Usuario;
import Menus.ConsoleUtils;

public class VisaoUsuario {

    private static Scanner console = new Scanner(System.in);

    public char mostraMenuDadosUsuario(Usuario u) {
        ConsoleUtils.limparTela(); // limpa tela

        System.out.println("\n\nPresenteFácil 3.0");
        System.out.println("-----------------");
        System.out.println("> Início > Meus Dados");
        System.out.println("\nID: " + u.getId());
        System.out.println("Nome: " + u.getNome());
        System.out.println("Email: " + u.getEmail());
        System.out.println("Pergunta secreta: " + u.getPerguntaSecreta());
        System.out.println("\n(1) Alterar meus dados");
        System.out.println("(2) Excluir minha conta");
        System.out.println("\n(R) Retornar ao menu anterior");
        System.out.print("\nOpção: ");
        String entrada = console.nextLine().trim().toUpperCase();
        return entrada.isEmpty() ? ' ' : entrada.charAt(0);
    }

    public String leRespostaParaConfirmacao() {
        System.out.print("\nPara confirmar as alterações, digite sua Resposta Secreta atual: ");
        return console.nextLine();
    }

    public void leAlteracaoUsuario(Usuario u) {
        System.out.println("\n-- Alterar Dados (deixe em branco para manter o valor atual) --");
        System.out.print("Nome [" + u.getNome() + "]: ");
        String nome = console.nextLine();
        if (!nome.isEmpty())
            u.setNome(nome);

        System.out.print("Email [" + u.getEmail() + "]: ");
        String email = console.nextLine();
        if (!email.isEmpty())
            u.setEmail(email);

        System.out.print("Nova senha (opcional): ");
        String senha = console.nextLine();
        if (!senha.isEmpty())
            u.setHashSenha(senha); // A hash será calculada no Controle

        System.out.print("Pergunta secreta [" + u.getPerguntaSecreta() + "]: ");
        String pergunta = console.nextLine();
        if (!pergunta.isEmpty())
            u.setPerguntaSecreta(pergunta);

        System.out.print("Resposta secreta [oculta]: ");
        String resposta = console.nextLine();
        if (!resposta.isEmpty())
            u.setRespostaSecreta(resposta);
    }

    public boolean confirmaExclusao() {
        System.out.print("\nATENÇÃO! Esta ação é irreversível.");
        System.out.print("\nTem certeza que deseja EXCLUIR sua conta? (S/N): ");
        return console.nextLine().trim().equalsIgnoreCase("S");
    }

    public void exibeMensagem(String msg) {
        System.out.println("\n" + msg);
        ConsoleUtils.pausar();
    }
}