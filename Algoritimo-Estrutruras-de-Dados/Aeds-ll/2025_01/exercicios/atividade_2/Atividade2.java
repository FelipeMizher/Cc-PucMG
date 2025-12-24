import java.util.Locale;
import java.util.Scanner;

//Atuvudade que complementa o Exemplo1.java e Exemplo2.java
//Usar junto com o pub_tipo3.in

class Atividade2{
  public static void ProcessarRegistro(int id, double preco, String tempo, String cidade){
    System.out.printf("Registro lido: %d %.2f %s %s\n", id, preco, tempo, cidade);
  }

  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int id;
    double preco;
    String tempo;
    String cidade;

    while((id = scanner.nextInt()) != 0){
      preco = scanner.nextDouble();
      tempo = scanner.next();
      cidade = scanner.nextLine().trim();
      ProcessarRegistro(id, preco, tempo, cidade);
    }

    scanner.close();
  }
}