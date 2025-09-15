import java.util.Scanner;

public class aquecimento2{
    public static int contador(String str){
        int count = 0;

        if(str.equals("")){
            return 0;
        }
        
        char c = str.charAt(0);

            if(Character.isUpperCase(c)){
                count = 1;
            }

        return count + contador(str.substring(1));
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        do{
            line = sc.nextLine();
            if(!line.equals("FIM")){
                System.out.println(contador(line));
            }
        } while(!line.equals("FIM"));

        sc.close();
    }
}
