import java.util.*;

class Idioma{
    String nome;
    String traducao;

    Idioma(String nome, String traducao){
        this.nome = nome;
        this.traducao = traducao;
    }
}

public class Etiquetas_do_Noel{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());

        Idioma[] idiomas = new Idioma[N];

        for(int i = 0; i < N; i++){
            String nomeIdioma = sc.nextLine();
            String traducao = sc.nextLine();
            idiomas[i] = new Idioma(nomeIdioma, traducao);
        }

        int M = Integer.parseInt(sc.nextLine());

        for(int i = 0; i < M; i++){
            String nomeCrianca = sc.nextLine();
            String idiomaCrianca = sc.nextLine();

            String saudacao = "";
            for(int j = 0; j < N; j++){
                if(idiomas[j].nome.equals(idiomaCrianca)){
                    saudacao = idiomas[j].traducao;
                    j = N;
                }
            }

            System.out.println(nomeCrianca);
            System.out.println(saudacao);
            System.out.println();
        }

        sc.close();
    }
}