// 821811 - Felipe Rivetti Mizher

/*
 Exemplo1000 - v0.0. - 29 / 10 / 2023
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
   Definicao de tipo arranjo com inteiros 
   baseado em estrutura 
 */ 
typedef 
 struct s_int_Array 
 { 
   int   length; 
   ints data  ; 
   int   ix    ; 
 } int_Array; 
 
/** 
   Definicao de referencia para arranjo com inteiros 
   baseado em estrutura 
 */ 
typedef int_Array* ref_int_Array;  
/** 
   new_int_Array - Reservar espaco para arranjo com inteiros 
   @return referencia para arranjo com inteiros 
   @param n - quantidade de datos 
 */ 
ref_int_Array new_int_Array ( int n ) 
{ 
 // reserva de espaco 
    ref_int_Array tmpArray = (ref_int_Array) malloc (sizeof(int_Array)); 
 
 // estabelecer valores padroes 
    if ( tmpArray == NULL ) 
    { 
       IO_printf ( "\nERRO: Falta espaco.\n" ); 
    } 
    else 
    { 
       tmpArray->length     =  0; 
       tmpArray->data        = NULL; 
       tmpArray->ix             = -1; 
       if ( n>0 ) 
       { 
        // guardar a quantidade de dados 
           tmpArray->length =  n; 
        // reservar espaco para os dados 
           tmpArray->data    = (ints) malloc (n * sizeof(int)); 
        // definir indicador do primeiro elemento 
           tmpArray->ix        =  0; 
       } // end if 
    } // end if 
 
 // retornar referencia para espaco reservado 
    return ( tmpArray ); 
} // end new_int_Array ( ) 
 
/** 
   free_int_Array - Dispensar espaco para arranjo com inteiros 
   @param tmpArray - referencia para grupo de valores inteiros 
 */ 
void free_int_Array ( ref_int_Array tmpArray ) 
{ 
 // testar se ha' dados, antes de reciclar o espaco 
    if ( tmpArray != NULL ) 
    { 
       if ( tmpArray->data != NULL ) 
       {  
          free ( tmpArray->data );  
       } // end if 
       free ( tmpArray ); 
    } // fim se 
} // end free_int_Array ( )  
/** 
   printIntArray    - Mostrar arranjo com valores inteiros. 
   @param array  - grupo de valores inteiros 
 */ 
void printIntArray ( int_Array array ) 
{ 
 // mostrar valores no arranjo 
    if ( array.data ) 
    { 
       for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 ) 
       { 
         // mostrar valor 
            printf ( "%2d: %d\n", array.ix, array.data [ array.ix ] ); 
       } // end for 
    } // end if 
} // end printIntArray ( ) 
 
/** 
   Method_01 - Mostrar certa quantidade de valores. 
 */ 
void method_01 ( ) 
{ 
 // definir dado 
    int_Array array; 
 
 // montar arranjo em estrutura 
    array. length  = 5; 
    array. data     = (ints) malloc (array.length * sizeof(int)); 
 
 // testar a existência de dados 
    if ( array.data ) 
    { 
       array. data [ 0 ] = 1; 
       array. data [ 1 ] = 2; 
       array. data [ 2 ] = 3; 
       array. data [ 3 ] = 4; 
       array. data [ 4 ] = 5; 
    } // fim se 
     
 // identificar 
    IO_id ( "Method_01 - v0.0" ); 
 
 // executar o metodo auxiliar 
    printIntArray ( array ); 
 
 // reciclar o espaco 
    if ( array.data ) 
    { 
        free ( array.data ); 
    } // fim se 
 
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
 IO_id ( "EXEMPLO1000 - Programa - v0.0" );
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