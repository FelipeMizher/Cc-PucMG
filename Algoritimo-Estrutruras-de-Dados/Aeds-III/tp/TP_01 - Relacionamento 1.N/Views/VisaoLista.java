package Views;  
  
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.List;
import java.util.Scanner;

import Entidades.Lista;
import Menus.ConsoleUtils;

public class VisaoLista {

    private static Scanner console = new Scanner(System.in);
    private static final SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");

    /**
     * Mostra o menu principal de listas, construído dinamicamente.
     * @param listas As listas do usuário a serem exibidas.
     * @return A opção digitada pelo usuário (pode ser um número ou uma letra).
     */
    public String mostraMenuPrincipalListas(List<Lista> listas) {
        ConsoleUtils.limparTela(); // limpa tela
        
        System.out.println("\n\nPresenteFácil 1.0");
        System.out.println("-----------------");
        System.out.println("> Início > Minhas listas");
        System.out.println("\nLISTAS");
        if (listas.isEmpty()) {
            System.out.println("Nenhuma lista cadastrada.");
        } else {
            for (int i = 0; i < listas.size(); i++) {
                Lista l = listas.get(i);
                System.out.printf("(%d) %s - %s\n", i + 1, l.getNome(), l.getDataLimiteFormatada());
            }
        }
        System.out.println("\n(N) Nova lista");
        System.out.println("(R) Retornar ao menu anterior");
        System.out.print("\nOpção: ");
        return console.nextLine().trim().toUpperCase();
    }

    /**
     * Mostra os detalhes de uma lista específica e o submenu de ações.
     * @param l A lista a ser detalhada.
     * @return O caractere da opção escolhida.
     */
    public char mostraMenuDetalheLista(Lista l) {
        ConsoleUtils.limparTela();
        
        System.out.println("PresenteFácil 1.0");
        System.out.println("-----------------");
        System.out.println("> Início > Minhas listas > " + l.getNome());
        System.out.println("\nCÓDIGO: " + l.getCodigoCompartilhavel());
        System.out.println("NOME: " + l.getNome());
        System.out.println("DESCRIÇÃO: " + l.getDescricao());
        System.out.println("DATA DE CRIAÇÃO: " + l.getDataCriacaoFormatada());
        System.out.println("DATA LIMITE: " + l.getDataLimiteFormatada());

        System.out.println("\n(1) Gerenciar produtos da lista");
        System.out.println("(2) Alterar dados da lista");
        System.out.println("(3) Excluir lista");
        System.out.println("(4) Copiar código de compartilhamento");
        System.out.println("\n(R) Retornar ao menu anterior");
        System.out.print("\nOpção: ");
        String entrada = console.nextLine().trim().toUpperCase();
        return entrada.isEmpty() ? ' ' : entrada.charAt(0);
    }
    
    /**
     * Lê do console os dados para uma nova lista.
     * @return um objeto Lista preenchido (sem IDs).
     */
    public Lista leLista() {
        System.out.println("\n-- Nova Lista --");
        System.out.print("Nome: ");
        String nome = console.nextLine();
        System.out.print("Descrição: ");
        String descricao = console.nextLine();
        System.out.print("Data limite (dd/mm/aaaa, opcional): ");
        String dataStr = console.nextLine();
        long dataLimite = 0;
        if (!dataStr.isEmpty()) {
            try {
                dataLimite = sdf.parse(dataStr).getTime();
            } catch (ParseException e) {
                System.out.println("Formato de data inválido. A data limite não será definida.");
            }
        }
        return new Lista(-1, -1, nome, descricao, dataLimite, "");
    }

    /**
     * Lê do console os dados para alterar uma lista existente.
     * @param l A lista original a ser alterada.
     */
    public void leAlteracaoLista(Lista l) {
        System.out.println("\n-- Alterar Lista (deixe em branco para manter o valor atual) --");
        System.out.print("Nome ["+l.getNome()+"]: ");
        String nome = console.nextLine();
        if(!nome.isEmpty()) l.setNome(nome);

        System.out.print("Descrição ["+l.getDescricao()+"]: ");
        String descricao = console.nextLine();
        if(!descricao.isEmpty()) l.setDescricao(descricao);
        
        System.out.print("Data limite ["+l.getDataLimiteFormatada()+"]: ");
        String dataStr = console.nextLine();
        if (!dataStr.isEmpty()) {
            try {
                l.setDataLimite(sdf.parse(dataStr).getTime());
            } catch (ParseException e) {
                System.out.println("Formato de data inválido. A data limite não será alterada.");
            }
        }
    }

    public boolean confirmaExclusao() {
        System.out.print("\nTem certeza que deseja excluir esta lista? (S/N): ");
        return console.nextLine().trim().toUpperCase().equals("S");
    }

    public void exibeMensagem(String msg) {
        System.out.println("\n" + msg);
        ConsoleUtils.pausar();
    }
}