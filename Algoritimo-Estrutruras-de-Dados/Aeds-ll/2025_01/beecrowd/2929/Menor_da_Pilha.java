import java.util.*;

class Pilha{
    private int elementos[];
    private int topo;
    private int tamanho;

    public Pilha(int tamanho){
        this.tamanho = tamanho;
        elementos = new int[tamanho];
        topo = -1;
    }

    public boolean isVazia(){
        return topo == -1;
    }

    public boolean isFull(){
        return topo == tamanho - 1;
    }

    public void Empilhar(int elemento){
        if(isFull()){
            System.out.println("Pilha cheia! Não é possível empilhar.");
        } else{
            elementos[++topo] = elemento;
        }
    }

    public int Desempilhar(){
        int result = -1;

        if(isVazia()){
            System.out.println("Pilha vazia! Não é possível desempilhar.");
        } else{
            result = elementos[topo];
            topo--;
        }

        return result;
    }

    public int VerificarMenor(){
        int result = -1;

        if(isVazia()){
            System.out.println("A pilha está vazia!");
        } else{
            result = elementos[0];

            for(int i = 1; i <= topo; i++){
                if(elementos[i] < result){
                    result = elementos[i];
                }
            }
        }

        return result;
    }
}

public class Menor_da_Pilha{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Pilha pilha = new Pilha(N);

        for(int i = 0; i < N; i++){
            String line = sc.next();

            if(line.equals("PUSH")){
                int V = sc.nextInt();
                pilha.Empilhar(V);
            } else if(line.equals("POP")){
                pilha.Desempilhar();
            } else if(line.equals("MIN")){
                int menor = pilha.VerificarMenor();
                if(menor != -1){
                    System.out.println(menor);
                }
            }
        }

        sc.close();
    }
}
