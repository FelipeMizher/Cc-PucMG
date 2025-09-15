public class ExemploArq02Leitura{
    public static void main(String[] args){
        Arq.openRead("exemplo.txt");

        String str = Arq.readString();

        Arq.close();

        System.out.println("str: " + str);
    }
}
