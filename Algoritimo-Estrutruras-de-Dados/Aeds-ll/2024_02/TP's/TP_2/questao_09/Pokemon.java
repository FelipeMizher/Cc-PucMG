import java.util.*;
import java.io.*;
import java.text.*;

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

    public static void swap(Pokemon p[], int i, int j, Log log){
        Pokemon tmp = p[i];
        p[i] = p[j];
        p[j] = tmp;

        log.incrementaMovimentacoes();
        log.incrementaMovimentacoes();
        log.incrementaMovimentacoes();
    }

    public static boolean comparar(Pokemon p1, Pokemon p2, Log log){
        boolean resposta = false;
    
        if(p1.getHeight() > p2.getHeight()){
            resposta = true;
            log.incrementaCount();
        } else if(p1.getHeight() < p2.getHeight()){ 
            resposta = false;
        } else{
            if(p1.getName().compareTo(p2.getName()) > 0){
                resposta = true;
            } else{
                resposta = false;
            }
            log.incrementaCount();
        }
    
        return resposta;
    }
    
    public static void construir(Pokemon array[], int tamanhoHeap, Log log){
        
        for(int i = tamanhoHeap; i > 1 && comparar(array[i], array[i / 2], log); i /= 2){
            swap(array, i, i / 2, log);
        }
    }
    
    public static int getMaiorFilho(Pokemon array[], int i, int tamanhoHeap, Log log){
        int filho;
        
        if(2 * i + 1 > tamanhoHeap){
            filho = 2 * i;
        } else if(comparar(array[2 * i], array[2 * i + 1], log)){
            filho = 2 * i;
        } else{
            filho = 2 * i + 1; 
        }
    
        return filho;
    }
    
    public static void reconstruir(Pokemon array[], int tamanhoHeap, Log log){
        int i = 1, filho;
    
        while(i <= (tamanhoHeap / 2)){
            filho = getMaiorFilho(array, i, tamanhoHeap, log);
            if(!comparar(array[i], array[filho], log)){
                swap(array, i, filho, log);
                i = filho;
            } else{
                i = tamanhoHeap;
            }
        }
    }
    
    public static void heapsort(Pokemon p[], Log log, int n){
        Pokemon tmp[] = new Pokemon[n + 1];
    
        for(int i = 0; i < n; i++){
            tmp[i + 1] = p[i];
        }
    
        for(int tamanhoHeap = 2; tamanhoHeap <= n; tamanhoHeap++){
            construir(tmp, tamanhoHeap, log);
        }
    
        int tamanhoHeap = n;
    
        while (tamanhoHeap > 1){
            swap(tmp, 1, tamanhoHeap--, log);
            reconstruir(tmp, tamanhoHeap, log);
        }
    
        for(int i = 0; i < n; i++){
            p[i] = tmp[i + 1];
        }
    
        for(Pokemon pokemon : p){
            pokemon.print();
        }
    }
    
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        Log log = new Log("821811_heapsort.txt");

        List<Pokemon> pokemons = new ArrayList<>();
        String line = sc.nextLine();

        while(!line.equals("FIM")){
            try{
                int id = Integer.parseInt(line);
                Pokemon p = new Pokemon();
                p.read(id);
                pokemons.add(p);
            } catch(Exception e){
                System.out.println("Erro ao ler o ID: " + e.getMessage());
                break;
            }
            line = sc.nextLine();
        }

        Pokemon[] pokemonArray = pokemons.toArray(new Pokemon[0]);
        Pokemon.heapsort(pokemonArray, log, pokemonArray.length);

        log.registrarLog();

        sc.close();
    }
}