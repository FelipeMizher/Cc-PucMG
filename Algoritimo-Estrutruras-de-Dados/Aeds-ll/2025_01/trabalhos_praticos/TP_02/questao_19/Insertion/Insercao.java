import java.util.*;
import java.io.FileWriter;
import java.io.IOException;
import java.time.Duration;
import java.time.Instant;

class Log {
    public int count;
    public int movimentacoes;
    public float time;
    public String fileName;

    Log(String fileName) {
        this.count = 0;
        this.movimentacoes = 0;
        this.fileName = fileName;
    }

    public void incrementaCount() {
        count++;
    }

    public void incrementaMovimentacoes() {
        movimentacoes++;
    }

    public void registrarLog() {
        try {
            FileWriter writer = new FileWriter(this.fileName);
            writer.write(String.format("Matrícula: 821811 \ttempo de execução: %.3f segundos \tNúmero de comparações: %d\tNúmero de movimentações: %d",
                this.time, this.count, this.movimentacoes));
            writer.close();
        } catch (IOException e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
}

public class Insercao{
    public static void InsercaoBinaria(int[] array, Log log){
        for(int i = 1; i < array.length; i++){
            int tmp = array[i];
            int j = i - 1;

            int pos = pesquisaBinaria(array, 0, j, tmp, log);

            while(j >= pos){
                array[j + 1] = array[j];
                j--;
                log.incrementaMovimentacoes();
            }

            array[j + 1] = tmp;
            log.incrementaMovimentacoes();
        }
    }

    public static int pesquisaBinaria(int[] array, int inicio, int fim, int chave, Log log){
        while(inicio <= fim){
            int meio = (inicio + fim) / 2;
            log.incrementaCount();
            if(array[meio] > chave){
                fim = meio - 1;
            } else{
                inicio = meio + 1;
            }
        }
        return inicio;
    }

    public static void main(String[] args){
        Log log = new Log("821811_insercao_100000.txt");
        int[] array = new int[100000];
        Random rand = new Random();

        for(int i = 0; i < array.length; i++){
            array[i] = rand.nextInt(10000);
        }

        Instant start = Instant.now();

        InsercaoBinaria(array, log);

        Instant end = Instant.now();
        long elapsedTime = Duration.between(start, end).toMillis();
        log.time = (float) elapsedTime / 1000;
        log.registrarLog();
    }
}
