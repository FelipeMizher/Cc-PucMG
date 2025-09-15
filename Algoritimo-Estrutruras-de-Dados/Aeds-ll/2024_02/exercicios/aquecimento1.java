import java.util.*;

class aquecimento1{
    public static int contador(String str){
        int count = 0;

        for(int i = 0; i < str.length(); i++){
            char c = str.charAt(i);

            if(Character.isUpperCase(c)){
                count++;
            }
            
        }
        return count;
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
