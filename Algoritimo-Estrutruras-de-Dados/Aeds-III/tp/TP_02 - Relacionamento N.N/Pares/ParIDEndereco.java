package Pares;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

import Registros.RegistroHashExtensivel;

public class ParIDEndereco implements RegistroHashExtensivel<ParIDEndereco> {

    private int id;
    private long endereco;
    private final short TAMANHO = 12;

    public ParIDEndereco() {
        this.id = -1;
        this.endereco = -1;
    }

    public ParIDEndereco(int id, long endereco) {
        this.id = id;
        this.endereco = endereco;
    }

    public int getId() {
        return id;
    }

    public long getEndereco() {
        return endereco;
    }

    public short size() {
        return TAMANHO;
    }

    @Override
    public int hashCode() {
        return id;
    }

    public String toString() {
        return "(" + id + ";" + endereco + ")";
    }

    public byte[] toByteArray() throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);
        dos.writeInt(id);
        dos.writeLong(endereco);
        return baos.toByteArray();
    }

    public void fromByteArray(byte[] ba) throws IOException {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
        id = dis.readInt();
        endereco = dis.readLong();
    }
}