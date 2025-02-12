import static spark.Spark.*;
import service.ClienteService;

public class Aplicacao {
	
	private static ClienteService clienteService = new ClienteService();
	
	public static void main(String[] args) {
		port(6780);
		
		post("/cliente/insert", (request, response) -> clienteService.insert(request, response));
		
		get("/cliente/", (request, response) -> clienteService.getAll(request, response));
		
		get("/cliente/:id", (request, response) -> clienteService.get(request, response));
	}
	
}
