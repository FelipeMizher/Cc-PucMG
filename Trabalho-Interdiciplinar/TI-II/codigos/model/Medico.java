package model;

public class Medico {
    private int crm;
    private String nome;
    private String sobrenome;
    private String email;
    private String data_nascimento;
    private String senha; // Novo atributo

    // Construtor sem parâmetros
    public Medico() {
    }

    // Construtor completo sem senha
    public Medico(int crm, String nome, String sobrenome, String email, String data_nascimento) {
        this.crm = crm;
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.email = email;
        this.data_nascimento = data_nascimento;
    }

    // Construtor completo com senha
    public Medico(int crm, String nome, String sobrenome, String email, String data_nascimento, String senha) {
        this.crm = crm;
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.email = email;
        this.data_nascimento = data_nascimento;
        this.senha = senha;
    }

    // Getters e Setters
    public int getCrm() {
        return crm;
    }

    public void setCrm(int crm) {
        this.crm = crm;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSobrenome() {
        return sobrenome;
    }

    public void setSobrenome(String sobrenome) {
        this.sobrenome = sobrenome;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getDataNascimento() {
        return data_nascimento;
    }

    public void setDataNascimento(String data_nascimento) {
        this.data_nascimento = data_nascimento;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }
}