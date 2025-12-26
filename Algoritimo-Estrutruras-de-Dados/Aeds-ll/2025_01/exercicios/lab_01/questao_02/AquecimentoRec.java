import java.util.*;

public class AquecimentoRec{
    public static int IsFim(String str){
        int result = 1;

        if(str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static int ContarRec(String str, int index){
        int count = 0;

            if(index < str.length()){
                if(str.charAt(index) >= 'A' && str.charAt(index) <= 'Z'){
                    count++;
                }
                count = count + ContarRec(str, index + 1);
            }

        return count;
    }

    public static int Contar(String str){
        return ContarRec(str, 0);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        line = sc.nextLine();
        while(IsFim(line) != 0){
            System.out.println(Contar(line) + "");

            line = sc.nextLine();
        }
        sc.close();
    }
}
