import java.util.*;

class Aquecimento{
    public static int IsFim(String str){
        int result = 0;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 1;
        }

        return result;
    }

    public static int Contar(String str){
        int count = 0;

        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i) >= 'A' && str.charAt(i) <= 'Z'){
                count++;
            }
        }

        return count;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String line;

        line = sc.nextLine();
        while(IsFim(line) != 1){
            System.out.println(Contar(line) + " ");

            line = sc.nextLine();
        }

        sc.close();
    }
}