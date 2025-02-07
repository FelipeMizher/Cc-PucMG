package model;

public class Remedio {
    private int id;
    private String nome;
    private double preco;
    private int estoque;
    private int medicoCrm; // Adicionado atributo para a chave estrangeira

    // Construtor sem parâmetros
    public Remedio() {
    }

    // Construtor completo
    public Remedio(int id, String nome, double preco, int estoque, int medicoCrm) {
        this.id = id;
        this.nome = nome;
        this.preco = preco;
        this.estoque = estoque;
        this.medicoCrm = medicoCrm;
    }

    // Getters e Setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public int getEstoque() {
        return estoque;
    }

    public void setEstoque(int estoque) {
        this.estoque = estoque;
    }

    public int getMedicoCrm() {
        return medicoCrm;
    }

    public void setMedicoCrm(int medicoCrm) {
        this.medicoCrm = medicoCrm;
    }

    @Override
    public String toString() {
        return "Remedio{" +
                "id=" + id +
                ", nome='" + nome + '\'' +
                ", preco=" + preco +
                ", estoque=" + estoque +
                ", medicoCrm=" + medicoCrm +
                '}';
    }
}