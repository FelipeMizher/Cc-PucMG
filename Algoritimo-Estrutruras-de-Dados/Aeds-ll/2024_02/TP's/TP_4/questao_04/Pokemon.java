import java.util.*;
import java.text.*;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.time.Duration;
import java.time.Instant;
import java.io.IOException;

class NoAN{
    public boolean cor;
    public Pokemon elemento;
    public NoAN esq, dir;

    public NoAN(){
        this(null, false, null, null);
    }

    public NoAN(Pokemon elemento){
        this(elemento, false, null, null);
    }

    public NoAN(Pokemon elemento, boolean cor){
        this(elemento, cor, null, null);
    }

    public NoAN(Pokemon elemento, boolean cor, NoAN esq, NoAN dir){
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
        System.out.print(elemento + "\nraiz");
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
        } else if(elemento.equals(i.elemento.getName())){
            log.incrementaCount();
            resp = true;
        } else if(elemento.compareTo(i.elemento.getName()) < 0){
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

    public void inserir(Pokemon elemento) throws Exception{
        if(raiz == null){
            raiz = new NoAN(elemento);
        } else if(raiz.esq == null && raiz.dir == null){
            if(elemento.getName().compareTo(raiz.elemento.getName()) < 0){
                raiz.esq = new NoAN(elemento);
            } else{
                raiz.dir = new NoAN(elemento);
            }
        } else if(raiz.esq == null){
            if(elemento.getName().compareTo(raiz.elemento.getName()) < 0){
                raiz.esq = new NoAN(elemento);
            } else if(elemento.getName().compareTo(raiz.dir.elemento.getName()) < 0){
                raiz.esq = new NoAN(raiz.elemento);
                raiz.elemento = elemento;
            } else{
                raiz.esq = new NoAN(raiz.elemento);
                raiz.elemento = raiz.dir.elemento;
                raiz.dir.elemento = elemento;
            }
            raiz.esq.cor = raiz.dir.cor = false;
        } else if(raiz.dir == null){
            if(elemento.getName().compareTo(raiz.elemento.getName()) > 0){
                raiz.dir = new NoAN(elemento);
            } else if(elemento.getName().compareTo(raiz.esq.elemento.getName()) > 0){
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
            if(pai.elemento.getName().compareTo(avo.elemento.getName()) > 0){ 
                if(i.elemento.getName().compareTo(pai.elemento.getName()) > 0){
                    avo = rotacaoEsq(avo);
                } else{
                    avo = rotacaoDirEsq(avo);
                }
            } else{ 
                if(i.elemento.getName().compareTo(pai.elemento.getName()) < 0){
                    avo = rotacaoDir(avo);
                } else{
                    avo = rotacaoEsqDir(avo);
                }
            }

            if(bisavo == null){
                raiz = avo;
            } else if(avo.elemento.getName().compareTo(bisavo.elemento.getName()) < 0){
                bisavo.esq = avo;
            } else{
                bisavo.dir = avo;
            }
            avo.cor = false;
            avo.esq.cor = avo.dir.cor = true;
        } 
    }

    private void inserir(Pokemon elemento, NoAN bisavo, NoAN avo, NoAN pai, NoAN i) throws Exception{
        if(i == null){
            if(elemento.getName().compareTo(pai.elemento.getName()) < 0){
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

            if(elemento.getName().compareTo(i.elemento.getName()) < 0){
                inserir(elemento, avo, pai, i, i.esq);
            } else if(elemento.getName().compareTo(i.elemento.getName()) > 0){
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

    public static void inserirArvore(Alvinegra arvore, Pokemon p[], Scanner sc) throws Exception{
        String id;

        id = sc.nextLine();
        while(!id.equals("FIM")){
            Pokemon novo;
            novo = Procurar(p, id);
            arvore.inserir(novo);
            id = sc.nextLine();
        }
    }

    public static void procuraNaArvore(Alvinegra arvore, Log log,Scanner sc){
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
        Alvinegra arvore = new Alvinegra();
        Log log = new Log("/tmp/821811_arvoreAlvinegra.txt");

        Exibir(personagens); 
        inserirArvore(arvore, personagens, sc);
        Instant start = Instant.now();
        procuraNaArvore(arvore, log, sc);
        Instant end = Instant.now();
        long elapsedTime = Duration.between(start, end).toMillis();
        log.time = (float) elapsedTime / 1000; 
        log.registrarLog();
        sc.close();
    }
    
}