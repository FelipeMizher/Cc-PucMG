import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.time.Duration;
import java.time.Instant;
import java.util.*;

class NoAN{
    public boolean cor;
    public Show elemento;
    public NoAN esq, dir;

    public NoAN(){
        this(null, false, null, null);
    }

    public NoAN(Show elemento){
        this(elemento, false, null, null);
    }

    public NoAN(Show elemento, boolean cor){
        this(elemento, cor, null, null);
    }

    public NoAN(Show elemento, boolean cor, NoAN esq, NoAN dir){
        this.cor = cor;
        this.elemento = elemento;
        this.esq = esq;
        this.dir = dir;
    }
}

class Alvinegra{
    private NoAN raiz; 

    public Alvinegra(){
        raiz = null;
    }

    public void pesquisar(String elemento, Log log){
        System.out.print("=>raiz");
        boolean resp = pesquisar(elemento, raiz, log);

        if(resp){ 
            System.out.print(" SIM\n"); 
        } else{ 
            System.out.print(" NAO\n"); 
        }
    }

    private boolean pesquisar(String elemento, NoAN i, Log log){
        boolean resp;

        if(i == null){
            log.incrementaCount();
            resp = false;
        } else if(elemento.equals(i.elemento.getTitle())){
            log.incrementaCount();
            resp = true;
        } else if(elemento.compareTo(i.elemento.getTitle()) < 0){
            log.incrementaCount();
            System.out.print(" esq");
            resp = pesquisar(elemento, i.esq, log);
        } else{
            System.out.print(" dir");
            resp = pesquisar(elemento, i.dir, log);
        }

        return resp;
    }

    public void caminharCentral(){
        System.out.print("[ ");
        caminharCentral(raiz);
        System.out.println("]");
    }

    private void caminharCentral(NoAN i){
        if(i != null){
            caminharCentral(i.esq); 
            System.out.print(i.elemento + ((i.cor) ? "(p) " : "(b) ")); 
            caminharCentral(i.dir);
        }
    }

    public void caminharPre(){
        System.out.print("[ ");
        caminharPre(raiz);
        System.out.println("]");
    }

    private void caminharPre(NoAN i){
        if(i != null){
            System.out.print(i.elemento + ((i.cor) ? "(p) " : "(b) ")); 
            caminharPre(i.esq);
            caminharPre(i.dir);
        }
    }

    public void caminharPos(){
        System.out.print("[ ");
        caminharPos(raiz);
        System.out.println("]");
    }

    private void caminharPos(NoAN i){
        if(i != null){
            caminharPos(i.esq); 
            caminharPos(i.dir); 
            System.out.print(i.elemento + ((i.cor) ? "(p) " : "(b) ")); 
        }
    }

    public void inserir(Show elemento) throws Exception{
        if(raiz == null){
            raiz = new NoAN(elemento);
        } else if(raiz.esq == null && raiz.dir == null){
            if(elemento.getTitle().compareTo(raiz.elemento.getTitle()) < 0){
                raiz.esq = new NoAN(elemento);
            } else{
                raiz.dir = new NoAN(elemento);
            }
        } else if(raiz.esq == null){
            if(elemento.getTitle().compareTo(raiz.elemento.getTitle()) < 0){
                raiz.esq = new NoAN(elemento);
            } else if(elemento.getTitle().compareTo(raiz.dir.elemento.getTitle()) < 0){
                raiz.esq = new NoAN(raiz.elemento);
                raiz.elemento = elemento;
            } else{
                raiz.esq = new NoAN(raiz.elemento);
                raiz.elemento = raiz.dir.elemento;
                raiz.dir.elemento = elemento;
            }
            raiz.esq.cor = raiz.dir.cor = false;
        } else if(raiz.dir == null){
            if(elemento.getTitle().compareTo(raiz.elemento.getTitle()) > 0){
                raiz.dir = new NoAN(elemento);
            } else if(elemento.getTitle().compareTo(raiz.esq.elemento.getTitle()) > 0){
                raiz.dir = new NoAN(raiz.elemento);
                raiz.elemento = elemento;
            } else{
                raiz.dir = new NoAN(raiz.elemento);
                raiz.elemento = raiz.esq.elemento;
                raiz.esq.elemento = elemento;
            }
            raiz.esq.cor = raiz.dir.cor = false;

        } else{
            inserir(elemento, null, null, null, raiz);
        }
        raiz.cor = false;
    }

