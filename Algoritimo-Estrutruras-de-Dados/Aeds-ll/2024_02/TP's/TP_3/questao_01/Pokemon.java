import java.util.*;
import java.io.*;
import java.text.*;

class Lista{
    public Scanner sc;
    public Pokemon p[];
    public int tamanho = 0;

    Lista(int tamanho){
        this.p = new Pokemon[tamanho];
        this.tamanho = 0;
        this.sc = new Scanner(System.in);
    }

    void inserirInicio(Pokemon pokemon) throws Exception{
        if(tamanho >= p.length){
            throw new Exception("LIMITE EXCEDIDO");
        }

        for(int i = tamanho - 1; i >= 0; i--){
            p[i + 1] = p[i];
        }

        p[0] = pokemon;
        tamanho++;
    }

    void inserir(Pokemon pokemon, int posicao) throws Exception{
        if(posicao < 0 || posicao > tamanho){
            throw new Exception("ERRO AO INSERIR");
        }

        for(int i = tamanho - 1; i >= posicao; i--){
            p[i + 1] = p[i];
        }

        p[posicao] = pokemon;
        tamanho++;
    }

    void inserirFim(Pokemon pokemon) throws Exception{
        if(tamanho >= p.length){
            throw new Exception("LIMITE EXCEDIDO");
        }

        p[tamanho] = pokemon;
        tamanho++;
    }

    Pokemon removerInicio() throws Exception{
        if(tamanho == 0){
            throw new Exception("LISTA VAZIA");
        }

        Pokemon removido = p[0];
        for(int i = 0; i < tamanho - 1; i++){
            p[i] = p[i + 1];
        }

        tamanho--;
      return removido;
    }

    Pokemon remover(int posicao) throws Exception{
        if(tamanho == 0 || posicao < 0 || posicao >= tamanho){
            throw new Exception("ERRO AO REMOVER"); 
        }

        Pokemon removido = p[posicao];
        for(int i = posicao; i < tamanho; i++){
            p[i] = p[i + 1];
        }

        tamanho--;
      return removido;
    }

    Pokemon removerFim() throws Exception{
        if(tamanho == 0){
            throw new Exception("LISTA VAZIA");
        }

        Pokemon removido = p[tamanho -1];
        tamanho --;
       return removido;
    }

    public void metodos(Pokemon p[], int x) {
        String m = "";
        Pokemon novo;

        for(int i = 0; i < x + 1; i++){
            m = sc.nextLine();
            String[] str = m.split(" ");
            try{
                switch (str[0]){
                    case "II":
                        novo = Procurar(p, str[1]);
                        inserirInicio(novo);
                        break;
                    case "IF":
                        novo = Procurar(p, str[1]);
                        inserirFim(novo);
                        break;
                    case "I*":
                        novo = Procurar(p, str[2]);
                        inserir(novo, Integer.parseInt(str[1]));
                        break;
                    case "RI":
                        novo = removerInicio();
                        System.out.println("(R) " + novo.getName());
                        break;
                    case "RF":
                        novo = removerFim();
                        System.out.println("(R) " + novo.getName());
                        break;
                    case "R*":
                        novo = remover(Integer.parseInt(str[1]));
                        System.out.println("(R) " + novo.getName());
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

    Pokemon Procurar(Pokemon p[], String id){
        Pokemon x = null;
        try{
          int idInt = Integer.parseInt(id);
          for(int i = 0; i < p.length; i++){
            if(p[i] != null && p[i].getId() == idInt){
              x = p[i].clone();
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
            p[i].print(i);
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
    
    public void print(int pos){

        System.out.print("["+pos+"] [#"+this.getId()+" -> "+this.getName()+": "+this.getDescription());
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
     
        pos++;
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
    
    
    public static void main(String[] args) throws Exception{
        Pokemon personagens[] = new Pokemon[803];
        Lista list = new Lista(803);
        String id;

        Exibir(personagens); 
        id = list.sc.nextLine();
        while(!id.equals("FIM")){
            Pokemon novo = list.Procurar(personagens, id);
            list.inserirFim(novo);
            id = list.sc.nextLine();
        }
        int n = list.sc.nextInt();
        list.metodos(personagens, n);
        list.sc.close();
    }
    
}