import java.util.*;

public class mergesort{
    private void Mergesort(int esq, int dir, int[] array){
        if (esq < dir){
           int meio = (esq + dir) / 2;
        Mergesort(esq, meio, array);
        Mergesort(meio + 1, dir, array);
           intercalar(esq, meio, dir, array);
        }
     }

     public void intercalar(int esq, int meio, int dir, int[] array){
        int n1, n2, i, j, k;
  
        n1 = meio - esq + 1;
        n2 = dir - meio;
  
        int[] a1 = new int[n1+1];
        int[] a2 = new int[n2+1];
  
        for(i = 0; i < n1; i++){
           a1[i] = array[esq+i];
        }
  
        for(j = 0; j < n2; j++){
           a2[j] = array[meio+j+1];
        }
  
        a1[i] = a2[j] = 0x7FFFFFFF;
  
        for(i = j = 0, k = esq; k <= dir; k++){
           array[k] = (a1[i] <= a2[j]) ? a1[i++] : a2[j++];
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int array[] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16, 15, 5, 13, 9, 1, 11, 7, 3};

        for(int i = 0; i < array.length; i++){
            System.out.print("[" + array[i] + "]");
        }
        System.out.println();

    mergesort obj = new mergesort();
        obj.Mergesort(0, array.length - 1, array);

        for(int i = 0; i < array.length; i++){
            System.out.print("[" + array[i] + "] ");
        }

        sc.close();
    }
}