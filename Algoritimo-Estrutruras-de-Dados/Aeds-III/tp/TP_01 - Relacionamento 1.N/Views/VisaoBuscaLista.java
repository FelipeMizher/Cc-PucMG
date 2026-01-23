package Views;

import java.util.Scanner;

import Entidades.Lista;
import Menus.ConsoleUtils;

public class VisaoBuscaLista {
    
    private static Scanner console = new Scanner(System.in);

    public String leCodigo() {
        ConsoleUtils.limparTela(); // limpa tela

        System.out.println("\n\nPresenteFácil 1.0");
        System.out.println("-----------------");
        System.out.println("> Buscar Lista");
        System.out.print("\nDigite o código compartilhável da lista (ou 'R' para retornar ao menu): ");
        return console.nextLine().trim();
    }

    public void mostraListaEncontrada(Lista l) {
        if (l == null) {
            System.out.println("\nNenhuma lista encontrada com este código.");
            ConsoleUtils.pausar();
            return;
        }

        System.out.println("\n-- Lista Encontrada --");
        System.out.println("NOME: " + l.getNome());
        System.out.println("DESCRIÇÃO: " + l.getDescricao());
        System.out.println("DATA LIMITE: " + l.getDataLimiteFormatada());
        System.out.println("\n(Em breve: visualizar produtos da lista)");
        System.out.println("----------------------");
        
        ConsoleUtils.pausar();
    }
}