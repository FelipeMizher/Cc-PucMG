import java.util.*;

public class Contador{
    public static int IsFim(String line){
        int result = 1;

        if(line.charAt(0) == 'F' && line.charAt(1) == 'I' && line.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static int Verificar(char c){
        int result = 0;

        if(c >= 'A' && c <= 'Z'){
            result = 1;
        }

        return result;
    }

    public static int Contar(String line){
        int count = 0;

        for(int i = 0; i < line.length(); i++){
            if(Verificar(line.charAt(i)) == 1){
                count++;
            } 
        }

        return count;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        line = sc.nextLine();
        while(IsFim(line) != 0){
            System.out.println(Contar(line));
            line = sc.nextLine();
        }

        sc.close();
    }
}