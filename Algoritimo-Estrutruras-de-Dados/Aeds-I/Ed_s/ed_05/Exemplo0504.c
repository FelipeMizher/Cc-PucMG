// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0504 - v0.0. - 18 / 09 / 2023
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
 Method_01a - Mostrar certa quantidade de valores.
 @param x - quantidade de valores a serem mostrados
*/
void method_01a ( int x )
{
// definir dado local
 int y = 1; // controle
// repetir enquanto controle menor que a quantidade desejada
 while ( y <= x )
 {
 // mostrar valor
 IO_printf ( "%s%d\n", "Valor = ", y );
 // passar ao proximo
 y = y + 1;
 } // end if
} // end method_01a( )
/**
 Method_01 - Mostrar certa quantidade de valores.
 OBS.: Preparacao e disparo de outro metodo.
*/
void method_01 ( )
{
// identificar
 IO_id ( " Method_01 - v0.0" );
// executar o metodo auxiliar
 method_01a ( 5 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
 Method_02a - Mostrar certa quantidade de valores pares.
 @param x - quantidade de valores a serem mostrados
*/
void method_02a ( int x )
{
// definir dado local
 int y = 1; // controle
 int z = 2;
// repetir enquanto controle menor que a quantidade desejada
 while ( y <= x )
 {
 // mostrar valor
 IO_printf ( "%d: %d\n", y, z );
 // passar ao proximo par
 z = z + 2;
 // passar ao proximo valor controlado
 y = y + 1;
 } // end while
} // end method_02a( )
/**
 Method_02.
*/
void method_02 ( )
{
// identificar
 IO_id ( "Method_02 - v0.0" );
// executar o metodo auxiliar
 method_02a ( 5 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
 Method_03a - Mostrar certa quantidade de valores pares.
 @param x - quantidade de valores a serem mostrados
*/
void method_03a ( int x )
{
// definir dado local
 int y = 1; // controle
 int z = 0;
// repetir enquanto controle menor que a quantidade desejada
 while ( y <= x )
 {
 // vincular o valor a ser mostrado ao controle
 z = 2 * y;
 // mostrar valor
 IO_printf ( "%d: %d\n", y, z );
 // passar ao proximo valor controlado
 y = y + 1;
 } // end while
} // end method_03a( )
/**
 Method_03.
*/
void method_03 ( )
{
// identificar
 IO_id ( " Method_03 - v0.0" );
// executar o metodo auxiliar
 method_03a ( 5 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
 Method_04a - Mostrar certa quantidade de valores pares.
 @param x - quantidade de valores a serem mostrados
*/
void method_04a ( int x )
{
// definir dado local
 int y = x; // controle
 int z = 0;
// repetir enquanto controle menor que a quantidade desejada
 while ( y > 0 )
 {
 // vincular o valor a ser mostrado ao controle
 z = 2 * y;
 // mostrar valor
 IO_printf ( "%d: %d\n", y, z );
 // passar ao proximo valor controlado
 y = y - 1;
 } // end while
} // end method_04a( )
/**
 Method_04.
*/
void method_04 ( )
{
// identificar
 IO_id ( "Method_04 - v0.0" );
// executar o metodo auxiliar
 method_04a ( 5 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
 Method_05a - Mostrar certa quantidade de valores pares.
 @param x - quantidade de valores a serem mostrados
*/
void method_05a ( int x )
{
// definir dado local
 int y = 0; // controle
// repetir enquanto controle menor que a quantidade desejada
 for ( y = x; y > 0; y = y-1 )
 {
 // mostrar valor
 IO_printf ( "%d: %d\n", y, (2*y) );
 } // end for
} // end method_05a( )
/**
 Method_05.
*/
void method_05 ( )
{
// identificar
 IO_id ( "Method_05 - v0.0" );
// executar o metodo auxiliar
 method_05a ( 5 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "EXEMPLO0500 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 - method_01" );
 IO_println ( "2 - method_02" );
 IO_println ( "3 - method_03" );
 IO_println ( "4 - method_04" );
 IO_println ( "5 - method_05" );
 /*IO_println ( "6 - method_06" );   
 IO_println ( "7 - method_07" );
 IO_println ( "8 - method_08" );    
 IO_println ( "9 - method_09" );
 IO_println ( "10 - method_10" ); 
 IO_println ( "11 - method_11" );
 IO_println ( "12 - method_12" );
 IO_println ( "13 - method_13" ); 
 IO_println ( "14 - method_14" );    
 IO_println ( "15 - method_15" ); 
 IO_println ( "16 - method_16" );
 IO_println ( "17 - method_17" ); 
 IO_println ( "18 - method_18" );
 IO_println ( "19 - method_19" );
 IO_println ( "20 - method_20" ); */    
 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 printf ( "\nx = %d", x );
 // testar valor
 switch ( x )
 {
 case 0: method_00 ( ); break;
 case 1: method_01 ( ); break;
 case 2: method_02 ( ); break;
 case 3: method_03 ( ); break;
 case 4: method_04 ( ); break;
 case 5: method_05 ( ); break;
 /*case 6: method_06 ( ); break;         
 case 7: method_07 ( ); break;         
 case 8: method_08 ( ); break;   
 case 9: method_09 ( ); break;         
 case 10: method_10 ( ); break;  
 case 11: method_11 ( ); break;          
 case 12: method_12 ( ); break; 
 case 13: method_13 ( ); break;
 case 14: method_14 ( ); break;
 case 15: method_15 ( ); break;
 case 16: method_16 ( ); break;
 case 17: method_17 ( ); break;
 case 18: method_18 ( ); break;
 case 19: method_19 ( ); break;
 case 20: method_20 ( ); break;*/
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

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5 -> { 1, 2, 3, 4, 5 }
---------------------------------------------- historico
Versao Data Modificacao
 0.1 18/09 esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa
*/