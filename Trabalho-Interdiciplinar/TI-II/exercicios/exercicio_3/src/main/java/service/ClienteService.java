package service;
import java.util.List;
import java.util.Scanner;
import java.io.File;
import dao.ClienteDAO;
import model.Cliente;
import spark.Request;
import spark.Response;

public class ClienteService {
	private ClienteDAO ClienteDAO = new ClienteDAO();
	private String form;
	private final int FORM_INSERT = 1;
	private final int FORM_DETAIL = 2;
	private final int FORM_UPDATE = 3;
	
	public void makeForm() {
		makeForm(FORM_INSERT, new Cliente());
	}

	public void makeForm(int tipo, Cliente cliente) {
	    String nomeArquivo = "form.html";
	    form = "";
	    try {
	        Scanner entrada = new Scanner(new File(nomeArquivo));
	        while (entrada.hasNext()) {
	            form += (entrada.nextLine() + "\n");
	        }
	        entrada.close();
	    } catch (Exception e) {
	        System.out.println(e.getMessage());
	    }

	    String umCliente = "";
	    if (tipo != FORM_INSERT) {
	        umCliente += "\t<table width=\"80%\" bgcolor=\"#f3f3f3\" align=\"center\">";
	        umCliente += "\t\t<tr>";
	        umCliente += "\t\t\t<td align=\"left\"><font size=\"+2\"><b>&nbsp;&nbsp;&nbsp;<a href=\"/cliente/list/1\">Novo Cliente</a></b></font></td>";
	        umCliente += "\t\t</tr>";
	        umCliente += "\t</table>";
	        umCliente += "\t<br>";
	    }

	    if (tipo == FORM_INSERT || tipo == FORM_UPDATE) {
	        String action = "/cliente/";
	        String name, email, buttonLabel;
	        if (tipo == FORM_INSERT) {
	            action += "insert";
	            name = "Inserir Cliente";
	            email = "email@example.com";
	            buttonLabel = "Inserir";
	        } else {
	            action += "update/" + cliente.getCodigo();
	            name = "Atualizar Cliente (Código " + cliente.getCodigo() + ")";
	            email = cliente.getEmail();
	            buttonLabel = "Atualizar";
	        }
	        umCliente += "\t<form class=\"form--register\" action=\"" + action + "\" method=\"post\" id=\"form-add\">";
	        umCliente += "\t<table width=\"80%\" bgcolor=\"#f3f3f3\" align=\"center\">";
	        umCliente += "\t\t<tr>";
	        umCliente += "\t\t\t<td colspan=\"3\" align=\"left\"><font size=\"+2\"><b>&nbsp;&nbsp;&nbsp;" + name + "</b></font></td>";
	        umCliente += "\t\t</tr>";
	        umCliente += "\t\t<tr>";
	        umCliente += "\t\t\t<td colspan=\"3\" align=\"left\">&nbsp;</td>";
	        umCliente += "\t\t</tr>";
	        umCliente += "\t\t<tr>";
	        umCliente += "\t<tr>";
	        umCliente += "\t\t<td>&nbsp;Código: <input class=\"input--register\" type=\"text\" name=\"codigo\" value=\"" + cliente.getCodigo() + "\"></td>";
	        umCliente += "\t</tr>";
	        umCliente += "\t\t\t<td>&nbsp;Nome: <input class=\"input--register\" type=\"text\" name=\"nome\" value=\"" + cliente.getNome() + "\"></td>";
	        umCliente += "\t\t\t<td>Email: <input class=\"input--register\" type=\"text\" name=\"email\" value=\"" + email + "\"></td>";
	        umCliente += "\t\t\t<td>Idade: <input class=\"input--register\" type=\"text\" name=\"idade\" value=\"" + cliente.getIdade() + "\"></td>";
	        umCliente += "\t\t</tr>";
	        umCliente += "\t\t<tr>";
	        umCliente += "\t\t\t<td colspan=\"3\" align=\"center\"><input type=\"submit\" value=\"" + buttonLabel + "\" class=\"input--main__style input--button\"></td>";
	        umCliente += "\t\t</tr>";
	        umCliente += "\t</table>";
	        umCliente += "\t</form>";
	    } else if (tipo == FORM_DETAIL) {
	        umCliente += "\t<table width=\"80%\" bgcolor=\"#f3f3f3\" align=\"center\">";
	        umCliente += "\t\t<tr>";
	        umCliente += "\t\t\t<td colspan=\"3\" align=\"left\"><font size=\"+2\"><b>&nbsp;&nbsp;&nbsp;Detalhar Cliente (Código " + cliente.getCodigo() + ")</b></font></td>";
	        umCliente += "\t\t</tr>";
	        umCliente += "\t\t<tr>";
	        umCliente += "\t\t\t<td colspan=\"3\" align=\"left\">&nbsp;</td>";
	        umCliente += "\t\t</tr>";
	        umCliente += "\t<tr>";
	        umCliente += "\t\t\t<td>&nbsp;Nome: " + cliente.getNome() + "</td>";
	        umCliente += "\t\t\t<td>Email: " + cliente.getEmail() + "</td>";
	        umCliente += "\t\t\t<td>Idade: " + cliente.getIdade() + "</td>";
	        umCliente += "\t\t</tr>";
	        umCliente += "\t</table>";
	    } else {
	        System.out.println("ERRO! Tipo não identificado " + tipo);
	    }
	    form = form.replaceFirst("<UM-CLIENTE>", umCliente);

	    String list = new String("<table width=\"80%\" align=\"center\" bgcolor=\"#f3f3f3\">");
	    list += "\n<tr><td colspan=\"4\" align=\"left\"><font size=\"+2\"><b>&nbsp;&nbsp;&nbsp;Relação de Clientes</b></font></td></tr>\n" +
	            "\n<tr><td colspan=\"4\">&nbsp;</td></tr>\n" +
	            "\n<tr>\n" +
	            "</tr>\n";

	    List<Cliente> clientes = ClienteDAO.getAll();

	    int i = 0;
	    String bgcolor = "";
	    for (Cliente c : clientes) {
	        bgcolor = (i++ % 2 == 0) ? "#fff5dd" : "#dddddd";
	        list += "\n<tr bgcolor=\"" + bgcolor + "\">\n" +
	                "\t<td>" + c.getCodigo() + "</td>\n" +
	                "\t<td>" + c.getNome() + "</td>\n" +
	                "\t<td>" + c.getEmail() + "</td>\n" +
	                "\t<td>" + c.getIdade() + "</td>\n" +
	                "</tr>\n";
	    }
	    list += "</table>";
	    form = form.replaceFirst("<LISTAR-CLIENTE>", list);
	}
	
