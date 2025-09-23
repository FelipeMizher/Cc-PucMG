import java.io.IOException;
import java.io.RandomAccessFile;
import java.text.DecimalFormat;
import java.util.*;

public class Arquivo{
    public static void Gravar(int n, Scanner sc){
        try{
         try(RandomAccessFile raf = new RandomAccessFile("Arquivo.txt", "rw")){
            for(int i = 0; i < n; i++){
               double x = sc.nextDouble();
               raf.writeDouble(x);
            }
         }
      } catch(IOException e){
         System.out.println("Erro ao acessar o arquivo: " + e.getMessage());
      }
    }

    public static void Mostrar(DecimalFormat df){
        try{
            try(RandomAccessFile raf = new RandomAccessFile("Arquivo.txt", "r")){
               long tamanho = raf.length();
               long pos = tamanho - 8;
   
               while(pos >= 0){
                  raf.seek(pos);
               double x = raf.readDouble();
               System.out.println(df.format(x));
               pos -= 8; 
               }
            }
         } catch(IOException e){
            System.out.println("Erro ao acessar o arquivo: " + e.getMessage());
         }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#.###");
        int n = 0;

        n = sc.nextInt();
        Gravar(n, sc);
        Mostrar(df);

        sc.close();
    }
}