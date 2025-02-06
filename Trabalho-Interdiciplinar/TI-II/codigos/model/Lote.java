package model;

public class Lote {
    private int id;
    private Remedio remedio; // Referência direta ao objeto Remedio
    private String validade;
    private int quantidade;
    private CompraMedico compraMedico; // Referência direta ao objeto CompraMedico

    // Construtor sem parâmetros
    public Lote() {
    }

    // construtor sem compra médico
    public Lote(int id, Remedio remedio, String validade, int quantidade) {
        this.id = id;
        this.remedio = remedio;
        this.validade = validade;
        this.quantidade = quantidade;
    }

    // Construtor completo
    public Lote(int id, Remedio remedio, String validade, int quantidade, CompraMedico compraMedico) {
        this.id = id;
        this.remedio = remedio;
        this.validade = validade;
        this.quantidade = quantidade;
        this.compraMedico = compraMedico;
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

    public String getValidade() {
        return validade;
    }

    public void setValidade(String validade) {
        this.validade = validade;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public CompraMedico getCompraMedico() {
        return compraMedico;
    }

    public void setCompraMedico(CompraMedico compraMedico) {
        this.compraMedico = compraMedico;
    }
}