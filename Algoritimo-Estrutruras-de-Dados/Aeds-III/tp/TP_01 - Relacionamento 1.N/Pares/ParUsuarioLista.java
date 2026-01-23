package Pares;

import java.io.*;

import Registros.RegistroArvoreBMais;

public class ParUsuarioLista implements RegistroArvoreBMais<ParUsuarioLista> {

    private int idUsuario;
    private int idLista;
    private final short TAMANHO = 8; // Dois inteiros = 4 + 4 bytes

    public ParUsuarioLista() {
        this(-1, -1);
    }

    public ParUsuarioLista(int idUsuario, int idLista) {
        this.idUsuario = idUsuario;
        this.idLista = idLista;
    }

    public int getIdUsuario() {
        return this.idUsuario;
    }

    public int getIdLista() {
        return this.idLista;
    }

    @Override
    public short size() {
        return this.TAMANHO;
    }

    @Override
    public ParUsuarioLista clone() {
        return new ParUsuarioLista(this.idUsuario, this.idLista);
    }

    // Compara dois pares. A comparação primária é pelo idUsuario.
    @Override
    public int compareTo(ParUsuarioLista outro) {
        if (this.idUsuario != outro.idUsuario) {
            return this.idUsuario - outro.idUsuario;
        }
        return (this.idLista == -1) ? 0 : this.idLista - outro.idLista;
    }

    @Override
    public byte[] toByteArray() throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);
        dos.writeInt(this.idUsuario);
        dos.writeInt(this.idLista);
        return baos.toByteArray();
    }

    @Override
    public void fromByteArray(byte[] ba) throws IOException {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
        this.idUsuario = dis.readInt();
        this.idLista = dis.readInt();
    }
}