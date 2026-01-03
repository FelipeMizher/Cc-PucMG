import java.util.*;

public class TDA_Racional{
    public static int calcular(int a, int b){
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        
        return a;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        for(int i = 0; i < N; i++){
            int N1, D1, N2, D2;
            String operation;

            N1 = sc.nextInt();
            sc.next();
            D1 = sc.nextInt();
            operation = sc.next();
            N2 = sc.nextInt();
            sc.next();
            D2 = sc.nextInt();

            int numResult = 0, denResult = 0;

            if(operation.equals("+")){
                numResult = N1 * D2 + N2 * D1;
                denResult = D1 * D2;
            } else if(operation.equals("-")){
                numResult = N1 * D2 - N2 * D1;
                denResult = D1 * D2;
            } else if(operation.equals("*")){
                numResult = N1 * N2;
                denResult = D1 * D2;
            } else if(operation.equals("/")){
                numResult = N1 * D2;
                denResult = N2 * D1;
            }

            int resp = calcular(Math.abs(numResult), Math.abs(denResult));
            int Num = numResult / resp;
            int Den = denResult / resp;

            System.out.printf("%d/%d = %d/%d\n", numResult, denResult, Num, Den);
        }

        sc.close();
    }
}