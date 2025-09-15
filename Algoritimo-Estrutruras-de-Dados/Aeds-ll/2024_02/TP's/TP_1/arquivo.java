import java.io.IOException;
import java.io.RandomAccessFile;
import java.text.DecimalFormat;
import java.util.Scanner;

public class arquivo{
    public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      DecimalFormat df = new DecimalFormat("#.###");
      int n = 0;
      String arqName = "arquivo.txt";

      try{
         n = sc.nextInt();

         try(RandomAccessFile raf = new RandomAccessFile(arqName, "rw")){
            for(int i = 0; i < n; i++){
               double x = sc.nextDouble();
               raf.writeDouble(x);
            }
         }

         try(RandomAccessFile raf = new RandomAccessFile(arqName, "r")){
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
        
      sc.close();
    }
}