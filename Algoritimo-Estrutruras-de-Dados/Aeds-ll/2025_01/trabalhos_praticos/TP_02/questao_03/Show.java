import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.time.Duration;
import java.time.Instant;
import java.util.*;

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
 
    public void Informacoes(){
        try{
            FileWriter writer = new FileWriter(this.fileName);
            writer.write("Matrícula: 821811 \ttime de execução: " + this.time + " segundos \tNúmero de comparações: " + this.count);
            writer.close();

        } catch(IOException e){
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
    private ArrayList<String> cast;
    private String country;
    private Data data;
    private String release_year;
    private String rating;
    private String duration;
    private ArrayList<String> listed_in;

    public Show(){
        this.show_id = "";
        this.type = "";
        this.title = "";
        this.director = "";
        this.cast = new ArrayList<String>();
        this.country = "";
        this.data = new Data();
        this.release_year = "";
        this.rating = "";
        this.duration = "";
        this.listed_in = new ArrayList<String>();
    }

    public Show(String show_id, String type, String title, String director, ArrayList<String> cast, String country, String date_added,
                String release_year, String rating, String duration, ArrayList<String> listed_in){
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

    public String getShow_id(){
        return this.show_id;
    }
    public void setShow_id(String show_id){
        this.show_id = show_id;
    }

    public String getType(){
        return this.type;
    }
    public void setType(String type){
        this.type = type;
    }

    public String getTitle(){
        return this.title;
    }
    public void setTitle(String title){
        this.title = title;
    }

    public String getDirector(){
        return this.director;
    }
    public void setDirector(String director){
        this.director = director;
    }

    public ArrayList<String> getCast(){
        return this.cast;
    }
    public void setCast(ArrayList<String> cast){
        this.cast = cast;
    }

    public String getCountry(){
        return this.country;
    }
    public void setCountry(String country){
        this.country = country;
    }

    public Data getData(){
        return this.data;
    }
    public void setData(Data data){
        this.data = data;
    }

    public String getRelease_year(){
        return this.release_year;
    }
    public void setRelease_year(String release_year){
        this.release_year = release_year;
    }

    public String getRating(){
        return this.rating;
    }
    public void setRating(String rating){
        this.rating = rating;
    }

    public String getDuration(){
        return this.duration;
    }
    public void setDuration(String duration){
        this.duration = duration;
    }

    public ArrayList<String> getListed_in(){
        return this.listed_in;
    }
    public void setListed_in(ArrayList<String> listed_in){
        this.listed_in = listed_in;
    }    

    public Show Clone(){
        return new Show(this.show_id, this.type, this.title, this.director,
                        new ArrayList<>(this.cast), this.country, 
                        this.data.toString(), this.release_year,
                        this.rating, this.duration, new ArrayList<>(this.listed_in));
    }
    

    public void imprimir(){
        System.out.print("=> " + this.getShow_id() + " ## ");
        System.out.print(this.getTitle() + " ## ");
        System.out.print(this.getType() + " ## ");
        System.out.print(this.getDirector() + " ## ");
        System.out.print("[");
        for(int i = 0; i < this.getCast().size(); i++){
            System.out.print(this.getCast().get(i));

            if(i < this.getCast().size() -1){ 
                System.out.print(", ");
            }
        }
        System.out.print("] ## ");
        System.out.print(this.getCountry() + " ## ");
        System.out.print(this.getData().toString() + " ## ");
        System.out.print(this.getRelease_year() + " ## ");
        System.out.print(this.getRating() + " ## ");
        System.out.print(this.getDuration() + " ## ");
        System.out.print("[");
        for(int i = 0; i < this.getListed_in().size(); i++){
            System.out.print(this.getListed_in().get(i));
            if(i < this.getListed_in().size() - 1){ 
                System.out.print(", ");
            }
        }
        System.out.println("] ##");
    }           

    public void Read(String finalId) throws IOException{
        BufferedReader buffer = new BufferedReader(new FileReader("/tmp/disneyplus.csv"));
        String line = buffer.readLine();
    
        while(line != null){
            String[] data = line.split(",");
            String showId = data[0];
    
            if(showId.equals(finalId)){
                this.show_id = data[0];
                this.title = data[2];
                break;
            }
    
            line = buffer.readLine();
        }
    
        buffer.close();
    }
    
    public static void Buscar(Show[] shows, Log log, Scanner sc){
        Instant start, end;
        boolean achou;
        
        start = Instant.now();
        String title = sc.nextLine();
        
        while(!title.equals("FIM")){
            achou = false;
        
            for(int i = 0; i < shows.length && shows[i] != null && !achou; i++){
                if(shows[i].getTitle().equals(title)){
                    System.out.println("SIM");
                    achou = true;
                }
                log.incrementaCount();
            }
            
            if(!achou){
                System.out.println("NAO");
            }
            
            title = sc.nextLine();
        }
        
        end = Instant.now();
        long elapsedtime = Duration.between(start, end).toMillis();
        log.time = (float) elapsedtime / 1000;
        log.Informacoes();
    }

    public static int IsFim(String line){
        int result = 1; 

        if(line.charAt(0) == 'F' && line.charAt(1) == 'I' && line.charAt(2) == 'M'){
            result = 0;
        }

        return result;
    }    

    public static void main(String[] args) throws FileNotFoundException{
        Scanner sc = new Scanner(System.in);
        Log log = new Log("/tmp/821811_sequencial.txt");
        ArrayList<Show> listaShows = new ArrayList<>();
    
        String line = sc.nextLine();
        while (IsFim(line) != 0){
            try{
                Show s = new Show();
                s.Read(line);
                listaShows.add(s);
            } catch(Exception e){
                System.out.println("Erro na leitura do ID: " + e.getMessage());
            }
            line = sc.nextLine();
        }

        Show[] shows = listaShows.toArray(new Show[0]);
        Show.Buscar(shows, log, sc);
        sc.close();
    }
}

