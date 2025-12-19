class Contato{
    String nome;
    String telefone;
    String email;
    String cpf;

    public Contato(){
        this("", "", "", "");
    }

    public Contato(String nome, String telefone, String email, String cpf){
        this.nome = nome;
        this.telefone = telefone;
        this.email = email;
        this.cpf = cpf;
    }

    public String getNome(){
        return nome;
    }
    public void setNome(String nome){
        this.nome = nome;
    }

    public String getTelefone(){
        return telefone;
    }
    public void setTelefone(String telefone){
        this.telefone = telefone;
    }

    public String getEmail(){
        return email;
    }
    public void setEmail(String email){
        this.email = email;
    }

    public String getCpf(){
        return cpf;
    }
    public void setCpf(String cpf){
        this.cpf = cpf;
    }
}

public class Agenda{
    private No raiz;

    private class No{
        public char letra;
        public No esq, dir;
        public Celula primeiro, ultimo;

        public No(char letra){
            this.letra = letra;
            this.esq = this.dir = null;
            primeiro = ultimo = new Celula(null);
        }
    }

    private class Celula{
        Contato contato;
        Celula prox;

        public Celula(Contato contato){
            this.contato = contato;
            prox = null;
        }
    }

    public Agenda(){
        construirNos();
    }

    private void construirNos(){
        char[] letrasBalanceadas = {
                'N', 'G', 'T',
                'D', 'J', 'Q', 'W',
                'B', 'F', 'H', 'L', 'O', 'R', 'U', 'X',
                'A', 'C', 'E', 'I', 'K', 'M', 'P', 'S', 'V', 'Y', 'Z'
        };

        for(char c : letrasBalanceadas){
            raiz = inserirNo(raiz, c);
        }
    }

    private No inserirNo(No no, char letra){
        if(no == null){
            no = new No(letra);
        } else if(letra < no.letra){
            no.esq = inserirNo(no.esq, letra);
        } else if(letra > no.letra){
            no.dir = inserirNo(no.dir, letra);
        }
        return no;
    }

    private No pesquisarNo(char letra){
        No no = raiz;
        while(no != null){
            if(letra == no.letra){
                return no;
            } else if(letra < no.letra){
                no = no.esq;
            } else{
                no = no.dir;
            }
        }
        return null;
    }

    public void inserir(Contato contato) throws Exception{
        if(contato.getNome() == null || contato.getNome().isEmpty()){
            throw new Exception("Nome inválido");
        }
        inserir(raiz, contato);
    }

    private void inserir(No no, Contato contato){
        if(no != null){
            char inicial = Character.toUpperCase(contato.nome.charAt(0));
            if(inicial == no.letra){
                no.ultimo.prox = new Celula(contato);
                no.ultimo = no.ultimo.prox;
            } else if(inicial < no.letra){
                inserir(no.esq, contato);
            } else{
                inserir(no.dir, contato);
            }
        }
    }

    public Contato remover(String nome){
        No no = pesquisarNo(Character.toUpperCase(nome.charAt(0)));
        if (no == null) return null;

        Celula atual = no.primeiro.prox;
        Celula anterior = no.primeiro;

        while(atual != null && !nome.equals(atual.contato.getNome())){
            anterior = atual;
            atual = atual.prox;
        }

        if(atual != null){
            Contato removido = atual.contato;
            anterior.prox = atual.prox;
            if(atual == no.ultimo){
                no.ultimo = anterior;
            }
            return removido;
        }
        return null;
    }

    public Contato pesquisar(String nome){
        No no = pesquisarNo(Character.toUpperCase(nome.charAt(0)));
        if(no != null){
            for(Celula c = no.primeiro.prox; c != null; c = c.prox){
                if(nome.equals(c.contato.getNome())){
                    return c.contato;
                }
            }
        }
        return null;
    }

    public Contato pesquisarCPF(String cpf){
        return pesquisarCPF(raiz, cpf);
    }

    private Contato pesquisarCPF(No no, String cpf){
        if(no != null){
            for(Celula c = no.primeiro.prox; c != null; c = c.prox){
                if(cpf.equals(c.contato.getCpf())){
                    return c.contato;
                }
            }

            Contato achadoEsq = pesquisarCPF(no.esq, cpf);
            if (achadoEsq != null) return achadoEsq;

            Contato achadoDir = pesquisarCPF(no.dir, cpf);
            if (achadoDir != null) return achadoDir;
        }
        return null;
    }

    public static void main(String[] args) throws Exception{
        Agenda agenda = new Agenda();

        agenda.inserir(new Contato("Felipe", "1234", "felipe@email.com", "111.111.111-11"));
        agenda.inserir(new Contato("Gabriela", "5678", "gabriela@email.com", "222.222.222-22"));
        agenda.inserir(new Contato("Carlos", "4321", "carlos@email.com", "333.333.333-33"));

        Contato encontrado = agenda.pesquisar("Felipe");
        if(encontrado != null){
            System.out.println("Nome encontrado: " + encontrado.getNome());
        } else{
            System.out.println("Nome não encontrado.");
        }

        Contato porCpf = agenda.pesquisarCPF("222.222.222-22");
        if(porCpf != null){
            System.out.println("Contato pelo CPF: " + porCpf.getNome());
        } else{
            System.out.println("CPF não encontrado.");
        }

        Contato removido = agenda.remover("Carlos");
        if(removido != null){
            System.out.println("Removido: " + removido.getNome());
        }

        Contato falhaBusca = agenda.pesquisar("Carlos");
        if (falhaBusca == null){
            System.out.println("Carlos não está mais na agenda.");
        }
    }
}
