import java.util.*;

public class algebra_re{
    public static int isFinal(String str){
        int result = 1;

        if(str.length() == 1 && str.charAt(0) == '0'){
            result = 0; 
        }
        
       return result; 
    }

    public static String NOT(String x){
        String result = "1";

        if(x.length() > 0 && x.charAt(0) == '1'){
            result = "0";
        }

       return result;
    }

    public static String AND(String x){
        String result = "1";

        for(int i = 0; i < x.length(); i++){
            result = (x.charAt(i) == '0') ? "0" : result;
        }

      return result;
    }


    public static String OR(String x){
        String result = "0";

        for(int i = 0; i < x.length(); i++){
            result = (x.charAt(i) == '1') ? "1" : result;
        }

      return result;
    }

    public static String alteracao(String in, int i){
        if(i >= 0){
            if(in.charAt(i) == '('){
                int end = i;
                while(!(in.charAt(end) == ')')){
                    end++;
                }
                switch(in.charAt(i - 1)){    
                    case 't':
                        String sub = in.substring(i - 3, end + 1); 
                        String resp = NOT(sub); 
                        in = in.replace(sub, resp);
                        
                        i = in.length()-1;
                        break;
                    case 'd':
                        sub = in.substring(i-3, end+1); 
                        resp = AND(sub);
                        in = in.replace(sub, resp);
                        
                        i = in.length()-1;
                        break;
                    case 'r':
                        sub = in.substring(i-2, end+1); 
                        resp = OR(sub);
                        in = in.replace(sub, resp);
                        
                        i = in.length()-1;
                        break;
                    default:
                        System.out.println("ERRO no switch!");
                        break;
                }
            
            }
            in = alteracao(in, i - 1);
        }
            
        return in;
    }

    public static String algebraBool(String x) {
        String resp = "";
        
        if(x.length() >= 5){
            if(x.charAt(0) == '2'){
                if(x.length() >= 7){ 
                    x = x.replace('A', x.charAt(2) == '1' ? '1' : '0');
                    x = x.replace('B', x.charAt(4) == '1' ? '1' : '0');
                    resp = alteracao(x.substring(6), x.length() - 7);
                }
            } else{
                if(x.length() >= 9){ 
                    x = x.replace('A', x.charAt(2) == '1' ? '1' : '0');
                    x = x.replace('B', x.charAt(4) == '1' ? '1' : '0');
                    x = x.replace('C', x.charAt(6) == '1' ? '1' : '0');
                    resp = alteracao(x.substring(8), x.length() - 9);
                }
            }
        }
    
        return resp;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line;
        
        line = sc.nextLine();
        while(isFinal(line) != 0){
            String resp = algebraBool(line);
            System.out.println(resp);
            line = sc.nextLine();
        }
        sc.close();
    }
}
