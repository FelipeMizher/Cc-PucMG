package Pares;

import java.io.*;
import java.util.Objects;

import Registros.RegistroHashExtensivel;

public class ParCodigoLista implements RegistroHashExtensivel<ParCodigoLista> {

    private String codigo;
    private int idLista;
    private final short TAMANHO = 14; // 10 bytes para o código + 4 para o ID

    public ParCodigoLista() {
        this("", -1);
    }

    public ParCodigoLista(String codigo, int idLista) {
        // Garante que o código sempre tenha 10 caracteres para o tamanho fixo
        this.codigo = String.format("%-10.10s", codigo);
        this.idLista = idLista;
    }

    public String getCodigo() {
        return this.codigo.trim();
    }

    public int getIdLista() {
        return this.idLista;
    }

    @Override
    public short size() {
        return TAMANHO;
    }

    @Override
    public int hashCode() {
        return this.codigo.trim().hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        ParCodigoLista that = (ParCodigoLista) obj;
        return Objects.equals(this.getCodigo(), that.getCodigo());
    }

    @Override
    public byte[] toByteArray() throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);
        dos.write(this.codigo.getBytes("UTF-8"));
        dos.writeInt(this.idLista);
        return baos.toByteArray();
    }

    @Override
    public void fromByteArray(byte[] ba) throws IOException {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);
        byte[] bufferCodigo = new byte[10];
        dis.read(bufferCodigo);
        this.codigo = new String(bufferCodigo, "UTF-8");
        this.idLista = dis.readInt();
    }
}