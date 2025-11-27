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
        this.movimentacoes = 0;
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
                    this.time, this.count, this.movimentacoes));
            writer.close();
        } catch(IOException e){
            System.out.println("Erro: " + e.getMessage());
        }
    }
}

public class Bolha{
    public static void swap(int i, int j, int[] array, Log log){
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        log.incrementaMovimentacoes();
        log.incrementaMovimentacoes();
        log.incrementaMovimentacoes();
    }

    public static void bolha_sort(int[] array, Log log){
        int n = array.length;

        for(int i = n - 1; i > 0; i--){
            for(int j = 0; j < i; j++){
                log.incrementaCount();
                if(array[j] > array[j + 1]){
                    swap(j, j + 1, array, log);
                }
            }
        }
    }

    public static void main(String[] args){
        Log log = new Log("821811_bolha_100000.txt");
        int[] array = new int[100000];
        Random rand = new Random();

        for(int i = 0; i < array.length; i++){
            array[i] = rand.nextInt(1000);
        }

        Instant start = Instant.now();
        bolha_sort(array, log);
        Instant end = Instant.now();

        long elapsedtime = Duration.between(start, end).toMillis();
        log.time = (float) elapsedtime / 1000;
        log.registrarLog();
    }
}