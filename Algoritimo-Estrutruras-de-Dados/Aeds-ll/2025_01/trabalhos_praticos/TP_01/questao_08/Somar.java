import java.util.*;

public class Somar{
    public static int IsFim(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M' && str.charAt(3) == '\0'){
            result = 0;
        }

        return result;
    }

    public static int SomarDigitos(String num){
        int soma = 0;
        
        for(int i = 0; i < num.length(); i++){
            soma = soma + num.charAt(i) - '0';
        }

        return soma;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String num;

        num = sc.nextLine();
        while(IsFim(num) != 0){
            System.out.println(SomarDigitos(num));
            num = sc.nextLine();
        }

        sc.close();
    }
}
