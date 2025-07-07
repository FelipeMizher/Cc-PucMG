
/* 
   Exemplo1300 - v0.0. - 13 / 11 / 2023 
   Author: _____Felipe Rivetti Mizher____ 
 
 */ 
 
// ----------------------------------------------- classes 
 
#include "Contato.hpp"  // classe para tratar dados de pessoas 
 
// ----------------------------------------------- definicoes globais 
 
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
   Method_01 - Testar definicoes da classe. 
 */ 
void method_01 ( ) 
{ 
 // definir dados 
    Contato       pessoa1; 
    ref_Contato pessoa2 = nullptr; 
    ref_Contato pessoa3 = new Contato ( ); 
 
 // identificar 
    cout << "\nMethod_01 - v0.0\n" << endl; 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( ) 
 
// ----------------------------------------------- acao principal 
 
/* 
  Funcao principal. 
  @return codigo de encerramento 
*/ 
int main ( int argc, char** argv ) 
{ 
 // definir dado 
    int x = 0;                // definir variavel com valor inicial 
 
 // repetir até desejar parar 
    do 
    { 
     // identificar 
        cout << "EXEMPLO1300 - Programa - v0.0\n" << endl; 
 
     // mostrar opcoes 
        cout << "Opcoes" << endl; 
        cout << " 0 - parar " << endl; 
        cout << " 1 - testar definicao de contatos (objetos) " << endl; 
 
     // ler do teclado 
        cout << endl << "Entrar com uma opcao: "; 
        cin  >> x; 
 
     // escolher acao 
        switch ( x ) 
        { 
          case 0: 
            method_00 ( ); 
           break; 
          case 1: 
            method_01 ( ); 
           break; 
          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); 
 
 // encerrar 
    pause  ( "Apertar ENTER para terminar" ); 
    return ( 0 ); 
} // end main ( ) 