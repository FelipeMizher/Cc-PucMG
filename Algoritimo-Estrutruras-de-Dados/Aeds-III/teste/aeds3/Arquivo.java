package aeds3;
import java.io.*;
import java.lang.reflect.Constructor;

public class Arquivo<T extends Entidade> {

    RandomAccessFile arquivo;
    HashExtensivel<ParIDEndereco> indiceDireto;
    String nomeArquivo;
    int TAM_CABECALHO = 12;
    Constructor<T> construtor;

    public Arquivo(String nomeArquivo, Constructor<T> construtor) throws Exception {
        this.nomeArquivo = nomeArquivo;
        this.construtor = construtor;
        arquivo = new RandomAccessFile("./dados/"+nomeArquivo+".db", "rw");
        indiceDireto = new HashExtensivel<>(ParIDEndereco.class.getConstructor(), 4, "./dados/"+nomeArquivo+".d.db", "./dados/"+nomeArquivo+".c.db");
        if(arquivo.length()<TAM_CABECALHO) {
            arquivo.writeInt(0);  // último id usado
            arquivo.writeLong(-1);  // cabeça da lista de espaços vazios
        }
    }

    public int create(T entidade) throws Exception {

        // Obtem o ID para esta entidade
        arquivo.seek(0);
        int novoId = arquivo.readInt()+1;
        arquivo.seek(0);
        arquivo.writeInt(novoId);
        entidade.setID(novoId);

        // Escreve o novo registro no fim do arquivo
        byte[] vb = entidade.toByteArray();
        long pos = buscaVazio(vb.length);
        if(pos == -1) {
            arquivo.seek(arquivo.length());
            pos = arquivo.getFilePointer();
            arquivo.writeByte(' ');
            arquivo.writeShort(vb.length);
            arquivo.write(vb);
        } else {
            arquivo.seek(pos);
            arquivo.writeByte(' ');
            arquivo.skipBytes(2);
            arquivo.write(vb);
        }
        indiceDireto.create(new ParIDEndereco(entidade.getID(), pos));
        return novoId;
    }

    public T read(int id) throws Exception {
        arquivo.seek(TAM_CABECALHO);
        ParIDEndereco pie = indiceDireto.read(id);
        if(pie!=null) {
            arquivo.seek(pie.getEndereco());
            byte lapide = arquivo.readByte();
            short tam = arquivo.readShort();
            if(lapide==' ') {
                byte[] vb = new byte[tam];
                arquivo.read(vb);
                T entidade = construtor.newInstance();
                entidade.fromByteArray(vb);
                if(entidade.getID() == id) {
                    return entidade;
                }
            }
        }
        return null;
    }

    public boolean update(T novaEntidade) throws Exception {
        ParIDEndereco pie = indiceDireto.read(novaEntidade.getID());
        if(pie!=null) {
            long pos = pie.getEndereco();
            arquivo.seek(pos);
            byte lapide = arquivo.readByte();
            short tam = arquivo.readShort();
            if(lapide==' ') {
                byte[] vb = new byte[tam];
                arquivo.read(vb);
                T entidade = construtor.newInstance();
                entidade.fromByteArray(vb);
                if(entidade.getID() == novaEntidade.getID()) {
                    byte[] vb2 = novaEntidade.toByteArray();
                    int tam2 = vb2.length;
                    if(tam2 <= tam) {
                        arquivo.seek(pos+3);
                        arquivo.write(vb2);
                    } else {
                        arquivo.seek(pos);
                        arquivo.writeByte('*');
                        insereVazio(pos, tam);

                        long novaPos = buscaVazio(tam2);
                        if(novaPos == -1) {
                            arquivo.seek(arquivo.length());
                            novaPos = arquivo.getFilePointer();
                            arquivo.writeByte(' ');
                            arquivo.writeShort(tam2);
                            arquivo.write(vb2);
                        } else {
                            arquivo.seek(novaPos);
                            arquivo.writeByte(' ');
                            arquivo.skipBytes(2);
                            arquivo.write(vb2);
                        }
                        indiceDireto.update(new ParIDEndereco(novaEntidade.getID(), novaPos));
                    }
                    return true;
                }
            }
        }
        return false;
    }
    
    public boolean delete(int id) throws Exception {
        ParIDEndereco pie = indiceDireto.read(id);
        if(pie!=null) {
            long pos = pie.getEndereco();
            arquivo.seek(pos);
            byte lapide = arquivo.readByte();
            short tam = arquivo.readShort();
            if(lapide==' ') {
                byte[] vb = new byte[tam];
                arquivo.read(vb);
                T entidade = construtor.newInstance();
                entidade.fromByteArray(vb);
                if(entidade.getID() == id) {
                    arquivo.seek(pos);
                    arquivo.writeByte('*');
                    insereVazio(pos, tam);
                    indiceDireto.delete(id);
                    return true;
                }
            }
        }
        return false;
    }

    public void close() throws Exception {
        arquivo.close();
    }

    public void insereVazio(long enderecoEspaco, int tamanhoEspaco) throws Exception {
        long anterior=4; // endereco do ponteiro inicial da lista
        long proximo=-1;
        long endereco;
        short tamanho;

        arquivo.seek(4);
        endereco = arquivo.readLong();

        if(endereco==-1) {
            // lista vazia
            arquivo.seek(anterior);
            arquivo.writeLong(enderecoEspaco);
            arquivo.seek(enderecoEspaco+3);  // salta o lápide e o indicador de tamanho;
            arquivo.writeLong(-1);
        } else {
            // lista não estava vazia
            do {
                arquivo.seek(endereco);
                arquivo.readByte();
                tamanho = arquivo.readShort();
                proximo = arquivo.readLong();
                if(tamanhoEspaco<tamanho) {
                    if(anterior==4)
                        arquivo.seek(anterior);
                    else   
                        arquivo.seek(anterior+3);
                    arquivo.writeLong(enderecoEspaco);
                    arquivo.seek(enderecoEspaco+3);
                    arquivo.writeLong(endereco);
                    break;
                }
                if(proximo==-1) {
                    arquivo.seek(endereco+3);
                    arquivo.writeLong(enderecoEspaco);
                    arquivo.seek(enderecoEspaco+3);
                    arquivo.writeLong(-1);
                    break;
                }
                anterior = endereco;
                endereco = proximo;
            } while(endereco!=-1);
        }
    }

    public long buscaVazio(int tamanhoEspaco) throws Exception {
        long anterior = 4; // cabeça da lista
        long proximo;
        arquivo.seek(anterior);
        long endereco = arquivo.readLong();
        int tamanho;

        while(endereco!=-1) {
            arquivo.seek(endereco);
            arquivo.readByte();
            tamanho = arquivo.readShort();
            proximo = arquivo.readLong();
            if(tamanhoEspaco<tamanho) {
                if(anterior == 4)
                    arquivo.seek(anterior);
                else
                    arquivo.seek(anterior+3);
                arquivo.writeLong(proximo);
                break;
            }
            anterior = endereco;
            endereco = proximo;
        }
        return endereco;
    }

} 