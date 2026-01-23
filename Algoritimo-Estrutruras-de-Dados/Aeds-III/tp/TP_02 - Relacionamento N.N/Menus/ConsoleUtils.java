package Menus;

// Imports para copiar automaticamente o código de compartilhamento de uma lista
import java.awt.Toolkit;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.StringSelection;

import java.io.IOException;
import java.util.Scanner;

public class ConsoleUtils {

    // Adicionamos um Scanner estático para não precisar criá-lo toda vez
    private static Scanner console = new Scanner(System.in);

    // Limpa a tela do console. Funciona em Windows, Linux e macOS.
    public static void limparTela() {
        try {
            String os = System.getProperty("os.name").toLowerCase();

            if (os.contains("win")) {
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            } else {
                new ProcessBuilder("clear").inheritIO().start().waitFor();
            }
        } catch (IOException | InterruptedException e) {
            for (int i = 0; i < 50; i++) {
                System.out.println();
            }
        }
    }

    // Método para "pausar" assim será possivel que as mensagens de erro não sumam
    // assim que aparecem
    public static void pausar() {
        System.out.print("\nPressione ENTER para continuar...");
        console.nextLine();
    }

    /**
     * Copia o texto fornecido para a área de transferência do sistema.
     * @param texto O texto a ser copiado.
     */
    public static void copiarParaClipboard(String texto) {
        // Pega a área de transferência do sistema
        Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
        // Cria um objeto "selecionável" com o texto
        StringSelection stringSelection = new StringSelection(texto);
        // Define o conteúdo da área de transferência
        clipboard.setContents(stringSelection, null);
    }
}