// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0406 - v0.0. - 11 / 09 / 2023
 Author: ____Felipe Rivetti Mizher___
*/
// dependencias
#include "io.h" // para definicoes proprias

/**
 Funcao para determinar se valor inteiro e' positivo.
 @return true, se positivo; false, caso contrario
 @param x - valor a ser testado
*/
bool positive ( int x )
{
// definir dado local
 bool result = false;
// testar a condicao
 if ( x > 0 )
 {
 result = true;
 } // end if
 return ( result );
} // end positive ( )

/**
 Funcao para determinar se valor inteiro pertence a intervalo aberto.
 @return true, se pertencer; false, caso contrario
 @param x - valor a ser testado
 @param inferior - limite inferior do intervalo
 @param superior - limite superior do intervalo
*/
bool belongsTo ( int x, int inferior, int superior )
{
// definir dado local
 bool result = false;
// testar a condicao
 if ( inferior < x && x < superior )
 {
 result = true;
 } // end if
 return ( result );
} // end belongsTo ( )

/**
 Funcao para determinar se valor inteiro e' par.
 @return true, se par; false, caso contrario
 @param x - valor a ser testado
*/
bool even ( int x )
{
// definir dado local
 bool result = false;
// testar a condicao ( resto inteiro (%) da divisao por 2 igual a zero )
 if ( x % 2 == 0 )
 {
 result = true;
 } // end if
 return ( result );
} // end even ( )

/**
 Funcao para determinar se caractere e' letra minuscula.
 @return true, se par; false, caso contrario
 @param x - valor a ser testado
*/
bool isLowerCase ( char x )
{
// definir dado local
 bool result = false;
// testar a condicao
 if ( 'a' <= x && x <= 'z' )
 {
 result = true;
 } // end if
 return ( result );
} // end isLowerCase ( )

/**
 Method_00 - nao faz nada.
*/
void method_00 ( void )
{
// nao faz nada
} // end method_00 ( )
/**

/**
 Method_01 - Repeticao para ler certa quantidade de valores.
*/
void method_01 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
// identificar
 IO_id ( "Method 01 - v0.0" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
 printf ( "\nquantidade = %d\n", quantidade );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat ( 
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 printf ( "\nvalor = %d\n", valor );
 // passar ao proximo valor
 controle = controle + 1;
 } // end while
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
 Method_02 - Ler valores e contar positivos.
*/
void method_02 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
// identificar
 IO_id ( "Method02 - v0.0" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo
 if ( positive ( valor ) )
 {
 contador = contador + 1;
 } // end if
 // passar ao proximo valor
 controle = controle + 1;
 } // end while
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
 Method_03 - Ler valores e contar positivos menores que 100.
*/
void method_03 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
// identificar
 IO_id ( "Method_03 - v0.0" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo
 if ( belongsTo ( valor, 0, 100 ) )
 {
 contador = contador + 1;
 } // end if
 // passar ao proximo valor
 controle = controle + 1;
 } // end while
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos menores que 100 = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
 Method_04 - Ler valores e contar positivos menores que 100 e pares.
*/
void method_04 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
// identificar
 IO_id ( "Method_04 - v0.0" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo menor que 100 e par
 if ( belongsTo ( valor, 0, 100 ) && even ( valor ) )
 {
 contador = contador + 1;
 } // end if
 // passar ao proximo valor
 controle = controle + 1;
 } // end while
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
 Method05 - Ler valores e contar positivos menores que 100 e pares (alternativo).
*/
void method_05 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
 bool ok = false;
// identificar
 IO_id ( "EXEMPLO0405 - Method05 - v0.0" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo menor que 100 e par
 ok = belongsTo ( valor, 0, 100 );
 ok = ok && even ( valor );
 if ( ok )
 {
 contador = contador + 1;
 } // end if
 // passar ao proximo valor
 controle = controle + 1;
 } // end while
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
 Method_06 - Ler palavra e contar letras minusculas.
*/
void method_06 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 int contador = 0;
// identificar
 IO_id ( "Method06 - v0.0" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar se caractere e' letra minuscula
 if ( isLowerCase ( simbolo ) )
 {
 contador = contador + 1;
 } // end if
 } // end for
// mostrar a quantidade de minusculas
 IO_printf ( "%s%d\n", "Minusculas = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
 Method_07 - Ler palavra, contar e mostrar letras minusculas.
*/
void method_07 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 int contador = 0;
// identificar
 IO_id ( "Method07 - v0.0" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar se caractere e' letra minuscula
 if ( isLowerCase ( simbolo ) )
 {
 // mostrar
 IO_printf ( "%c ", simbolo );
 // contar
 contador = contador + 1;
 } // end if
 } // end for
// mostrar a quantidade de minusculas
 IO_printf ( "\n%s%d\n", "Minusculas = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

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
 IO_println ( "1 - method_01" );
 IO_println ( "2 - method_02" );
 IO_println ( "3 - method_03" );
 IO_println ( "4 - method_04" );
 IO_println ( "5 - method_05" );
 IO_println ( "6 - method_06" );   
 IO_println ( "7 - method_07" );     
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
 case 6: method_06 ( ); break;         
 case 7: method_07 ( ); break;         
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
a.) -1
b.) 0
c.) 5 e { 1, 2, 3, 4, 5 }
---------------------------------------------- historico
Versao Data Modificacao
 0.1 11/09 esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. (OK) identificacao de programa
*/