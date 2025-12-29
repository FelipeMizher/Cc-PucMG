import java.util.*;

class Atleta{
    String nome;
    int peso;

    public Atleta(){
        this.nome = "";
        this.peso = 0;
    }

    public Atleta(String nome, int peso){
        this.nome = nome;
        this.peso = peso;
    }

    public String getNome(){
        return nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }
}

public class Aquecimento{
    public static int Comparar(Atleta a1, Atleta a2){
        int result = 0;
    
        if(a1.peso > a2.peso){
            result = -1;
        } else if(a1.peso < a2.peso){
            result = 1;
        } else{
            result = a1.nome.compareTo(a2.nome);
        }
    
        return result;
    }

    public static void swap(Atleta[] atletas, int i, int j){
        Atleta temp = atletas[i];
        atletas[i] = atletas[j];
        atletas[j] = temp;
    }

    private static void OrdenarAtletas(Atleta[] atletas, int N){
        for(int i = 0; i < N; i++){
            int max = i;
            for(int j = i + 1; j < N; j++){
                if(Comparar(atletas[j], atletas[max]) < 0){
                    max = j;
                }
            }
            swap(atletas, i, max);
        }
    }

    private static void ImprimirAtletas(Atleta[] atletas){
        for(Atleta atleta : atletas){
            System.out.println(atleta.nome + " " + atleta.peso);
        }
    }

    private static void LerAtletas(Scanner sc, Atleta[] atletas, int N){
        for(int i = 0; i < N; i++){
            String nome = sc.next();
            int peso = sc.nextInt();
            atletas[i] = new Atleta(nome, peso);
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Atleta[] atletas = new Atleta[N];

        LerAtletas(sc, atletas, N);
        OrdenarAtletas(atletas, N);
        ImprimirAtletas(atletas);

        sc.close();
    }
}
