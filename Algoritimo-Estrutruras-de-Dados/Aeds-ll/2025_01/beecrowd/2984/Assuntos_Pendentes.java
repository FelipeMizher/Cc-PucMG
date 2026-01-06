import java.util.*;

public class Assuntos_Pendentes{ 
    public static int verificar(String line){
        int abertos = 0;

        for(int i = 0; i < line.length(); i++){
            char c = line.charAt(i);

            if(c == '('){
                abertos++;
            } else if(c == ')'){
                if(abertos > 0){
                    abertos--;
                }
            }
        }

        return abertos;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        int pendentes = verificar(line);

        if(pendentes > 0){
            System.out.println("Ainda temos " + pendentes + " assunto(s) pendente(s)!");
        } else{
            System.out.println("Partiu RU!");
        }

        sc.close();
    }
}
