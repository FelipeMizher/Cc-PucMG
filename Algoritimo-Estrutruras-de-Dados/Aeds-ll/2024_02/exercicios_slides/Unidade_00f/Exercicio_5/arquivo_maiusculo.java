import java.io.RandomAccessFile;
import java.util.Scanner;

public class arquivo_maiusculo{
    public static void exibir(String arqName) throws Exception{
        RandomAccessFile raf = new RandomAccessFile(arqName, "r");

        String str = raf.readLine();
        str = str.toUpperCase();

        System.out.println("conteudo maiusculo: " + str);

        raf.close();
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        String arqName = sc.nextLine();

        try{
            exibir(arqName);
        } catch(Exception e){
            System.out.println(e.getMessage());
        }

        sc.close();
    }
}
