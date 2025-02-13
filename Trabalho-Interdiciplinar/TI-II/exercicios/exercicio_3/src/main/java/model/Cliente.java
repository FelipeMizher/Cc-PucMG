package model;

public class Cliente {

	private int codigo;
	private String nome;
	private String email;
	private int idade;
	
	public Cliente() {
		super();
		this.codigo = -1;
		this.nome = "";
		this.email = "";
		this.idade = 0;
	}
	
	public Cliente(int codigo, String nome, String email, int idade) {
		this.codigo = codigo;
		this.nome = nome;
		this.email = email;
		this.idade = idade;
	}
	
	public int getCodigo() {
		return codigo;
	}
	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}
	public int getIdade() {
		return idade;
	}
	public void setIdade(int idade) {
		this.idade = idade;
	}

	@Override
	public String toString() {
		return "Cliente [codigo=" + codigo + ", nome=" + nome + ", email=" + email + ", idade=" + idade + "]";
	}
	
	
	
	
	
}
