import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Scanner;

public class Ler_e_Mostrar{
    public static void exibir(String arqName){
        try{
            RandomAccessFile raf = new RandomAccessFile(arqName, "r");

            String str = raf.readLine();
            System.out.println("Conteudo do arquivo: " + str);

            raf.close();
        } catch(IOException e){
            System.out.println("" + e.getMessage());
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        String arqName = sc.nextLine();

        exibir(arqName);

        sc.close();
    }
}
