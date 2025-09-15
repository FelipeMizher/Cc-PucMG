import java.util.*;

public class ciframento_re{
    public static int isFinal(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static String Ciframento(String str, int index){
        String result;

        if(index >= str.length()){
            result = " ";
        } else{
            char var = str.charAt(index);
                
            if(var >= ' ' && var <= '~'){
                var = (char) (var + 3); 
            }

            result = var + Ciframento(str, index + 1);
        }

        return result;
    }
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;

        line = sc.nextLine();
        while(isFinal(line) != 0){
            System.out.println(Ciframento(line, 0));
            line = sc.nextLine();
        }

        sc.close();
    }
}