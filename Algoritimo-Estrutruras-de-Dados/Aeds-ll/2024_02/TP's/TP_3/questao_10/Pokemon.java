import java.util.*;
import java.io.*;
import java.text.*;
import java.time.Duration;
import java.time.Instant;

class CelulaDupla{
    Pokemon elemento;
    public CelulaDupla ant;
    public CelulaDupla prox;

    public CelulaDupla(){
        this(null);
    }

    public CelulaDupla(Pokemon p){
        this.elemento = p;
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
    
    void inserir(Pokemon p) throws Exception{
        ultimo.prox = new CelulaDupla(p);
		ultimo.prox.ant = ultimo;
		ultimo = ultimo.prox;
        tamanho++;
    }

    public void swap(CelulaDupla p1, CelulaDupla p2, Log log){
        Pokemon tmp = p1.elemento;

        p1.elemento = p2.elemento;
        p2.elemento = tmp; 
        log.incrementaMovimentacoes(); 
        log.incrementaMovimentacoes(); 
        log.incrementaMovimentacoes();
    }

    public static boolean comparar(Pokemon a, Pokemon b, Log log){
        boolean resultado;
    
        log.incrementaCount();
        if(a.getGen() < b.getGen()){
            resultado = true;
        } else if(a.getGen() > b.getGen()){
            resultado = false;
        } else{
            log.incrementaCount();
            resultado = a.getName().compareTo(b.getName()) < 0;
        }
    
        return resultado;
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
            Pokemon pivo = i.elemento;
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

    void Exibir(){
        CelulaDupla i = primeiro.prox;
    
        while(i != null){ 
            i.elemento.print(); 
            i = i.prox;
        }
    }
}

class Pokemon{
    public static final String FILE_PATH = "/tmp/pokemon.csv";
    public static SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
    
    private int id;
    private int gen;
    private String name;
    private String description;
    private ArrayList<String> types;
    private ArrayList<String> abilities;
    private double weight;
    private double height;
    private int capture_rate;
    private boolean is_legendary;
    private Date capture_date;

    public Pokemon(){
        this.id = 0;
        this.gen = 0;
        this.name = "";
        this.description = "";
        this.types = new ArrayList<String>();
        this.abilities = new ArrayList<String>();
        this.weight = 0;
        this.height = 0;
        this.capture_rate = 0;
        this.is_legendary = false;
        this.capture_date = null;
    }

    public Pokemon(int id, int gen, String name, String description, ArrayList<String> types, ArrayList<String> abilities, double weight, double height, int capture_rate, boolean is_legendary, Date capture_date){
        this.id = id;
        this.gen = gen;
        this.name = name;
        this.description = description;
        this.types = types;
        this.abilities = abilities;
        this.weight = weight;
        this.height = height;
        this.capture_rate = capture_rate;
        this.is_legendary = is_legendary;
        this.capture_date = capture_date;
    }

    public int getId(){ 
        return this.id; 
    }
    public int getGen(){ 
        return this.gen; 
    }
    public String getName(){ 
        return this.name; 
    }
    public String getDescription(){ 
        return this.description; 
    }
    public ArrayList<String> getTypes(){
        return this.types; 
    }
    public ArrayList<String> getAbilities(){
        return this.abilities; 
    }
    public double getWeight(){ 
        return this.weight; 
    }
    public double getHeight(){ 
        return this.height; 
    }
    public int getCaptureRate(){ 
        return this.capture_rate; 
    }
    public boolean getIsLegendary(){ 
        return this.is_legendary; 
    }
    public Date getCaptureDate(){ 
        return this.capture_date; 
    }

    public void setId(int id){ 
        this.id = id; 
    }
    public void setGen(int gen){ 
        this.gen = gen; 
    }
    public void setName(String name){ 
        this.name = name; 
    }
    public void setDescription(String description){ 
        this.description = description; 
    }
    public void setTypes(ArrayList<String> types){ 
        this.types = types; 
    }
    public void setAbilities(ArrayList<String> abilities){ 
        this.abilities = abilities; 
    }
    public void setWeight(double weight){ 
        this.weight = weight; 
    }
    public void setHeight(double height){ 
        this.height = height; 
    }
    public void setCaptureRate(int capture_rate){ 
        this.capture_rate = capture_rate; 
    }
    public void setIsLegendary(boolean is_legendary){ 
        this.is_legendary = is_legendary; 
    }
    public void setCaptureDate(Date capture_Date){
        this.capture_date = capture_Date; 
    }

    public Pokemon clone(){ 
        return new Pokemon(this.id, this.gen, this.name, this.description, this.types, this.abilities, 
                           this.weight, this.height, this.capture_rate, this.is_legendary, this.capture_date); 
    }
    
    public void print(){

        System.out.print("[#"+this.getId()+" -> "+this.getName()+": "+this.getDescription());
        System.out.print(" - ['");
        for(int i = 0; i < this.getTypes().size(); i++){
            System.out.print(this.getTypes().get(i));

            if(i < this.getTypes().size() - 1){
                System.out.print("', '");
            }
        }
        System.out.print("'] - ['");
        for(int i = 0; i < this.getAbilities().size(); i++){
            System.out.print(this.getAbilities().get(i));

            if(i < this.getAbilities().size() - 1){
                System.out.print("', '");
            }
        }
        System.out.println("'] - "+this.getWeight()+"kg - "+this.getHeight()+"m - "+this.getCaptureRate()+"% - "+this.getIsLegendary()+" - "+this.getGen()+" gen] - "+sdf.format(this.getCaptureDate()));
        
    }

    public void read(int finalId) throws IOException{
        BufferedReader buffer = new BufferedReader(new FileReader(FILE_PATH));
        String line = buffer.readLine();    
        int Id = 0;
        int positionStart = 0;
        int positionEnd = 0;

        while(Id != finalId){
            line = buffer.readLine();
            positionStart = 0;
            positionEnd = 0;
            positionEnd = line.indexOf(",", positionStart);
            Id = Integer.parseInt(line.substring(positionStart, positionEnd));
        }

        this.setId(Id);

        positionStart = positionEnd+1;
        positionEnd = line.indexOf(",", positionStart);
        this.setGen(Integer.parseInt(line.substring(positionStart, positionEnd)));
        
        positionStart = positionEnd+1;
        positionEnd = line.indexOf(",", positionStart);
        this.setName(line.substring(positionStart, positionEnd));

        positionStart = positionEnd+1;
        positionEnd = line.indexOf(",", positionStart);
        this.setDescription(line.substring(positionStart, positionEnd));

        ArrayList<String> types = new ArrayList<String>();
        positionStart = positionEnd+1;
        positionEnd = line.indexOf(",", positionStart);
        types.add(line.substring(positionStart, positionEnd));
        positionStart = positionEnd+1;
        positionEnd = line.indexOf(",", positionStart);
        if(!line.substring(positionStart, positionEnd).equals("")){      
            types.add(line.substring(positionStart, positionEnd));
        }
        this.setTypes(types);
 
        ArrayList<String> abilities = new ArrayList<String>();
        positionStart = positionEnd+4;
        positionEnd = line.indexOf("]", positionStart);
        int position = line.indexOf("'", positionStart);
        abilities.add(line.substring(positionStart, position));
        while(position+1!=positionEnd){                                  
            positionStart = position+4;
            position = line.indexOf("'", positionStart);
            abilities.add(line.substring(positionStart, position));
        }
        this.setAbilities(abilities);
        
        positionStart = positionEnd+3;
        positionEnd = line.indexOf(",", positionStart);
        try {
            this.setWeight(Double.parseDouble(line.substring(positionStart, positionEnd)));            
        } catch (Exception e) {
            this.setWeight(0);
        }

        positionStart = positionEnd+1;
        positionEnd = line.indexOf(",", positionStart);
        try {
            this.setHeight(Double.parseDouble(line.substring(positionStart, positionEnd)));            
        } catch (Exception e) {
            this.setHeight(0);
        }

        positionStart = positionEnd+1;
        positionEnd = line.indexOf(",", positionStart);
        this.setCaptureRate(Integer.parseInt(line.substring(positionStart, positionEnd)));

        positionStart = positionEnd+1;
        positionEnd = line.indexOf(",", positionStart);
        if(line.substring(positionStart, positionEnd).equals("0")) this.setIsLegendary(false);
        else this.setIsLegendary(true);

        positionStart = positionEnd+1;
        try {
            this.setCaptureDate(sdf.parse(line.substring(positionStart, line.length())));
        } catch (ParseException e) {
            this.setCaptureDate(null);;
        }

        buffer.close();
    }

    public static Pokemon Procurar(Pokemon p[], String id){
        Pokemon x = new Pokemon();

        for(int i = 0; i < p.length; i++){
            if (p[i].getId() == Integer.parseInt(id)) {
                x = p[i].clone();
                i = p.length;
            }
        }
        return x;
    }
    
    public static void main(String[] args) throws IOException{
        Pokemon pokemons[] = new Pokemon[801];
        Log log = new Log("/tmp/821811_quicksort.txt");
        ListaPersonagem lista = new ListaPersonagem();

        for (int id = 1; id <= 801; id++) {
            Pokemon novoPokemon = new Pokemon();
            try {
                novoPokemon.read(id); 
                pokemons[id - 1] = novoPokemon;
            } catch (IOException e) {
                System.out.println("Erro ao ler o Pokémon com ID " + id + ": " + e.getMessage());
            }
        }

        String id = lista.sc.nextLine();
        while (!id.equals("FIM")) {
            Pokemon novo = Procurar(pokemons, id);
            try{
                if(novo != null){
                    lista.inserir(novo);
                }
            } catch(Exception e){
                System.out.println("Erro ao inserir o Pokémon: " + e.getMessage());
            }
            id = lista.sc.nextLine();
        }
        Instant start = Instant.now();
        lista.quicksort(log);
        Instant end = Instant.now();
        long elapsedTime = Duration.between(start, end).toMillis();
        log.time = (float) elapsedTime / 1000; 
        log.registrarLog();
        lista.Exibir();
        lista.sc.close();
    }
}