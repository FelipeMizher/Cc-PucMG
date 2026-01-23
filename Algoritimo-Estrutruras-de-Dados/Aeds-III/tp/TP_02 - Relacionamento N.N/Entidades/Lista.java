package Entidades;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;

import Registros.Registro;

public class Lista implements Registro {

    private int id;
    private int idUsuario;
    private String nome;
    private String descricao;
    private long dataCriacao;
    private long dataLimite; // Opcional, 0 se não houver
    private String codigoCompartilhavel;

    private static final SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");

    public Lista() {
        this(-1, -1, "", "", 0, "");
    }

    public Lista(int id, int idUsuario, String nome, String descricao, long dataLimite, String codigo) {
        this.id = id;
        this.idUsuario = idUsuario;
        this.nome = nome;
        this.descricao = descricao;
        this.dataLimite = dataLimite;
        // Data de criação é sempre a data atual no momento da criação real
        this.dataCriacao = new Date().getTime(); 
        this.codigoCompartilhavel = codigo;
    }

    // Getters
    public int getId() { return id; }
    public int getIdUsuario() { return idUsuario; }
    public String getNome() { return nome; }
    public String getDescricao() { return descricao; }
    public String getCodigoCompartilhavel() { return codigoCompartilhavel; }

    public String getDataCriacaoFormatada() {
        return sdf.format(new Date(this.dataCriacao));
    }

    public String getDataLimiteFormatada() {
        if (this.dataLimite == 0) {
            return "N/D";
        }
        return sdf.format(new Date(this.dataLimite));
    }

    // Setters
    public void setId(int id) { this.id = id; }
    public void setIdUsuario(int id) { this.idUsuario = id; }
    public void setNome(String n) { this.nome = n; }
    public void setDescricao(String d) { this.descricao = d; }
    public void setDataLimite(long d) { this.dataLimite = d; }
    public void setDataCriacao(long d) { this.dataCriacao = d; }
    public void setCodigoCompartilhavel(String c) { this.codigoCompartilhavel = c; }

    @Override
    public byte[] toByteArray() throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);
        dos.writeInt(id);
        dos.writeInt(idUsuario);
        dos.writeUTF(nome);
        dos.writeUTF(descricao);
        dos.writeLong(dataCriacao);
        dos.writeLong(dataLimite);
        dos.writeUTF(codigoCompartilhavel);
        return baos.toByteArray();
    }

    @Override
    public void fromByteArray(byte[] ba) throws IOException {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
        this.id = dis.readInt();
        this.idUsuario = dis.readInt();
        this.nome = dis.readUTF();
        this.descricao = dis.readUTF();
        this.dataCriacao = dis.readLong();
        this.dataLimite = dis.readLong();
        this.codigoCompartilhavel = dis.readUTF();
    }
}