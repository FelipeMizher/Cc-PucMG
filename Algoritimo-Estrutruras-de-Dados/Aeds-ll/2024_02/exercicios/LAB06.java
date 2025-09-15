import java.util.*;
import java.io.FileWriter;
import java.time.Duration;
import java.time.Instant;
import java.io.IOException;

class Log{
    public float time;
    public String fileName;
     
    Log(String fileName){
        this.fileName = fileName;
    }
 
    public void registrarLog(){
        try{
            FileWriter writer = new FileWriter(this.fileName);
            writer.write("Matrícula: 821811 \ttime de execução: " + this.time + " milisegundos\n\n");
            writer.close();

        }catch(IOException e){
            System.out.println("Erro: " + e.getMessage());
        }
    }
}

class LAB06{
    public static void crescente(int[] array, int n) {
		for (int i = 0; i < n; i++) {
			array[i] = i;
		}
	}

    public static void swap(int i, int j, int[] array){
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;

    }

    public static void QuickSortFirstPivot(int esq, int dir, int[] array){
        int i = esq, j = dir;
        int pivo = array[esq];

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
            QuickSortFirstPivot(esq, j, array);
        }
        if(i < dir){  
            QuickSortFirstPivot(i, dir, array);
        }
    }
    
    public static void QuickSortLastPivot(int esq, int dir, int[] array){
        int i = esq, j = dir;
        int pivo = array[dir];

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
            QuickSortLastPivot(esq, j, array);
        }
        if(i < dir){  
            QuickSortLastPivot(i, dir, array);
        }
    }
    
    public static void QuickSortRandomPivot(int esq, int dir, int[] array){
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
            QuickSortRandomPivot(esq, j, array);
        }
        if(i < dir){  
            QuickSortRandomPivot(i, dir, array);
        }
    }
    
    public static void QuickSortMedianOfThree(int esq, int dir, int[] array){
        int i = esq, j = dir;
        int tmp = (esq + dir) / 2;
        
        if(array[esq] > array[tmp]){
            swap(esq, tmp, array);
        }
        
        if(array[esq] > array[dir]){
            swap(esq, dir, array);
        }
        
        if(array[tmp] > array[dir]){
            swap(tmp, dir, array);
        }     
        
        
        int pivo = array[tmp];

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
            QuickSortMedianOfThree(esq, j, array);
        }
        if(i < dir){  
            QuickSortMedianOfThree(i, dir, array);
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] array = new int[10000];
        Log log;
        Instant start, end;
         
        // Mudando a quantidade de números de 100, 1000 e 10.000
        int n = 10000;
        
        // Mudando as formas de gerar o array para obter as diferentes tabelas de tempo de execuções
        Random rand = new Random();
		crescente(array, n);	
		for (int i = 0; i < n; i++) {
			swap(i, Math.abs(rand.nextInt()) % n, array);
		}

            System.out.print("[");
    
            for (int i = 0; i < n; i++) {
                System.out.print(" ("+i+")" + array[i]);
            }
    
            System.out.println("]");
		
		log = new Log("tempo_execucao1.txt");
	
        start = Instant.now();
        QuickSortFirstPivot(0, array.length - 1, array);
        end = Instant.now();
        long elapsedTime1 = Duration.between(start, end).toMillis();
        log.time = (float) elapsedTime1;
        log.registrarLog();

        log = new Log("tempo_execucao2.txt");
        
        start = Instant.now();
        QuickSortLastPivot(0, array.length - 1, array);
        end = Instant.now();
        long elapsedTime2 = Duration.between(start, end).toMillis();
        log.time = (float) elapsedTime2;
        log.registrarLog();

        log = new Log("tempo_execucao3.txt");
        
        start = Instant.now();
        QuickSortRandomPivot(0, array.length - 1, array);
        end = Instant.now();
        long elapsedTime3 = Duration.between(start, end).toMillis();
        log.time = (float) elapsedTime3;
        log.registrarLog();

        log = new Log("tempo_execucao4.txt");
        
        start = Instant.now();
        QuickSortMedianOfThree(0, array.length - 1, array);
        end = Instant.now();
        long elapsedTime4 = Duration.between(start, end).toMillis();
        log.time = (float) elapsedTime4;
        log.registrarLog();

        sc.close();
    }   
}
