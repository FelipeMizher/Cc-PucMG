import java.io.RandomAccessFile;

public class ExemploRAF03Cabecote{
    public static void main(String[] args) throws Exception{
        RandomAccessFile raf = new RandomAccessFile("exemplo2.txt", "rw");

        raf.writeInt(20);

        raf.seek(0);
        System.out.println(raf.readInt());

        raf.close();
    }
}
