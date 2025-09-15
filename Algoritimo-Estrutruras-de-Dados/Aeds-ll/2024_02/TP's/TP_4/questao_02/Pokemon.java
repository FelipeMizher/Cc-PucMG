import java.util.*;
import java.text.*;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.time.Duration;
import java.time.Instant;
import java.io.IOException;

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
    public Pokemon elemento;
    public No2 esq, dir;

    public No2(Pokemon elemento){
        this(elemento, null, null);
    }

    public No2(Pokemon elemento, No2 esq, No2 dir){
        this.elemento = elemento;
        this.esq = esq;
        this.dir = dir;
    }
}

class ArvoreArvore{
    private No raiz;

    public ArvoreArvore() throws Exception{
        raiz = null;
    }
    
    public void inserir(int x) throws Exception{
        raiz = inserir(x, raiz);
    }
    private No inserir(int x, No i) throws Exception{
        if(i == null){
            i = new No(x);
        } else if(x < i.elemento){
            i.esq = inserir(x, i.esq);
        } else if(x > i.elemento){
            i.dir = inserir(x, i.dir);
        } else{
            System.err.println("ERROR AO INSERIR NUM");
        }
        return i;
    }
    
    public void inserir(Pokemon s) throws Exception{
        inserir(s, raiz);
    }

    public void inserir(Pokemon p, No i) throws Exception{
        if(i.elemento == (p.getCaptureRate() % 15)){
            i.outro = inserir2(p, i.outro);
        } else if((p.getCaptureRate() % 15) < i.elemento){
            inserir(p, i.esq);
        } else if((p.getCaptureRate() % 15) > i.elemento){
            inserir(p, i.dir);
        } else{
            throw new Exception("Erro ao inserir!");
        }
    }

    public No2 inserir2(Pokemon s, No2 i) throws Exception{
        if(i == null){
            i = new No2(s);
        } else if(s.getName().compareTo(i.elemento.getName()) < 0){
            i.esq = inserir2(s, i.esq);
        } else if(s.getName().compareTo(i.elemento.getName()) > 0){
            i.dir = inserir2(s, i.dir);
        } else{
            throw new Exception("Erro ao inserir: elemento existente!");
        }
        return i;
    }

