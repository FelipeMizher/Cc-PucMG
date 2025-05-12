// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0900 - v0.0. - 18 / 10 / 2023
 Author: ____Felipe Rivetti Mizher___
*/
// dependencias
#include "io.h" // para definicoes proprias
/**
 Method_00 - nao faz nada.
*/
void method_00 ( void )
{
    // nao faz nada
} // end method_00 ( )

/** 
   printIntMatrix        - Mostrar arranjo bidimensional com valores inteiros. 
   @param rows       - quantidade de linhas 
   @param columns - quantidade de colunas 
   @param matrix     - grupo de valores inteiros 
 */ 
void printIntMatrix ( int rows, int columns, int matrix[ ][columns] ) 
{ 
 // definir dado local 
    int x = 0; 
    int y = 0; 
 
 // mostrar valores na matriz 
    for ( x=0; x<rows; x=x+1 ) 
    { 
        for ( y=0; y<columns; y=y+1 ) 
        { 
         // mostrar valor 
            IO_printf ( "%3d\t", matrix [ x ][ y ] ); 
        } // end for 
        IO_printf ( "\n" ); 
    } // end for 
} // end printIntMatrix ( ) 
 
/** 
   Method_01 - Mostrar certa quantidade de valores. 
 */ 
void method_01 ( ) 
{ 
 // definir dado 
    int matrix [ ][3] = {  
                                   {1, 2, 3}, 
                                   {4, 5, 6}, 
                                   {7, 8, 9} 
                                 }; 
 
 // identificar 
    IO_id ( "Method_01 - v0.0" ); 
 
 // executar o metodo auxiliar 
    printIntMatrix ( 3, 3, matrix ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( ) 

int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "EXEMPLO0900 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 - method_01" ); 
 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 // testar valor
 switch ( x )
 {
 case 0: method_00 ( ); break;
 case 1: method_01 ( ); break; 
 default:
 IO_pause ( IO_concat ( "Valor diferente das opcoes [0,1] (",
 IO_concat ( IO_toString_d ( x ), ")" ) ) );
 } // end switch
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // end main ( )