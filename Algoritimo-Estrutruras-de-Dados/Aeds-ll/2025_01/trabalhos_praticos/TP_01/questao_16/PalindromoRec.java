import java.util.*;

public class PalindromoRec{
    public static int IsFim(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static int VerificarRec(String str, int start, int end){
        int result = 1;

        if(start < end){
            if(str.charAt(start) != str.charAt(end)){
                result = 0;
                start = end; 
            } else{
                result = VerificarRec(str, start + 1, end - 1);
            }
        }

        return result;
    }

    public static int Verificar(String str){
        return VerificarRec(str, 0, str.length() - 1);
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
