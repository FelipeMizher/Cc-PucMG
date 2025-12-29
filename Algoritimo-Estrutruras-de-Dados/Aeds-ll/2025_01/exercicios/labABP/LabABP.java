package labABP;
class No{
    int elemento;
    No esq, dir; 

    public No(int elemento){
        this.elemento = elemento;
        esq = dir = null;
    }
}

class ArvoreBinaria{
	private No raiz;

	public ArvoreBinaria(){
		raiz = null;
	}

    public boolean pesquisar(int x){
		return pesquisar(x, raiz);
	}

    private boolean pesquisar(int x, No i){
        boolean resp;

        if(i == null){
           resp = false;
        } else if(x == i.elemento){
           resp = true;
        } else if(x < i.elemento){
           resp = pesquisar(x, i.esq);
        } else{
           resp = pesquisar(x, i.dir);
        }

        return resp;
    }

    public void inserir(int x) throws Exception{
        raiz = inserir(x, raiz);
    }

    private No inserir(int x, No i) throws Exception{
        if(i == null){
            i = new No(x);
        } else if(x < i.elemento){
            i.esq = inserir(x, i.esq);
        } else if(x > i.elemento){
            i.dir = inserir(x, i.dir);
        } else{
            throw new Exception("Erro!");
        }

        return i;
    }

    public void caminharCentral(){
        caminharCentral(raiz);
        System.out.println();
    }

    private void caminharCentral(No i){
        if(i != null){
            caminharCentral(i.esq);
            System.out.print(i.elemento + " ");
            caminharCentral(i.dir);
        }
    }

    public void caminharPos(){
        caminharPos(raiz);
        System.out.println();
    }

    private void caminharPos(No i){
        if(i != null){
            caminharPos(i.esq);
            caminharPos(i.dir);
            System.out.print(i.elemento + " ");
        }
    }

    public void caminharPre(){
        caminharPre(raiz);
        System.out.println();
    }

    private void caminharPre(No i){
        if(i != null){
            System.out.print(i.elemento + " ");
            caminharPre(i.esq);
            caminharPre(i.dir);
        }
    }

    public int getAltura(){
        return getAltura(raiz);
    }

    private int getAltura(No i){
        int count = -1;
        
        if(i != null){
            int alturaEsq = getAltura(i.esq);
            int alturaDir = getAltura(i.dir);

            if(alturaEsq > alturaDir){
                count = alturaEsq + 1;
            } else{
                count = alturaDir + 1;
            }
        }

        return count;
    }
}

public class LabABP{
    public static void main(String[] args) throws Exception{
        ArvoreBinaria arvore = new ArvoreBinaria();

        arvore.inserir(7);
        arvore.inserir(4);
        arvore.inserir(1);
        arvore.inserir(5);
        arvore.inserir(9);
        arvore.inserir(13);

        arvore.caminharCentral();
        arvore.caminharPre();
        arvore.caminharPos();
        System.out.println(arvore.pesquisar(5));
        System.out.println(arvore.pesquisar(6));
        System.out.println(arvore.getAltura());
    }
}