package Pares;

import java.io.*;
import Registros.RegistroHashExtensivel;

public class ParGtinId implements RegistroHashExtensivel<ParGtinId> {

    private String gtin;
    private int id;
    private final short TAMANHO = 17; // GTIN-13 (13 bytes) + ID (4 bytes)

    public ParGtinId() {
        this("", -1);
    }

    public ParGtinId(String gtin, int id) {
        // Garante que o GTIN tenha 13 caracteres para o tamanho fixo
        this.gtin = String.format("%-13.13s", gtin);
        this.id = id;
    }

    public String getGtin() { return this.gtin.trim(); }
    public int getId() { return this.id; }
    public short size() { return TAMANHO; }

    @Override
    public int hashCode() {
        return this.getGtin().hashCode();
    }

    @Override
    public byte[] toByteArray() throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);
        dos.write(this.gtin.getBytes("UTF-8"));
        dos.writeInt(this.id);
        return baos.toByteArray();
    }

    @Override
    public void fromByteArray(byte[] ba) throws IOException {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
        byte[] bufferGtin = new byte[13];
        dis.read(bufferGtin);
        this.gtin = new String(bufferGtin, "UTF-8");
        this.id = dis.readInt();
    }
}