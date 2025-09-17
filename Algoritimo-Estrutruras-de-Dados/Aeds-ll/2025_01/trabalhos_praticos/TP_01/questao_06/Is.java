import java.util.*;

public class Is{
    public static int IsFim(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static boolean Vogais(String str){
        boolean result = true;

        for(int i = 0; i < str.length(); i++){
            char c = str.charAt(i);

            if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
                c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U'){
                result = false; 
            }
        }
        return result;
    }

    public static boolean Consoantes(String str){
        boolean result = true;

        for(int i = 0; i < str.length(); i++){
            char c = str.charAt(i);

            if((c < 'A' || (c > 'Z' && c < 'a') || c > 'z') ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                result = false;
            }
        }
        return result;
    }

    public static boolean Inteiros(String str){
        boolean result = true;

        for(int i = 0; i < str.length(); i++){
            char c = str.charAt(i);

            if(c < '0' || c > '9'){
                result = false;
            }
        }
    
        return result;
    }

    public static boolean Reais(String str){
        boolean result = true;
        boolean pontoDecimalEncontrado = false;

        for(int i = 0; i < str.length(); i++){
            char c = str.charAt(i);

            if(c == '.' || c == ','){
                if(pontoDecimalEncontrado){
                    result =  false; 
                }
                pontoDecimalEncontrado = true; 
            } else if(c < '0' || c > '9'){
                result =  false;
            }
        }

      return result;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        line = sc.nextLine();
        while(IsFim(line) != 0){
            if(Vogais(line) != false){
                System.out.print("SIM");
            } else{
                System.out.print("NAO");
            }

            if(Consoantes(line) != false){
                System.out.print(" SIM");
            } else{
                System.out.print(" NAO");
            }

            if(Inteiros(line) != false){
                System.out.print(" SIM");
            } else{
                System.out.print(" NAO");
            }

            if(Reais(line) != false){
                System.out.print(" SIM");
            } else{
                System.out.print(" NAO");
            }
            System.out.println();
            line = sc.nextLine();
        }

        sc.close();
    }
}
