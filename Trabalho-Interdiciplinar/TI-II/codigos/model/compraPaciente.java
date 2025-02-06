package model;

public class CompraPaciente {
    private int id;
    private Remedio remedio;  // Alterado para referenciar o objeto Remedio
    private int quantidade;
    private String data;

    // Construtor sem parâmetros
    public CompraPaciente() {
    }

    // Construtor completo
    public CompraPaciente(int id, Remedio remedio, int quantidade, String data) {
        this.id = id;
        this.remedio = remedio;
        this.quantidade = quantidade;
        this.data = data;
    }

    // Getters e Setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Remedio getRemedio() {
        return remedio;
    }

    public void setRemedio(Remedio remedio) {
        this.remedio = remedio;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }
}