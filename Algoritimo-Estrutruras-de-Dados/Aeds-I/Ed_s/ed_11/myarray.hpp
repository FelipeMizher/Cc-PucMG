// 821811 - Felipe Rivetti Mizher

/* 
   myarray.hpp   - v0.0. - 30 / 10 / 2023 
   Author: ______________________ 
*/ 
 
// ----------------------------------------------- definicoes globais 
 
#ifndef  _MYARRAY_HPP_ 
#define _MYARRAY_HPP_ 
 
// dependencias 
 
#include <iostream> 
using std::cin  ;  // para entrada 
using std::cout;  // para saida 
using std::endl;  // para mudar de linha 
 
#include <iomanip> 
using std::setw;   // para definir espacamento 
 
#include <string> 
using std::string;   // para cadeia de caracteres 
 
#include <fstream> 
using std::ofstream;   // para gravar arquivo 
using std::ifstream ;   // para ler       arquivo 
 
 
template < typename T > 
class Array 
{ 
  private:   // area reservada 
    T   optional; 
    int length; 
    T  *data; 
    
  public:   // area aberta 
    Array ( int n, T initial ) 
    { 
     // definir valores iniciais 
        optional = initial; 
        length    = 0; 
        data       = nullptr; 
 
     // reservar area 
        if ( n > 0 ) 
        { 
             length  = n; 
             data     = new T [ length ]; 
        } 
    } // end constructor 
 
    void free ( ) 
    { 
       if ( data != nullptr ) 
       { 
          delete ( data ); 
          data = nullptr; 
       } // end if 
    } // end free ( ) 
 
   void set ( int position, T value ) 
    { 
      if ( 0 <= position && position < length ) 
      { 
         data [ position ] = value; 
      } // end if 
    } // end set ( ) 
 
    T    get ( int position ) 
    { 
      T value = optional; 
 
      if ( 0 <= position && position < length ) 
      { 
        value = data [ position ]; 
      } // end if 
 
      return ( value ); 
    } // end get ( ) 
 
    void print ( ) 
    { 
       cout << endl; 
       for ( int x = 0; x < length; x=x+1 ) 
       { 
           cout << setw( 3 ) << x << " : " 
                    << setw( 9 ) << data[ x ] 
                    << endl; 
       } // end for 
       cout << endl; 
    } // end print ( ) 
    
    void read ( ) 
    { 
       cout << endl; 
       for ( int x = 0; x < length; x=x+1 ) 
       { 
           cout << setw( 3 ) << x << " : "; 
           cin   >> data[ x ]; 
       } // end for 
       cout << endl; 
    } // end read ( )
    
    void fprint ( string fileName ) 
    { 
       ofstream afile;  // output file 
 
       afile.open ( fileName ); 
       afile << length << endl; 
       for ( int x = 0; x < length; x=x+1 ) 
       { 
           afile << data[ x ] << endl; 
       } // end for 
       afile.close ( ); 
    } // end fprint ( ) 
    
     void fread ( string fileName ) 
    { 
       ifstream afile; // input file 
       int n = 0; 
       afile.open ( fileName ); 
       afile >> n; 
       if ( n <= 0 ) 
       { 
          cout << "\nERROR: Invalid length.\n" << endl; 
       } 
       else 
       { 
        // guardar a quantidade de dados 
           length  = n; 
        // reservar area 
           data    = new T [ n ]; 
        // ler dados 
           for ( int x = 0; x < length; x=x+1 ) 
           { 
              afile >> data[ x ]; 
           } // end for 
       } // end if 
       afile.close ( ); 
    } // end fread ( )
    
     Array ( )    // construtor padrao 
    { 
     // definir valores iniciais 
        length  = 0; 
     // reservar area 
        data     = nullptr; 
    } // end constructor 
 
     // contrutor baseado em copia 
    Array ( int length, int other [ ] ) 
    { 
       if ( length <= 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
        // criar copia 
           this->length = length; 
        // reservar area 
           data   = new T [ this->length ]; 
        // ler dados 
           for ( int x = 0; x < this->length; x=x+1 ) 
           { 
               data [ x ] = other [ x ]; 
           } // end for 
       } // end if 
    } // end constructor ( ) 
    
     Array ( const Array& other ) 
    { 
       if ( other.length <= 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
        // criar copia 
           length = other.length; 
        // reservar area 
           data    = new T [ other.length ]; 
        // ler dados 
           for ( int x = 0; x < length; x=x+1 ) 
           { 
               data [ x ] = other.data [ x ]; 
           } // end for 
       } // end if 
    } // end constructor ( )
    
        Array& operator= ( const Array <T> other ) 
    { 
       if ( other.length <= 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
           this->length = other.length; 
           this->data    = new T [ other.length ]; 
           for ( int x = 0; x < this->length; x=x+1 ) 
           { 
               data [ x ] = other.data [ x ]; 
           } // end for 
       } // end if 
       return ( *this ); 
    } // end operator= ( )
    
    bool operator== ( const Array <T> other )
 {
     bool result = false;
     int x = 0;
     if ( other.length == 0 || length != other.length )
     {
         cout << "\nERROR: Missing data.\n" << endl;
     }
     else
     {
         x = 0; 
         result = true;
         while ( x < this->length && result )
         {
             result = result && (data [ x ] == other.data [ x ] );
             x = x + 1;
         } // end while
     } // end if
     return ( result );
 } // end operator== ( )
    
