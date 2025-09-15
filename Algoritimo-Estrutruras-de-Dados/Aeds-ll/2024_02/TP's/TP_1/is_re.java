import java.util.*;

public class is_re{
    public static int isFinal(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static boolean isVogal(String str, int index){
        boolean result = true;
    
        if(index >= str.length()){
            result = true; 
        } else{
            char c = str.charAt(index);
    
            if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
                c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U'){
                result = false;
            } else{
                result = isVogal(str, index + 1);
            }
        }
    
        return result;
    }

    public static boolean isConsoante(String str, int index){
        boolean result = true;
    
        if(index >= str.length()){
            result = true;
        } else{
            char c = str.charAt(index);
    
            if((c < 'A' || (c > 'Z' && c < 'a') || c > 'z') ||
                c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                result = false; 
            } else{
                result = isConsoante(str, index + 1);
            }
        }
    
        return result;
    }

    public static boolean isInteiro(String str, int index){
        boolean result;
    
        if(index >= str.length()){
            result = true;
        } else{
            char c = str.charAt(index);
    
            if(c < '0' || c > '9'){
                result = false; 
            } else{
                result = isInteiro(str, index + 1); 
            }
        }
    
        return result;
    }

    public static boolean isReal(String str, int index, boolean pontoDecimalEncontrado){
        boolean result = true;
    
        if(index >= str.length()){
            result = true;
        } else{
            char c = str.charAt(index);
    
            if(c == '.' || c == ','){
                if(pontoDecimalEncontrado){
                    result = false; 
                } else{
                    result = isReal(str, index + 1, true); 
                }
            } else if(c < '0' || c > '9'){
                result = false; 
            } else{
                result = isReal(str, index + 1, pontoDecimalEncontrado); 
            }
        }
    
        return result;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;
        String vogal = "", consoante = "", inteiros = "", reais = "";

        line = sc.nextLine();

        while(isFinal(line) != 0){
            if(isVogal(line, 0) == true){
                vogal = "SIM";
            } else{
                vogal = "NAO";
            }

            if(isConsoante(line, 0) == true){
                consoante = "SIM";
            } else{
                consoante = "NAO";
            }

            if(isInteiro(line, 0) == true){
                inteiros = "SIM";
            } else{
                inteiros = "NAO";
            }

            if(isReal(line, 0, false)){
                reais = "SIM";
            } else{
                reais = "NAO";
            }

            System.out.println(vogal + " " +  consoante + " " + inteiros + " " + reais);

            line = sc.nextLine();
        }

        sc.close();
    }
}
