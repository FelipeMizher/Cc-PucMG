import java.util.Random;
import java.util.Scanner;
import java.lang;

public class aleatorio{
    public static int isFinal(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static String alterar(String str){
        char[] novaString = new char[str.length()];
        Random gerador = new Random();
        gerador.setSeed(4);
    
        char letra1 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));
        char letra2 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));

        for(int i = 0; i < str.length(); i++){
            char c = str.charAt(i);
            if(c == letra1){
                novaString[i] = letra2; 
            } else {
                novaString[i] = c;
            }
        }
    
        return new String(novaString);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        line = sc.nextLine();
        while(isFinal(line) != 0){
            System.out.println(alterar(line));
            line = sc.nextLine();
        }

        sc.close();
    }
}
