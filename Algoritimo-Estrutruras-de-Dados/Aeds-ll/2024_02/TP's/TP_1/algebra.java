import java.util.*;

public class algebra{
    public static int isFinal(String str){
        int result = 1;

        if(str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static String NOT(String x){
        return x.charAt(4) == '1' ? "0" : "1";
    }

    public static String AND(String x){
        String resp = "1";

        for(int i = 0; i < x.length(); i++){
            if(x.charAt(i) == '0'){
                resp = "0";
                i = x.length();
            }
        }
        return resp;
    }


    public static String OR(String x){
        String resp = "0";
        for(int i = 0; i < x.length(); i++){
            if(x.charAt(i) == '1'){
                resp = "1";
                i = x.length();
            }
        }
        return resp;
    }

    public static String alteracao(String in){
        for(int i = in.length() - 1; i >= 0; i--){
            if(in.charAt(i) == '('){
                int end = i;
                while(!(in.charAt(end) == ')')){
                    end++;
                }
                switch(in.charAt(i-1)){    
                    case 't':
                        String sub = in.substring(i-3, end+1); 
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
        }
        return in;
    }

    public static String algebraBool(String x){
        String resp = "";
        if(x.charAt(0) == '2'){
            if(x.charAt(2) == '1'){ 
                x = x.replace('A', '1'); 
            } else{ 
                x = x.replace('A', '0'); 
            }
            if(x.charAt(4) == '1'){ 
                x = x.replace('B', '1'); 
            } else{ 
                x = x.replace('B', '0'); 
            }
            resp = alteracao(x.substring(6));
        } else{
            if(x.charAt(2) == '1'){ 
                x = x.replace('A', '1'); 
            } else{ 
                x = x.replace('A', '0'); 
            }
            if(x.charAt(4) == '1'){ 
                x = x.replace('B', '1'); 
            } else{ 
                x = x.replace('B', '0'); 
            }
            if(x.charAt(6) == '1'){ 
                x = x.replace('C', '1'); 
            } else{ 
                x = x.replace('C', '0'); 
            }
            resp = alteracao(x.substring(8)); 
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
