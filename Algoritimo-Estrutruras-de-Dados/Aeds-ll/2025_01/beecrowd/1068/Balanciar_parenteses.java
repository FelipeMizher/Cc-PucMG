import java.util.*;

public class Balanciar_parenteses{
    public static boolean verificar(String line){
        boolean resp = false;
        int count = 0;

        for(int i = 0; i < line.length(); i++){
            char c = line.charAt(i);

            if(c == '('){
                count++;
            } else if(c == ')'){
                count--;
                if(count < 0){
                    i = line.length();
                }
            }
        }

        if(count == 0){
            resp = true;
        }

        return resp;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        while(sc.hasNext()){
            String line = sc.nextLine();
            if(verificar(line)){
                System.out.println("correct");
            } else{
                System.out.println("incorrect");
            }
        }
        sc.close();
    }
}
