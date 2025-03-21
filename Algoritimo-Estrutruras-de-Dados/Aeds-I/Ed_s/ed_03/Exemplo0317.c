// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0317 - v0.0. - 04 / 09 / 2023
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

/**
 Method_09 - Repeticao com intervalos.
*/
void method_09 ( void )
{
// definir dado
 double inferior = 0;
 double superior = 0;
 double passo = 0;
 double x = 0;
// identificar
 IO_id ( "Method_09 - v0.0" );
// ler do teclado
 inferior = IO_readdouble ( "Limite inferior do intervalo : " );
 superior = IO_readdouble ( "Limite superior do intervalo : " );
 passo = IO_readdouble ( "Variacao no intervalo (passo): " );
// inicio teste variacao
 for ( x = superior; x >= inferior; x = x - passo )
 {
 // mostrar valor atual
 IO_printf ( "%lf\n", x );
 } // end for
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/**
 Method_10 - Repeticao com confirmacao.
*/
void method_10 ( void )
{
// definir dado
 double inferior = 0;
 double superior = 0;
 double passo = 0;
 double x = 0;
// identificar
 IO_id ( "Method10 - v0.0" );
// ler do teclado
 inferior = IO_readdouble ( "Limite inferior do intervalo : " );
// repetir ate' haver confirmacao de validade
 do
 {
 superior = IO_readdouble ( "Limite superior do intervalo: " );
 }
 while ( inferior >= superior );
// repetir ate' haver confirmacao de validade
 do
 {
 passo = IO_readdouble ( "Variacao no intervalo (passo): " );
 }
 while ( passo <= 0.0 );
// inicio teste variacao
 for ( x = inferior; x <= superior; x = x + passo )
 {
 // mostrar valor atual
 IO_printf ( "%lf\n", x );
 } // end for
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

/**
 Method_11 - Repeticao com confirmacao.
*/
void method_11 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
 
 char word [STR_SIZE];
 int tamanho = 0;
// identificar
 IO_id ( "Method11 - v0.0" );
// ler do teclado
    printf("Digite uma palavra: ");
    scanf("%s" , word); getchar();
// repetir ate' haver mostrar todas as letras maiusculas.
    tamanho = strlen ( word );
    for ( y = 0; y < tamanho; y = y + 1 ){
      if(word[y] >= 'A' && word[y] <= 'Z'){
         // mostrar valor atual
         IO_printf ( "%d: [%c]\n", y, word [y] );
      }
 } // end for
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_11 ( )

/**
 Method_12 - Repeticao com confirmacao.
*/
void method_12 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
 int count = 0;
 char word [STR_SIZE];
 int tamanho = 0;
// identificar
 IO_id ( "Method12 - v0.0" );
// ler do teclado
    printf("Digite uma palavra: ");
    scanf("%s" , word); getchar();
// repetir ate' haver mostrar todas as letras maiusculas.
    tamanho = strlen ( word );
    for ( y = 0; y < tamanho; y = y + 1 ){
      if(word[y] >= 'A' && word[y] <= 'Z'){
         // mostrar valor atual
         IO_printf ( "[%c]\n", word [y] );
          count++;
      }
 } // end for
    printf("Numero de letras maiusculas: %d\n" , count);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_12 ( )

/**
 Method_13 - Repeticao com confirmacao.
*/
void method_13 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
 int count = 0;
 char word [STR_SIZE];
 int tamanho = 0;
// identificar
 IO_id ( "Method13 - v0.0" );
// ler do teclado
    printf("Digite uma palavra: ");
    scanf("%s" , word); getchar();
// repetir ate' haver mostrar todas as letras maiusculas.
    tamanho = strlen ( word );
    for ( y = tamanho - 1; y >= 0; y-- ){
      if(word[y] >= 'A' && word[y] <= 'Z'){
         // mostrar valor atual
         IO_printf ( "[%c]\n", word [y] );
          count++;
      }
 } // end for
// mostrar a quantidade de letras maiusculas na palavra.
    printf("Numero de letras maiusculas: %d\n" , count);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_13 ( )

/**
 Method_14 - Repeticao com confirmacao.
*/
void method_14 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
 int count = 0;
 char word [STR_SIZE];
 int tamanho = 0;
// identificar
 IO_id ( "Method14 - v0.0" );
// ler do teclado
    printf("Digite uma palavra: ");
    scanf("%s" , word); getchar();
// repetir ate' haver mostrar todas as letras e contar.
    tamanho = strlen ( word );
    for ( y = 0; y < tamanho; y = y + 1 ){
      if(word[y] >= 'A' && word[y] <= 'Z' || 
         word[y] >= 'a' && word[y] <= 'z'){
         // mostrar valor atual
         IO_printf ( "[%c]\n", word [y] );
          count++;
      }
 } // end for
    printf("Numero de letras: %d\n" , count);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_14 ( )

/**
 Method_15 - Repeticao com confirmacao.
*/
void method_15 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
 int count = 0;
 char word [STR_SIZE];
 int tamanho = 0;
// identificar
 IO_id ( "Method15 - v0.0" );
// ler do teclado
    printf("Digite uma palavra: ");
    scanf("%s" , word); getchar();
// repetir ate' haver mostrar todas os digitos.
    tamanho = strlen ( word );
     for (int i = 0; word[i] != '\0'; i++) {
        if (isdigit(word[i])) {
            printf("%c\n", word[i]); // Imprimir o dígito encontrado
            count++;
        }
    } // end for
    printf("\nNumero de digitos encontrados: %d\n" , count);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_15 ( )

/**
 Method_16 - Repeticao com confirmacao.
*/
void method_16 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
 int count = 0;
 char word [STR_SIZE];
 int tamanho = 0;
// identificar
 IO_id ( "Method16 - v0.0" );
// ler do teclado
    printf("Digite uma palavra: ");
    scanf("%s" , word); getchar();
// repetir ate' haver mostrar todas os nao digitos nem letras.
    tamanho = strlen ( word );
     for (int i = 0; word[i] != '\0'; i++) {
        if(!((word[i] >= 'A' && word[i] <= 'Z') || 
           (word[i] >= 'a' && word[i] <= 'z') || 
           (word[i] >= '0' && word[i] <= '9'))){
         // mostrar valor atual
         IO_printf ( "%c\n", word[i] );
          count++;
      }
    } // end for
    printf("\nNumero de simbolos encontrados: %d\n" , count);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_16 ( )

/**
 Method_17 - Repeticao com confirmacao.
*/
void method_17 ( void )
{
// definir dado
    int a, b, n, x;
// identificar
 IO_id ( "Method17 - v0.0" );
// ler do teclado
    printf("Digite o valor de a: \n");
    scanf("%d" , &a); getchar();
    printf("Digite o valor de b: \n");
    scanf("%d" , &b); getchar();
    printf("Digite o valor de n: \n");
    scanf("%d" , &n); getchar();
    
    int numero[n];
    for(x = 0; x < n; x++){
        printf("digite o %d numero: \n", x + 1);
        scanf("%d" , &numero[x]); getchar();
    }
// repetir ate' haver mostrar os numeros que estao dentro das condições.
    printf("\nNúmeros dentro do intervalo [%d, %d] e múltiplos de 5:\n", a, b);
    for (x = 0; x < n; x++)
    {
        if (numero[x] >= a && numero[x] <= b && numero[x] % 5 == 0)
        {
            printf("%d\n", numero[x]);
        }
    }
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_17 ( )

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
 IO_println ( "8 - repeticao com intervalos" );
 IO_println ( "9 - repeticao com intervalos" );
 IO_println ( "10 - repeticao com confirmacao" );
 IO_println ( "11 - mostrar letras maiussculas" );
 IO_println ( "12 - mostrar letras maiussculas e contar" );
 IO_println ( "13 - mostrar letras maiussculas de tras pra frente e contar" );
 IO_println ( "14 - mostrar apenas letras e contar" );
 IO_println ( "15 - mostrar apenas os digitos e contar" );
 IO_println ( "16 - mostrar e contar o que nao for letra nem simbolo" );
 IO_println ( "17 - definir um intervalo com condicoes" );
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
 case 9: method_09 ( ); break;
 case 10: method_10 ( ); break;
 case 11: method_11 ( ); break;
 case 12: method_12 ( ); break;
 case 13: method_13 ( ); break;
 case 14: method_14 ( ); break;
 case 15: method_15 ( ); break;
 case 16: method_16 ( ); break;
 case 17: method_17 ( ); break;
 default:
 IO_pause ( IO_concat ( "Valor diferente das opcoes disponiveis. (",
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
a.) [ 0.1 : 0.5 ] e passo = 0.1
b.) [ 0.5 : 0.1 ] e passo = -0.1
c.) [ 0.5 : 0.1 ] e passo = 0.1
d.) [ 0.1 : 0.5 ] e passo = -0.1
---------------------------------------------- historico
Versao Data Modificacao
 0.1 04/09 esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. (OK) identificacao de programa
*/