// 821811 - Felipe Rivetti Mizher

/* 
   Exemplo1117 - v0.0. - 30 / 10 / 2023 
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
 // definir dados 
    Array  <int> int_array1 ( 1, 0 ); 
    Array  <int> int_array2 ( 1, 0 ); 
 
 // identificar 
    cout << endl << "Method_07 - v0.0" << endl; 
 
 // ler dados 
    int_array1.fread ( "INT_ARRAY1.TXT" ); 
 
 // mostrar dados 
    cout << "\nOriginal\n" << endl; 
    int_array1.print ( ); 
 
 // copiar  dados 
    int_array2 = int_array1; 
 
 // mostrar dados 
    cout << "\nCopia\n" << endl; 
    int_array2.print ( ); 
 
 // reciclar espaco 
    int_array1.free ( );  
    int_array2.free ( );  
 
// encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_07 ( ) 
 
/**
 Method_08.
*/
void method_08 ( )
{
 // definir dados
    int other [ ] = { 1, 2, 3 };
    Array <int> int_array1 ( 3, other );
    Array <int> int_array2 ( 3, other );
    int x;
    
 // identificar
    cout << endl << "Method_08 - v0.0" << endl;
    
 // mostrar dados
    cout << endl;
    cout << "Array_1";
    int_array1.print ( );
    
 // mostrar dados
    cout << "Array_2";
    int_array2.print ( );
    
 // mostrar comparacao
    cout << "Igualdade = " << (int_array1==int_array2) << endl;
    
 // alterar dado
    int_array2.set ( 0, (-1) );
    
 // mostrar dados
    cout << endl;
    cout << "Array_1" << endl;
    int_array1.print ( );
 
    cout << "Array_2" << endl;
    int_array2.print ( );
    
 // mostrar comparacao
    cout << "Igualdade = " << (int_array1==int_array2) << endl;
    
 // reciclar espaco
    int_array1.free ( ); 
    int_array2.free ( ); 
    
 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_08 ( ) 
 
/**
 Method_09.
*/
void method_09 ( )
{
 // definir dados
    Array <int> int_array1 ( 1, 0 );
    Array <int> int_array2 ( 1, 0 );
    Array <int> int_array3 ( 1, 0 );
    
 // identificar
    cout << endl << "EXEMPLO1110 - Method_09 - v0.0" << endl;
    
 // ler dados
    int_array1.fread ( "INT_ARRAY1.TXT" );
    
 // copiar dados
    int_array2 = int_array1;
    
 // somar dados
    int_array3 = int_array2 + int_array1;
    
 // mostrar dados
    cout << endl;
    cout << "Original" << endl;
    int_array1.print ( );
    
 // mostrar dados
    cout << "Copia" << endl;
    int_array2.print ( );
    
 // mostrar dados
    cout << "Soma" << endl;
    int_array3.print ( );
    
 // reciclar espaco
    int_array1.free ( ); 
    int_array2.free ( ); 
    int_array3.free ( ); 
    
 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_09 ( ) 
 
/**
 Method_10.
*/
void method_10 ( )
{
 // definir dados
    int other [ ] = { 1, 2, 3, 4, 5 };
    Array <int> int_array ( 5, other );
    int x;
    
 // identificar
    cout << endl << "Method_10 - v0.0" << endl;
    
 // mostrar dados
    cout << "\nAcesso externo" << endl;
    for ( x=0; x<int_array.getLength( ); x=x+1 )
    {
    cout << endl << setw( 3 ) << x << " : " << int_array [ x ];
    } // fim repetir
    cout << endl << "\nFora dos limites:";
    cout << endl << "[-1]: " << int_array.get(-1) << endl;
    cout << endl << "[" << int_array.getLength( ) << "]: " 
    << int_array [ int_array.getLength( ) ] << endl;
    
 // reciclar espaco
    int_array.free ( ); 
    
 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

/**
 Method_11.
*/
void method_11 ( )
{
 // definir dados
    Array <int> int_array;
    int inferior = 1;
    int superior = 100;
    
 // identificar
    cout << endl << "Method_11 - v0.0" << endl;
    
 // pedir dados
    int_array.readN();
    int_array.randomIntGenerate(inferior, superior);
    
 // mostrar dados
    int_array.fprint ( "DADOS.TXT" );
    
 // reciclar espaco
    int_array.free ( ); 
    
 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_11 ( )

/**
 Method_12.
*/
void method_12 ( )
{
 // definir dados
    Array <int> int_array;
    int maior = 0;
    
 // identificar
    cout << endl << "Method_12 - v0.0" << endl;
    
 // ler o arquivo com o array
    int_array.fread( "DADOS.TXT" );
    
 // ver qual o maior numero par e mostrar ele
    maior = int_array.searchFirstEven ( );
        
    if (maior % 2 != 0) {
        cout << "\nNenhum valor par encontrado no arranjo." << endl;
    } else {
        cout << "\nMaior valor par encontrado: " << maior << endl;
    }
    
 // reciclar espaco
    int_array.free ( ); 
    
 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_12 ( )

/**
 Method_13.
*/
void method_13 ( )
{
 // definir dados
    Array <int> int_array;
    int menor = 0;
    
 // identificar
    cout << endl << "Method_13 - v0.0" << endl;
    
 // ler o arquivo com o array
    int_array.fread( "DADOS.TXT" );
    
 // ver qual o menor numero impar e mostrar ele
    menor = int_array.searchFirstOdd ( );
        
    if (menor % 2 == 0) {
        cout << "\nNenhum valor par encontrado no arranjo." << endl;
    } else {
        cout << "\nMenor valor impar encontrado: " << menor << endl;
    }
    
 // reciclar espaco
    int_array.free ( ); 
    
 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_13 ( )

/**
 Method_14.
*/
void method_14 ( )
{
 // definir dados
    Array <int> int_array;
    int soma = 0, inicio = 0, fim = 0;
    
 // identificar
    cout << endl << "Method_14 - v0.0" << endl;
    
 // pedir dados
    cout << "digite o valor de inicio: ";
    cin >> inicio;
    
    cout << "digite o valor do fim: ";
    cin >> fim;
    
 // ler o arquivo com o array
    int_array.fread( "DADOS.TXT" );
    
 // somar os valores do array definindo o limite da soma
    soma = int_array.addInterval( inicio, fim );
    
    if (inicio < 0 || inicio >= int_array.getLength() || fim < 0 || fim >= int_array.getLength() || inicio > fim) {
        cout << "Intervalo inválido." << endl;
    } else {
        cout << "Soma dos valores no intervalo [" << inicio << ", " << fim << "]: " << soma << endl;
    }
    
 // reciclar espaco
    int_array.free ( ); 
    
 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_14 ( )

/**
 Method_15.
*/
void method_15 ( )
{
 // definir dados
    Array <int> int_array;
    int inicio = 0, fim = 0;
    double media = 0.0;
    
 // identificar
    cout << endl << "Method_15 - v0.0" << endl;
    
 // pedir dados
    cout << "digite o valor de inicio: ";
    cin >> inicio;
    
    cout << "digite o valor do fim: ";
    cin >> fim;
    
 // ler o arquivo com o array
    int_array.fread( "DADOS.TXT" );
    
 // calcular a media e exibir
    media = int_array.averageInterval( inicio, fim );
    
    if (inicio < 0 || inicio >= int_array.getLength() || fim < 0 || fim >= int_array.getLength() || inicio > fim) {
        cout << "Intervalo inválido." << endl;
    } else {
        cout << "A media dos valores no intervalo [" << inicio << ", " << fim << "]: " << media << endl;
    }
    
 // reciclar espaco
    int_array.free ( ); 
    
 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_15 ( )

/**
 Method_16.
*/
void method_16 ( )
{
 // definir dados
    Array <int> int_array;
    int teste = 0; 
    
 // identificar
    cout << endl << "Method_16 - v0.0" << endl;

 // ler o arquivo com o array
    int_array.fread( "DADOS.TXT" );
    
 // verificar se existe vaor negativo e mostrar o resultado
    teste = int_array.positive();
    
    if (teste == 1){
        cout << "\nTodos os valores sao positivos" << endl;
    } else {
        cout << "\nExiste valores negativos" << endl;
    }
    
 // reciclar espaco
    int_array.free ( ); 
    
 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_16 ( )

/**
 Method_17.
*/
void method_17 ( )
{
 // definir dados
    Array <int> int_array;
    int teste = 0; 
    
 // identificar
    cout << endl << "Method_17 - v0.0" << endl;

 // ler o arquivo com o array
    int_array.fread( "DADOS.TXT" );
    
 // verificar se o array esta em ordem crescente
    teste = int_array.isCrescent();
    
    if (teste == 1){
        cout << "\nEsta em ordem" << endl;
    } else {
        cout << "\nNao esta em ordem" << endl;
    }
    
 // reciclar espaco
    int_array.free ( ); 
    
 // encerrar
    pause ( "Apertar ENTER para continuar" );
} // end method_17 ( )
 
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
        cout << "EXEMPLO1117 - Programa - v0.0\n    " << endl; 
 
     // mostrar opcoes 
        cout << "Opcoes        " << endl; 
        cout << " 0 - parar       " << endl; 
        cout << " 1 - mostrar dados inteiros em arranjo " << endl; 
        cout << " 2 - pedir e mostrar dados inteiros em arranjo " << endl; 
        cout << " 3 - salvar o array em arquivo " << endl; 
        cout << " 4 - ler o array do arquivo " << endl; 
        cout << " 5 - copiar array " << endl; 
        cout << " 6 - criar nova copia " << endl; 
        cout << " 7 - ler e copiar dados " << endl; 
        cout << " 8 - comparar arrays " << endl; 
        cout << " 9 - somar arrays " << endl; 
        cout << "10 - valores dentro e fora do limite " << endl;
        cout << "11 - numeros aleatorios " << endl;
        cout << "12 - maior numero par" << endl;
        cout << "13 - menor numero impar" << endl;
        cout << "14 - soma entre os numeros do intervalo" << endl;
        cout << "15 - media entre os valores do intervalo" << endl;
        cout << "16 - testar positivos" << endl;
        cout << "17 - testar ordem" << endl;
 
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
          case 11:  method_11 ( );   break;
          case 12:  method_12 ( );   break;
          case 13:  method_13 ( );   break;
          case 14:  method_14 ( );   break;
          case 15:  method_15 ( );   break;
          case 16:  method_16 ( );   break;
          case 17:  method_17 ( );   break;
          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); 
 
 // encerrar 
    pause  ( "Apertar ENTER para terminar" ); 
    return ( 0 ); 
} // end main ( ) 