    public void pesquisar(String elemento, Log log){
        System.out.print("=> " + elemento + "\nraiz ");
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
        } else if(no.elemento.getName().compareTo(x) > 0){ 
            System.out.print(" esq"); 
            log.incrementaCount();
            resp = pesquisarSegundaArvore(no.esq, x, log);
        } else if(no.elemento.getName().compareTo(x) < 0){ 
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
        try {
            FileWriter writer = new FileWriter(this.fileName);
            writer.write("Matrícula: 821811 \ttempo de execução: " + this.time + " segundos  \tNúmero de comparações: " + this.count);
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

        while(line != null && Id != finalId){
            line = buffer.readLine();
            if(line == null){ 
                break;
            }

            positionStart = 0;
            positionEnd = line.indexOf(",", positionStart);
            Id = Integer.parseInt(line.substring(positionStart, positionEnd));
        }

        if (line == null || Id != finalId) {
            buffer.close();
            return;
        }

        this.setId(Id);

        positionStart = positionEnd + 1;
        positionEnd = line.indexOf(",", positionStart);
        if(positionEnd != -1){
            this.setGen(Integer.parseInt(line.substring(positionStart, positionEnd)));
        }
        
        positionStart = positionEnd + 1;
        positionEnd = line.indexOf(",", positionStart);
        if(positionEnd != -1){
            this.setName(line.substring(positionStart, positionEnd));
        }

        positionStart = positionEnd + 1;
        positionEnd = line.indexOf(",", positionStart);
        if(positionEnd != -1){
            this.setDescription(line.substring(positionStart, positionEnd));
        }

        ArrayList<String> types = new ArrayList<String>();
        positionStart = positionEnd+1;
        positionEnd = line.indexOf(",", positionStart);
        if(positionEnd != -1){
            types.add(line.substring(positionStart, positionEnd));
        }
        positionStart = positionEnd + 1;
        positionEnd = line.indexOf(",", positionStart);
        if(positionEnd != -1 && !line.substring(positionStart, positionEnd).isEmpty()){
            types.add(line.substring(positionStart, positionEnd));
        }
        this.setTypes(types);
 
        ArrayList<String> abilities = new ArrayList<>();
        positionStart = positionEnd + 4;
        positionEnd = line.indexOf("]", positionStart);
        if(positionEnd != -1){
            int position = line.indexOf("'", positionStart);
            if(position != -1){
                abilities.add(line.substring(positionStart, position));
            }
            while(position != -1 && position + 1 != positionEnd){
                positionStart = position + 4;
                position = line.indexOf("'", positionStart);
                if(position != -1){
                    abilities.add(line.substring(positionStart, position));
                }
            }
        }
        this.setAbilities(abilities);
        
        positionStart = positionEnd + 3;
        positionEnd = line.indexOf(",", positionStart);
        if(positionEnd != -1){
            try{
                this.setWeight(Double.parseDouble(line.substring(positionStart, positionEnd)));            
            } catch(Exception e){
                this.setWeight(0);
            }
        }

        positionStart = positionEnd + 1;
        positionEnd = line.indexOf(",", positionStart);
        if(positionEnd != -1){
            try{
                this.setHeight(Double.parseDouble(line.substring(positionStart, positionEnd)));            
            } catch(Exception e){
                this.setHeight(0);
            }
        }

        positionStart = positionEnd + 1;
        positionEnd = line.indexOf(",", positionStart);
        if(positionEnd != -1){
            this.setCaptureRate(Integer.parseInt(line.substring(positionStart, positionEnd)));
        }

        positionStart = positionEnd + 1;
        positionEnd = line.indexOf(",", positionStart);
        if(positionEnd != -1){
            this.setIsLegendary(line.substring(positionStart, positionEnd).equals("1"));
        }

        positionStart = positionEnd + 1;
        if(positionStart < line.length()){
            try{
                this.setCaptureDate(sdf.parse(line.substring(positionStart)));
            } catch(ParseException e){
                this.setCaptureDate(null);
            }
        }
    
        buffer.close();
    }

    public static void Exibir(Pokemon[] p) throws Exception {
        FileReader file;
        BufferedReader bf;
        String line;
        int i = 0;
    
        file = new FileReader(FILE_PATH);
        bf = new BufferedReader(file);

        line = bf.readLine();
    
        while(line  != null && i < p.length){
            try{
                Pokemon personagem = new Pokemon();
                personagem.read(i + 1);
                p[i] = personagem;
                i++;
            } catch(Exception e){
                System.out.println(e.getMessage());
            }
            line = bf.readLine();
        }
        bf.close();
        file.close();
    }

    public static Pokemon Procurar(Pokemon p[], String id){
        Pokemon x = new Pokemon();

        for(int i = 0; i < p.length; i++){
            if(p[i].getId() == Integer.parseInt(id)){
                x = p[i];
                i = p.length;
            }
        }
        return x;
    }

    public static void inserirNaArvore(ArvoreArvore arvore, Pokemon personagens[], Scanner sc) throws Exception{
        String id;

        id = sc.nextLine();
        while(!id.equals("FIM")){
            Pokemon novo;
            novo = Procurar(personagens, id);
            arvore.inserir(novo);
            id = sc.nextLine();
        }
    }

    public static void procuraNaArvore(ArvoreArvore arvore, Log log,Scanner sc){
        String nome; 

        nome = sc.nextLine();
        while(!nome.equals("FIM")){ 
            arvore.pesquisar(nome, log);
            nome = sc.nextLine();
        }
    }
    
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        Pokemon personagens[] = new Pokemon[803];
        ArvoreArvore arvore = new ArvoreArvore();
        arvore.inserir(7);
        arvore.inserir(3);
        arvore.inserir(11);
        arvore.inserir(1);
        arvore.inserir(5);
        arvore.inserir(9);
        arvore.inserir(13);
        arvore.inserir(0);
        arvore.inserir(2);
        arvore.inserir(4);
        arvore.inserir(6);
        arvore.inserir(8);
        arvore.inserir(10);
        arvore.inserir(12);
        arvore.inserir(14);
        Log log = new Log("/tmp/821811_arvoreBinaria.txt");

        Exibir(personagens); 
        inserirNaArvore(arvore, personagens, sc);
        Instant start = Instant.now();
        procuraNaArvore(arvore, log, sc);
        Instant end = Instant.now();
        long elapsedTime = Duration.between(start, end).toMillis();
        log.time = (float) elapsedTime / 1000; 
        log.registrarLog();
        sc.close();
    }
    
}