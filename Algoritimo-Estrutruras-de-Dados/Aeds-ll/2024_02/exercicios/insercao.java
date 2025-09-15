import java.util.*;

class insercao{
    public static int pesquisaBinaria(int esq, int dir, int x, int[] array){
      int meio;

      while (esq <= dir){
         meio = (esq + dir) / 2;
         if(x == array[meio]){
            return meio;
         } else if(x > array[meio]){
            esq = meio + 1;
         } else{
            dir = meio - 1;
         }
      }
      return esq;
   }

    public static void Ordernar_insercao(int[] array){
    
		for(int i = 1; i < array.length; i++){
			int tmp = array[i];
            int j = i - 1;
            
            int pos = pesquisaBinaria(0, j, tmp, array);

            while(j >= pos){
                array[j + 1] = array[j];
            j--;
         }
         array[j + 1] = tmp;	
      }
	}

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N;
        
        N = sc.nextInt();
        
        int[] array = new int[N];
        
        for(int i = 0; i < N; i++){
            array[i] = sc.nextInt();
        }
            
        Ordernar_insercao(array);
            
        for(int i = 0; i < N; i++){
            System.out.print(array[i] + " ");
        }
        
        System.out.println();
        
        sc.close();
    }
}
