import java.util.*;

class T1{
    int tabela[];
    T2 t2;

    boolean pesquisar(int x){
        boolean resp;
        int i1 = hashT1(x);
        if(tabela[i1] == null){
            resp = false;
        } else if(tabela[i1] == x){
            resp = true;
        } else{
            resp = t2.pesquisar(x);
        }

        return resp;
    }
}

class T2{
    T3 t3;
    Lista lista;
    Arvore arvore;

    boolean pesquisar(int x){
        boolean resp;
        int i2 = hashT2(x);
        if(i2 == 0){
            resp = t3.pesquisar(x);
        } else if(i2 == 1){
            resp = lista.pesquisar(x);
        } else{
            resp = arvore.pesquisar(x);
        }

        return resp;
    }
}

class T3{
    int tabela[];
    Arvore arvore;

    boolean pesquisar(int x){
        boolean resp;
        int i3 = hashT3(x);
        if(tabela[i3] == null){
            resp = false;
        } else if(tabela[i3] == x){
            resp = true;
        } else{
            int i3r = rehashT3(x);
            if(tabela[i3r] == null){
                resp = false;
            } else if(tabela[i3r] == x){
                resp = true;
            } else{
                resp = arvore.pesquisar(x);
            }
        }

        return resp;
    }
}

public class Hash{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        sc.close();
    }
}