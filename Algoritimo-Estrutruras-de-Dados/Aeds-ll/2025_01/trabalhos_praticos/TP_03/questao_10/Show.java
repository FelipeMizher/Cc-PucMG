import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.time.Duration;
import java.time.Instant;
import java.util.*;

class CelulaDupla{
    Show elemento;
    public CelulaDupla ant;
    public CelulaDupla prox;

    public CelulaDupla(){
        this(null);
    }

    public CelulaDupla(Show s){
        this.elemento = s;
        this.ant = this.prox = null;  
    }
}

class Log{
    public int count;
    public int movimentacoes;
    public float time;
    public String fileName;
     
    Log(String fileName){
        this.count = 0;
 
        this.fileName = fileName;
    }
 
    public void incrementaCount(){
        count++;
    }

    public void incrementaMovimentacoes(){
        movimentacoes++;
    }
 
    public void registrarLog(){
        try{
            FileWriter writer = new FileWriter(this.fileName);
            writer.write("Matrícula: 821811 \ttime de execução: " + this.time + " segundos \tNúmero de comparações: " + this.count + "\tNúmero de movimentações: " + this.movimentacoes);
            writer.close();

        }catch(IOException e){
            System.out.println("Erro: " + e.getMessage());
        }
    }
}

class ListaPersonagem{
    public CelulaDupla primeiro, ultimo;
    public int tamanho;
    public Scanner sc;

    ListaPersonagem(){
        CelulaDupla tmp = new CelulaDupla();
        primeiro = tmp;
        ultimo = primeiro;
        tamanho = 0;
        this.sc = new Scanner(System.in);
    }
    
    void inserir(Show s) throws Exception{
        ultimo.prox = new CelulaDupla(s);
		ultimo.prox.ant = ultimo;
		ultimo = ultimo.prox;
        tamanho++;
    }

    public void swap(CelulaDupla p1, CelulaDupla p2, Log log){
        Show tmp = p1.elemento;

        p1.elemento = p2.elemento;
        p2.elemento = tmp; 
        log.incrementaMovimentacoes(); 
        log.incrementaMovimentacoes(); 
        log.incrementaMovimentacoes();
    }

    public static int mesParaNumero(String mes){
        String[] meses = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
    
        int result = 0;
        for(int i = 0; i < 12; i++){
            if(mes.equals(meses[i])){
                result = i + 1;
            }
        }

        return result;
    }
    
    public static boolean comparar(Show a, Show b, Log log){
        boolean result = false;

        int anoA = a.getData().getAno();
        int anoB = b.getData().getAno();

        int mesA = mesParaNumero(a.getData().getMes());
        int mesB = mesParaNumero(b.getData().getMes());

        int diaA = a.getData().getDia();
        int diaB = b.getData().getDia();
    
        if(anoA < anoB){
            result = true;
            log.incrementaCount();
        } else if(anoA == anoB){
            if(mesA < mesB){
                result = true;
                log.incrementaCount();
            } else if(mesA == mesB){
                if(diaA < diaB){
                    result = true;
                    log.incrementaCount();
                } else if(diaA == diaB){
                    if(a.getTitle().compareTo(b.getTitle()) < 0){
                        result = true;
                        log.incrementaCount();
                    }
                }
            }
        }
    
        return result;
    }

    public boolean verificar(CelulaDupla i, CelulaDupla procurada){
        boolean x = false;

        while(!x && i != null){
            if(i == procurada){
                x = true;
            }
            i = i.prox;
        }
        return x;
    }

    public void quicksort(CelulaDupla i, CelulaDupla j, Log log){
        if(i != j && i != j.prox){
            CelulaDupla ii = i;
            CelulaDupla jj = j;
            Show pivo = i.elemento;

            while(verificar(ii, jj)){
                while(comparar(ii.elemento, pivo, log)){
                    ii = ii.prox;
                }
                while(comparar(pivo, jj.elemento, log)){
                    jj = jj.ant;
                }
                if(verificar(ii, jj)){
                    swap(ii, jj, log);
                    ii = ii.prox;
                    jj = jj.ant;
                }
            }
            quicksort(i, jj, log);
            quicksort(ii, j, log);
        }
    }

