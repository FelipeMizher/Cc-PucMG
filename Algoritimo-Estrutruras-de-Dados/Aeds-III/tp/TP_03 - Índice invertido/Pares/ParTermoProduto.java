package Pares;

import java.io.*;
import java.util.Arrays;
import Registros.RegistroArvoreBMais;

public class ParTermoProduto implements RegistroArvoreBMais<ParTermoProduto> {

    // Define um tamanho fixo para a string do termo
    private final int TAMANHO_TERMO = 30;

    // Tamanho total do registro: 30 (termo) + 4 (idProduto) + 8 (tf) = 42 bytes
    private final short TAMANHO = 42;

    private String termo;
    private int idProduto;
    private double tf; // Term Frequency

    public ParTermoProduto() {
        this("", -1, 0.0);
    }

    public ParTermoProduto(String termo, int idProduto, double tf) {
        this.termo = termo;
        this.idProduto = idProduto;
        this.tf = tf;
    }

    // Getters
    public String getTermo() {
        return this.termo;
    }

    public int getIdProduto() {
        return this.idProduto;
    }

    public double getTf() {
        return this.tf;
    }

    @Override
    public short size() {
        return this.TAMANHO;
    }

    @Override
    public ParTermoProduto clone() {
        return new ParTermoProduto(this.termo, this.idProduto, this.tf);
    }

    /**
     * Compara dois pares. A comparação primária é pelo 'termo'.
     * Se os termos são iguais, a comparação secundária é pelo 'idProduto'.
     */
    @Override
    public int compareTo(ParTermoProduto outro) {
        int compTermo = this.termo.compareTo(outro.termo);
        if (compTermo != 0) {
            return compTermo;
        }
        // Se o ID do produto na busca for -1, considera como um 'match' (retorna 0)
        return (this.idProduto == -1 || outro.idProduto == -1) ? 0 : this.idProduto - outro.idProduto;
    }

    @Override
    public byte[] toByteArray() throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);

        // Cria um buffer de bytes com o tamanho fixo
        byte[] bufferTermo = new byte[TAMANHO_TERMO];
        Arrays.fill(bufferTermo, (byte) 0); // Preenche com zeros

        byte[] termoBytes = this.termo.getBytes("UTF-8");
        System.arraycopy(termoBytes, 0, bufferTermo, 0, Math.min(termoBytes.length, TAMANHO_TERMO));

        dos.write(bufferTermo);

        dos.writeInt(this.idProduto);
        dos.writeDouble(this.tf);

        return baos.toByteArray();
    }

    @Override
    public void fromByteArray(byte[] ba) throws IOException {
        ByteArrayInputStream bais = new ByteArrayInputStream(ba);
        DataInputStream dis = new DataInputStream(bais);

        byte[] bufferTermo = new byte[TAMANHO_TERMO];
        dis.readFully(bufferTermo);

        // Converte o buffer para String, remove os nulos e espaços extras
        this.termo = new String(bufferTermo, "UTF-8").trim();
        int nullPos = this.termo.indexOf('\0');
        if (nullPos != -1) {
            this.termo = this.termo.substring(0, nullPos);
        }

        this.idProduto = dis.readInt();
        this.tf = dis.readDouble();
    }

    @Override
    public String toString() {
        return "Par(Termo: '" + this.termo + "', IDProduto: " + this.idProduto + ", TF: " + this.tf + ")";
    }
}