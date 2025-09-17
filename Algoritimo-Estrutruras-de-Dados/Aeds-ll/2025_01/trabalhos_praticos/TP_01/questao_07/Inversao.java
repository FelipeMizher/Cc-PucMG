import java.util.*;

public class Inversao{
    public static int IsFim(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static String Inverter(String str){
        char[] result = new char[str.length()];
        int tam = str.length();

        for(int i = tam - 1, j = 0; i >= 0; i--, j++){
            char c = str.charAt(i);
            result[j] = c;
        }

        return new String(result);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        line = sc.nextLine();
        while(IsFim(line) != 0){
            System.out.println(Inverter(line));
            line = sc.nextLine();
        }

        sc.close();
    }
}
