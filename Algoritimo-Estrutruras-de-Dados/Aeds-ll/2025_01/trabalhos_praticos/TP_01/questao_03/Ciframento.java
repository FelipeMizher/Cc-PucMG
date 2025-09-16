import java.util.*;

public class Ciframento{
    public static int IsFim(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static String Verificar(String str){
        int tam = str.length(); 
        String result = new String();

        for(int i = 0; i < tam; i++){
            char c = str.charAt(i);

            if(c >= ' ' && c <= '~'){
                c = (char) (c + 3);
            }

            result = result + c; 
        }

        return result;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        line = sc.nextLine();
        while(IsFim(line) != 0){
            System.out.println(Verificar(line));
            line = sc.nextLine();
        }

        sc.close();
    }
}
