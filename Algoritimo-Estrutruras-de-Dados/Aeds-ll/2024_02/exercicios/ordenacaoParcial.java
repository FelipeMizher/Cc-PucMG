import java.util.*;

class OrdenacaoParcial{
    private static void printArray(int[] array){
        System.out.print("[ ");

         for(int i = 0; i < array.length; i++){
            System.out.print(array[i] + " ");
        }

        System.out.println("]");
    }

    public static void swap(int[] array, int i, int j){
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void selecaoParcial(int[] array, int k){
        int n = array.length;
    
        for(int i = 0; i < k; i++){
            int menor = i;
            for(int j = (i + 1); j < n; j++){
                if(array[menor] > array[j]){
                    menor = j;
                }
            }      
            swap(array, menor, i);
        }
    }
    
    public static void insercaoParcial(int[] array, int k){
        int n = array.length;
    
        for(int i = 1; i < n; i++){
            int tmp = array[i];
            int j = (i < k) ? i - 1 : k - 1;    
            while((j >= 0) && (array[j] > tmp)){
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = tmp;
        }
    }
    
    public static void quicksort(int esq, int dir, int k, int[] array){
        int i = esq, j = dir, pivo = array[(esq + dir) / 2];

        while(i <= j){
            while(array[i] < pivo){
                i++;
            }
            while(array[j] > pivo){
                j--;
                if(i <= j){ 
                    swap(array, i, j); i++; j--; 
                }   
            }
        }

        if(esq < j){
            quicksort(esq, j, k, array);
        }
        if(i < k && i < dir){
            quicksort(i, dir, k, array);
        }   
    }

    public static int getMaiorFilho(int[] array, int i, int tamHeap){
      int filho;
      
      if(2*i == tamHeap || array[2*i] > array[2*i+1]){
         filho = 2*i;
      } else{
         filho = 2*i + 1;
      }
      return filho;
   }
    
    public static void construir(int[] array, int tamHeap){
      for(int i = tamHeap; i > 1 && array[i] > array[i/2]; i /= 2){
         swap(array, i, i/2);
      }
   }
   
   public static void reconstruir(int[] array, int tamHeap){
      int i = 1;
      
      while(i <= (tamHeap/2)){
         int filho = getMaiorFilho(array, i, tamHeap);
         if(array[i] < array[filho]){
            swap(array, i, filho);
            i = filho;
         } else{
            i = tamHeap;
         }
      }
   }
    
    public static void heapsort(int[] array, int k){
        int n = array.length;
    
        for(int tam = 2; tam <= k; tam++)
            construir(array, tam);

            for(int i = k + 1; i <= n; i++)
                if(array[i] < array[1]){
                    swap(array, i , 1); 
                    reconstruir(array, k);
                }

                int tam = k;
                while(tam > 1){
                    swap(array, 1, tam--); 
                    reconstruir(array, tam);
                }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int array[] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16};
        int array2[] = {31, 16, 42, 5, 23, 20, 35, 2, 41, 38};
        int array3[] = {27, 9, 29, 21, 23, 12, 49, 50, 26, 1};
        int array4[] = {35, 39, 40, 46, 24, 27, 15, 6, 23, 14};
        
        printArray(array);
        selecaoParcial(array, 3);
        printArray(array);
        System.out.println();

        printArray(array2);
        insercaoParcial(array2, 3);
        printArray(array2);
        System.out.println();

        printArray(array3);
        quicksort(0, array3.length, 3, array);
        printArray(array3);
        System.out.println();

        printArray(array4);
        heapsort(array4, 3);
        printArray(array4);
        System.out.println();
        
        sc.close();
    }
}
