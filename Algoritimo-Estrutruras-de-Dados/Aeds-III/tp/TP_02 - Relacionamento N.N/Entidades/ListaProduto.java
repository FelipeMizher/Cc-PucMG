package Entidades;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import Registros.Registro;

public class ListaProduto implements Registro {

    private int id;
    private int idLista;
    private int idProduto;
    private int quantidade;
    private String observacoes;

    public ListaProduto() {
        this(-1, -1, -1, 1, "");
    }

    public ListaProduto(int id, int idLista, int idProduto, int quantidade, String observacoes) {
        this.id = id;
        this.idLista = idLista;
        this.idProduto = idProduto;
        this.quantidade = quantidade;
        this.observacoes = observacoes;
    }
    
    // Getters
    public int getId() { return id; }
    public int getIdLista() { return idLista; }
    public int getIdProduto() { return idProduto; }
    public int getQuantidade() { return quantidade; }
    public String getObservacoes() { return observacoes; }

    // Setters
    public void setId(int id) { this.id = id; }
    public void setIdLista(int idLista) { this.idLista = idLista; }
    public void setIdProduto(int idProduto) { this.idProduto = idProduto; }
    public void setQuantidade(int quantidade) { this.quantidade = quantidade; }
    public void setObservacoes(String observacoes) { this.observacoes = observacoes; }

    // Serialização para o CRUD (toByteArray / fromByteArray)
    @Override
    public byte[] toByteArray() throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);
        dos.writeInt(id);
        dos.writeInt(idLista);
        dos.writeInt(idProduto);
        dos.writeInt(quantidade);
        dos.writeUTF(observacoes);
        return baos.toByteArray();
    }

    // Desserialização para o CRUD (toByteArray / fromByteArray)
    @Override
    public void fromByteArray(byte[] ba) throws IOException {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
        this.id = dis.readInt();
        this.idLista = dis.readInt();
        this.idProduto = dis.readInt();
        this.quantidade = dis.readInt();
        this.observacoes = dis.readUTF();
    }
}