import java.util.*;

class Camisa{
    String nome;
    String cor;
    char tamanho;

    public Camisa(String nome, String cor, char tamanho){
        this.nome = nome;
        this.cor = cor;
        this.tamanho = tamanho;
    }
}

class Lista{
    private Camisa[] camisas;
    private int n;

    public Lista(){
        camisas = new Camisa[1000];
        n = 0;
    }

    public void inserir(Camisa c) throws Exception{
        if(n >= camisas.length){
            throw new Exception("Erro ao inserir!");
        }
        camisas[n++] = c;
    }

    public Camisa get(int i){
        return camisas[i];
    }

    public int tamanho(){
        return n;
    }

    public void ordenar(){
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i - 1; j++){
                int cmpCor = camisas[j].cor.compareTo(camisas[j + 1].cor);
                if(cmpCor > 0 ||
                    (cmpCor == 0 && camisas[j].tamanho < camisas[j + 1].tamanho) || 
                    (cmpCor == 0 && camisas[j].tamanho == camisas[j + 1].tamanho &&
                     camisas[j].nome.compareTo(camisas[j + 1].nome) > 0)){

                    Camisa temp = camisas[j];
                    camisas[j] = camisas[j + 1];
                    camisas[j + 1] = temp;
                }
            }
        }
    }
}

public class Camisetas{
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine();

        while(N != 0){
            Lista lista = new Lista();

            for(int i = 0; i < N; i++){
                String nome = sc.nextLine();
                String cor = sc.next();
                char tamanho = sc.next().charAt(0);
                sc.nextLine();

                Camisa c = new Camisa(nome, cor, tamanho);
                lista.inserir(c);
            }

            lista.ordenar();

            for(int i = 0; i < lista.tamanho(); i++){
                Camisa c = lista.get(i);
                System.out.printf("%s %c %s\n", c.cor, c.tamanho, c.nome);
            }
            System.out.println();
            N = sc.nextInt();
            sc.nextLine();
        }

        sc.close();
    }
}