	public Object get(Request request, Response response) {
	    int id = Integer.parseInt(request.params(":id"));
	    Cliente cliente = (Cliente) ClienteDAO.getByCodigo(id);

	    if (cliente != null) {
	        response.status(200); // success
	        makeForm(FORM_DETAIL, cliente);
	    } else {
	        response.status(404); // 404 Not found
	        String resp = "Cliente " + id + " não encontrado.";
	        makeForm();
	        form.replaceFirst("<input type=\"hidden\" id=\"msg\" name=\"msg\" value=\"\">", "<input type=\"hidden\" id=\"msg\" name=\"msg\" value=\"" + resp + "\">");
	    }

	    return form;
	}
	
	public Object insert(Request request, Response response) {
		int codigo = Integer.parseInt(request.queryParams("codigo"));
	    String nome = request.queryParams("nome");
	    String email = request.queryParams("email");
	    int idade = Integer.parseInt(request.queryParams("idade"));

	    String resp = "";

	    Cliente cliente = new Cliente(codigo, nome, email, idade);

	    if (ClienteDAO.insert(cliente)) {
	        resp = "Cliente (" + nome + ") inserido!";
	        response.status(201); // 201 Created
	    } else {
	        resp = "Cliente (" + nome + ") não inserido!";
	        response.status(404); // 404 Not found
	    }

	    makeForm();
	    return form.replaceFirst("<input type=\"hidden\" id=\"msg\" name=\"msg\" value=\"\">", "<input type=\"hidden\" id=\"msg\" name=\"msg\" value=\"" + resp + "\">");
	}
	
	public Object getAll(Request request, Response response) {
		makeForm();
	    response.header("Content-Type", "text/html");
	    response.header("Content-Encoding", "UTF-8");
		return form;
	}	


}
