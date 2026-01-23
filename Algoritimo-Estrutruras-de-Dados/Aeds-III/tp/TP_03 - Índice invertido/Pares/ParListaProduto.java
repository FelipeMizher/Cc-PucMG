package Pares;

import java.io.*;
import Registros.RegistroArvoreBMais;

public class ParListaProduto implements RegistroArvoreBMais<ParListaProduto> {

    private int idLista;
    private int idListaProduto;
    private final short TAMANHO = 8;

    public ParListaProduto() {
        this(-1, -1);
    }

    public ParListaProduto(int idLista, int idListaProduto) {
        this.idLista = idLista;
        this.idListaProduto = idListaProduto;
    }

    public int getIdLista() {
        return this.idLista;
    }

    public int getIdListaProduto() {
        return this.idListaProduto;
    }

    public short size() {
        return this.TAMANHO;
    }

    public ParListaProduto clone() {
        return new ParListaProduto(this.idLista, this.idListaProduto);
    }

    @Override
    public int compareTo(ParListaProduto outro) {
        if (this.idLista != outro.idLista) {
            return this.idLista - outro.idLista;
        }
        // Se o ID do produto na busca for -1, considera como um 'match' para qualquer
        // produto.
        return (this.idListaProduto == -1) ? 0 : this.idListaProduto - outro.idListaProduto;
    }

    public byte[] toByteArray() throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);
        dos.writeInt(this.idLista);
        dos.writeInt(this.idListaProduto);
        return baos.toByteArray();
    }

    public void fromByteArray(byte[] ba) throws IOException {
        DataInputStream dis = new DataInputStream(new ByteArrayInputStream(ba));
        this.idLista = dis.readInt();
        this.idListaProduto = dis.readInt();
    }
}