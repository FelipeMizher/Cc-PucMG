class AlgebraRec{
    public static boolean IsFim(String str){
        return str.length() == 1 && str.charAt(0) == '0';
    }

    public static String Replace(String x, char target, char replace){
        String resp = "";
        for(int i = 0; i < x.length(); i++){
            if(x.charAt(i) == target){
                resp += replace;
            } else{
                resp += x.charAt(i);
            }
        }
        return resp;
    }

    public static String Replace(String x, String target, String replace){
        String resp = "";
        for(int i = 0; i < x.length(); i++){
            if(x.charAt(i) != target.charAt(0)){
                resp += x.charAt(i);
            } else{
                for(int j = i + 1, k = 1; k < target.length(); k++, j++){
                    if(x.charAt(j) != target.charAt(k)){
                        k = target.length();
                        resp += x.charAt(i);
                    } else{
                        resp += replace;
                        k = target.length();
                        i += target.length() - 1;
                    }
                }
            }
        }
        return resp;
    }

    public static String Substring(String x, int start, int end){
        if(start < 0 || end >= x.length() + 1) throw new StringIndexOutOfBoundsException();
        String resp = "";
        for(int i = start; i < end; i++){
            resp += x.charAt(i);
        }
        return resp;
    }

    public static String Substring(String x, int start){
        if(start < 0 || start > x.length() - 1) throw new StringIndexOutOfBoundsException();
        String resp = "";
        for(int i = start; i < x.length(); i++){
            resp += x.charAt(i);
        }
        return resp;
    }

    public static String algebra(String x){
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
            resp = alteracao(x.substring(6), x.length() - 7);
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
            resp = alteracao(x.substring(8), x.length() - 9);
        }
        return resp;
    }

    public static String alteracao(String in, int i){
        if(i >= 0){
            if(in.charAt(i)=='('){
                int end = i;
                while(!(in.charAt(end)==')')){
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
                        MyIO.println("ERRO no switch!");
                        break;
                }
            
            }
            in = alteracao(in,i-1);
        }
            
        return in;
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

    public static void main(String[] args){
        String line = MyIO.readLine();

        while(!IsFim(line)){
            String resp = algebra(line);
            MyIO.println(resp);
            line = MyIO.readLine();
        }
    }
}
