// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0307 - v0.0. - 04 / 09 / 2023
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
 Method_01 - Repeticao com teste no inicio.
*/
void method_01 ( void )
{
// definir dado
 int x = 0;
// identificar
 IO_id ( "Method_01 - v0.0" );
// ler do teclado o valor inicial
 x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
 while ( x > 0 )
 {
 // mostrar valor atual
 IO_println ( IO_toString_d ( x ) );
 // passar ao proximo valor
 x = x - 1;
 } // end while
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
 Method_02 - Repeticao com teste no inicio.
*/
void method_02 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
// identificar
 IO_id ( "Method_02 - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
 y = x; // copiar o valor lido (e' melhor)
 while ( y > 0 )
 {
 // mostrar valor atual
 IO_println ( IO_toString_d ( x ) );
 // passar ao proximo valor
 y = y - 1;
 } // end while
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
 Method_03 - Repeticao com teste no inicio.
*/
void method_03 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
// identificar
 IO_id ( "Method_03 - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
 y = 1; // o valor lido devera' ser preservado
 while ( y <= x )
 {
 // mostrar valor atual
 IO_printf ( "%d\n", y );
 // passar ao proximo valor
 y = y + 1;
 } // end while
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
 Method_04 - Repeticao com teste no inicio e variacao.
*/
void method_04 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
 int z = 0;
// identificar
 IO_id ( "Method_04 - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
// inicio teste variacao
 for ( y = 1; y <= x; y = y + 1 )
 {
 // ler valor do teclado
 z = IO_readint ( "Valor = " );
 // mostrar valor atual
 IO_printf ( "%d. %d\n", y, z );
 } // end for
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
 Method_05 - Repeticao com teste no inicio e variacao.
*/
void method_05 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
 int z = 0;
// identificar
 IO_id ( "Method_05 - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
// inicio teste variacao
 for ( y = x; y >= 1; y = y - 1 )
 {
 // ler valor do teclado
 z = IO_readint ( "Valor = " );
 // mostrar valor atual
 IO_printf ( "%d. %d\n", y, z );
 } // end for
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
 Method_06 - Repeticao sobre cadeia de caracateres.
*/
void method_06 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
 
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
// identificar
 IO_id ( "Method_06 - v0.0" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// repetir para cada letra
 tamanho = strlen ( palavra ) - 1;
// OBS: A cadeia de caracteres iniciam suas posições em zero.
// inicio teste variacao
 for ( y = tamanho; y >= 0; y = y - 1 )
 {
 // mostrar valor atual
 IO_printf ( "%d: [%c]\n", y, palavra [y] );
 } // end for
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
 Method_07 - Repeticao sobre cadeia de caracateres.
*/
void method_07 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
 
 char palavra [STR_SIZE];
 int tamanho = 0;
// identificar
 IO_id ( "Method07 - v0.0" );
// ler do teclado
 IO_printf ( "Entrar com uma palavra: " );
 scanf ( "%s", palavra ); getchar( );
// OBS: A cadeia de caracteres dispensa a indicacao de endereco (&) na leitura.
// repetir para cada letra
 tamanho = strlen ( palavra );
// OBS: A cadeia de caracteres iniciam suas posições em zero.
// inicio teste variacao
 for ( y = 0; y < tamanho; y = y + 1 )
 {
 // mostrar valor atual
 IO_printf ( "%d: [%c]\n", y, palavra [y] );
 } // end for
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/**
 Method_08 - Repeticao com intervalos.
*/
void method_08 ( void )
{
// definir dado
 int inferior = 0;
 int superior = 0;
 int x = 0;
// identificar
 IO_id ( "Method08 - v0.0" );
// ler do teclado
 inferior = IO_readint ( "Limite inferior do intervalo: " );
 superior = IO_readint ( "Limite superior do intervalo : " );
// inicio teste variacao
 for ( x = inferior; x <= superior; x = x + 1 )
 {
 // mostrar valor atual
 IO_printf ( "%d\n", x );
 } // end for
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/*
 Funcao principal.
 @return codigo de encerramento
*/
int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "EXEMPLO0300 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 - repeticao com teste no inicio" );
 IO_println ( "2 - repeticao com teste no inicio" );
 IO_println ( "3 - repeticao com teste no inicio" );
 IO_println ( "4 - repeticao com teste no inicio e variacao" );
 IO_println ( "5 - repeticao com teste no inicio e variacao" );
 IO_println ( "6 - repeticao sobre cadeia de caracateres" );
 IO_println ( "7 - repeticao sobre cadeia de caracateres" );
 IO_println ( "8 - repeticao sobre cadeia de caracateres" );
 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 // testar valor
 switch ( x )
 {
 case 0: method_00 ( ); break;
 case 1: method_01 ( ); break;
 case 2: method_02 ( ); break;
 case 3: method_03 ( ); break;
 case 4: method_04 ( ); break;
 case 5: method_05 ( ); break;
 case 6: method_06 ( ); break;
 case 7: method_07 ( ); break;
 case 8: method_08 ( ); break;
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
a.) 0 e 1
b.) 1 e 5
c.) 3 e 5
d.) -5 e 5
---------------------------------------------- historico
Versao Data Modificacao
 0.1 04/09 esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa
*/