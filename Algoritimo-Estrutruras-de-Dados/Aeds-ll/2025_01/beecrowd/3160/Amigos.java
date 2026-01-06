import java.util.*;

class Lista{
    private String[] nome;
    private int n;

    public Lista(){
        this(6);
    }

    public Lista(int tamanho){
        nome = new String[tamanho];
        n = 0;
    }

    public void inserirInicio(String s) throws Exception{
        if(n >= nome.length){
            throw new Exception("Erro ao inserir!");
        }
    
        for(int i = n; i > 0; i--){
            nome[i] = nome[i - 1];
        }
    
        nome[0] = s;
        n++;
    }

    public void inserirFim(String s) throws Exception{
        if(n >= nome.length){
            throw new Exception("Erro ao inserir!");
        }
    
        nome[n] = s;
        n++;
    }    

    public void inserir(String s, int pos) throws Exception{
        if(n >= nome.length || pos < 0 || pos > n){
            throw new Exception("Erro ao inserir!");
        }
    
        for (int i = n; i > pos; i--){
            nome[i] = nome[i - 1];
        }
    
        nome[pos] = s;
        n++;
    }    

    public String removerInicio() throws Exception{
        if(n == 0){
            throw new Exception("Erro ao remover!");
        }
    
        String resp = nome[0];
        n--;
    
        for(int i = 0; i < n; i++){
            nome[i] = nome[i + 1];
        }
    
        nome[n] = null;
    
        return resp;
    }
    
    public String removerFim() throws Exception{
        if(n == 0){
            throw new Exception("Erro ao remover!");
        }
    
        String resp = nome[--n];
        nome[n] = null;
    
        return resp;
    }    

    public String remover(int pos) throws Exception{
        if(n == 0 || pos < 0 || pos >= n){
            throw new Exception("Erro ao remover!");
        }
    
        String resp = nome[pos];
        n--;
    
        for(int i = pos; i < n; i++){
            nome[i] = nome[i + 1];
        }
    
        nome[n] = null;
    
        return resp;
    }    

    public void mostrar(){
        for(int i = 0; i < n; i++){
            System.out.print(nome[i] + " ");
        }
    }    

    public boolean pesquisar(String s){
        boolean retorno = false;

        for(int i = 0; i < n && retorno == false; i++){
            retorno = nome[i].equals(s);
        }

        return retorno;
    }    
}

public class Amigos{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Lista lista = new Lista(100);

        String[] atuais = sc.nextLine().split(" ");
        for(String nome : atuais){
            try{
                lista.inserirFim(nome);
            } catch(Exception e){
                System.out.println(e.getMessage());
            }
        }

        String[] novos = sc.nextLine().split(" ");
        String indicado = sc.nextLine();

        try{
            if(!indicado.equals("nao")){
                int pos = -1;

                for(int i = 0; i < atuais.length; i++){
                    if(atuais[i].equals(indicado)){
                        pos = i;
                        i = atuais.length;
                    }
                }

                if(pos != -1){
                    for(int i = 0; i < novos.length; i++){
                        lista.inserir(novos[i], pos);
                        pos++;
                    }
                } else{
                    System.out.println("Amigo nao encontrado!");
                }
            } else{
                for(String nome : novos){
                    lista.inserirFim(nome);
                }
            }
        } catch(Exception e){
            System.out.println(e.getMessage());
        }

        lista.mostrar();
        sc.close();
    }
}
