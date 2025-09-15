import java.util.*;

public class is{
    public static int isFinal(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static boolean isVogal(String str){
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

    public static boolean isConsoante(String str){
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

    public static boolean isInteiro(String str){
        boolean result = true;
        int index = 0;

        for(int i = index; i < str.length(); i++){
            char c = str.charAt(i);

            if(c < '0' || c > '9'){
                result = false;
            }
        }
    
        return result;
    }

    public static boolean isReal(String str){
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
        String vogal = "", consoante = "", inteiros = "", reais = "";

        line = sc.nextLine();
        while(isFinal(line) != 0){
            if(isVogal(line) == true){
                vogal = "SIM";
            } else{
                vogal = "NAO";
            }

            if(isConsoante(line) == true){
                consoante = "SIM";
            } else{
                consoante = "NAO";
            }

            if(isInteiro(line) == true){
                inteiros = "SIM";
            } else{
                inteiros = "NAO";
            }

            if(isReal(line) == true){
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
