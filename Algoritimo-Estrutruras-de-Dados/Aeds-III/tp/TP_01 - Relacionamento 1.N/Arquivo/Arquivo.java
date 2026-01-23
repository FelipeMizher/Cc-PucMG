package Arquivo;

import java.io.File;
import java.io.RandomAccessFile;
import java.lang.reflect.Constructor;

import Estruturas.HashExtensivel;
import Pares.ParIDEndereco;
import Registros.Registro;

public class Arquivo<T extends Registro> {

    protected final int TAM_CABECALHO = 12;
    protected RandomAccessFile arquivo;
    
    String nomeArquivo;
    protected Constructor<T> construtor;
    HashExtensivel<ParIDEndereco> indiceDireto;

    public Arquivo(String na, Constructor<T> c) throws Exception {
        File d = new File("Dados");
        if (!d.exists()) d.mkdir();
        d = new File("Dados/" + na);
        if (!d.exists()) d.mkdir();

        this.nomeArquivo = "Dados/" + na + "/" + na + ".db";
        this.construtor = c;
        arquivo = new RandomAccessFile(this.nomeArquivo, "rw");

        if (arquivo.length() < TAM_CABECALHO) {
            arquivo.writeInt(0);   // último ID
            arquivo.writeLong(-1); // lista de registros marcados para exclusão
        }

        indiceDireto = new HashExtensivel<>(ParIDEndereco.class.getConstructor(), 4,
                "Dados/" + na + "/" + na + ".d.db",
                "Dados/" + na + "/" + na + ".c.db");
    }

    public int create(T obj) throws Exception {
        arquivo.seek(0);
        int proximoID = arquivo.readInt() + 1;
        arquivo.seek(0);
        arquivo.writeInt(proximoID);
        obj.setId(proximoID);
        byte[] b = obj.toByteArray();

        long endereco = getDeleted(b.length);
        if (endereco == -1) {
            arquivo.seek(arquivo.length());
            endereco = arquivo.getFilePointer();
            arquivo.writeByte(' ');
            arquivo.writeShort(b.length);
            arquivo.write(b);
        } else {
            arquivo.seek(endereco);
            arquivo.writeByte(' ');
            arquivo.skipBytes(2);
            arquivo.write(b);
        }

        indiceDireto.create(new ParIDEndereco(proximoID, endereco));
        return obj.getId();
    }

    public T read(int id) throws Exception {
        ParIDEndereco pid = indiceDireto.read(id);
        if (pid == null) return null;

        arquivo.seek(pid.getEndereco());
        byte lapide = arquivo.readByte();
        if (lapide != ' ') return null;

        short tam = arquivo.readShort();
        byte[] b = new byte[tam];
        arquivo.read(b);

        T obj = construtor.newInstance();
        obj.fromByteArray(b);
        return obj.getId() == id ? obj : null;
    }

    public boolean delete(int id) throws Exception {
        ParIDEndereco pie = indiceDireto.read(id);
        if (pie == null) return false;

        arquivo.seek(pie.getEndereco());
        byte lapide = arquivo.readByte();
        if (lapide != ' ') return false;

        short tam = arquivo.readShort();
        indiceDireto.delete(id);
        arquivo.seek(pie.getEndereco());
        arquivo.write('*');
        addDeleted(tam, pie.getEndereco());
        return true;
    }

    public boolean update(T obj) throws Exception {
        ParIDEndereco pie = indiceDireto.read(obj.getId());
        if (pie == null) return false;

        arquivo.seek(pie.getEndereco());
        byte lapide = arquivo.readByte();
        if (lapide != ' ') return false;

        short tamAntigo = arquivo.readShort();
        byte[] bNovo = obj.toByteArray();
        short tamNovo = (short) bNovo.length;

        if (tamNovo <= tamAntigo) {
            arquivo.seek(pie.getEndereco() + 3);
            arquivo.write(bNovo);
        } else {
            arquivo.seek(pie.getEndereco());
            arquivo.write('*');
            addDeleted(tamAntigo, pie.getEndereco());

            long novoEndereco = getDeleted(bNovo.length);
            if (novoEndereco == -1) {
                arquivo.seek(arquivo.length());
                novoEndereco = arquivo.getFilePointer();
                arquivo.writeByte(' ');
                arquivo.writeShort(tamNovo);
                arquivo.write(bNovo);
            } else {
                arquivo.seek(novoEndereco);
                arquivo.writeByte(' ');
                arquivo.skipBytes(2);
                arquivo.write(bNovo);
            }

            indiceDireto.update(new ParIDEndereco(obj.getId(), novoEndereco));
        }

        return true;
    }

    public void addDeleted(int tamanhoEspaco, long enderecoEspaco) throws Exception {
        arquivo.seek(4);
        long inicio = arquivo.readLong();
        arquivo.seek(4);
        arquivo.writeLong(enderecoEspaco);
        arquivo.seek(enderecoEspaco + 3);
        arquivo.writeLong(inicio);
    }

    public long getDeleted(int tamanhoNecessario) throws Exception {
        arquivo.seek(4);
        long endereco = arquivo.readLong();
        if (endereco == -1) return -1;

        arquivo.seek(endereco + 1);
        short tamanho = arquivo.readShort();
        if (tamanho >= tamanhoNecessario) {
            arquivo.seek(4);
            arquivo.writeLong(-1);
            return endereco;
        }
        return -1;
    }

    public void close() throws Exception {
        arquivo.close();
        indiceDireto.close();
    }
}