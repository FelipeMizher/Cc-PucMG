package Entidades;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import Registros.Registro;

public class Produto implements Registro {

    private int id;
    private String gtin13;
    private String nome;
    private String descricao;
    private boolean ativo;

    public Produto() {
        this(-1, "", "", "", true);
    }

    public Produto(int id, String gtin13, String nome, String descricao, boolean ativo) {
        this.id = id;
        this.gtin13 = gtin13;
        this.nome = nome;
        this.descricao = descricao;
        this.ativo = ativo;
    }

    // Getters
    public int getId() { return id; }
    public String getGtin13() { return gtin13; }
    public String getNome() { return nome; }
    public String getDescricao() { return descricao; }
    public boolean isAtivo() { return ativo; }

    // Setters
    public void setId(int id) { this.id = id; }
    public void setGtin13(String gtin13) { this.gtin13 = gtin13; }
    public void setNome(String nome) { this.nome = nome; }
    public void setDescricao(String descricao) { this.descricao = descricao; }
    public void setAtivo(boolean ativo) { this.ativo = ativo; }

    // Serialização para o CRUD (toByteArray / fromByteArray)
    @Override
    public byte[] toByteArray() throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);
        dos.writeInt(id);
        dos.writeUTF(gtin13);
        dos.writeUTF(nome);
        dos.writeUTF(descricao);
        dos.writeBoolean(ativo);
        return baos.toByteArray();
    }

    // Desserialização para o CRUD (toByteArray / fromByteArray)
    @Override
    public void fromByteArray(byte[] ba) throws IOException {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
        this.id = dis.readInt();
        this.gtin13 = dis.readUTF();
        this.nome = dis.readUTF();
        this.descricao = dis.readUTF();
        this.ativo = dis.readBoolean();
    }
}