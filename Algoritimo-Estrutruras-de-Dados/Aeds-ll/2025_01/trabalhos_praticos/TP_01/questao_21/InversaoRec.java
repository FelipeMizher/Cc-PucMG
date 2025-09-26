import java.util.*;

public class InversaoRec{
    public static int IsFim(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static String InverterRec(String str, int start, int tam){
        String result = "";

        if(tam >= 0){
            result = str.charAt(tam) + InverterRec(str, start + 1, tam - 1);
        }

        return new String(result);
    }

    public static String Inverter(String str){
        return InverterRec(str, 0, str.length() - 1);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        line = sc.nextLine();
        while(IsFim(line) != 0){
            System.out.println(Inverter(line));
            line = sc.nextLine();
        }

        sc.close();
    }
}