    Array& operator+ ( const Array <T> other )
 {
     static Array <T> result ( other );
     if ( other.length <= 0 )
     {
         cout << "\nERROR: Missing data.\n" << endl;
     }
     else
     {
         for ( int x = 0; x < this->length; x=x+1 )
         {
             result.data [ x ] = result.data [ x ] + this->data [ x ];
         } // end for
     } // end if
     return ( result );
 } // end operator+ ( )
    
    const int getLength ( )
 {
     return ( length );
 } // end getLength ( )
    T& operator[]( const int position )
 {
     static T value = optional;
     if ( position < 0 || length <= position )
     {
         cout << endl << "\nERROR: Invalid position.\n" << endl;
     }
     else
     {
         value = data [ position ];
     } // end if
     return ( value );
 } // end operator [ ]

    void readN() {
        cout << "Informe a quantidade de números aleatórios (N): ";
        cin >> length;
        if (length <= 0) {
            cout << "\nERROR: N deve ser um número positivo.\n" << endl;
        } else {
            data = new T[length]; // Aloca memória para N elementos
        }
    }
    
    void randomIntGenerate(T inferior, T superior) {
        srand(static_cast<unsigned>(time(nullptr)));
        for (int i = 0; i < length; i++) {
            data[i] = (rand() % (superior - inferior + 1)) + inferior;
        }
    }
    
    T searchFirstEven() {
        T maiorPar = 0;
        bool encontrado = false;

        for (int i = 0; i < length; i++) {
            if (data[i] % 2 == 0) {
                if (!encontrado) {
                    maiorPar = data[i];
                    encontrado = true;
                } else {
                    maiorPar = (data[i] > maiorPar) ? data[i] : maiorPar;
                }
            }
        }

        if (!encontrado) {
            cout << "\nERROR: Nenhum valor par encontrado no arranjo.\n" << endl;
        }

        return maiorPar;
    }
    
    T searchFirstOdd() {
        T menorImpar = 0;
        bool encontrado = false;

        for (int i = 0; i < length; i++) {
            if (data[i] % 2 != 0) {
                if (!encontrado) {
                    menorImpar = data[i];
                    encontrado = true;
                } else {
                    menorImpar = (data[i] < menorImpar) ? data[i] : menorImpar;
                }
            }
        }

        if (!encontrado) {
            cout << "\nERROR: Nenhum valor impar encontrado no arranjo.\n" << endl;
        }

        return menorImpar;
    }

    T addInterval(int inicio, int fim) {
        T soma = 0;
        int i = 0;
        
        if (inicio >= 0 && inicio < length && fim >= 0 && fim < length && inicio <= fim) {
        for (i = inicio; i <= fim; i = i + 1) {
            soma = soma + data[i];
        }
    }

        return soma;
    }
    
    double averageInterval(int inicio, int fim) {
        double soma = 0, valor = 0;
        double media = 0;
        int i = 0;
        
        if (inicio >= 0 && inicio < length && fim >= 0 && fim < length && inicio <= fim) {
        for (i = inicio; i <= fim; i = i + 1) {
            soma = soma + data[i];
            valor = valor + 1;
        }
    }
        media = soma / valor;
        
        return media;
    }
    
    int positive(){
        int i = 0;
        
        for(i = 0; i < length; i = i + 1){
            if(data[i] <= 0){
                return 0;
            }
        }
        return 1;
    }
    
    int isCrescent(){
        int i = 0;
        
        for(i = 0; i < length; i = i + 1){
            if(data[i] > data[i + 1]){
                return 0;
            }
        }
        return 1;
    }
    
    int searchInterval(int variavel, int inicio, int fim){
        int i = 0;
        
        if (inicio >= 0 && inicio < length && fim >= 0 && fim < length && inicio <= fim) {
            for (i = inicio; i <= fim; i = i + 1) {
                if (data[i] == variavel) {
                    return 1;
                }
            }
        }
        return 0;
    }
    
    void scalar(int constante, int inicio, int fim) {
        int i = 0;
        
        if (inicio >= 0 && inicio < length && fim >= 0 && fim < length && inicio <= fim) {
            for (i = inicio; i <= fim; i++) {
                data[i] = data[i] * constante;
            }
        }
    }
    
    void printScalar(){
        int i = 0;
        
        cout << "\nArranjo escalado: \n";
        for (i = 0; i < length; i = i + 1) {
            cout << data[i] << "\n";
        }
        cout << endl;
    }
    
    void sortUp() {
        for (int i = 0; i < length - 1; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    T temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
    
    void printSortUp(){
        int i = 0;
        
        for (i = 0; i < length; i++) {
            cout << data[i] << "\n";
        }
        cout << endl;
    }
    
    bool operator!=(const Array<T>& other) const {
        if (length != other.length) {
            return true;
        }
        for (int i = 0; i < length; i++) {
            if (data[i] != other.data[i]) {
                return true; 
            }
        }
        return false; 
    }
    
    Array<T> calculateDifferences(const Array<T>& other) const {
        if (length != other.length) {
            cout << "Os arranjos têm tamanhos diferentes." << endl;
            return *this; 
        }
    Array<T> differences(length, T());
        for (int i = 0; i < length; i++) {
            differences.data[i] = data[i] - other.data[i];
        }

        return differences;
    }
}; 
 
#endif 