    public void quicksort(Log log){
        quicksort(primeiro.prox, ultimo, log);
    }

    void exibir(){
        CelulaDupla i = primeiro.prox;
    
        while(i != null){ 
            i.elemento.Imprimir(); 
            i = i.prox;
        }
    }
}

class Data{
    private String mes;
    private int dia;
    private int ano;

    public Data(){
        this.mes = "NaN";
        this.dia = 0;
        this.ano = 0;
    }

    public Data(String mes, int dia, int ano){
        this.mes = mes;
        this.dia = dia;
        this.ano = ano;
    }

    public String getMes(){
        return mes;
    }
    public void setMes(String mes){
        this.mes = mes;
    }

    public int getDia(){
        return dia;
    }
    public void setDia(int dia){
        this.dia = dia;
    }

    public int getAno(){
        return ano;
    }
    public void setAno(int ano){
        this.ano = ano;
    }

    public String toString() {
        return mes + " " + dia + ", " + ano;
    }

    public static Data Converter(String data){
        String mes = "NaN";
        int dia = 0;
        int ano = 0;
    
        if(!data.equals("NaN")){
            String[] partes = data.split(" ");
            mes = partes[0];
            dia = Integer.parseInt(partes[1].replace(",", ""));
            ano = Integer.parseInt(partes[2]);
        }
    
        return new Data(mes, dia, ano);
    }    
}

class Show{
    private String show_id;
    private String type;
    private String title;
    private String director;
    private String[] cast;
    private String country;
    private Data data;
    private String release_year;
    private String rating;
    private String duration;
    private String[] listed_in;

    public Show(){
        this.show_id = "";
        this.type = "";
        this.title = "";
        this.director = "";
        this.cast = new String[]{"NaN"};
        this.country = "";
        this.data = new Data();
        this.release_year = "";
        this.rating = "";
        this.duration = "";
        this.listed_in = new String[]{"NaN"};
    }

    public String getShow_id(){
        return show_id;
    }
    public void setShow_id(String show_id){
        this.show_id = show_id;
    }

    public String getType(){
        return type;
    }
    public void setType(String type){
        this.type = type;
    }

    public String getTitle(){
        return title;
    }
    public void setTitle(String title){
        this.title = title;
    }

    public String getDirector(){
        return director;
    }
    public void setDirector(String director){
        this.director = director;
    }

    public String[] getCast(){
        return cast;
    }
    public void setCast(String[] cast){
        this.cast = cast;
    }

    public String getCountry(){
        return country;
    }
    public void setCountry(String country){
        this.country = country;
    }

    public Data getData(){
        return data;
    }
    public void setData(Data data){
        this.data = data;
    }

    public String getRelease_year(){
        return release_year;
    }
    public void setRelease_year(String release_year){
        this.release_year = release_year;
    }

    public String getRating(){
        return rating;
    }
    public void setRating(String rating){
        this.rating = rating;
    }

    public String getDuration(){
        return duration;
    }
    public void setDuration(String duration){
        this.duration = duration;
    }

    public String[] getListed_in(){
        return listed_in;
    }
    public void setListed_in(String[] listed_in){
        this.listed_in = listed_in;
    }

    public Show(String show_id, String type, String title, String director, String[] cast, String country, String date_added,
                String release_year, String rating, String duration, String[] listed_in){
        this.show_id = show_id;
        this.type = type;
        this.title = title;
        this.director = director;
        this.cast = cast;
        this.country = country;
        this.data = Data.Converter(date_added);
        this.release_year = release_year;
        this.rating = rating;
        this.duration = duration;
        this.listed_in = listed_in;
    }

