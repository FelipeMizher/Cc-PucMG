package Menus;

import Arquivo.*;
import Entidades.*;
import Controles.*;

import java.util.Scanner;
import java.security.MessageDigest;

public class MenuUsuarios {

    ArquivoUsuario arqUsuarios;
    private Usuario usuarioAtivo;
    private static Scanner console = new Scanner(System.in);

    public MenuUsuarios() throws Exception {
        arqUsuarios = new ArquivoUsuario();
    }

    public void incluirUsuario() {
        System.out.println("\nInclusão de usuário");
        try {
            String nome;
            do {
                System.out.print("Nome (min 4 chars, vazio p/ cancelar): ");
                nome = console.nextLine();
                if (nome.length() == 0) return;
                if (nome.length() < 4) System.err.println("Nome muito curto.");
            } while(nome.length() < 4);

            String email;
            do {
                System.out.print("Email (vazio p/ cancelar): ");
                email = console.nextLine().trim();
                if (email.isEmpty()) return;
                if (!email.contains("@")) System.err.println("Email inválido.");
            } while(!email.contains("@"));

            // verifica existência
            if (arqUsuarios.read(email) != null) {
                System.out.println("Email já cadastrado.");
                ConsoleUtils.pausar();
                return;
            }

            System.out.print("Senha: ");
            String senha = console.nextLine();

            System.out.print("Pergunta secreta (para recuperação): ");
            String pergunta = console.nextLine();

            System.out.print("Resposta secreta: ");
            String resposta = console.nextLine();

            String hash = hashSenha(senha);

            
            arqUsuarios.create(new Usuario(-1, nome, email, hash, pergunta, resposta));
            System.out.println("Usuário cadastrado com sucesso.");
            ConsoleUtils.pausar();

        } catch(Exception e) {
            System.out.println("Erro ao incluir usuário: " + e.getMessage());
            ConsoleUtils.pausar();
        }
    }

    public Usuario getUsuarioAtivo() {
        return usuarioAtivo;
    }

    public void login() {
        System.out.println("\nLogin");
        System.out.print("Email: ");
        String email = console.nextLine().trim();
        if (email.isEmpty()) return;
    
        System.out.print("Senha: ");
        String senha = console.nextLine();
    
        try {
            Usuario u = arqUsuarios.read(email);
            if (u == null) {
                System.out.println("Usuário não encontrado.");
                ConsoleUtils.pausar();
                return;
            }
    
            String hash = hashSenha(senha);
            if (hash.equals(u.getHashSenha())) {
                usuarioAtivo = u; // define usuário ativo
                System.out.println("\nLogin bem-sucedido. Bem-vindo, " + u.getNome() + "!");
                ConsoleUtils.pausar();

                // Exibe o menu principal do usuário
                menuPrincipalUsuario();
    
            } else {
                System.out.println("Senha incorreta.");
                ConsoleUtils.pausar();
            }
        } catch(Exception e) {
            System.out.println("Erro no login: " + e.getMessage());
            ConsoleUtils.pausar();
        }
    }
    
        private void menuPrincipalUsuario() {
        char opcao;
        boolean contaExcluida = false;
        do {
            ConsoleUtils.limparTela(); // limpa tela

            System.out.println("\n\nPresenteFácil 1.0");
            System.out.println("-----------------");
            System.out.println("> Início");
            System.out.println("\n(1) Meus dados");
            System.out.println("(2) Minhas listas");
            System.out.println("(3) Produtos (Funcionalidade Produtos (TP2) ainda não implementada.)");
            System.out.println("(4) Buscar lista");
            System.out.println("\n(S) Sair");
    
            System.out.print("\nOpção: ");
            String entrada = console.nextLine().trim().toUpperCase();
            opcao = entrada.isEmpty() ? ' ' : entrada.charAt(0);
    
            switch (opcao) {
                case '1':
                    try {
                        ControleUsuario controleUsuario = new ControleUsuario(usuarioAtivo);
                        if (controleUsuario.executa()) {
                            contaExcluida = true; // Marca que a conta foi excluída
                        }
                    } catch(Exception e) {
                        System.out.println("Erro ao gerenciar dados do usuário: " + e.getMessage());
                        ConsoleUtils.pausar();
                    }
                    break;
                case '2': 
                    try {
                        ControleLista controleLista = new ControleLista(usuarioAtivo);
                        controleLista.executa();
                    } catch(Exception e) {
                        System.out.println("Erro ao iniciar o módulo de listas: " + e.getMessage());
                        ConsoleUtils.pausar();
                    }
                    break;
                case '3': 
                    break;
                case '4': 
                    try {
                        ControleBuscaLista controleBusca = new ControleBuscaLista();
                        controleBusca.executa();
                    } catch(Exception e) {
                        System.out.println("Erro ao iniciar o módulo de busca: " + e.getMessage());
                        ConsoleUtils.pausar();
                    }
                    break;
                case 'S': 
                    System.out.println("\nSaindo da sua conta..."); 
                    usuarioAtivo = null;
                    break;
                default: 
                    System.out.println("\nOpção inválida!"); 
                    ConsoleUtils.pausar();
                    break;
            }
    
        } while (opcao != 'S' && !contaExcluida);

        if (contaExcluida) {
            usuarioAtivo = null; // Garante que o usuário seja deslogado
        }
        
    }

    // SHA-256 hex
    private static String hashSenha(String senha) {
        try {
            senha = senha.trim(); // remove espaços extras
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] bytes = md.digest(senha.getBytes("UTF-8"));
            StringBuilder sb = new StringBuilder();
            for (byte b : bytes) sb.append(String.format("%02x", b));
            return sb.toString();
        } catch(Exception e) {
            throw new RuntimeException(e);
        }
    }
}
