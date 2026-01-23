package Pares;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.Arrays;

import Registros.RegistroHashExtensivel;

public class ParEmailID implements RegistroHashExtensivel<ParEmailID> {

    private String email;
    private int id;
    // O tamanho fixo é mantido pois a sua versão do HashExtensivel.java exige registros de tamanho fixo.
    private final short TAMANHO = 68; // 64 bytes para email + 4 para ID

    public ParEmailID() {
        this.email = "";
        this.id = -1;
    }

    public ParEmailID(String email, int id) {
        this.email = email;
        this.id = id;
    }

    public int getID() {
        return id;
    }

    public String getEmail() {
        return email;
    }

    public short size() {
        return TAMANHO;
    }

    @Override
    public int hashCode() {
        String emailNormalizado = (this.email == null) ? "" : this.email.trim().toLowerCase();
        if (emailNormalizado.isEmpty()) {
            return 0;
        }
        long hashValue = 0;
        for (int i = 0; i < emailNormalizado.length(); i++) {
            hashValue = (hashValue * 31 + emailNormalizado.charAt(i)) % 1000000007;
        }
        return (int) Math.abs(hashValue);
    }

    @Override
    public String toString() {
        return "(" + this.email + ";" + this.id + ")";
    }

    @Override
    public byte[] toByteArray() throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);

        // cria buffer de email com 64 bytes zerados
        byte[] bufferEmail = new byte[64];
        Arrays.fill(bufferEmail, (byte) 0);

        // copia os bytes do email para dentro do buffer zerado
        byte[] emailBytes = this.email.getBytes("UTF-8");
        System.arraycopy(emailBytes, 0, bufferEmail, 0, Math.min(emailBytes.length, 64));

        dos.write(bufferEmail);
        dos.writeInt(this.id);

        return baos.toByteArray();
    }

    @Override
    public void fromByteArray(byte[] ba) throws IOException {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);

        byte[] bufferEmail = new byte[64];
        dis.readFully(bufferEmail);

        // remove caracteres nulos (\u0000) e espaços extras
        this.email = new String(bufferEmail, "UTF-8")
                .replace("\u0000", "")
                .trim();

        this.id = dis.readInt();
    }
}