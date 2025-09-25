import java.util.*;

public class CiframentoRec{
    public static int IsFim(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static String VerificarRec(String str, int start){
        String result = new String();

        if(start < str.length()){
            char c = str.charAt(start);

            if(c >= ' ' && c <= '~'){
                c = (char) (c + 3);
            }

            result = c + VerificarRec(str, start + 1); 
        }

        return result;
    }

    public static String Verificar(String str){
        return VerificarRec(str, 0);
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
