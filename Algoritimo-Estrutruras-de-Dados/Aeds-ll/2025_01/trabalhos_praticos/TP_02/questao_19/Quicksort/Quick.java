import java.util.*;
import java.io.FileWriter;
import java.io.IOException;
import java.time.Duration;
import java.time.Instant;

class Log{
    public int comparacoes = 0;
    public int movimentacoes = 0;
    public float tempo = 0;
    public String fileName;

    Log(String fileName){
        this.fileName = fileName;
    }

    public void incrementarComparacoes(){
        comparacoes++;
    }

    public void incrementarMovimentacoes(){
        movimentacoes++;
    }

    public void registrarLog(){
        try{
            FileWriter writer = new FileWriter(this.fileName);
            writer.write(String.format("Matrícula: 821811 \ttempo de execução: %.3f segundos \tNúmero de comparações: %d\tNúmero de movimentações: %d",
                    this.tempo, this.comparacoes, this.movimentacoes));
            writer.close();
        } catch(IOException e){
            System.out.println("Erro ao escrever o log: " + e.getMessage());
        }
    }
}

public class Quick{
    public static void swap(int i, int j, int[] array, Log log){
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        log.incrementarMovimentacoes();
        log.incrementarMovimentacoes();
        log.incrementarMovimentacoes();
    }

    public static void quicksort(int esq, int dir, int[] array, Log log){
        int i = esq, j = dir;
        int pivo = array[(esq + dir) / 2];

        while(i <= j){
            while(array[i] < pivo){
                i++;
                log.incrementarComparacoes();
            }
            log.incrementarComparacoes();

            while(array[j] > pivo){
                j--;
                log.incrementarComparacoes();
            }
            log.incrementarComparacoes();

            if(i <= j){
                swap(i, j, array, log);
                i++;
                j--;
            }
        }

        if(esq < j){
            quicksort(esq, j, array, log);
        }
        if(i < dir){
            quicksort(i, dir, array, log);
        }
    }

    public static void main(String[] args){
        Log log = new Log("821811_quicksort_100000.txt");
        int[] array = new int[100000];
        Random rand = new Random();

        for(int i = 0; i < array.length; i++){
            array[i] = rand.nextInt(10000);
        }

        Instant start = Instant.now();

        quicksort(0, array.length - 1, array, log);

        Instant end = Instant.now();
        log.tempo = Duration.between(start, end).toMillis() / 1000f;
        log.registrarLog();
    }
}
