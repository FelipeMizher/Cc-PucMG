import java.util.*;

public class ciframento{
    public static int isFinal(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static String Ciframento(String str){
        int tam = str.length();
        String resultString = new String();

        for(int i = 0; i < tam; i++){
            char var = str.charAt(i);
            
            if(var >= ' ' && var <= '~'){
                var = (char) (var + 3);
            }

            resultString += var;
        }

        return resultString;
    }
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        line = sc.nextLine();
        while(isFinal(line) != 0){
            System.out.println(Ciframento(line));
            line = sc.nextLine();
        }

        sc.close();
    }
}