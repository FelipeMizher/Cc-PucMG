import java.util.*;

public class bolha{
    public static void mostrar(int[] array){

         for(int i = 0; i < array.length; i++){
            System.out.print("[" + array[i] + "]");
        }
        System.out.println();
    }

    public static void swap(int i, int j, int[] array){
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    public static void bolha_sort(int[] array){
        int n = array.length;

        for(int i = n - 1; i > 0 ; i--){
            for(int j = 0; j < i; j++){
                if(array[j] > array[j + 1]){
                    swap(j, j + 1, array);
                }
            }
            mostrar(array);
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner (System.in);
        int array[] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16, 15, 5, 13, 9, 1, 11, 7, 3};

        for(int i = 0; i < array.length; i++){
            System.out.print("[" + array[i] + "]");
        }
        System.out.println();

        bolha_sort(array);

        sc.close();
    }
}
