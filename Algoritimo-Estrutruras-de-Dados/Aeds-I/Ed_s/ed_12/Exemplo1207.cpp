// 821811 - Felipe Rivetti Mizher

/* 
   Exemplo1207 - v0.0. - 30 / 10 / 2023 
   Author: ______Felipe Rivetti Mizher______ 
 
 */ 
// dependencias 
#include <iostream> // std::cin, std::cout, std:endl 
#include <limits> // std::numeric_limits 
#include <string> // para cadeias de caracteres 
 
// ----------------------------------------------- definicoes globais 
 
void pause ( std::string text ) 
{ 
    std::string dummy; 
    std::cin.clear ( ); 
    std::cout << std::endl << text; 
    std::cin.ignore( ); 
    std::getline(std::cin, dummy); 
    std::cout << std::endl << std::endl; 
} // end pause ( ) 
 
 
// ----------------------------------------------- classes / pacotes 
 
#include "mymatrix.hpp" 
 
using namespace std; 
 
// ----------------------------------------------- metodos 
 
/** 
   Method_00 - nao faz nada. 
 */ 
void method_00 ( ) 
{ 
 // nao faz nada 
} // end method_00 ( )  
    
/** 
   Method_01 - Mostrar certa quantidade de valores. 
 */ 
void method_01 ( ) 
{ 
 // definir dados 
    Matrix <int> int_matrix ( 2, 2, 0 ); 
 
    int_matrix.set ( 0, 0, 1 ); int_matrix.set ( 0, 1, 2 ); 
    int_matrix.set ( 1, 0, 3 ); int_matrix.set ( 1, 1, 4 ); 
 
 // identificar 
    cout << "\nMethod_01 - v0.0\n" << endl; 
 
 // mostrar dados 
    int_matrix.print ( ); 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( )

/** 
   Method_02. 
 */ 
void method_02 ( ) 
{ 
 // definir dados 
    Matrix <int> matrix ( 2, 2, 0 ); 
 
 // identificar 
    cout << endl << "Method_02 - v0.0" << endl; 
 
 // ler dados 
    matrix.read  ( ); 
 
 // mostrar dados 
    matrix.print ( ); 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_02 ( ) 

/** 
   Method_03. 
 */ 
void method_03 ( ) 
{ 
 // definir dados 
    Matrix <int> matrix ( 2, 2, 0 ); 
 
 // identificar 
    cout << endl << "Method_03 - v0.0" << endl; 
 
 // ler dados 
    matrix.read  ( ); 
 
 // mostrar dados 
    matrix.print ( ); 
 
 // gravar  dados 
    matrix.fprint( "MATRIX1.TXT" ); 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_03 ( ) 

/** 
   Method_04. 
 */ 
void method_04 ( ) 
{ 
 // definir dados 
    Matrix <int> matrix ( 1, 1, 0 ); 
 
 // identificar 
    cout <<  endl << "Method_04 - v0.0" << endl; 
 
 // ler dados 
    matrix.fread  ( "MATRIX1.TXT" ); 
 
 // mostrar dados 
    matrix.print ( ); 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_04 ( ) 

/** 
   Method_05. 
 */ 
void method_05 ( ) 
{ 
 // definir dados 
    Matrix <int> int_matrix1 ( 1, 1, 0 ); 
    Matrix <int> int_matrix2 ( 1, 1, 0 ); 
 
 // identificar 
    cout << endl << "Method_05 - v0.0" << endl; 
 
 // ler dados 
    int_matrix1.fread ( "MATRIX1.TXT" ); 
 
 // mostrar dados 
    cout << "\nOriginal\n" << endl; 
    int_matrix1.print ( ); 
 
 // copiar  dados 
    int_matrix2 = int_matrix1; 
 
 // mostrar dados 
    cout << "\nCopia\n" << endl; 
    int_matrix2.print ( ); 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_05 ( ) 

/** 
   Method_06. 
 */ 
void method_06 ( ) 
{ 
 // definir dados 
    Matrix <int> int_matrix ( 2, 2, 0 ); 
 
    int_matrix.set ( 0, 0, 0 );    int_matrix.set ( 0, 1, 0 ); 
    int_matrix.set ( 1, 0, 0 );    int_matrix.set ( 1, 1, 0 ); 
 
 // identificar 
    cout << endl << "Method_06 - v0.0" << endl; 
 
 // mostrar dados 
    int_matrix.print ( ); 
 
 // testar  condicao 
    cout << "Zeros = " << int_matrix.isZeros ( ) << endl; 
 
 // ler dados 
    int_matrix.fread ( "MATRIX1.TXT" ); 
 
 // mostrar dados 
    int_matrix.print ( ); 
 
 // testar  condicao 
    cout << "Zeros = " << int_matrix.isZeros ( ) << endl; 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_06 ( ) 

/** 
   Method_07. 
 */ 
void method_07 ( ) 
{ 
 // definir dados 
    Matrix <int> int_matrix1 ( 1, 1, 0 ); 
    Matrix <int> int_matrix2 ( 1, 1, 0 ); 
 
 // identificar 
    cout << endl << "Method_07 - v0.0" << endl; 
 
 // ler dados 
    int_matrix1.fread ( "MATRIX1.TXT" ); 
 
 // mostrar dados 
    cout << "\nMatrix_1\n"; 
    int_matrix1.print ( ); 
 
 // copiar  dados 
    int_matrix2 = int_matrix1; 
 
 // mostrar dados 
    cout << "\nMatrix_2\n"; 
    int_matrix2.print ( ); 
 
 // testar  condicao 
    cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl; 
 
 // alterar dados 
    int_matrix2.set ( 0, 0, (-1) ); 
 
 // mostrar dados 
    cout << "\nMatrix_1\n"; 
    int_matrix1.print ( ); 
 
 // mostrar dados 
    cout << "\nMatrix_2\n"; 
    int_matrix2.print ( ); 
 
 // testar  condicao 
    cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl; 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_07 ( ) 

/** 
   Method_08. 
 */ 
void method_08 ( ) 
{ 
 // definir dados 
    Matrix <int> int_matrix1 ( 1, 1, 0 ); 
    Matrix <int> int_matrix2 ( 1, 1, 0 ); 
    Matrix <int> int_matrix3 ( 1, 1, 0 ); 
 
 // identificar 
    cout << endl << "Method_08 - v0.0" << endl; 
 
 // ler dados 
    int_matrix1.fread ( "MATRIX1.TXT" ); 
 
 // mostrar dados 
    cout << "\nMatrix_1\n"; 
    int_matrix1.print ( ); 
 
 // copiar  dados 
    int_matrix2 = int_matrix1; 
 
 // mostrar dados 
    cout << "\nMatrix_2\n"; 
    int_matrix2.print ( ); 
 
 // operar  dados 
    int_matrix3 = int_matrix1 - int_matrix2; 
 
 // mostrar dados 
    cout << "\nMatrix_3\n"; 
    int_matrix3.print ( ); 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_08 ( )
 
/* 
  Funcao principal. 
  @return codigo de encerramento 
*/ 
int main ( int argc, char** argv ) 
{ 
 // definir dado 
    int x = 0;   // definir variavel com valor inicial 
 
 // repetir até desejar parar 
    do 
    { 
     // identificar 
        cout << "EXEMPLO1207 - Programa - v0.0\n    " << endl; 
 
     // mostrar opcoes 
        cout << "Opcoes        " << endl; 
        cout << " 0 - parar       " << endl; 
        cout << " 1 - method_01 " << endl; 
        cout << " 2 - method_02 " << endl; 
        cout << " 3 - method_03 " << endl; 
        cout << " 4 - method_04 " << endl; 
        cout << " 5 - method_05 " << endl; 
        cout << " 6 - method_06 " << endl; 
        cout << " 7 - method_07 " << endl; 
        cout << " 8 - method_08 " << endl; 
        /**cout << " 9 - method_09 " << endl; 
        cout << "10 - method_10 " << endl; */
 
     // ler do teclado 
        cout << endl << "Entrar com uma opcao: "; 
        cin  >> x; 
 
 
     // escolher acao 
        switch ( x ) 
        { 
          case 0:   method_00 ( );   break; 
          case 1:   method_01 ( );   break; 
          case 2:   method_02 ( );   break; 
          case 3:   method_03 ( );   break; 
          case 4:   method_04 ( );   break; 
          case 5:   method_05 ( );   break; 
          case 6:   method_06 ( );   break; 
          case 7:   method_07 ( );   break; 
          case 8:   method_08 ( );   break; 
          /**case 9:   method_09 ( );   break; 
          case 10:  method_10 ( );   break;*/ 
          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); 
 
 // encerrar 
    pause  ( "Apertar ENTER para terminar" ); 
    return ( 0 ); 
} // end main ( ) 
