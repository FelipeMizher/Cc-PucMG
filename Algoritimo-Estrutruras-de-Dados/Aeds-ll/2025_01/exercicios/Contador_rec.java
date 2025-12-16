import java.util.*;

public class Contador_rec{
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
        int count = ContarRec(line, 0);

        return count;
    }

    public static int ContarRec(String line, int pos){
        int count = 0;

        if(pos < line.length()){
            char c = line.charAt(pos);
            count = ContarRec(line, pos + 1);  
            if(Verificar(c) == 1){
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