/* 
   Contato.hpp  - v0.0. - 13 / 11 / 2023 
   Author: ______Felipe Rivetti Mizher______ 
 
 */ 
 
// ----------------------------------------------- definicoes globais 
 
#ifndef  _CONTATO_H_ 
#define _CONTATO_H_ 
 
// dependencias 
 
#include <iostream> 
using std::cin  ;  // para entrada 
using std::cout;   // para saida 
using std::endl;  // para mudar de linha 
 
#include <iomanip> 
using std::setw;  // para definir espacamento 
 
#include <string> 
using std::string;  // para cadeia de caracteres 
 
#include <fstream> 
using std::ofstream;  // para gravar arquivo 
using std::ifstream;   // para ler    arquivo 
 
// outras dependencias 
 
void pause ( std::string text ) 
{ 
    std::string dummy; 
    std::cin.clear ( ); 
    std::cout << std::endl << text; 
    std::cin.ignore( ); 
    std::getline(std::cin, dummy); 
    std::cout << std::endl << std::endl; 
} // end pause ( ) 
 
#include "Erro.hpp" 
 
// ----------------------------------------------  definicao de classe 
 
/** 
  * Classe para tratar contatos, derivada da classe Erro. 
  */ 
class Contato : public Erro 
{ 
  /** 
    * atributos privados. 
    */ 
    private: 
      string nome; 
      string fone; 
      string fone2;
     
    static const int MAX_TELEFONES = 10;
    string telefones[MAX_TELEFONES];
    int numTelefones;
    string enderecoResidencial;
    string enderecoProfissional;
     
     int isTelefoneValido(string telefone)
    {
        for (char c : telefone)
        {
            // Testar se as posições contêm apenas algarismos e o símbolo '-'
            if (!isdigit(c) && c != '-')
            {
                return 1; // O telefone é inválido
            }
        }
        return 0; // O telefone é válido
    }
 
  /** 
    * definicoes publicas. 
    */ 
    public: 
    /** 
      * Destrutor. 
      */ 
     ~Contato ( ) 
       { } 
 
    /** 
      * Construtor padrao. 
      */ 
      Contato ( ) 
      { 
       // atribuir valores iniciais vazios 
          nome   = ""; 
          fone   = ""; 
          fone2  = "";
      } // end constructor (padrao) 
      
      // ----------------------------------- metodos para acesso 
 
    /** 
      * Metodo para atribuir nome. 
      * @param nome a ser atribuido 
      */ 
      void setNome ( std::string nome ) 
      { 
        if ( nome.empty ( ) ) 
           setErro ( 1 ); // nome invalido 
        else 
        this->nome = nome; 
      } // end setNome ( ) 
 
    /** 
      * Metodo para atribuir telefone. 
      * @param fone a ser atribuido 
      */ 
      void setFone ( std::string fone ) 
      { 
        if ( fone.empty ( ) ) 
           setErro ( 2 ); // fone invalido 
        else 
        this->fone = fone; 
      } // end setFone ( ) 
 
     void setFone2( std::string fone2 )
     {
        if(fone2.empty ( ) )
            setErro ( 2 );
        else
        this->fone2 = fone2;
     } // end setFone2 ( )
 
    /** 
      * Funcao para obter nome. 
      * @return nome armazenado 
      */ 
      std::string getNome ( ) 
      { 
        return ( this->nome ); 
      } // end getNome ( ) 
 
    /** 
      * Funcao para obter fone. 
      * @return fone armazenado 
      */ 
      std::string getFone ( ) 
      { 
        return ( this->fone ); 
      } // end getFone ( )
      
      std::string getFone2 ( ) 
      { 
        return ( this->fone2 ); 
      } // end getFone2 ( )
      
       /** 
      * Funcao para obter dados de uma pessoa. 
      * @return dados de uma pessoa 
      */ 
      std::string toString ( ) 
      { 
        return ( "{ "+getNome( )+", "+getFone( )+" }" ); 
      } // end toString ( ) 
      
      /** 
      * Construtor alternativo. 
      * @param nome_inicial a ser atribuido 
      * @param fone_inicial   a ser atribuido 
      */ 
      Contato(std::string nome_inicial, std::string fone_inicial, std::string fone2_inicial)
      {
        setErro(0); // nenhum erro, ainda

        setNome(nome_inicial);
        setFone(fone_inicial);
        setFone2(fone2_inicial);
      } // end constructor (alternativo)
      
 /** 
    * indicar a existencia de erro. 
 */ 
  bool hasErro ( ) 
  { 
     return ( getErro( ) != 0 ); 
  } // end hasErro ( ) 
  
 /** 
    * Construtor alternativo baseado em copia. 
 */ 
      Contato ( Contato const & another ) 
      { 
       // atribuir valores iniciais por copia 
          setErro ( 0 );                         // copiar erro 
          setNome  ( another.nome   ); // copiar nome 
          setFone  ( another.fone   ); // copiar fone
          setFone2 ( another.fone2  ); // copiar fone2
      } // end constructor (alternativo)

    void testReadName(char* name)
    { 

        if (nome[0] == '\n')
        {
            cout << "\nNome inválido." << endl;
        }
        else
        {
            cout << "\nNome lido: " << name << endl;
        }
    }
    
