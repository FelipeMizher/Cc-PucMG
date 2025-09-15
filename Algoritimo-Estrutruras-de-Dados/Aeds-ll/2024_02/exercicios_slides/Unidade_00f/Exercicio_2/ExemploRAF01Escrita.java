import java.io.RandomAccessFile;

public class ExemploRAF01Escrita{
    public static void main(String[] args) throws Exception{
        RandomAccessFile raf = new RandomAccessFile("exemplo.txt", "rw");

        raf.writeBytes("AED 2");

        raf.close();
    }
}
