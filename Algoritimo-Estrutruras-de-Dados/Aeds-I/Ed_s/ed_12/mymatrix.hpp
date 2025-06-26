/* 
   mymatrix.hpp  - v0.0. - 11 /11_ / 2023 
   Author: _________________________ 
 
 */ 
 
// ----------------------------------------------- definicoes globais 
 
#ifndef  _MYMATRIX_H_ 
#define _MYMATRIX_H_ 
 
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
 
 
template < typename T > 
class Matrix 
{ 
  private:    // area reservada 
    T   optional; 
    int rows      ; 
    int columns; 
    T** data       ; 

  public:   // area aberta 
    Matrix ( ) 
    { 
     // definir valores iniciais 
        this->rows       = 0; 
        this->columns = 0; 
     // sem reservar area 
        data                  = nullptr; 
    } // end constructor 
 
    Matrix ( int rows, int columns, T initial ) 
    { 
     // definir dado local 
        bool OK            = true; 
     // definir valores iniciais 
        this->optional = initial      ; 
        this->rows       = rows       ; 
        this->columns = columns; 
     // reservar area 
        data         = new T* [ rows ]; 
        if ( data != nullptr ) 
        { 
           for ( int x = 0; x < rows; x=x+1 ) 
           { 
              data [x] = new T  [ columns ]; 
              OK = OK && ( data [x] != nullptr ); 
           } // end for 
           if ( ! OK ) 
           { 
              data = nullptr; 
           } // end if 
        } // end if 
    } // end constructor 
 
   ~Matrix ( ) 
   { 
       if ( data != nullptr ) 
       { 
          for ( int x = 0; x < rows; x=x+1 ) 
          { 
              delete ( data [ x ] ); 
          } // end for 
          delete ( data ); 
          data = nullptr; 
       } // end if 
   } // end destructor ( ) 
 
    void set ( int row, int column, T value ) 
    { 
      if ( row       < 0 || row        >= rows      || 
           column < 0 || column >= columns ) 
      { 
         cout << "\nERROR: Invalid position.\n"; 
      } 
      else 
      { 
         data [ row ][ column ] = value; 
      } // end if 
    } // end set ( ) 
 
    T    get ( int row, int column ) 
    { 
      T value = optional; 
      if ( row       < 0 || row       >= rows       || 
           column < 0 || column >= columns ) 
      { 
         cout << "\nERROR: Invalid position.\n"; 
      } 
      else 
      { 
         value = data [ row ][ column ]; 
      } // end if 
      return ( value ); 
    } // end get ( ) 
     
    void print ( ) 
    { 
       cout << endl; 
       for ( int x = 0; x < rows; x=x+1 ) 
       { 
           for ( int y = 0; y < columns; y=y+1 ) 
           { 
               cout << data[ x ][ y ] << "\t"; 
           } // end for 
           cout << endl; 
       } // end for 
       cout << endl; 
    } // end print ( ) 
    
     void read ( ) 
    { 
       cout << endl; 
       for ( int x = 0; x < rows; x=x+1 ) 
       { 
           for ( int y = 0; y < columns; y=y+1 ) 
           { 
               cout << setw( 2 ) << x << ", " 
                        << setw( 2 ) << y << " : "; 
               cin    >> data[ x ][ y ]; 
           } // end for 
       } // end for 
       cout << endl; 
    } // end read ( ) 
    
      void fprint ( string fileName ) 
    { 
       ofstream afile; 
 
       afile.open ( fileName ); 
       afile << rows       << endl; 
       afile << columns << endl; 
       for ( int x = 0; x < rows; x=x+1 ) 
       { 
           for ( int y = 0; y < columns; y=y+1 ) 
           { 
               afile << data[ x ][ y] << endl; 
           } // end for 
       } // end for 
       afile.close ( ); 
    } // end fprint ( ) 
    
