 import java.io.*;
 import java.net.*;
 import java.util.*;
 
class Contador{
    public int[] a;		
    public int[] e;
    public int[] i;
    public int[] o;
    public int[] u;
    public int consoantes;
    public int br;
    public int table;
    public String nome;
 
 
    Contador(String nome){ 
        this.a = new int[5];           
        this.e = new int[5];             
        this.i = new int[5];             
        this.o = new int[5];		        
        this.u = new int[5];             
        this.consoantes = 0;             
        this.br = 0;
        this.table = 0;
        this.nome = nome;
    }
 
    public String toString(){  
        return "a(" + this.a[0] + ") " +
               "e(" + this.e[0] + ") " + 
               "i(" + this.i[0] + ") " + 
               "o(" + this.o[0] + ") " + 
               "u(" + this.u[0] + ") " + 
               "\u00E1(" + this.a[1] + ") " +
               "\u00E9(" + this.e[1] + ") " +
               "\u00ED(" + this.i[1] + ") " +
               "\u00F3(" + this.o[1] + ") " +
               "\u00FA(" + this.u[1] + ") " +
               "\u00E0(" + this.a[2] + ") " +
               "\u00E8(" + this.e[2] + ") " +
               "\u00EC(" + this.i[2] + ") " +
               "\u00F2(" + this.o[2] + ") " +
               "\u00F9(" + this.u[2] + ") " +
               "\u00E3(" + this.a[3] + ") " +
               "\u00F5(" + this.o[3] + ") " +
               "\u00E2(" + this.a[4] + ") " +
               "\u00EA(" + this.e[4] + ") " +
               "\u00EE(" + this.i[4] + ") " +
               "\u00F4(" + this.o[4] + ") " +
               "\u00FB(" + this.u[4] + ") " +
               "consoante(" + this.consoantes + ") " +
               "<br>(" + this.br + ") " + 
               "<table>(" + this.table + ") " +
               this.nome;
    }
}
    
class leitura{
 
    public static String getHtml(String endereco){
       String resp="";

        try{
            URL url = new URL(endereco);
            BufferedReader bf = new BufferedReader(new InputStreamReader(url.openStream()));
            while((endereco = bf.readLine()) != null) resp += endereco;
        } catch(MalformedURLException mue){
            mue.printStackTrace();
        } catch(IOException e){
            e.printStackTrace();
        }

       return resp;
    }
 
    public static boolean isUpper(char c){ 
        return 'A' <= c && c <= 'Z';
    }
     
    public static boolean isLower(char c){ 
        return 'a' <= c && c <= 'z';
    }
     
    public static boolean isLetter(char c){ 
        return isUpper(c) || isLower(c);
    }
    
    public static boolean isVowel(char c){
        if(isUpper(c)){
            return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        } else if(isLower(c)){
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        } else{
            return false;
        }
    }
    
    public static boolean isConsonant(char c){
       return isLower(c) && !isVowel(c);
    }
    
    public static boolean isBr(String str, int i){ 
       return str.charAt(i) == '<' &&
       str.charAt(i+1) == 'b' &&
       str.charAt(i+2) == 'r' &&
       str.charAt(i+3) == '>';
    }
 
    public static boolean isTable(String str, int i){ 
       return str.charAt(i) == '<' &&
       str.charAt(i + 1) == 't' &&
       str.charAt(i + 2) == 'a' &&
       str.charAt(i + 3) == 'b' &&
       str.charAt(i + 4) == 'l' &&
       str.charAt(i + 5) == 'e' &&
       str.charAt(i + 6) == '>';
    }

    public static void contar(Contador contador,String html){

        for(int i=0; i<html.length();i++){
            if(isTable(html, i)){  
                contador.table++;
                i += 6;
            }else if(isBr(html, i)){ 
                contador.br++;
                i += 3;
            }else if(isConsonant(html.charAt(i))){ 
                contador.consoantes++;
            }else{                            
                switch(html.charAt(i)){                   
                    case 'a': contador.a[0]++; break;
                    case 'e': contador.e[0]++; break;
                    case 'i': contador.i[0]++; break;
                    case 'o': contador.o[0]++; break;
                    case 'u': contador.u[0]++; break;
                    case 225: contador.a[1]++; break;
                    case 233: contador.e[1]++; break;
                    case 237: contador.i[1]++; break;
                    case 243: contador.o[1]++; break;
                    case 250: contador.u[1]++; break;
                    case 224: contador.a[2]++; break;
                    case 232: contador.e[2]++; break;
                    case 236: contador.i[2]++; break;
                    case 242: contador.o[2]++; break;
                    case 249: contador.u[2]++; break;
                    case 227: contador.a[3]++; break;
                    case 245: contador.o[3]++; break;
                    case 226: contador.a[4]++; break;
                    case 234: contador.e[4]++; break;
                    case 238: contador.i[4]++; break;
                    case 244: contador.o[4]++; break;
                    case 251: contador.u[4]++; break;
                    default: break;
                }
            }
        }
    }

    public static boolean isFim(String in){ 
        return in.length() == 3 && in.charAt(0)=='F' && in.charAt(1)=='I' && in.charAt(2)=='M';
    }
 
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

       String nome = sc.nextLine();
       while(!isFim(nome)){  
          Contador x = new Contador(nome); 
          String url = sc.nextLine();
          String content = getHtml(url);
          contar(x, content);
          System.out.println(x.toString());
          nome = sc.nextLine();
       }

       sc.close();
    }
}
