import java.util.Scanner;
import Menus.ConsoleUtils;
import Menus.MenuUsuarios;

public class Main {
    public static void main(String[] args) {

        Scanner console = new Scanner(System.in);
        MenuUsuarios menuUsuarios;

        try {
            menuUsuarios = new MenuUsuarios();

            char opcao;
            do {
                ConsoleUtils.limparTela(); // limpa tela

                System.out.println("\n\nPresente Fácil 2.0");
                System.out.println("------------------");
                System.out.println("\n(1) Login");
                System.out.println("(2) Novo usuário");
                System.out.println("(S) Sair");

                System.out.print("\nOpção: ");
                String entrada = console.nextLine().trim().toUpperCase();
                opcao = entrada.isEmpty() ? ' ' : entrada.charAt(0);

                switch (opcao) {
                    case '1':
                        menuUsuarios.login();
                        break;
                    case '2':
                        menuUsuarios.incluirUsuario();
                        break;
                    case 'S':
                        System.out.println("Saindo...");
                        break;
                    default:
                        System.out.println("Opção inválida!");
                        ConsoleUtils.pausar();
                        break;
                }

            } while (opcao != 'S');

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            console.close();
        }
    }
}