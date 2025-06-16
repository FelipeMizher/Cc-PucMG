// 821811 - Felipe Rivetti Mizher

/* 
   Exemplo1201 - v0.0. - 30 / 10 / 2023 
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
        cout << "EXEMPLO1201 - Programa - v0.0\n    " << endl; 
 
     // mostrar opcoes 
        cout << "Opcoes        " << endl; 
        cout << " 0 - parar       " << endl; 
        cout << " 1 - method_01 " << endl; 
        cout << " 2 - method_02 " << endl; 
        /**cout << " 3 - method_03 " << endl; 
        cout << " 4 - method_04 " << endl; 
        cout << " 5 - method_05 " << endl; 
        cout << " 6 - method_06 " << endl; 
        cout << " 7 - method_07 " << endl; 
        cout << " 8 - method_08 " << endl; 
        cout << " 9 - method_09 " << endl; 
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
          /**case 3:   method_03 ( );   break; 
          case 4:   method_04 ( );   break; 
          case 5:   method_05 ( );   break; 
          case 6:   method_06 ( );   break; 
          case 7:   method_07 ( );   break; 
          case 8:   method_08 ( );   break; 
          case 9:   method_09 ( );   break; 
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
