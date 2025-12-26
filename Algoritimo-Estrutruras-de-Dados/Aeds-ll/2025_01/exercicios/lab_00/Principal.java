import java.util.Locale;
import java.util.Scanner;

class Data{
    private int dia;
    private int mes;
    private int ano;

    public Data(int dia, int mes, int ano){
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    public int getDia(){
        return dia;
    }

    public void setDia(int dia){
        this.dia = dia;
    }

    public int getMes(){
        return mes;
    }

    public void setMes(int mes){
        this.mes = mes;
    }

    public int getAno(){
        return ano;
    }

    public void setAno(int ano){
        this.ano = ano;
    }
}

class Duracao{
    private int hora;
    private int minutos;

    public Duracao(int hora, int minutos){
        this.hora = hora;
        this.minutos = minutos;
    }

    public int getHora(){
        return hora;
    }

    public void setHora(int hora){
        this.hora = hora;
    }

    public int getMinutos(){
        return minutos;
    }

    public void setMinutos(int minutos){
        this.minutos = minutos;
    }
}

class Passagem{
    private int id;
    private double preco;
    private String cidade;
    private Data data;
    private Duracao duracao;

    public Passagem(int id, double preco, String cidade, Data data, Duracao duracao){
        this.id = id;
        this.preco = preco;
        this.cidade = cidade;
        this.data = data;
        this.duracao = duracao;
    }


    public static void ProcessarRegistro(){
        System.out.printf("Registro lido: %d; %02d/%02d/%d; %02d:%02d; %s; %.2f\n", 
        id, data.getDia(), data.getMes(), data.getAno(), duracao.getHora(), duracao.getMinutos(), 
        cidade, preco);
    }

}

class Principal{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        scanner.useLocale(Locale.US);
        scanner.useDelimiter("\\s+|-|:|\r\n");
        int n = sc.nextInt();
        
        for(int i = 0; i < n; i++){
            int id = sc.nextInt();
            double preco = sc.nextDouble();
            int ano = sc.nextInt();
            int mes = sc.nextInt();
            int dia = sc.nextInt();
            int hora = sc.nextInt();
            int minutos = sc.nextInt();
            sc.nextLine();
            String cidade = sc.nextLine().trim();

            Data data = new Data(dia, mes, ano);
            Duracao duracao = new Duracao(int hora, int minutos);
            Passagem passagem = new Passagem(id, preco, cidade, data, duracao);

            passagem.ProcessarRegistro();
        }

        scanner.close();
    }
}