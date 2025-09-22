import java.util.*;

public class Substring{
    public static int IsFim(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static int Reduzir(String str){
        StringBuilder newString = new StringBuilder();
        boolean[] vistos = new boolean[256];
        int result = 0;

        for(int i = 0; i < str.length(); i++){
            char c = str.charAt(i);
            
            if(!vistos[c]){ 
                newString.append(c);
                vistos[c] = true;
            }
        }

        for(int i = 0; i < newString.length(); i++){
            result = result + 1;
        }
    
        return result;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        line = sc.nextLine();
        while(IsFim(line) != 0){
            System.out.println(Reduzir(line));
            line = sc.nextLine();
        }

        sc.close();
    }
}
