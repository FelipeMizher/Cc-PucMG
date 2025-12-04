import java.util.*;

class Celula{
   public int elemento;
   public Celula inf, sup, esq, dir;
 
   public Celula(){
      this(0);
   }
 
   public Celula(int elemento){
      this(elemento, null, null, null, null);
   }
 
   public Celula(int elemento, Celula inf, Celula sup, Celula esq, Celula dir){
      this.elemento = elemento;
       this.inf = inf;
       this.sup = sup;
       this.esq = esq;
       this.dir = dir;
   }
}

class Matriz{
   private Celula inicio;
   private int linha, coluna;

   static Scanner sc = new Scanner(System.in);

   public Matriz(){
      this(3, 3);
   }

   public Matriz(int linha, int coluna){
      this.linha = linha;
      this.coluna = coluna;
      int i = 0, j = 0;
      inicio = new Celula();

      Celula tmpLinha = inicio; 
      Celula tmpColuna = inicio; 
      Celula tmpLink = inicio;

      while(j < coluna - 1){
         tmpColuna.dir = new Celula();
         tmpColuna.dir.esq = tmpColuna;
         tmpColuna = tmpColuna.dir;
         j++;
      } 
      j = 0; 
      tmpColuna = inicio;

      while(i < linha - 1){
         tmpLink = tmpLinha; 
         tmpLinha.inf = new Celula();    
         tmpLinha.inf.sup = tmpLinha;     
         tmpLinha = tmpLinha.inf;         
         tmpColuna = tmpLinha;            
         j = 0;
         while(j < coluna - 1){
            tmpColuna.dir = new Celula();
            tmpColuna.dir.esq = tmpColuna;
            tmpColuna = tmpColuna.dir;
            tmpLink = tmpLink.dir;
            tmpLink.inf = tmpColuna;    
            tmpLink.inf.sup = tmpLink;
            j++;
         }
         i++;
      } 
      tmpColuna = null;
      tmpLinha = null;
      tmpLink = null;
   }

   public void setLinha(int linha){
      this.linha = linha;
   }

   public void setColuna(int coluna){
      this.coluna = coluna;
   }

   public int getLinha(){
      return this.linha;
   }

   public int getColuna(){
      return this.coluna;
   }

   public void ExibirMatriz(){
      Celula tmp, tmpL;

      for(tmpL = inicio; tmpL != null; tmpL = tmpL.inf){
         for(tmp = tmpL; tmp != null; tmp = tmp.dir){
            System.out.print(tmp.elemento + " ");
         }
         System.out.println();
      }
   }

   public void lerMatriz(){
      Celula tmp, tmpL;

      for(tmpL = inicio; tmpL != null; tmpL = tmpL.inf){
         for(tmp = tmpL; tmp != null; tmp = tmp.dir){
            tmp.elemento = sc.nextInt();
         }
      }
   }

   public Matriz soma(Matriz m){
      Matriz resp = null;

      if(this.linha == m.linha && this.coluna == m.coluna){
         resp = new Matriz(this.linha, this.coluna);
         Celula aLinha, bLinha, Linha2, a, b, c;
         for(aLinha = this.inicio, bLinha = m.inicio, Linha2 = resp.inicio; 
            aLinha != null && bLinha != null && Linha2 != null; 
            aLinha = aLinha.inf, bLinha = bLinha.inf, Linha2 = Linha2.inf){
            for(a = aLinha, b = bLinha, c = Linha2; 
               a != null && b != null && c != null; 
               a = a.dir, b = b.dir, c = c.dir){
               c.elemento = a.elemento + b.elemento;
            }
         }
      } else{
         throw new IllegalArgumentException("As matrizes devem ter as mesmas dimensões para serem somadas.");
      }
      return resp;
   }

   public Matriz multiplicacao(Matriz m){
      Matriz resp = new Matriz(this.linha, m.coluna);
      Celula Linha, a, Coluna, b, Linha2, c;

      for(Linha = this.inicio, Linha2 = resp.inicio; Linha != null; Linha = Linha.inf, Linha2 = Linha2.inf){
         for(Coluna = m.inicio, c = Linha2; Coluna != null; Coluna = Coluna.dir, c = c.dir){
            int soma = 0;
            for(a = Linha, b = Coluna; a != null && b != null; a = a.dir, b = b.inf){
               soma += a.elemento * b.elemento;
            }
            c.elemento = soma;
         }
      }
      return resp;
   }

   public boolean isQuadrada(){
      boolean result = false;

      if(this.linha == this.coluna){
         result = true;
      }

      return result;
   }

   public void mostrarDiagonalPrincipal (){
      if(isQuadrada() == true){
         Celula tmp = inicio;
         for(int i = 0; i < linha; i++){
            System.out.print(tmp.elemento + " ");
            if(tmp.dir != null && tmp.inf != null){
               tmp = tmp.dir.inf;
            }
         }
         System.out.println();
      }
   }

   public void mostrarDiagonalSecundaria (){
      if(isQuadrada() == true){
         Celula tmp = inicio;
         while(tmp.dir != null){
            tmp = tmp.dir;
         }
         
         for(int i = 0; i < linha; i++){
            System.out.print(tmp.elemento + " ");
            if(tmp.esq != null && tmp.inf != null){
               tmp = tmp.esq.inf;
            }
         }
         System.out.println();
      }
   }

   public static void construir(){
      int linha1 = sc.nextInt();
         int coluna1 = sc.nextInt();
         Matriz m1 = new Matriz(linha1, coluna1);
         m1.lerMatriz();
         int linha2 = sc.nextInt();
         int coluna2 = sc.nextInt();
         Matriz m2 = new Matriz(linha2, coluna2);
         m2.lerMatriz();
         m1.mostrarDiagonalPrincipal();
         m1.mostrarDiagonalSecundaria();
         Matriz soma = m1.soma(m2);
         soma.ExibirMatriz();
         Matriz multi = m1.multiplicacao(m2);
         multi.ExibirMatriz();
   }

   public static void main(String[] args){
      int x = sc.nextInt();

      while(x > 0){
         construir();
         x--;
      }
      
      sc.close();
   }
}