    public static void ordenar(String[] array){
        for(int i = 0; i < array.length - 1; i++){
            for(int j = 0; j < array.length - i - 1; j++){
                if(array[j].compareTo(array[j + 1]) > 0){
                    String temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }    

    public static Show Ler(String line){
        Show s = new Show();
        String[] temp = new String[12];
        int index = 0;
        boolean dentroAspas = false;
        StringBuilder campo = new StringBuilder();
    
        for(int i = 0; i < line.length(); i++){
            char c = line.charAt(i);
    
            if(c == '\"'){
                dentroAspas = !dentroAspas;
            } else if(c == ',' && !dentroAspas){
                temp[index++] = campo.length() == 0 ? "NaN" : campo.toString();
                campo.setLength(0); 
            } else{
                campo.append(c);
            }
        }
    
        temp[index] = campo.length() == 0 ? "NaN" : campo.toString();
    
        s.show_id      = temp[0];
        s.type         = temp[1];
        s.title        = temp[2];
        s.director     = temp[3];
        s.cast = temp[4].equals("NaN") ? new String[]{"NaN"} : temp[4].split(",\\s*");
        if(!temp[4].equals("NaN")){
            ordenar(s.cast);
        }
        s.country      = temp[5];
        s.data         = Data.Converter(temp[6]);
        s.release_year = temp[7];
        s.rating       = temp[8];
        s.duration     = temp[9];
        s.listed_in = temp[10].equals("NaN") ? new String[]{"NaN"} : temp[10].split(",\\s*");
        if(!temp[10].equals("NaN")){
            ordenar(s.listed_in);
        }
    
        return s;
    }
     
    public void Imprimir(){
        System.out.print("=> " + show_id + " ## ");
        System.out.print(title + " ## ");
        System.out.print(type + " ## ");
        System.out.print(director + " ## ");
    
        System.out.print("[");
        if(cast.length == 1 && cast[0].equals("NaN")){
            System.out.print("NaN");
        } else {
            for(int i = 0; i < cast.length; i++){
                System.out.print(cast[i]);
                if(i < cast.length - 1) System.out.print(", ");
            }
        }
        System.out.print("] ## ");
    
        System.out.print(country + " ## ");
        System.out.print(data.toString() + " ## ");
        System.out.print(release_year + " ## ");
        System.out.print(rating + " ## ");
        System.out.print(duration + " ## ");
    
        System.out.print("[");
        if(listed_in.length == 1 && listed_in[0].equals("NaN")){
            System.out.print("NaN");
        } else {
            for(int i = 0; i < listed_in.length; i++){
                System.out.print(listed_in[i]);
                if(i < listed_in.length - 1) System.out.print(", ");
            }
        }
        System.out.println("] ## ");
    }       

    public static void Carregar(Show[] shows){
        File file = new File("/tmp/disneyplus.csv");

        try{
            Scanner sc = new Scanner(file);
            sc.nextLine();
    
            for(int i = 0; i < 1368; i++){
                String linha = sc.nextLine();
                shows[i] = Show.Ler(linha);
            }
    
            sc.close();
        } catch(FileNotFoundException e){
            System.out.println("Arquivo não encontrado!");
        }
    }

    public static int IsFim(String line){
        int result = 1; 

        if(line.charAt(0) == 'F' && line.charAt(1) == 'I' && line.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }

    public static void Pesquisar_ID(Show[] shows, String id, ListaPersonagem lista) throws Exception{
        for(int i = 0; i < shows.length; i++){
            if(shows[i] != null && shows[i].getShow_id().equals(id)){
                lista.inserir(shows[i]);
                i = shows.length;
            }
        }
    }

    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        Show[] shows = new Show[1368];
        Log log = new Log("/tmp/821811_quicksort3.txt");
        String line;
        Instant start, end;
        ListaPersonagem lista = new ListaPersonagem();

        Carregar(shows);

        line = sc.nextLine();
        while(IsFim(line) != 0){
            Pesquisar_ID(shows, line, lista);
            line = sc.nextLine();
        }

        sc.close();

        start = Instant.now();
        lista.quicksort(log);
        lista.exibir();
        end = Instant.now();
        long elapsedtime = Duration.between(start, end).toMillis();
        log.time = (float) elapsedtime / 1000;
        log.registrarLog();
    }
}