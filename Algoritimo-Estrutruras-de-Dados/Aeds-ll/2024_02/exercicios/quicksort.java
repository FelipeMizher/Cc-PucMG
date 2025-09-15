import java.util.*;

public class quicksort{
    public static void mostrar(int[] array){

        System.out.print("[ ");
        for(int i = 0; i < array.length; i++){
           System.out.print(array[i] + " ");
       }
       System.out.print("]");
       System.out.println();
   }

    public static void swap(int i, int j, int[] array){
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;

    }

    public static void Quicksort(int esq, int dir, int[] array){
        int i = esq, j = dir;
        int pivo = array[(dir + esq) / 2];

        while (i <= j){
            while(array[i] < pivo){ 
                i++;
            }
            while(array[j] > pivo){ 
                j--;
            }

            if(i <= j){
                swap(i, j, array);
                i++;
                j--;
            }
        }

        if(esq < j){  
            Quicksort(esq, j, array);
        }
        if(i < dir){  
            Quicksort(i, dir, array);
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int array[] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16, 15, 5, 13, 9, 1, 11, 7, 3}; 

        mostrar(array);

        Quicksort(0, array.length - 1, array);

        mostrar(array);

        sc.close();
    }
}
