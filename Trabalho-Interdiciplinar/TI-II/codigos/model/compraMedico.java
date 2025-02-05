package model;

import java.time.LocalDate;

public class CompraMedico {
    private int id;
    private int medicoCrm; // Relaciona ao CRM do médico
    private int remedioId; // Relaciona ao ID do remédio
    private int quantidade;
    private LocalDate dataValidade;
    private LocalDate dataCompra;

    // Construtor sem parâmetros
    public CompraMedico() {
    }

    // Construtor completo
    public CompraMedico(int id, int medicoCrm, int remedioId, int quantidade, LocalDate dataValidade, LocalDate dataCompra) {
        this.id = id;
        this.medicoCrm = medicoCrm;
        this.remedioId = remedioId;
        this.quantidade = quantidade;
        this.dataValidade = dataValidade;
        this.dataCompra = dataCompra;
    }

    // Getters e Setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getMedicoCrm() {
        return medicoCrm;
    }

    public void setMedicoCrm(int medicoCrm) {
        this.medicoCrm = medicoCrm;
    }

    public int getRemedioId() {
        return remedioId;
    }

    public void setRemedioId(int remedioId) {
        this.remedioId = remedioId;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public LocalDate getDataValidade() {
        return dataValidade;
    }

    public void setDataValidade(LocalDate dataValidade) {
        this.dataValidade = dataValidade;
    }

    public LocalDate getDataCompra() {
        return dataCompra;
    }

    public void setDataCompra(LocalDate dataCompra) {
        this.dataCompra = dataCompra;
    }
}