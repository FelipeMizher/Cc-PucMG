import java.util.*;

public class Contagem{
    public static int IsFim(String str){
        int result = 1;

        if(str.length() >= 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static int Verificar(String str){
        int count = 0;
        str = str.trim();

        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) == ' '){
                count++;
            }
        }

        count = count + 1;  

        return count;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        line = sc.nextLine();
        while(IsFim(line.trim()) != 0){
            System.out.println(Verificar(line));
            line = sc.nextLine();
        }

        sc.close();
    }
}
