import java.util.*;

public class Senha{
    public static int IsFim(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static int Verificar(String str){
        int result = 0;
        boolean maiuscula = false, minuscula = false, especial = false, numero = false;

        for(int i = 0; i < str.length(); i++){
            char c = str.charAt(i);

            if(c >= 'A' && c <= 'Z'){
                maiuscula = true;
            } else if(c >= 'a' && c <= 'z'){
                minuscula = true;
            } else if(c >= '0' && c <= '9'){
                numero = true;
            } else{
                especial = true;
            }
        }

        if(maiuscula && minuscula && especial && numero){
            result = 1;
        } else{
            result = 0;
        }

        return result;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        line = sc.nextLine();
        while(IsFim(line) != 0){
            if(line.length() >= 8){
                if(Verificar(line) == 1){
                    System.out.println("SIM");
                } else{
                    System.out.println("NAO");
                }
            } else{
                System.out.println("NAO");
            }
            line = sc.nextLine();
        }

        sc.close();
    }
}
