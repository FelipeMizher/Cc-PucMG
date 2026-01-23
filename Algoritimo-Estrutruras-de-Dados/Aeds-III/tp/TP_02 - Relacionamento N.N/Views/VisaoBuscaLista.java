package Views;

import java.util.Scanner;
import Entidades.Lista;
import Menus.ConsoleUtils;
import Entidades.Usuario;
import java.util.List;

public class VisaoBuscaLista {

    private static Scanner console = new Scanner(System.in);

    public String leCodigo() {
        ConsoleUtils.limparTela(); // limpa tela

        System.out.println("\n\nPresenteFácil 2.0");
        System.out.println("-----------------");
        System.out.println("> Buscar Lista");
        System.out.print("\nDigite o código compartilhável da lista (ou 'R' para retornar ao menu): ");
        return console.nextLine().trim();
    }

    public void mostraListaEncontrada(Lista l, Usuario autor, List<String> nomesProdutos) {
        if (l == null) {
            System.out.println("\nNenhuma lista encontrada com este código.");
            ConsoleUtils.pausar();
            return;
        }

        System.out.println("\n-- Lista Encontrada --");
        System.out.println("NOME: " + l.getNome());
        System.out.println("AUTOR: " + (autor != null ? autor.getNome() : "Desconhecido"));
        System.out.println("DESCRIÇÃO: " + l.getDescricao());
        System.out.println("DATA LIMITE: " + l.getDataLimiteFormatada());
        System.out.println("\n-- PRODUTOS --");
        if (nomesProdutos.isEmpty()) {
            System.out.println("Nenhum produto nesta lista.");
        } else {
            for (String nomeProduto : nomesProdutos) {
                System.out.println("- " + nomeProduto);
            }
        }
        System.out.println("----------------------");

        ConsoleUtils.pausar();
    }
}