    private void balancear(NoAN bisavo, NoAN avo, NoAN pai, NoAN i){
        if(pai.cor == true){
            if(pai.elemento.getTitle().compareTo(avo.elemento.getTitle()) > 0){ 
                if(i.elemento.getTitle().compareTo(pai.elemento.getTitle()) > 0){
                    avo = rotacaoEsq(avo);
                } else{
                    avo = rotacaoDirEsq(avo);
                }
            } else{ 
                if(i.elemento.getTitle().compareTo(pai.elemento.getTitle()) < 0){
                    avo = rotacaoDir(avo);
                } else{
                    avo = rotacaoEsqDir(avo);
                }
            }

            if(bisavo == null){
                raiz = avo;
            } else if(avo.elemento.getTitle().compareTo(bisavo.elemento.getTitle()) < 0){
                bisavo.esq = avo;
            } else{
                bisavo.dir = avo;
            }
            avo.cor = false;
            avo.esq.cor = avo.dir.cor = true;
        } 
    }

    private void inserir(Show elemento, NoAN bisavo, NoAN avo, NoAN pai, NoAN i) throws Exception{
        if(i == null){
            if(elemento.getTitle().compareTo(pai.elemento.getTitle()) < 0){
                i = pai.esq = new NoAN(elemento, true);
            } else{
                i = pai.dir = new NoAN(elemento, true);
            }

            if(pai.cor == true){
                balancear(bisavo, avo, pai, i);
            }
        } else{
            if(i.esq != null && i.dir != null && i.esq.cor == true && i.dir.cor == true){
                i.cor = true;
                i.esq.cor = i.dir.cor = false;

                if(i == raiz){
                    i.cor = false;
                } else if(pai.cor == true){
                    balancear(bisavo, avo, pai, i);
                }
            }

            if(elemento.getTitle().compareTo(i.elemento.getTitle()) < 0){
                inserir(elemento, avo, pai, i, i.esq);
            } else if(elemento.getTitle().compareTo(i.elemento.getTitle()) > 0){
                inserir(elemento, avo, pai, i, i.dir);
            } else{
                throw new Exception("Erro inserir (elemento repetido)!");
            }
        }
    }

    private NoAN rotacaoDir(NoAN no){
        NoAN noEsq = no.esq;
        NoAN noEsqDir = noEsq.dir;

        noEsq.dir = no;
        no.esq = noEsqDir;

        return noEsq;
    }

    private NoAN rotacaoEsq(NoAN no){
        NoAN noDir = no.dir;
        NoAN noDirEsq = noDir.esq;

        noDir.esq = no;
        no.dir = noDirEsq;

        return noDir;
    }

    private NoAN rotacaoDirEsq(NoAN no){
        no.dir = rotacaoDir(no.dir);

        return rotacaoEsq(no);
    }

    private NoAN rotacaoEsqDir(NoAN no){
        no.esq = rotacaoEsq(no.esq);

        return rotacaoDir(no);
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

    public static void inserirArvore(Alvinegra arvore, Show shows[], Scanner sc) throws Exception{
        String id;

        id = sc.nextLine();
        while(IsFim(id) != 0){
            Show novo;
            novo = Procurar(shows, id);
            arvore.inserir(novo);
            id = sc.nextLine();
        }
    }

    public static void procuraNaArvore(Alvinegra arvore, Log log,Scanner sc){
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
        Alvinegra arvore = new Alvinegra();
        Log log = new Log("/tmp/821811_arvoreAlvinegra.txt");

        Carregar(shows);
        inserirArvore(arvore, shows, sc);
        Instant start = Instant.now();
        procuraNaArvore(arvore, log, sc);
        Instant end = Instant.now();
        long elapsedTime = Duration.between(start, end).toMillis();
        log.time = (float) elapsedTime / 1000; 
        log.registrarLog();
        sc.close();
    }
}