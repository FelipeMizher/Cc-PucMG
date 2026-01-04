import java.util.*;

class Lista{
    private String[] nome;
    private int n;

    public Lista(){
        nome = new String[1000];
        n = 0;
    }

    public boolean existe(String s){
        boolean resp = false;

        for(int i = 0; i < n; i++){
            if(nome[i].equals(s)){
                resp = true;
            }
        }

        return resp;
    }

    public void inserir(String s) throws Exception{
        if(n >= nome.length){
            throw new Exception("Erro ao inserir!");
        }
    
        nome[n] = s;
        n++;
    }    

    public String get(int i){
        return nome[i];
    }

    public int tamanho(){
        return n;
    }

    public void ordenar(){
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(nome[j].compareTo(nome[j + 1]) > 0){
                    String temp = nome[j];
                    nome[j] = nome[j + 1];
                    nome[j + 1] = temp;
                }
            }
        }
    }    
}

public class Amigos_do_Habay{
    public static String encontrarAmigoDoHabay(Lista lista){
        String vencedor = "";
        int maior = -1;

        for(int i = 0; i < lista.tamanho(); i++){
            String atual = lista.get(i);
            int len = atual.length();

            if(len > maior){
                maior = len;
                vencedor = atual;
            }
        }

        return vencedor;
    }

    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        String line = sc.next();

        Lista yesList = new Lista();
        Lista noList = new Lista();

        while(!line.equals("FIM")){
            String amigos = sc.next();
            
            if(amigos.equals("YES")){
                if(!yesList.existe(line)){
                    yesList.inserir(line);  
                }
            } else if(amigos.equals("NO")){
                if(!noList.existe(line)){
                    noList.inserir(line);
                }
            } else{
                System.out.println("Erro!");
            }
            line = sc.next();
        }

        String vencedor = encontrarAmigoDoHabay(yesList);

        yesList.ordenar();
        noList.ordenar();

        for(int i = 0; i < yesList.tamanho(); i++){
            System.out.println(yesList.get(i));
        }

        for(int i = 0; i < noList.tamanho(); i++){
            System.out.println(noList.get(i));
        }

        System.out.println();

        System.out.println("Amigo do Habay:\n" + vencedor);

        sc.close();
    }
}