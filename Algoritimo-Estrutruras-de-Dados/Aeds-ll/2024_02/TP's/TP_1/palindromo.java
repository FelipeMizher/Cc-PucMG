import java.util.*;

public class palindromo{
    public static void isPalindromo(String str){
        int result = 1; 
        int start = 0; 
        int end = str.length() - 1;

        while(start < end){
            if (str.charAt(start) != str.charAt(end)){
                result = 0;
                start = end;
            }
            start++;
            end--;
        }
        
        if(result == 1){
            System.out.println("SIM");
        } else{
            System.out.println("NAO");
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;
        
        line = sc.nextLine();
        
        while(!line.equals("FIM")){
            isPalindromo(line);
            line = sc.nextLine();
        }
        sc.close();
    }
}
