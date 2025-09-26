import java.util.*;

public class IsRec{
    public static int IsFim(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static boolean VogaisRec(String str, int start){
        boolean result = true;

        if(start < str.length()){
            char c = str.charAt(start);

            if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
                c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U'){
                result = false; 
            } else{
                result = VogaisRec(str, start + 1);
            }
        }

        return result;
    }

    public static boolean Vogais(String str){
        return VogaisRec(str, 0);
    }

    public static boolean ConsoantesRec(String str, int start){
        boolean result = true;

        if(start < str.length()){
            char c = str.charAt(start);

            if((c < 'A' || (c > 'Z' && c < 'a') || c > 'z') ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                result = false;
            } else{
                result = ConsoantesRec(str, start + 1);
            }
        }
        return result;
    }

    public static boolean Consoantes(String str){
        return ConsoantesRec(str, 0);
    }

    public static boolean InteirosRec(String str, int start){
        boolean result = true;

        if(start < str.length()){
            char c = str.charAt(start);

            if(c < '0' || c > '9'){
                result = false;
            }
        } else{
            result = InteirosRec(str, start + 1);
        }
    
        return result;
    }

    public static boolean Inteiros(String str){
        return InteirosRec(str, 0);
    }

    public static boolean ReaisRec(String str, int start){
        boolean result = true;
        boolean pontoDecimalEncontrado = false;

        if(start < str.length()){
            char c = str.charAt(start);

            if(c == '.' || c == ','){
                if(pontoDecimalEncontrado){
                    result =  false; 
                }
                pontoDecimalEncontrado = true; 
            } else if(c < '0' || c > '9'){
                result =  false;
            } else{
                result = ReaisRec(str, start + 1);
            }
        }

        return result;
    }

    public static boolean Reais(String str){
        return ReaisRec(str, 0);
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
