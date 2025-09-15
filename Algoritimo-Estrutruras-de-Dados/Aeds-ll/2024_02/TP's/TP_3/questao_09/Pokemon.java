import java.util.*;
import java.io.*;
import java.text.*;

class Celula{
    Pokemon elemento;
    Celula prox;
    Celula(){
        this(null);
    }
    Celula(Pokemon p){
        this.prox = null;
        this.elemento = p;
    }
}

class Pilha{
    public Scanner sc;
    public Celula topo;

    Pilha(int tamanho){
        topo = null;
        this.sc = new Scanner(System.in);
    }

    Pokemon remover() throws Exception{    
        Pokemon resposta;
    
        if(topo.prox == null){
            resposta = topo.elemento;
            topo = null;
        } else{
            Celula atual = topo;
            while(atual.prox.prox != null){
                atual = atual.prox;
            }
    
            resposta = atual.prox.elemento;
            atual.prox = null;
        }
    
        return resposta;
    }
    
    public void metodos(Pokemon p[], int x){
        String m = "";
        Pokemon novo;

        for(int i = 0; i < x + 1; i++){
            m = sc.nextLine();
            String[] str = m.split(" ");
            try{
                if(str[0].equals("R")){
                    Pokemon removido = remover();
                    System.out.println("(R) " +removido.getName());
                } else{
                    novo = Procurar(p, str[1]);
                    inserir(novo);
                }
            } catch(Exception e){
                e.getMessage();
            }
        }
        mostrar();
    }

    public void inserir(Pokemon p){
        Celula nova = new Celula(p);

        if(topo == null){
            topo = nova;
        } else{
            Celula atual = topo;
            while(atual.prox != null){
                atual = atual.prox;
            }
            atual.prox = nova;
        }
    }

    Pokemon Procurar(Pokemon p[], String id){
        Pokemon x = new Pokemon();

        try{
            int searchId = Integer.parseInt(id);
            for(int i = 0; i < p.length; i++){
                if(p[i].getId() == searchId){ 
                    x = p[i].clone();
                    i = p.length;
                }
            }
        } catch(Exception e){
            e.getMessage();
        }
        return x;
    }
    

    void mostrar() {
        Celula i = topo;
        int index = 0;
        while (i != null) {
            System.out.print("[" + index + "] ");
            i.elemento.print();
            i = i.prox;
            index++;
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

    public static void imprimir(Pokemon pokemon, int index) {
        System.out.print("[" + index + "] ");
        pokemon.print();
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
    
    public static void main(String[] args) throws IOException{
        Pokemon pokemons[] = new Pokemon[801];
        Pilha pilha = new Pilha(801);

        for(int id = 1; id <= 801; id++){
            Pokemon novoPokemon = new Pokemon();
            try {
                novoPokemon.read(id); 
                pokemons[id - 1] = novoPokemon;
            } catch (IOException e) {
                System.out.println("Erro ao ler o Pokémon com ID " + id + ": " + e.getMessage());
            }
        }

        String id = pilha.sc.nextLine();
        while(!id.equals("FIM")){
            Pokemon novo = pilha.Procurar(pokemons, id);
            pilha.inserir(novo);
            id = pilha.sc.nextLine();
        }
        int n = pilha.sc.nextInt();
        pilha.metodos(pokemons, n);
        pilha.sc.close();
    }
}