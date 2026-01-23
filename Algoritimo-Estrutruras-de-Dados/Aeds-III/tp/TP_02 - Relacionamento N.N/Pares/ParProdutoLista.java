package Pares;

import java.io.*;
import Registros.RegistroArvoreBMais;

public class ParProdutoLista implements RegistroArvoreBMais<ParProdutoLista> {

    private int idProduto;
    private int idListaProduto;
    private final short TAMANHO = 8;

    public ParProdutoLista() {
        this(-1, -1);
    }

    public ParProdutoLista(int idProduto, int idListaProduto) {
        this.idProduto = idProduto;
        this.idListaProduto = idListaProduto;
    }

    public int getIdProduto() {
        return this.idProduto;
    }

    public int getIdListaProduto() {
        return this.idListaProduto;
    }

    public short size() {
        return this.TAMANHO;
    }

    public ParProdutoLista clone() {
        return new ParProdutoLista(this.idProduto, this.idListaProduto);
    }

    @Override
    public int compareTo(ParProdutoLista outro) {
        if (this.idProduto != outro.idProduto) {
            return this.idProduto - outro.idProduto;
        }
        // Se o ID da lista na busca for -1, considera como um 'match' para qualquer
        // lista.
        return (this.idListaProduto == -1) ? 0 : this.idListaProduto - outro.idListaProduto;
    }

    public byte[] toByteArray() throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        DataOutputStream dos = new DataOutputStream(baos);
        dos.writeInt(this.idProduto);
        dos.writeInt(this.idListaProduto);
        return baos.toByteArray();
    }

    public void fromByteArray(byte[] ba) throws IOException {
        DataInputStream dis = new DataInputStream(new ByteArrayInputStream(ba));
        this.idProduto = dis.readInt();
        this.idListaProduto = dis.readInt();
    }
}