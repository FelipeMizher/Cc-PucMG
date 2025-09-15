class ExemploArq01Escrita{
    public static void main(String[] args){
        Arq.openWrite("exemplo.txt");

        Arq.println("AED_2");

        Arq.close();
    }
}