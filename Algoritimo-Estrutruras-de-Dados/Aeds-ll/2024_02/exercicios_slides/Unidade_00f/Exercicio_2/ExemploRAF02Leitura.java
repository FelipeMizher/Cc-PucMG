import java.io.RandomAccessFile;

public class ExemploRAF02Leitura{
    public static void main(String[] args) throws Exception{
        RandomAccessFile raf = new RandomAccessFile("exemplo.txt", "rw");

        String str = raf.readLine();

        raf.close();

        System.out.println("str: " + str);
    }
}
