import java.util.*;

class selecao{
    public static void swap(int[] array, int i, int j){
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void mostrar(int[] array){
        System.out.print("[ ");

         for(int i = 0; i < array.length; i++){
            System.out.print(array[i] + " ");
        }

        System.out.println("]");
    }

    public static void Selecao(int[] array){
        int n = array.length;
    
		for(int i = 0; i < (n - 1); i++){
			int menor = i;
			for(int j = (i + 1); j < n; j++){
				if (array[menor] > array[j]){
					menor = j;
				}
			}
			
			if (menor != i){
                swap(array, menor, i);
            }
            mostrar(array);
		}
	}

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int array[] = {12, 4, 8, 2, 14, 17, 6, 18, 10, 16, 15, 5, 13, 9, 1, 11, 7, 3};
        
        mostrar(array);
        System.out.println();
        Selecao(array);
        
        sc.close();
    }
}
