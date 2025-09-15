import java.util.*;

public class palindromo_re{
    public static int isFinal(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static int isPalindromo(String str, int start, int end){
        int result = 1;

        if(start < end){
            if(str.charAt(start) != str.charAt(end)){
                result = 0;
            } else{
                result = isPalindromo(str, start + 1, end - 1);
            }
        }

        return result;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;
        
        line = sc.nextLine();
        
        while(isFinal(line) != 0){
            if(isPalindromo(line, 0, line.length() - 1) == 1){
                System.out.println("SIM");
            } else{
                System.out.println("NAO");
            }
            line = sc.nextLine();
        }
        sc.close();
    }
}
