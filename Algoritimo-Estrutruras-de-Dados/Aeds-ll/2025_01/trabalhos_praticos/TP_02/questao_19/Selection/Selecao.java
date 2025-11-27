import java.util.*;
import java.io.FileWriter;
import java.io.IOException;
import java.time.Duration;
import java.time.Instant;

class Log{
    public int count;
    public int movimentacoes;
    public float time;
    public String fileName;
     
    Log(String fileName){
        this.count = 0;
 
        this.fileName = fileName;
    }
 
    public void incrementaCount(){
        count++;
    }

    public void incrementaMovimentacoes(){
        movimentacoes++;
    }
 
    public void registrarLog(){
        try{
            FileWriter writer = new FileWriter(this.fileName);
            writer.write(String.format("Matrícula: 821811 \ttempo de execução: %.3f segundos \tNúmero de comparações: %d\tNúmero de movimentações: %d",
    this.time, this.count, this.movimentacoes
));

            writer.close();

        }catch(IOException e){
            System.out.println("Erro: " + e.getMessage());
        }
    }
}

class Selecao{
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

    public static void selecao(int[] array, Log log){
        int n = array.length;
    
        for(int i = 0; i < (n - 1); i++){
            int menor = i;
            for(int j = (i + 1); j < n; j++){
                log.incrementaCount();
                if (array[menor] > array[j]){
                    menor = j;
                }
            }
    
            if(menor != i){
                swap(array, menor, i);
                log.incrementaMovimentacoes();
                log.incrementaMovimentacoes();
                log.incrementaMovimentacoes();
            }
        }
    }
    

    public static void main(String[] args){
        Log log = new Log("821811_selecao_10000.txt");
        Instant start, end;
    
        int[] array = new int[10000];
        Random rand = new Random();
        for(int i = 0; i < array.length; i++){
            array[i] = rand.nextInt(1000);
        }
    
        start = Instant.now();
    
        selecao(array, log);
    
        end = Instant.now();
        long elapsedtime = Duration.between(start, end).toMillis();
        log.time = (float) elapsedtime / 1000;
        log.registrarLog();
    }
    
}
