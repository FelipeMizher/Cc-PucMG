import java.text.Normalizer;
import java.util.*;

public class Anagrama{
    public static int IsFim(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static String normalizar(String str){
        return Normalizer.normalize(str, Normalizer.Form.NFD)
                         .replaceAll("[^\\p{ASCII}]", "")
                         .toLowerCase();
    }

    public static int Verificar(String str1, String str2){
        int result = 1, i = 0;
        int tam1 = str1.length(), tam2 = str2.length();
    
        if(tam1 != tam2){
            result = 0;
        } else{
            boolean[] usados = new boolean[tam2];
    
            while(i < tam1){
                boolean igual = false;
    
                for(int j = 0; j < tam2; j++){
                    if(str1.charAt(i) == str2.charAt(j) && !usados[j]){
                        igual = true;
                        usados[j] = true;
                        j = tam2;  
                    }
                }
    
                if(!igual){
                    result = 0;
                }
    
                i++;
            }
        }
    
        return result;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line1, line2;
    
        while(sc.hasNextLine()){
            line1 = sc.nextLine().trim();

            if(IsFim(line1) == 0){
            } else{
                String[] palavras = line1.split(" - ");

                if(palavras.length == 2){
                    line1 = normalizar(palavras[0].trim());
                    line2 = normalizar(palavras[1].trim());

                    if(Verificar(line1, line2) == 1){
                        System.out.println("SIM");
                    } else{
                        System.out.println("NAO");
                    }
                }
            }
        }

        sc.close();
    }
}
