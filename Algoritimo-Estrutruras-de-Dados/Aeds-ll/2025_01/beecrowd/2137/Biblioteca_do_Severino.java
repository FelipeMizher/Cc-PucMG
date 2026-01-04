import java.util.*;

public class Biblioteca_do_Severino{
    public static void Selecao(int[] array){
        int n = array.length;
    
        for(int i = 0; i < n - 1; i++){
            int menor = i;
    
            for(int j = i + 1; j < n; j++){
                if(array[j] < array[menor]){
                    menor = j;
                }
            }
    
            int temp = array[i];
            array[i] = array[menor];
            array[menor] = temp;
        }
    }    

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int N = 0;

        while(sc.hasNext()){
            N = sc.nextInt();
            
            int[] cadastros = new int[N];

            for(int i = 0; i < N; i++){
                cadastros[i] = sc.nextInt();
            }

            Selecao(cadastros);

            for(int i = 0; i < N; i++){
                System.out.printf("%04d\n", cadastros[i]);
            }
        }
        sc.close();
    }
}
