import java.io.IOException;
import java.util.*;

class Duende{
    String nome;
    int idade;

    public Duende(String nome, int idade){
        this.nome = nome;
        this.idade = idade;
    }
}

class Pilha{
    private Duende[] array;
    private int topo;

    Pilha(int tamanho){
        array = new Duende[tamanho];
        topo = 0;
    }

    public void empilhar(Duende d){
        array[topo++] = d;
    }

    public Duende desempilhar(){
        return array[--topo];
    }

    public boolean isVazia(){
        return (topo == 0);
    }
}

public class Time_de_Duendes{
    public static boolean Comparar(Duende a, Duende b){
        boolean result;

        if(a.idade < b.idade){
            result = true;
        } else if(a.idade > b.idade){
            result = false;
        } else{
            result = (a.nome.compareTo(b.nome) > 0);
        }

        return result;
    }

    public static void sort(Duende[] duendes, int n){
        for(int i = 0; i < (n - 1); i++){
            int maior = i;
            for(int j = (i + 1); j < n; j++) {
                if(Comparar(duendes[maior], duendes[j])){
                    maior = j;
                }
            }
            swap(duendes, maior, i);
        }
    }

    public static void swap(Duende[] duendes, int i, int j){
        Duende temp = duendes[i];
        duendes[i] = duendes[j];
        duendes[j] = temp;
    }

    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine();
        Duende[] duendes = new Duende[N];

        for(int i = 0; i < N; i++){
            String nome = sc.next();
            int idade = sc.nextInt();
            duendes[i] = new Duende(nome, idade);
        }

        sort(duendes, N);

        int times = N / 3;
        Pilha lideres = new Pilha(times);
        Pilha entregadores = new Pilha(times);
        Pilha pilotos = new Pilha(times);

        for(int i = times - 1; i >= 0; i--){
            lideres.empilhar(duendes[i]);
        }
        for(int i = 2 * times - 1; i >= times; i--){
            entregadores.empilhar(duendes[i]);
        }
        for(int i = 3 * times - 1; i >= 2 * times; i--){
            pilotos.empilhar(duendes[i]);
        }

        for(int i = 1; i <= times; i++){
            System.out.println("Time " + i);
            Duende lider = lideres.desempilhar();
            Duende entregador = entregadores.desempilhar();
            Duende piloto = pilotos.desempilhar();
            System.out.println(lider.nome + " " + lider.idade);
            System.out.println(entregador.nome + " " + entregador.idade);
            System.out.println(piloto.nome + " " + piloto.idade);
            System.out.println();
        }

        sc.close();
    }
}