    void readPhone(char* numero)
    { 

        if (numero[0] == '\n')
        {
            cout << "\nNumero inválido." << endl;
        }
        else
        {
            cout << "\nNumero lido: " << numero << endl;
        }
    }
    
    void testTelefone(char* telefone)
    {

        if (isTelefoneValido(telefone) == 0)
        {
            cout << "\nNúmero de telefone válido: " << telefone << endl;
        }
        else
        {
            cout << "\nNúmero de telefone inválido." << endl;
        }
    }
    
    void readFromFile(string fileName)
    {
        ifstream arquivo(fileName);

        if (arquivo.is_open())
        {
            getline(arquivo, nome);
            getline(arquivo, fone);

            arquivo.close(); 
            setErro(0); 
        }
        else
        {
            setErro(1); // Erro ao abrir o arquivo
        }
    }
    
    void testReadFromFile(string fileName)
    {
        readFromFile(fileName);

        if (hasErro())
        {
            cout << "Erro: Não foi possível ler dados do arquivo." << endl;
        }
        else
        {
            cout << "Dados lidos do arquivo: " << endl;
            cout << "Nome: " << nome << endl;
            cout << "Telefone: " << fone << endl;
        }
    }
    
    void writeToFile(string fileName)
    {
        ofstream arquivo(fileName);

            arquivo << nome << endl;
            arquivo << fone << endl;

        arquivo.close();
            
    }
    
        void testDoisTelefones()
    {
        cout << "Nome: " << getNome() << endl;
        cout << "Telefone 1: " << getFone() << endl;

        if (!getFone2().empty())
        {
            cout << "Telefone 2: " << getFone2() << endl;
        }
        else
        {
            cout << "Segundo telefone não válido." << endl;
        }
    }
    
    int getNumTelefones() const {
    return numTelefones;
    }

    void testNumTelefones() const {
        cout << "Número de telefones associados ao contato: " << getNumTelefones() << endl;
    }
    
    void setFone2a(std::string fone2a) {
        if (fone2a.empty()) {
            setErro(2); // fone2a inválido
        } else {
            // Verificar se já existe um segundo telefone
            if (!fone2.empty()) {
                cout << "Você já possui um segundo telefone. Deseja substituir? (S/N): ";
                char resposta;
                cin >> resposta;
                if (toupper(resposta) == 'N') {
                    return; // 
                }
            }
            fone2 = fone2a;
            setErro(0); 
        }
    }
    
    void testSetFone2a(std::string fone2a) {
        setFone2a(fone2a);

        if (hasErro()) {
            cout << "Erro ao atribuir segundo telefone." << endl;
        } else {
            testDoisTelefones();
        }
    }
    
    void setFone2b(std::string fone2b) {
        if (fone2b.empty()) {
            setErro(2); 
        } else {
            if (fone2.empty()) {
                setErro(3); 
            } else {
                fone2 = fone2b;
                setErro(0); 
            }
        }
    }
    
    void testSetFone2b(std::string fone2b) {
        setFone2b(fone2b);

        if (hasErro()) {
            if (getErro() == 3) {
                cout << "Erro: Não há segundo telefone para alterar." << endl;
            } else {
                cout << "Erro ao alterar o valor do segundo telefone." << endl;
            }
        } else {
            testDoisTelefones();
        }
    }
    
    void setFone2c(){
        if (fone2.empty()) {
            setErro(3);
        } else {
            fone2.clear();
            setErro(0);
        }
    }
    
    void testSetFone2c() {
        setFone2c();

        if (hasErro()) {
            if (getErro() == 3) {
                cout << "Erro: Não há segundo telefone para remover." << endl;
            } else {
                cout << "Erro ao remover o valor do segundo telefone." << endl;
            }
        } else {
           testDoisTelefones();
        }
    }
    
    void setTelefone(string telefone) {
        if (numTelefones < MAX_TELEFONES) {
            telefones[numTelefones++] = telefone;
            setErro(0);
        } else {
            setErro(4); 
        }
    }

    void addTelefone(string telefone)
    {
        if (numTelefones < MAX_TELEFONES)
        {
            telefones[numTelefones++] = telefone;
        }
    }

    string getTelefone(int indice) const
    {
        if (indice >= 0 && indice < numTelefones)
        {
            return telefones[indice];
        }
        return "";
    }

    void testQuantidadeTelefones() const
    {
        for (int i = 0; i < getNumTelefones(); ++i)
        {
            cout << "Telefone " << i + 1 << ": " << getTelefone(i) << endl;
        }
    }

    void setEnderecoResidencial(string endereco)
    {
        enderecoResidencial = endereco;
    }

    void setEnderecoProfissional(string endereco)
    {
        enderecoProfissional = endereco;
    }

    string getEnderecoResidencial() const
    {
        return enderecoResidencial;
    }

    string getEnderecoProfissional() const
    {
        return enderecoProfissional;
    }

    void testEnderecos() const
    {
        cout << "Endereço Residencial: " << getEnderecoResidencial() << endl;
        cout << "Endereço Profissional: " << getEnderecoProfissional() << endl;
    }
 
}; // fim da classe Contato 
 
using ref_Contato = Contato*;  // similar a typedef Contato* ref_Contato; 
 
#endif 