       void fread ( string fileName ) 
    { 
       ifstream afile; 
       int m = 0; 
       int n  = 0; 
 
       afile.open ( fileName ); 
       afile >> m; 
       afile >> n; 
       if ( m <= 0 || n <= 0 ) 
       { 
          cout << "\nERROR: Invalid dimensions for matrix.\n" << endl; 
       } 
       else 
       { 
        // guardar a quantidade de dados 
           rows       = m; 
           columns = n; 
        // reservar area 
           data         = new T* [ rows ]; 
           for ( int x = 0; x < rows; x=x+1 ) 
           { 
               data [x] = new T  [ columns ]; 
           } // end for 
        // ler dados 
           for ( int x = 0; x < rows; x=x+1 ) 
           { 
               for ( int y = 0; y < columns; y=y+1 ) 
               { 
                   afile >> data[ x ][ y ]; 
               } // end for 
           } // end for 
       } // end if 
       afile.close ( ); 
    } // end fread ( ) 
    
    Matrix& operator= ( const Matrix <T> &other ) 
    { 
       if ( other.rows == 0 || other.columns == 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
           this->rows        = other.rows  ; 
           this->columns = other.columns; 
           this->data         = new T* [ rows ]; 
           for ( int x = 0; x < rows; x=x+1 ) 
           { 
               this->data [ x ] = new T  [ columns ]; 
           } // end for 
           for ( int x = 0; x < this->rows; x=x+1 ) 
           { 
               for ( int y = 0; y < this->columns; y=y+1 ) 
               { 
                   data [ x ][ y ] = other.data [ x ][ y ]; 
               } // end for 
           } // end for 
       } // end if 
       return ( *this ); 
    } // end operator= ( ) 
    
    bool isZeros ( ) 
    { 
       bool result = false; 
       int x = 0; 
       int y = 0; 
       if ( rows > 0 && columns > 0 ) 
       { 
          result = true; 
          while ( x < rows && result ) 
          { 
                y = 0; 
                while ( y < columns && result ) 
                { 
                      result = result && ( data [ x ][ y ] == 0 ); 
                      y = y + 1; 
                } // end while 
                x = x + 1; 
          } // end while 
       } // end if 
       return ( result ); 
    } // end isZeros ( ) 
    
    bool operator!= ( const Matrix <T> &other ) 
    { 
       bool result = false; 
       int    x         = 0; 
       int    y         = 0; 
 
       if ( other.rows       == 0 || rows        != other.rows      || 
            other.columns == 0 || columns != other.columns ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
          x = 0; 
          while ( x < rows && ! result ) 
          { 
                y = 0; 
                while ( y < columns && ! result ) 
                { 
                      result = ( data [ x ][ y ] != other.data [ x ][ y ] ); 
                      y = y + 1; 
                } // end while 
                x = x + 1; 
          } // end while 
       } // end if 
       return ( result ); 
    } // end operator!= ( ) 
    
    Matrix& operator- ( const Matrix <T> &other ) 
    { 
       static Matrix <T> result ( 1, 1, 0 ); 
       int      x      = 0; 
       int      y      = 0; 
 
       if ( other.rows       == 0 || rows        != other.rows || 
            other.columns == 0 || columns != other.columns ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
          result.rows       = rows; 
          result.columns = other.columns; 
          result.data         = new T* [ result.rows ]; 
          for ( int x = 0; x < result.rows; x=x+1 ) 
          { 
              result.data [x] = new T  [ result.columns ]; 
          } // end for 
 
          for ( int x = 0; x < result.rows; x=x+1 ) 
          { 
              for ( int y = 0; y < result.columns; y=y+1 ) 
              { 
                  result.data [ x ][ y ] = data [ x ][ y ] - other.data [ x ][ y ]; 
              } // end for 
          } // end for 
       } // end if 
       return ( result ); 
    } // end operator- ( ) 
    
