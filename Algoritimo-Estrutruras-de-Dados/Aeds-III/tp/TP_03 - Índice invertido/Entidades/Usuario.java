package Entidades;

import java.io.*;

import Registros.Registro;

public class Usuario implements Registro {

    private int id;
    private String nome;
    private String email;
    private String hashSenha;
    private String perguntaSecreta;
    private String respostaSecreta;

    public Usuario() {
        this(-1, "", "", "", "", "");
    }

    public Usuario(int id, String nome, String email, String hashSenha, String pergunta, String resposta) {
        this.id = id;
        this.nome = nome;
        this.email = email;
        this.hashSenha = hashSenha;
        this.perguntaSecreta = pergunta;
        this.respostaSecreta = resposta;
    }

    // getters / setters
    @Override
    public void setId(int i) { this.id = i; }
    @Override
    public int getId() { return this.id; }

    public String getNome() { return nome; }
    public void setNome(String n) { this.nome = n; }

    public String getEmail() { return email; }
    public void setEmail(String e) { this.email = e; }

    public String getHashSenha() { return hashSenha; }
    public void setHashSenha(String h) { this.hashSenha = h; }

    public String getPerguntaSecreta() { return perguntaSecreta; }
    public void setPerguntaSecreta(String p) { this.perguntaSecreta = p; }

    public String getRespostaSecreta() { return respostaSecreta; }
    public void setRespostaSecreta(String r) { this.respostaSecreta = r; }

    // serialização para o CRUD (toByteArray / fromByteArray)
    @Override
    public byte[] toByteArray() throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);

        dos.writeInt(this.id);
        dos.writeUTF(this.nome != null ? this.nome : "");
        dos.writeUTF(this.email != null ? this.email : "");
        dos.writeUTF(this.hashSenha != null ? this.hashSenha : "");
        dos.writeUTF(this.perguntaSecreta != null ? this.perguntaSecreta : "");
        dos.writeUTF(this.respostaSecreta != null ? this.respostaSecreta : "");

        return baos.toByteArray();
    }

    @Override
    public void fromByteArray(byte[] ba) throws IOException {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);

        this.id = dis.readInt();
        this.nome = dis.readUTF();
        this.email = dis.readUTF();
        this.hashSenha = dis.readUTF();
        this.perguntaSecreta = dis.readUTF();
        this.respostaSecreta = dis.readUTF();
    }

    @Override
    public String toString() {
        return "ID: " + id + " | Nome: " + nome + " | Email: " + email;
    }
}