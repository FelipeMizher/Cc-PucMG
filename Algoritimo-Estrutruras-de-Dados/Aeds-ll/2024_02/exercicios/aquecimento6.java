import java.util.*;

public class aquecimento6{
    public static void Espelho(int inicio, int fim){
        String seq1 = "";
        String seq2 = "";

        for(int i = inicio; i <= fim; i++){
            seq1 += i;
            seq2 = seq1;
        }

        for(int i = fim; i >= inicio; i--){
            String numero = String.valueOf(i); 

            for(int j = numero.length() - 1; j >= 0; j--){
                seq2 += numero.charAt(j);
            }
        }
        
        System.out.println(seq2);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int inicio = 0, fim = 0;
        
        while(sc.hasNextInt()){
            inicio = sc.nextInt();
            fim = sc.nextInt();
            
            Espelho(inicio, fim);
        }
        sc.close();
    }
}