    Matrix& operator* ( const Matrix <T> &other ) 
    { 
       static Matrix <T> result ( 1, 1, 0 ); 
       int x      = 0; 
       int y      = 0; 
       int z      = 0; 
       int sum = 0; 
 
       if (           rows <= 0 ||           columns == 0 || 
            other.rows <= 0 || other.columns == 0 || 
                    columns    != other.rows                ) 
       { 
          cout << endl << "ERROR: Invalid data." << endl; 
          result.data [ 0 ][ 0 ] = 0; 
       } 
       else 
       { 
          result.rows       = rows; 
          result.columns = other.columns; 
          result.data         = new T* [ result.rows ]; 
          for ( int x = 0; x < result.rows; x=x+1 ) 
          { 
              result.data [x] = new T  [ result.columns ]; 
          } // end for 
 
          for ( x = 0; x < result.rows; x = x + 1 ) 
          { 
              for ( y = 0; y < result.columns; y = y + 1 ) 
              { 
                 sum = 0; 
                 for ( z = 0; z < columns; z = z + 1 ) 
                 { 
                     sum = sum + data [ x ][ z ] *  other.data [ z ][ y ]; 
                 } // end for 
                 result.data [ x ][ y ] = sum; 
             } // end for 
          } // end for 
       } // end if 
       return ( result ); 
    } // end operator* ( ) 
    
    const int getRows ( ) 
    { 
       return ( rows ); 
    } // end getRows ( ) 
 
    const int getColumns ( ) 
    { 
       return ( columns ); 
    } // end getColumns ( ) 
    
    void randomIntGenerate() {
        srand(static_cast<unsigned int>(time(nullptr)));
        for (int i = 0; i < rows; i = i + 1) {
            for (int j = 0; j < columns; j = j + 1) {
                data[i][j] = rand() % 100 + 1;
            }
        }
    }
    
    Matrix scalar(T constant) const {
        Matrix result(rows, columns, 0);

        for (int i = 0; i < rows; i = i + 1) {
            for (int j = 0; j < columns; j = j + 1) {
                result.set(i, j, data[i][j] * constant);
            }
        }

        return result;
    }
    
    bool isIdentify() const{
        if(rows != columns){
            return false;
        }
        for(int i = 0; i < rows; i = i + 1){
            for(int j = 0; j < columns; j = j + 1){
                if((i == j && data[i][j] != 1) || (i != j && data[i][j] != 0)){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isEqual(const Matrix <T> &other) const{
        if (rows != other.rows || columns != other.columns){  
          return false; 
       } else{
        for(int i = 0; i < rows; i = i + 1){
            for(int j = 0; j < columns; j = j + 1){
                if(data[i][j] != other.data[i][j]){
                    return false;
                    }
                }
            }
        }
      return true;
    }
    
    Matrix add(const Matrix& other) const {

    Matrix result(rows, columns, 0);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result.set(i, j, data[i][j] + other.data[i][j]);
        }
    }

        return result;
    }
    
    void addRows(int row1, int row2, T constant) {

        for (int j = 0; j < columns; j = j + 1) {
            data[row1][j] += constant * data[row2][j];
        }
    }
    
    void subtractRows(int row1, int row2, T constant) {

        for (int j = 0; j < rows; j = j + 1) {
            data[row1][j] -= constant * data[row2][j];
        }
    }
    
    int searchRows(T value){
        for(int i = 0; i < rows; i = i + 1){
            for(int j = 0; j < columns; j = j + 1){
                if(data[i][j] == value){
                    return i;
                }
            }
        }
        return -1;
    }
    
    int searchColumns(T value){
        for(int i = 0; i < rows; i = i + 1){
            for(int j = 0; j < columns; j = j + 1){
                if(data[i][j] == value){
                    return j;
                }
            }
        }
        return -1;
    }
    

    void transpose() {
        T** newData = new T*[columns];
        for (int i = 0; i < columns; ++i) {
            newData[i] = new T[rows];
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                newData[j][i] = data[i][j];
            }
        }

        std::swap(rows, columns);
        data = newData;
    }
    
    int emOrdemL() const {

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns - 1; ++j) {
                if (data[i][j] > data[i][j + 1]) {
                    return 0; 
                }
            }
        }

        return 1; 
    }
    
    int emOrdemC() const {

        for (int j = 0; j < columns; ++j) {
            for (int i = 0; i < rows - 1; ++i) {
                if (data[i][j] > data[i + 1][j]) {
                    return 0;
                }
            } 
        }
        return 1;
    }
}; // end class 
 
#endif 