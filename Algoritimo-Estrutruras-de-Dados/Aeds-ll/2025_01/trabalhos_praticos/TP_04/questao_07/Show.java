import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.time.Duration;
import java.time.Instant;
import java.util.*;

class Celula{
	public Show elemento;
    public Celula prox;

    Celula(Show elemento){
        this.elemento = elemento;
        this.prox = null;
    }

	Celula(Show elemento, Celula prox){
		this.elemento = elemento;
		this.prox = prox;
	}
}

class Lista{
	private Celula primeiro; 
	private Celula ultimo; 

	public Lista(){
        primeiro = new Celula(null);
        ultimo = primeiro;
    }

	public void mostrar(){
		System.out.print("[ ");
		for(Celula i = primeiro.prox; i != null; i = i.prox){
			System.out.print(i.elemento + " ");
		}
		System.out.println("] ");
	}

	public boolean pesquisar(Show elemento, Log log){
        boolean achou = false;
        for(Celula i = primeiro.prox; i != null && !achou; i = i.prox){
            log.incrementaCount();
            if(i.elemento.getTitle().equals(elemento.getTitle())){
                achou = true;
            }
        }
        return achou;
    }


	public void inserirInicio(Show elemento){
		Celula tmp = new Celula(elemento);
        tmp.prox = primeiro.prox;
		primeiro.prox = tmp;
		if(primeiro == ultimo){
			ultimo = tmp;
		}
        tmp = null;
	}

	public void inserirFim(Show elemento){
		Celula tmp = new Celula(elemento);
		ultimo.prox = tmp;
		ultimo = ultimo.prox;
        tmp = null;
	}

    public void inserirMeio(Show x, int posicao) throws Exception{
        Celula i;
        int cont;

        for(i = primeiro, cont = 0; (i.prox != ultimo && cont < posicao); i = i.prox, cont++);
		
		if(posicao < 0 || posicao > cont + 1){
			throw new Exception("Erro ao inserir (posicao " + posicao + "(cont = " + cont + ") invalida)!");
        } else if(posicao == cont + 1){
            inserirFim(x);
		}else{
            Celula tmp = new Celula(x);
            tmp.prox = i.prox;
            i.prox = tmp;
            tmp = i = null;
        }
    }

	public Show removerInicio() throws Exception{
      Show resp;

		if(primeiro == ultimo){
			throw new Exception("Erro ao remover (vazia)!");
		}else{
            primeiro = primeiro.prox;
            resp = primeiro.elemento;
        }

		return resp;
	}

	public Show removerFim() throws Exception{
        Show resp;
        Celula i = null;

		if(primeiro == ultimo){
			throw new Exception("Erro ao remover (vazia)!");
		} else{
            resp = ultimo.elemento;
            for(i = primeiro; i.prox != ultimo; i = i.prox);
            ultimo = i;
            i = ultimo.prox = null;
        }
		return resp;
	}

	public Show removerMeio(int posicao) throws Exception{
        Celula i;
        int cont;
        Show resp;

		if(primeiro == ultimo){
			throw new Exception("Erro ao remover (vazia)!");
        }else{
            for(i = primeiro, cont = 0; (i.prox != ultimo && cont < posicao); i = i.prox, cont++);

		    if(posicao < 0 || posicao > cont + 1){
                throw new Exception("Erro ao remover (posicao " + posicao + " invalida)!");
            } else if(posicao == cont + 1){
                resp = removerFim();
            }else{
                Celula tmp = i.prox;
                resp = tmp.elemento;
                i.prox = tmp.prox;
                tmp.prox = null;
                i = tmp = null;
            }
        }

		return resp;
	}

    public Show remover(Show elemento) throws Exception{
        Show resp;
        Celula ant = primeiro;
        Celula i = primeiro.prox;

        while(i != null && i.elemento != elemento){
            ant = i;
            i = i.prox;
        }

        if(i == null){
            throw new Exception("Erro ao remover (elemento não encontrado)!");
        } else{
            resp = i.elemento;
            ant.prox = i.prox;
            if(i == ultimo){
                ultimo = ant;
            }
            i.prox = null;
        }
        return resp;
    }
}

class Hash{
    private Lista[] tabela;
    private int tamanho;
    private int ultimaPosicaoTentada;

    public Hash(){
        this(21);
    }

    public Hash(int tamanho){
        this.tamanho = tamanho;
        this.tabela = new Lista[tamanho];
        for(int i = 0; i < tamanho; i++){
            tabela[i] = new Lista();
        }
    }

    public int h(Show elemento){
        int soma = 0;
        String titulo = elemento.getTitle();
        for(int i = 0; i < titulo.length(); i++){
            soma += titulo.charAt(i);
        }
        return soma % tamanho;
    }

    public void inserir(Show elemento){
        int pos = h(elemento);
        tabela[pos].inserirInicio(elemento);
    }

    public int pesquisar(Show elemento, Log log){
        int pos = h(elemento);
        ultimaPosicaoTentada = pos;
        boolean encontrado = tabela[pos].pesquisar(elemento, log);
        return (encontrado ? pos : -1);
    }

    public int getUltimaPosicaoTentada(){
        return ultimaPosicaoTentada;
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

public class Show{
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

    public static Show Procurar(Show p[], String id){
        Show x = null;

        for(int i = 0; i < p.length && x == null; i++){
            if(p[i] != null && p[i].getShow_id().equals(id)){
                x = p[i];
            }
        }

        return x;
    }

    public static void inserirHash(Hash hash, Show p[], Scanner sc) throws Exception{
        String id = sc.nextLine();

        while(!id.equals("FIM")){
            Show novo;
            novo = Procurar(p, id);
            hash.inserir(novo);
            id = sc.nextLine();
        }
    }

    public static void procuraNaHash(Hash hash, Show[] p, Log log, Scanner sc){
        String titulo = sc.nextLine();

        while (!titulo.equals("FIM")){ 
            Show temp = new Show();
            temp.setTitle(titulo);

            int pos = hash.pesquisar(temp, log);
            System.out.println(" (Posicao: " + (pos == -1 ? hash.getUltimaPosicaoTentada() : pos) + ") " + (pos == -1 ? "NAO" : "SIM"));
            titulo = sc.nextLine(); 
        }
    }

    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        Show[] shows = new Show[1368];
        Hash hash = new Hash();
        Log log = new Log("/tmp/821811_hashIndireta.txt");

        Carregar(shows);
        inserirHash(hash, shows, sc);
        Instant start = Instant.now();
        procuraNaHash(hash, shows, log, sc);
        Instant end = Instant.now();
        long elapsedTime = Duration.between(start, end).toMillis();
        log.time = (float) elapsedTime / 1000; 
        log.registrarLog();
        sc.close();
    }
}