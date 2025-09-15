import java.util.*;

public class aquecimento7{
    public static int isFinal(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }
    
    public static int verificar(String str){
        int result = 1;
        int count = 0;
         
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) == '('){
                count++;
            }
            
            if(str.charAt(i) == ')'){
               count--; 
            }

            if(count < 0){
                result = 0;
                i = str.length();
            }
        }
        
        if(count != 0){
            result = 0;
        }
        
        return result;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;
        
        line = sc.nextLine();
        while(isFinal(line) != 0){
            if(verificar(line) == 1){
                System.out.println("correto");
            } else{
                System.out.println("incorreto");
            }
            line = sc.nextLine();
        }
        
        sc.close();
    }
}
