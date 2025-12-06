import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.time.Duration;
import java.time.Instant;
import java.util.*;

class No{
    public No2 outro;
    public int elemento;
    public No esq, dir; 
    public No(int elemento){
        this(elemento, null, null, null);
    }

    public No(int elemento, No2 outro, No esq, No dir){
        this.elemento = elemento;
        this.outro = outro;
        this.esq = esq;
        this.dir = dir;
    }
}

class No2 {
    public Show elemento;
    public No2 esq, dir;

    public No2(Show elemento){
        this(elemento, null, null);
    }

    public No2(Show elemento, No2 esq, No2 dir){
        this.elemento = elemento;
        this.esq = esq;
        this.dir = dir;
    }
}

class ArvoreArvore{
    private No raiz;

    public ArvoreArvore() throws Exception{
        raiz = null;
        int index[] = { 7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12, 14 };

        for(int c = 0; c < index.length; c++){
            inserir(index[c]);
        }
    }

    public void inserir(int chave) throws Exception{
        raiz = inserir(chave, raiz);
    }

    private No inserir(int x, No i) throws Exception{
        if(i == null){
            i = new No(x);
        } else if(x < i.elemento){
            i.esq = inserir(x, i.esq);
        } else if(x > i.elemento){
            i.dir = inserir(x, i.dir);
        } else{
            throw new Exception("Erro ao inserir!");
        }

       return i;
    }
    
    public void inserir(Show s) throws Exception{
        inserir(s, raiz);
    }

    public void inserir(Show s, No i) throws Exception{
        int ano = Integer.parseInt(s.getRelease_year());

        if(i == null){
            throw new Exception("Erro ao inserir: show invalido!");
        } else if((ano % 15) < i.elemento){
            inserir(s, i.esq);
        } else if((ano % 15) > i.elemento){
            inserir(s, i.dir);
        } else{
            i.outro = inserir(s, i.outro);
        }
    }

    private No2 inserir(Show s, No2 i) throws Exception{
        if(i == null){
            i = new No2(s);
        } else if(s.getTitle().compareTo(i.elemento.getTitle()) < 0){
            i.esq = inserir(s, i.esq);

        } else if(s.getTitle().compareTo(i.elemento.getTitle()) > 0){
            i.dir = inserir(s, i.dir);
        } else{
            throw new Exception("Erro ao inserir: elemento já existente!");
        }
        return i;
    }

    public void pesquisar(String elemento, Log log){
        System.out.print("raiz");
        boolean resp = pesquisar(raiz, elemento, log);
        if(resp){
            System.out.print(" SIM\n");
        } else{
            System.out.print(" NAO\n");
        }
    }   

    private boolean pesquisar(No no, String x, Log log){
        boolean resp = false;
        if(no != null){
            resp = pesquisarSegundaArvore(no.outro, x, log);    
            if(!resp){
                System.out.print(" ESQ");
                resp = pesquisar(no.esq, x, log);
            }
            if(!resp){
                System.out.print(" DIR");
                resp = pesquisar(no.dir, x, log);
            }
        }

        return resp;
    }

    private boolean pesquisarSegundaArvore(No2 no, String x, Log log){
        boolean resp = false;
        if(no == null){ 
            resp = false; 
            log.incrementaCount();
        } else if(no.elemento.getTitle().compareTo(x) > 0){ 
            System.out.print(" esq"); 
            log.incrementaCount();
            resp = pesquisarSegundaArvore(no.esq, x, log);
        } else if(no.elemento.getTitle().compareTo(x) < 0){ 
            System.out.print(" dir"); 
            log.incrementaCount();
            resp = pesquisarSegundaArvore(no.dir, x, log);
        } else{
            resp = true;
        }
        
        return resp;
    }
}

class Log{
    public int count;
    public float time;
    public String fileName;
     
    Log(String fileName){
        this.count = 0;
        this.fileName = fileName;
    }
 
    public void incrementaCount(){
        count++;
    }
 
    public void registrarLog(){
        try{
            FileWriter writer = new FileWriter(this.fileName);
            writer.write("Matrícula: 821811 \ttempo de execução: " + this.time + " segundos  \tNúmero de comparações: " + this.count);
            writer.close();

        }catch(IOException e){
            System.out.println("Erro: " + e.getMessage());
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

    public Show clone(){
    String[] castClone = (this.cast != null) ? this.cast.clone() : null;
    String[] listedInClone = (this.listed_in != null) ? this.listed_in.clone() : null;
    String dataString = (this.data != null) ? this.data.toString() : null;

    return new Show(this.show_id, this.type, this.title, this.director,
                    castClone, this.country, dataString, this.release_year,
                    this.rating, this.duration, listedInClone);
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

    public static void swap(Show s[], int i, int j){
        Show tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }

    public static Show Procurar(Show s[], String id){
        Show x = new Show();

        for(int i = 0; i < s.length; i++){
            if(s[i].getShow_id().equals(id)){
                x = s[i];
                i = s.length;
            }
        }
        return x;
    }

    public static void inserirNaArvore(ArvoreArvore arvore, Show shows[], Scanner sc) throws Exception{
        String id;

        id = sc.nextLine();
        while(IsFim(id) != 0){
            Show novo;
            novo = Procurar(shows, id);
            arvore.inserir(novo);
            id = sc.nextLine();
        }
    }

    public static void procuraNaArvore(ArvoreArvore arvore, Log log,Scanner sc){
        String nome; 

        nome = sc.nextLine();
        while(IsFim(nome) != 0){ 
            arvore.pesquisar(nome, log);
            nome = sc.nextLine();
        }
    }

    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        Show[] shows = new Show[1368];
        ArvoreArvore arvore = new ArvoreArvore();
        Log log = new Log("/tmp/821811_arvoreBinaria.txt");

        Carregar(shows);
        inserirNaArvore(arvore, shows, sc);
        Instant start = Instant.now();
        procuraNaArvore(arvore, log, sc);
        Instant end = Instant.now();
        long elapsedTime = Duration.between(start, end).toMillis();
        log.time = (float) elapsedTime / 1000; 
        log.registrarLog();
        sc.close();
    }
}