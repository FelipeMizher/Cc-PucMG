import java.util.*;

public class Array_Hash{
    public static void contar(int N, Scanner sc){
        while(N > 0){
            int L = sc.nextInt();
            sc.nextLine();

            int result = 0;
            for(int i = 0; i < L; i++){
                String line = sc.nextLine();

                for(int j = 0; j < line.length(); j++){
                    int valor = (line.charAt(j) - 'A') + i + j;
                    result = result + valor;
                }
            }

            System.out.println(result);
            N--;
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        contar(N, sc);
        sc.close();
    }
}
