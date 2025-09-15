import java.io.RandomAccessFile;
import java.util.Scanner;

public class Ler_Nome_Frase {
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);

        String arqName = sc.nextLine();

        RandomAccessFile raf = new RandomAccessFile(arqName, "rw");

        String text = sc.nextLine();
        raf.writeBytes(text);

        raf.close();
        sc.close();
    }
}
