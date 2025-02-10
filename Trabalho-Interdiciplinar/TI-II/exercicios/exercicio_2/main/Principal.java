import java.util.List;
import java.util.Scanner;

import dao.ClienteDAO;
import models.Cliente;


public class Principal{
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		 ClienteDAO clienteDAO = new ClienteDAO();
		
		int resposta = 0;   
		
		while(resposta != 5){
			System.out.println(" Menu: ");
			System.out.println("1 - Inserir cliente");
			System.out.println("2 - Listar clientes");
			System.out.println("3 - Excluir cliente");
			System.out.println("4 - Atualizar cliente");
			System.out.println("5 - Sair");
			System.out.println("Escolha uma das opcao: ");
			resposta = sc.nextInt();
			
			switch(resposta) {
			case(1):
				System.out.println("Codigo: ");
			
				int codigo = sc.nextInt();
				sc.nextLine();
				
				System.out.println("Nome: ");
				String nome = sc.nextLine();
				
				System.out.println("Email: ");
				String email = sc.nextLine();
				
				System.out.println("Idade: ");
				int idade = sc.nextInt();
				sc.nextLine();
				
				Cliente cliente = new Cliente(codigo, nome, email, idade);
				
				clienteDAO.insert(cliente);
				break;
				
			case(2):
				List<Cliente> clientes =  clienteDAO.getAll();
				System.out.println("Clientes registrados: ");
				System.out.println(clientes);
				break;
				
			case(3):
				System.out.println("Digite o codigo do cliente que deseja excluir: ");
				int codigoAExcluir = sc.nextInt();
				sc.nextLine();
				clienteDAO.delete(codigoAExcluir);
				break;
			
			case(4):
				System.out.println("Digite o codigo do cliente que deseja atualizar informações: ");
				System.out.println("Obs: mpossivel alterar codigo e idade");
				int codigoAtt = sc.nextInt();
				sc.nextLine();
				
				System.out.println("Novo nome: ");
				String nomeAtt = sc.nextLine();
				
				System.out.println("Novo email: ");
				String emailAtt = sc.nextLine();
				
				Cliente cAntigo = clienteDAO.getByCodigo(codigoAtt);
						
	
				Cliente clienteAtt = new Cliente(cAntigo.getCodigo(), nomeAtt, emailAtt, cAntigo.getCodigo());
				
				clienteDAO.update(clienteAtt);
				
				break;
			default:
				System.out.println("Digite um numero que está no menu.");
				break;
			}
		}
		System.out.println("Programa encerrado.");
		sc.close();
	}
}