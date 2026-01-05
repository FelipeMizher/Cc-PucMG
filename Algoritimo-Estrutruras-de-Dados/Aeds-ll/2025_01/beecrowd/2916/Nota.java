import java.util.*;

public class Nota{
    public static void bubbleSort(int[] notas, int N){
        for(int i = 0; i < N - 1; i++){
            for(int j = 0; j < N - i - 1; j++){
                if(notas[j] > notas[j + 1]){
                    int temp = notas[j];
                    notas[j] = notas[j + 1];
                    notas[j + 1] = temp;
                }
            }
        }
    }

    public static void preencher(int [] notas, int N, Scanner sc){
        for(int i = 0; i < N; i++){
            notas[i] = sc.nextInt();
        }
    }

    public static int somar(int[] notas, int N, int K){
        int count = 0;

        for(int i = N - 1; i > N - 1 - K; i--){
                count += notas[i];
        }

       return count;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        while(sc.hasNext()){
            int N = sc.nextInt();
            int K = sc.nextInt();

            int[] notas = new int[N];
            preencher(notas, N, sc);
            bubbleSort(notas, N);
            int result = somar(notas, N, K);
            System.out.println(result);
        }
        sc.close();
    }
}
