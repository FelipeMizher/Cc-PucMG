import java.util.*;

public class Aleatorio{
    public static int IsFim(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static String Alterar(String str, char letra1, char letra2){
        char[] result = new char[str.length()];

        for(int i = 0; i < str.length(); i++){
            char c = str.charAt(i);

            if(c == letra1){
                result[i] = letra2;
            } else{
                result[i] = c;
            }
        }
        
        return new String(result);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        Random generator = new Random();
        generator.setSeed(4);

        line = sc.nextLine();
        while(IsFim(line) != 0){
            char letra1 = (char) ('a' + (Math.abs(generator.nextInt()) % 26));
            char letra2 = (char) ('a' + (Math.abs(generator.nextInt()) % 26));
            System.out.println(Alterar(line, letra1, letra2));
            line = sc.nextLine();
        }

        sc.close();
    }    
}