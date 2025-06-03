// 821811 - Felipe Rivetti Mizher

/* 
   Exemplo1105 - v0.0. - 30 / 10 / 2023 
   Author: ________________________ 
 
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
 
#include "myarray.hpp" 
 
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
    Array  <int> int_array ( 5, 0 ); 
 
    int_array.set ( 0, 1 ); 
    int_array.set ( 1, 2 ); 
    int_array.set ( 2, 3 ); 
    int_array.set ( 3, 4 ); 
    int_array.set ( 4, 5 ); 
 
 // identificar 
    cout << "\nMethod_01 - v0.0\n" << endl; 
 
 // mostrar dados 
    int_array.print ( ); 
 
 // reciclar espaco 
    int_array.free ( );  
 
// encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( ) 
 
/** 
   Method_02. 
 */ 
void method_02 ( ) 
{ 
 // definir dados 
    Array  <int> int_array ( 5, 0 ); 
 
 // identificar 
    cout <<  endl << "Method_02 - v0.0" << endl; 
 
 // ler dados 
    int_array.read  ( ); 
 
 // mostrar dados 
    int_array.print ( ); 
 
 // reciclar espaco 
    int_array.free ( );  
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_02 ( )  
 
/** 
   Method_03. 
 */ 
void method_03 ( ) 
{ 
 // definir dados 
    Array  <int> int_array ( 5, 0 ); 
 
 // identificar 
    cout <<  endl << "Method_03 - v0.0" << endl; 
 
 // ler dados 
    int_array.read  ( ); 
 
 // mostrar dados 
    int_array.fprint ( "INT_ARRAY1.TXT" ); 
 
 // reciclar espaco 
    int_array.free ( );  
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_03 ( )  

/** 
   Method_04. 
 */ 
void method_04 ( ) 
{ 
 // definir dados 
    Array  <int> int_array ( 5, 0 ); 
 
 // identificar 
    cout <<  endl << "Method_04 - v0.0" << endl; 
 
 // ler dados 
    int_array.fread ( "INT_ARRAY1.TXT" ); 
 
 // mostrar dados 
    int_array.print ( ); 
 
 // reciclar espaco 
    int_array.free ( );  
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_04 ( ) 
 
/** 
   Method_05. 
 */ 
void method_05 ( ) 
{ 
 // definir dados 
    int other [ ] = { 1, 2, 3, 4, 5 }; 
    Array  <int> int_array ( 5, other ); 
 
 // identificar 
    cout <<  endl << "Method_05 - v0.0" << endl; 
 
 // mostrar dados 
    cout << "\nCopia\n" << endl; 
    int_array.print (  ); 
 
 // reciclar espaco 
    int_array.free ( );  
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_05 ( ) 
 
/** 
   Method_06. 
 */ 
void method_06 ( ) 
{ 
 // definir dados 
    Array  <int> int_array1 ( 1, 0 ); 
 
 // identificar 
    cout <<  endl << "Method_06 - v0.0" << endl; 
 
 // ler dados 
    int_array1.fread ( "INT_ARRAY1.TXT" ); 
 
 // mostrar dados 
    cout << "\nOriginal\n" << endl; 
    int_array1.print ( ); 
 
 // criar   copia 
    Array <int> int_array2 ( int_array1 ); 
 
 // mostrar dados 
    cout << "\nCopia\n" << endl; 
    int_array2.print ( ); 
 
 // reciclar espaco 
    int_array1.free ( );  
    int_array2.free ( );  
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_06 ( ) 
 
/** 
   Method_07. 
 */ 
void method_07 ( ) 
{ 
 // identificar 
    cout <<  endl << "Method_07 - v0.0" << endl; 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_07 ( ) 
 
/** 
   Method_08. 
 */ 
void method_08 ( ) 
{ 
 // identificar 
    cout <<  endl << "Method_08 - v0.0" << endl; 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_08 ( ) 
 
/** 
   Method_09. 
 */ 
void method_09 ( ) 
{ 
 // identificar 
    cout <<  endl << "Method_09 - v0.0" << endl; 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_09 ( ) 
 
 
/** 
   Method_10. 
 */ 
void method_10 ( ) 
{ 
 // identificar 
    cout <<  endl << "Method_10 - v0.0" << endl; 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_10 ( ) 
 
// ----------------------------------------------- acao principal 
 
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
        cout << "EXEMPLO1105 - Programa - v0.0\n    " << endl; 
 
     // mostrar opcoes 
        cout << "Opcoes        " << endl; 
        cout << " 0 - parar       " << endl; 
        cout << " 1 - mostrar dados inteiros em arranjo " << endl; 
        cout << " 2 - pedir e mostrar dados inteiros em arranjo " << endl; 
        cout << " 3 - salvar o array em arquivo " << endl; 
        cout << " 4 - ler o array do arquivo " << endl; 
        cout << " 5 - copiar array " << endl; 
        cout << " 6 - criar nova copia " << endl; 
        cout << " 7 -        " << endl; 
        cout << " 8 -        " << endl; 
        cout << " 9 -        " << endl; 
        cout << "10 -        " << endl; 
 
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
          case 9:   method_09 ( );   break; 
          case 10:  method_10 ( );   break; 
          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); 
 
 // encerrar 
    pause  ( "Apertar ENTER para terminar" ); 
    return ( 0 ); 
} // end main ( ) 
