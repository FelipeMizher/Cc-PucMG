import java.util.*;
import java.io.*;
import java.text.*;
import java.time.Duration;
import java.time.Instant;

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
        try {
            FileWriter writer = new FileWriter(this.fileName);
            writer.write("Matrícula: 821811 \ttime de execução: " + this.time + " segundos \tNúmero de comparações: " + this.count);
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
        int id = 0;

        while(id != finalId && line != null){
            line = buffer.readLine();
            String[] data = line.split(",");
            id = Integer.parseInt(data[0]);
        }

        if(line != null){
            String[] data = line.split(",");
            this.id = Integer.parseInt(data[0]);
            this.name = data[2];
        }
        buffer.close();
    }

    public static void Buscar(Pokemon[] personagens, Log log, Scanner sc){
        Instant start, end;
        boolean achou;

        start = Instant.now();
        String name = sc.nextLine();

        while(!name.equals("FIM")){
            achou = false;
            for (int i = 0; i < personagens.length && personagens[i] != null && !achou; i++){
                if (personagens[i].getName().equals(name)){
                    System.out.println("SIM");
                    achou = true;
                }
                log.incrementaCount();
            }
            if (!achou) {
                System.out.println("NAO");
            }
            name = sc.nextLine();
        }

        end = Instant.now();
        long elapsedtime = Duration.between(start, end).toMillis();
        log.time = (float) elapsedtime / 1000;
        log.Informacoes();
    }

    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        Log log = new Log("/tmp/821811_sequencial.txt");
        List<Pokemon> listaPokemons = new ArrayList<>();

        String line = sc.nextLine();
        while(!line.equals("FIM")){
            try{
                int id = Integer.parseInt(line);
                Pokemon p = new Pokemon();
                p.read(id); 
                listaPokemons.add(p);
            } catch (Exception e){
                System.out.println("Erro na leitura do ID: " + e.getMessage());
            }
            line = sc.nextLine();
        }

        Pokemon[] personagens = listaPokemons.toArray(new Pokemon[0]);

        Pokemon.Buscar(personagens, log, sc);

        sc.close();
    }
}