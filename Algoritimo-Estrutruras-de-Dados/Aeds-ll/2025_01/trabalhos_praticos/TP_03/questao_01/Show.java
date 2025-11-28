import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

class Lista{
    public Scanner sc;
    public Show s[];
    public int tamanho = 0;

    Lista(int tamanho){
        this.s = new Show[tamanho];
        this.tamanho = 0;
        this.sc = new Scanner(System.in);
    }

    void inserirInicio(Show show) throws Exception{
        if(tamanho >= s.length){
            throw new Exception("LIMITE EXCEDIDO");
        }

        for(int i = tamanho - 1; i >= 0; i--){
            s[i + 1] = s[i];
        }

        s[0] = show;
        tamanho++;
    }

    void inserir(Show show, int posicao) throws Exception{
        if(posicao < 0 || posicao > tamanho){
            throw new Exception("ERRO AO INSERIR");
        }

        for(int i = tamanho - 1; i >= posicao; i--){
            s[i + 1] = s[i];
        }

        s[posicao] = show;
        tamanho++;
    }

    void inserirFim(Show show) throws Exception{
        if(tamanho >= s.length){
            throw new Exception("LIMITE EXCEDIDO");
        }

        s[tamanho] = show;
        tamanho++;
    }

    Show removerInicio() throws Exception{
        if(tamanho == 0){
            throw new Exception("LISTA VAZIA");
        }

        Show removido = s[0];
        for(int i = 0; i < tamanho - 1; i++){
            s[i] = s[i + 1];
        }

        tamanho--;

      return removido;
    }

    Show remover(int posicao) throws Exception {
        if (tamanho == 0 || posicao < 0 || posicao >= tamanho) {
            throw new Exception("ERRO AO REMOVER"); 
        }

        Show removido = s[posicao];

        for (int i = posicao; i < tamanho - 1; i++) {
            s[i] = s[i + 1];
        }

        tamanho--;
        return removido;    
    }

    Show removerFim() throws Exception{
        if(tamanho == 0){
            throw new Exception("LISTA VAZIA");
        }

        Show removido = s[tamanho -1];
        tamanho --;

       return removido;
    }

    public void metodos(Show s[], int x){
        String m = "";
        Show novo;

        for(int i = 0; i < x + 1; i++){
            m = sc.nextLine();
            String[] str = m.split(" ");
            try{
                switch(str[0]){
                    case "II":
                        novo = Procurar(s, str[1]);
                        inserirInicio(novo);
                        break;
                    case "IF":
                        novo = Procurar(s, str[1]);
                        inserirFim(novo);
                        break;
                    case "I*":
                        novo = Procurar(s, str[2]);
                        inserir(novo, Integer.parseInt(str[1]));
                        break;
                    case "RI":
                        novo = removerInicio();
                        System.out.println("(R) " + novo.getTitle());
                        break;
                    case "RF":
                        novo = removerFim();
                        System.out.println("(R) " + novo.getTitle());
                        break;
                    case "R*":
                        novo = remover(Integer.parseInt(str[1]));
                        System.out.println("(R) " + novo.getTitle());
                        break;
                    default:
                        break;
                }
            } catch(Exception e){
                System.out.println(e.getMessage());            
            }
        }
        mostrar();
    }

    Show Procurar(Show s[], String id){
        Show x = null;
        
        try{
          for(int i = 0; i < s.length; i++){
            if(s[i] != null && s[i].getShow_id().equals(id)){
                x = s[i].clone();
                break;
            }
          }
        } catch(NumberFormatException e){
          System.out.println("ID inválido: " + id);
        }

        return x;
    }

    void mostrar(){
        for(int i = 0; i < tamanho; i++){
            if(s[i] != null){
                s[i].Imprimir();
            }
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

    public static void Pesquisar_ID(Show[] shows, String id, ArrayList<Show> buscados){
        for(int i = 0; i < shows.length; i++){
            if(shows[i] != null && shows[i].getShow_id().equals(id)){
                buscados.add(shows[i]);
                i = shows.length;
            }
        }
    }

    public static void main(String[] args) throws Exception{
        Show[] shows = new Show[1368];
        Lista list = new Lista(1368);
        String line;

        Carregar(shows);
        line = list.sc.nextLine();
        while(IsFim(line) != 0){
            Show novo = list.Procurar(shows, line);
            list.inserirFim(novo);
            line = list.sc.nextLine();
        }
        int n = list.sc.nextInt();
        list.metodos(shows, n);
        list.sc.close();
    }
}