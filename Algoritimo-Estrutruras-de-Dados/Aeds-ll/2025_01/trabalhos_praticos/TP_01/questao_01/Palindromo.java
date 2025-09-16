import java.util.*;

public class Palindromo{
    public static int IsFim(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static int Verificar(String str){
        int result = 1;
        int i = 0, j = str.length() - 1;

        while(i < j){
            if(str.charAt(i) != str.charAt(j)){
                result = 0;
                i = j; 
            }
            i++;
            j--;
        }

        return result;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        line = sc.nextLine();
        while(IsFim(line) != 0){
            if(Verificar(line) != 0){
                System.out.println("SIM");
            } else{
                System.out.println("NAO");
            }
            line = sc.nextLine();
        }
        sc.close();
    }
}
