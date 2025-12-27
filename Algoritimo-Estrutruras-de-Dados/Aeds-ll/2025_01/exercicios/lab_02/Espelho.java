import java.util.*;

class Espelho{
    public static void Espelhar(int inicio, int fim){
        String s = "";

        for(int i = inicio; i <= fim; i++){
            s += i;
        }

        System.out.print(s);

        for(int i = s.length() - 1; i >= 0; i--){
            System.out.print(s.charAt(i));
        }

        System.out.println();
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int inicio = 0;
        int fim = 0;

        while(sc.hasNext()){
            inicio = sc.nextInt();
            fim = sc.nextInt();

            Espelhar(inicio, fim);
        }

        sc.close();
    }
}