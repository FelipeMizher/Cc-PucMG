// 821811 - Felipe Rivetti Mizher 

/* 
Exemplo00E - v0.0. - 21 / 08 / 2023 
Author: ____Felipe Rivetti Mizher _____ 
    
Para compilar em terminal (janela de comandos): 
Linux      : gcc -o exemplo00E exemplo00E.c 
Windows: gcc -o exemplo00E exemplo00E.c 
 
Para executar em terminal (janela de comandos): 
Linux      :  ./Exemplo00E
Windows:    Exemplo00E
 */ 
// dependencias 
#include <stdio.h> // para as entradas e saidas 
#include <stdlib.h> // para outras funcoes de uso geral 
#include <stdbool.h> // para valores logicos
#include <string.h> // para lidar com caracteres
#include <math.h> // para operacoes matematicas
#include "my_lib.h"
#include <fcntl.h> // para arquivos

int X = 0; // VARIAVEL EM CONTEXTO GLOBAL

void P2 ( int X ); // PROTOTIPO DE PROCEDIMENTO
void P1 ( int X )
{
 X = X + 1;
 printf ( "CHAMADO O PROCEDIMENTO P1 COM X = %d\n", X );
 if ( X < 4 )
 {
 P1 ( X );
 P2 ( X );
 }
 printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = %d\n", X );
 getchar ( ) ; // para esperar
} // fim do procedimento P1( )
void P2 ( int X )
{
 printf ( "CHAMADO O PROCEDIMENTO P2 COM X = %d\n", X );
 if ( X > 1 )
 P2 ( X - 1 );
 printf ( "RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = %d", X );
 getchar ( ); // para esperar
} // fim procedimento P2( )

void CONTAR ( int X )
{
 if ( X > 0 )
 {
 printf ( "\n%d\n", X );
 CONTAR ( X-1 );
 }
} // fim procedimento CONTAR( )

int PARES ( int X )
{
// DADO :
 int S = 0;
 if ( X > 0 )
 if ( X % 2 == 0 )
 S = 1 + PARES ( X-2 );
 else
 S = PARES ( X-1 );
 else
 S = 0;
 return ( S );
} // fim funcao PARES ( )

typedef int TABELA[10];
typedef struct SPONTOS { double X,Y,Z; } PONTOS; int VETOR2 [2];
typedef struct SPONTOS1 { PONTOS P1,P2; } PONTO;
typedef struct { double X, Y, Z; } PONTO3;
#define ORDEM 3
typedef int MATRIZ [ ORDEM ][ ORDEM ];
typedef double POLINOMIO[10+1]; // posicoes de 0:10
typedef int VETOR1[3]; // X,Y,Z
typedef PONTOS VETOR[2];
typedef char STRING10[10];
typedef double PONTOS3[3]; // X, Y, Z
typedef struct SVETOR { PONTOS P1, P2; } VETOR5;
typedef char STRING30[30];
int PROCURAR
 ( char LETRA, STRING30 S, int POSICAO )
{
// DADO :
 int R = 0;
 if ( POSICAO <= strlen(S) )
 if ( S [ POSICAO ] == LETRA )
 R = 1 + PROCURAR ( LETRA, S, POSICAO+1 );
 else
 R = PROCURAR ( LETRA,S,POSICAO+1 );
 else
 R = 0;
 return ( R );
} // fim funcao PROCURAR ( )

typedef
struct S_CELULA { int VALOR; struct S_CELULA *LINK; }
CELULA;
typedef struct S_CELULA * REF_CELULA;
REF_CELULA NEW_CELULA ( int INICIAL )
{
 REF_CELULA P; // APONTADOR PARA CELULA
 P = calloc ( 1, sizeof(CELULA) ); // OUTRA FORMA DE RESERVAR
 P->VALOR = INICIAL; // OUTRA NOTACAO
 P->LINK = NULL;
 return ( P );
} // fim funcao NEW_CELULA ( )

/** 
  Metodo 01. 
*/ 
void method_01 ( void ){      
     // identificar 
        printf ( "\n%s\n", "EXEMPLO0101 - PRIMEIRO EXEMPLO EM C" ); 
     // encerrar 
        printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR."  ); 
        getchar( );  // para esperar  
} // end method_01 ( )

/** 
  Metodo 02. 
*/ 
void method_02 ( void ){
      // identificar 
    // (dependente do sistema operacional) 
    system ( "cls" ); // ( Windows ) para limpar a tela 
//  system ( "clear" ); // ( Linux    ) para limpar a tela 
 
    printf ( "\n%s\n", "EXEMPLO0102 - PRIMEIRO EXEMPLO EM C" ); 
 // encerrar 
    printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR."     ); 
    getchar( );  // para esperar 
} // end method_02 ( )

/** 
  Metodo 03. 
*/
void method_03 ( void ){
    void clrscr ( ) { system ( "cls" ); } // para Windows
// identificar
 printf ( "\n%s\n", "EXEMPLO0103 - PRIMEIRO EXEMPLO EM C" );
 // (dependente do sistema operacional)
 clrscr ( ); // para limpar a tela
 printf ( "\n%s\n", "MATRICULA: ______ ALUNO : __________________" );
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_03 ( )

/** 
  Metodo 04. 
*/
void method_04 ( void ){
     // identificar
 printf ( "\n%s\n", "EXEMPLO0104 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\n" ); // para mudar de linha (="\n")
 printf ( "\n%s\n", "MATRICULA: ______ ALUNO : __________________" );
 printf ( "\n" ); // para mudar de linha
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_04 ( )

/** 
  Metodo 05. 
*/
void method_05 ( void ){
// identificar
 printf ( "\n%s\n", "EXEMPLO0105 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\n%s\n", "MATRICULA: ______ ALUNO : __________________" );
 printf ( "\nEXEMPLOS DE VALORES : " );
 printf ( "\nCARACTERE : %c", 'A' ); // letra ou simbolo
 printf ( "\nINTEIRO : %d", 10 ); // valor sem parte fracionaria
 printf ( "\nREAL : %f", 3.1415 ); // valor com parte fracionaria
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_05 ( )

/** 
  Metodo 06. 
*/
void method_06 ( void ){
    double PI = 3.1415; // Definição da macro (nome para substituir constante global)
     // identificar
 printf ( "\n%s\n", "EXEMPLO0106 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\n%s\n", "MATRICULA: ______ ALUNO : __________________" );
 printf ( "\nEXEMPLOS DE VALORES : " );
 printf ( "\nCARACTERE : %c", 'A' ); // letra ou simbolo
 printf ( "\nINTEIRO : %d", 10 ); // valor sem parte fracionaria
 printf ( "\nREAL : %f", PI ); // emprego de macro
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_06 ( )

/** 
  Metodo 07. 
*/
void method_07 ( void ){
     // definicao de constante (local)
 const float PI = 3.14; // com nome e tipo (melhor)
// identificar
 printf ( "\n%s\n", "EXEMPLO0107 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\n%s\n", "MATRICULA: ______ ALUNO : __________________" );
 printf ( "\nEXEMPLOS DE VALORES : " );
 printf ( "\nCARACTERE : %c", 'A' ); // letra ou simbolo
 printf ( "\nINTEIRO : %d", 10 ); // valor sem parte fracionaria
 printf ( "\nREAL : %f", PI ); // constante real
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_07 ( )

/** 
  Metodo 08. 
*/
void method_08 ( void ){
     // definicao de constante
 const float PI = 3.14; // com nome e tipo (melhor)
// definicao de variavel real
 float X = 10.01; // com atribuicao de valor inicial
// identificar
 printf ( "\n%s\n", "EXEMPLO0108 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\n%s\n", "MATRICULA: ______ ALUNO : __________________" );
 printf ( "\nEXEMPLOS DE VALORES : " );
 printf ( "\nCARACTERE : %c", 'A' ); // letra ou simbolo
 printf ( "\nINTEIRO : %d", 10 ); // valor sem parte fracionaria
 printf ( "\nREAL : %f", PI ); // constante real
 printf ( "\nREAL : %f", X ); // variavel real
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_08 ( )

/** 
  Metodo 09. 
*/
void method_09 ( void ){
     // definicao de constante
 const float PI = 3.14;
// definicao de variavel real
 float X = 10.01;
// definicao de variavel inteira
 int I = 10;
// identificar
 printf ( "\n%s\n", "EXEMPLO0109 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\n%s\n", "MATRICULA: ______ ALUNO : __________________" );
 printf ( "\nEXEMPLOS DE VALORES : " );
 printf ( "\nINTEIRO : %i" , I );
 printf ( "\nREAL : %f" , X );
 printf ( "\nREAL : %f" , PI );
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar
} // end method_09 ( )

/** 
  Metodo 10. 
*/
void method_10 ( void ){
     // definicao de constante
 const float PI = 3.14;
// definicao de variavel real
 float X = 10.01;
// definicao de variavel inteira
 int I = 10;
// definicao de variavel caractere
 char N = '\n'; // mudar de linha
// identificar
 printf ( "\n%s\n", "EXEMPLO0110 - PRIMEIRO EXEMPLO EM C" );
 printf ( "\n%s\n", "MATRICULA: ______ ALUNO : __________________" );
 printf ( "%c%s" , N, "EXEMPLOS DE VALORES : " );
 printf ( "%c%s%i", N, "INTEIRO : " , I );
 printf ( "%c%s%f", N, "REAL : " , X );
 printf ( "%c%s%f", N, "REAL : " , PI );
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar
} // end method_10 ()

/** 
  Metodo 11. 
*/
void method_11 ( void ){
    // PROGRAMA PARA LER E IMPRIMIR UM VALOR INTEIRO
// VARIAVEL:
 int X = 0;
// identificar
 printf ( "EXEMPLO0201 - LER E IMPRIMIR UM VALOR INTEIRO" );
 printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nO VALOR DIGITADO FOI: %d", X );
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_11 ()

/** 
  Metodo 12. 
*/
void method_12 ( void ){
    // PROGRAMA PARA LER E IMPRIMIR UM VALOR REAL
// VARIAVEL:
 float X = 0.0;
// identificar
 printf ( "EXEMPLO0202 - LER E IMPRIMIR UM VALOR REAL" );
 printf ( "\nFORNECER UM VALOR REAL QUALQUER: " );
 scanf ( "%f", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nO VALOR DIGITADO FOI: %f", X );
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_12 ()

/** 
  Metodo 13. 
*/
void method_13 ( void ){
    // PROGRAMA PARA LER E IMPRIMIR UM CARACTERE
// VARIAVEL:
 char X = '0';
// identificar
 printf ( "EXEMPLO0203 - LER E IMPRIMIR UM CARACTERE" );
 printf ( "\nFORNECER UM CARACTERE QUALQUER: " );
 scanf ( "%c", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nO VALOR DIGITADO FOI: %c", X );
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_13 ()

/** 
  Metodo 14. 
*/
void method_14 ( void ){
    // PROGRAMA PARA LER E IMPRIMIR, NO MAXIMO, 10 CARACTERES
// VARIAVEL:
 char X [10];
// identificar
 printf ( "EXEMPLO0204 - LER E IMPRIMIR, NO MAXIMO, 09 CARACTERES" );
 printf ( "\nDIGITE, NO MAXIMO, 09 CARACTERES QUAISQUER: " );
 scanf ( "%s", X ); // OBS.: NAO usar o (&) para caracteres !
 getchar( ); // limpar a entrada de dados
 printf ( "\nFOI DIGITADO: %s", X );
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_14 ()

/** 
  Metodo 15. 
*/
void method_15 ( void ){
// PROGRAMA PARA LER E SOMAR DOIS VALORES INTEIROS
// VARIAVEIS:
 int X=0, Y=0, Z=0;
// identificar
 printf ( "EXEMPLO0205 - LER E SOMAR DOIS VALORES INTEIROS" );
 printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nFORNECER OUTRO VALOR INTEIRO QUALQUER: " );
 scanf ( "%d", &Y );
 getchar( ); // limpar a entrada de dados
 Z = X + Y;
 printf ( "\nA SOMA DOS DOIS = %d", Z );
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_15 ()

/** 
  Metodo 16. 
*/
void method_16 ( void ){
    // PROGRAMA PARA LER E SUBTRAIR DOIS VALORES REAIS
// VARIAVEIS:
 float X=0.0, Y=0.0, Z=0.0;
// identificar
 printf ( "EXEMPLO0206 - LER E SUBTRAIR DOIS VALORES REAIS" );
 printf ( "\nFORNECER UM VALOR REAL QUALQUER: " );
 scanf ( "%f", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nFORNECER OUTRO VALOR REAL QUALQUER: " );
 scanf ( "%f", &Y );
 getchar( ); // limpar a entrada de dados
 Z = X - Y;
 printf ( "\nA DIFERENCA ENTRE OS DOIS = %f", Z );
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_16 ()

/** 
  Metodo 17. 
*/
void method_17 ( void ){
    // PROGRAMA PARA OPERAR VALORES LOGICOS
// VARIAVEIS:
 bool X=false, Y=false, Z=false;
// identificar
 printf ( "EXEMPLO0207 - OPERAR VALORES LOGICOS" );
 X = true;
 Y = false;
 Z = X || Y; // X ou Y
 printf ( "\nA DISJUNCAO ENTRE VERDADEIRO E FALSO = %d", Z );
 Z = X && Y; // X e Y
 printf ( "\nA CONJUNCAO ENTRE VERDADEIRO E FALSO = %d", Z );
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_17 ()
    
/** 
  Metodo 18. 
*/
void method_18 ( void ){
    // PROGRAMA PARA CALCULAR A VELOCIDADE DE UM VEICULO
// VARIAVEIS:
 float D = 0.0,// Distancia
T = 0.0, // Tempo
V = 0.0;// Velocidade
// identificar
 printf ( "EXEMPLO0208 - CALCULAR A VELOCIDADE DE UM VEICULO" );
 printf ( "\nFORNECER UMA DISTANCIA QUALQUER EM METROS: " );
 scanf ( "%f", &D );
 getchar( ); // limpar a entrada de dados
 printf ( "\nFORNECER O TEMPO PARA PERCORRE-LA EM SEGUNDOS: " );
 scanf ( "%f", &T );
 getchar( ); // limpar a entrada de dados
 V = D / T;
 printf ( "\nV = D / T = %f%s", V, " m/s " );
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_18 ()

/** 
  Metodo 19. 
*/
void method_19 ( void ){
    // PROGRAMA PARA COMPARAR CARACTERES COM UMA SENHA
// CONSTANTE:
 const char SENHA[5] = "XXXX";
// VARIAVEL:
 char S [10];
// identificar
 printf ( "EXEMPLO0209 - COMPARAR CARACTERES COM UMA SENHA" );
 printf ( "\nFORNECER UMA CADEIA DE CARACTERES QUALQUER: " );
 scanf ( "%s", S ); // OBS.: NAO usar o (&) para caracteres !
 getchar( ); // limpar a entrada de dados
 printf ( "\nA COMPARACAO COM A SENHA = %d", (strcmp(S,SENHA)==0)?1:0 );
// strcmp(S1,S2) compara S1 com S2
// igual a 0: S1 = S2 => 1 ( verdadeiro )
// diferente: S1 <> S2 => 0 ( falso )
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_19 ()

/** 
  Metodo 20. 
*/
void method_20 ( void ){
    // PROGRAMA PARA CALCULAR O ARCO TRIGONOMETRICO DE UM SENO
// CONSTANTE:
 const double PI = 3.14;
// VARIAVEIS:
 double ARCO = 0.0,
 COSSENO = 0.0,
 SENO = 0.0,
 TANGENTE = 0.0;
// identificar
 printf ( "EXEMPLO0210 - CALCULAR O ARCO TRIGONOMETRICO DE UM SENO" );
 printf ( "\nFORNECER O VALOR DO SENO: " );
 scanf ( "%lf", &SENO );
 getchar( ); // limpar a entrada de dados
 COSSENO = sqrt( 1.0 - pow(SENO,2) ); // raiz quadrada
 TANGENTE = SENO / COSSENO;
 ARCO = atan( TANGENTE ); // arcotangente
 printf ( "\nO ARCO TRIGONOMETRICO EM GRAUS = %lf", (ARCO*180.0/PI) );
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_20 ()

/** 
  Metodo 21. 
*/
void method_21 ( void ){
// PROGRAMA PARA LER UM VALOR INTEIRO E VERIFICAR SE E' ZERO
// VARIAVEL:
 int X = 0;
 printf ( "EXEMPLO301 - LER E TESTAR UM VALOR INTEIRO" );
 printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 if ( X == 0 )
 printf ( "\nO VALOR DIGITADO FOI ZERO" );
 else
 printf ( "\nO VALOR DIGITADO NAO FOI ZERO" );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_21 ()

/** 
  Metodo 22. 
*/
void method_22 ( void ){
    // PROGRAMA PARA LER UM REAL E TESTAR SE DIFERENTE DE ZERO
// VARIAVEL:
 float X = 0.0;
 printf ( "EXEMPLO302 - LER E TESTAR UM VALOR REAL" );
 printf ( "\nFORNECER UM VALOR REAL DIFERENTE DE ZERO: " );
 scanf ( "%f", &X );
 getchar( ); // limpar a entrada de dados
 if( X != 0.0 )
 printf ( "\nO VALOR DIGITADO FOI DIFERENTE DE ZERO" );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_22 ()

/** 
  Metodo 23. 
*/
void method_23 ( void ){
    // PROGRAMA PARA LER CARACTERE E VERIFICAR SE E' UM ALGARISMO
// VARIAVEL:
 char X = '0';
 printf ( "EXEMPLO303 - LER E TESTAR UM CARACTERE" );
 printf ( "\nFORNECER UM ALGARISMO QUALQUER: " );
 scanf ( "%c", &X );
 getchar( ); // limpar a entrada de dados
 if( X >= '0' && X <= '9' )
 {
 printf ( "\nO VALOR DIGITADO FOI UM ALGARISMO" );
 printf ( "\nO ALGARISMO DIGITADO FOI: %c", X );
 } // if ALGARISMO
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_23 ()
    
/** 
  Metodo 24. 
*/
void method_24 ( void ){
    // PROGRAMA PARA LER CARACTERE E TESTAR SE NAO E' ALGARISMO
// VARIAVEL:
 char X = '0';
 printf ( "EXEMPLO304 - LER E TESTAR CARACTERE" );
 printf ( "\nFORNECER UM CARACTERE QUALQUER: " );
 scanf ( "%c", &X );
 getchar( ); // limpar a entrada de dados
 if( !( X >= '0' && X <= '9') )
 {
 printf ( "\nNAO FOI DIGITADO UM ALGARISMO" );
 printf ( "\nFOI DIGITADO O CARACTERE: %c", X );
 } // if NAO ALGARISMO
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_24 ()

/** 
  Metodo 25. 
*/
void method_25 ( void ){
    // PROGRAMA PARA LER E TESTAR A IGUALDADE DE DOIS INTEIROS
// VARIAVEIS:
 int X=0, Y=0;
 printf ( "EXEMPLO305 - LER E TESTAR DOIS VALORES INTEIROS" );
 printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nFORNECER OUTRO VALOR INTEIRO QUALQUER: " );
 scanf ( "%d", &Y );
 getchar( ); // limpar a entrada de dados
 if( X == Y )
 printf ( "\nDOIS VALORES IGUAIS" );
 else
 {
 printf ( "\n%d", X );
 printf ( " DIFERENTE DE " );
 printf ( "%d", Y );
 }
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_25 ()

/** 
  Metodo 26. 
*/
void method_26 ( void ){
    // PROGRAMA PARA LER E TESTAR DOIS VALORES REAIS
// VARIAVEIS:
 double X=0.0, Y=0.0;
 printf ( "EXEMPLO306 - LER E TESTAR DOIS VALORES REAIS" );
 printf ( "\nFORNECER UM VALOR REAL QUALQUER: " );
 scanf ( "%lf", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nFORNECER OUTRO VALOR REAL QUALQUER: " );
 scanf ( "%lf", &Y );
 getchar( ); // limpar a entrada de dados
 if( ! (X == Y) ){
 printf ( "\n%lf", X );
 printf ( " DIFERENTE DE " );
 printf ( "%lf", Y );
 } else{
 printf ( "VALORES IGUAIS" );
 } // if VALORES DIFERENTES
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_26 ()

/** 
  Metodo 27. 
*/
void method_27 ( void ){
    // PROGRAMA PARA TRATAR ALTERNATIVAS COM VALORES LOGICOS
// VARIAVEIS:
 int X=0, Y=0;
 bool Z=false;
 printf ( "EXEMPLO307 - TRATAR VALORES LOGICOS" );
 printf ( "\nFORNECER UM VALOR INTEIRO QUALQUER: " );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nFORNECER OUTRO VALOR INTEIRO QUALQUER: " );
 scanf ( "%d", &Y );
 getchar( ); // limpar a entrada de dados
 Z = (X == Y);
 if( Z )
 printf ( "VALORES IGUAIS" );
 else{
 printf ( "VALORES DIFERENTES" );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
 }
} // end method_27 ()

/** 
  Metodo 28. 
*/
void method_28 ( void ){
// PROGRAMA PARA LER E TESTAR UMA LETRA
// VARIAVEL:
 char X = '0';
 printf ( "EXEMPLO308 - LER E TESTAR UMA LETRA" );
 printf ( "\nFORNECER UMA LETRA QUALQUER: " );
 scanf ( "%c", &X );
 getchar( ); // limpar a entrada de dados
 if( X >= 'A' && X <= 'Z' )
 printf ( "FOI DIGITADA UMA LETRA MAIUSCULA" );
 else
 if( X >= 'a' && X <= 'z' )
 printf ( "FOI DIGITADA UMA LETRA MINUSCULA" );
 else
 printf ( "NAO FOI DIGITADA UMA LETRA" );
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_28 ()

/** 
  Metodo 29. 
*/
void method_29 ( void ){
    // PROGRAMA PARA COMPARAR CARACTERES < , = , >
// VARIAVEL:
 char X = '0';
 printf ( "EXEMPLO309 - COMPARAR CARACTERES < , = , >" );
 printf ( "\nFORNECER UM DOS CARACTERES CITADOS: " );
 scanf ( "%c", &X );
 getchar( ); // limpar a entrada de dados
 switch( X )
 {
 case '>': printf ( "FOI DIGITADO O SINAL DE MAIOR" );
 break;
 case '=': printf ( "FOI DIGITADO O SINAL DE IGUAL" );
 break;
 case '<': printf ( "FOI DIGITADO O SINAL DE MENOR" );
 break;
 default : printf ( "FOI DIGITADO UM OUTRO CARACTERE QUALQUER" );
 } // COMPARACAO DE X COM < , = , >
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar
} // end method_29 ()

/** 
  Metodo 30. 
*/
void method_30 ( void ){
    // PROGRAMA PARA IDENTIFICAR CARACTERES
// VARIAVEL
 char X = '0';
 printf ( "EXEMPLO310 - IDENTIFICAR CARACTERES" );
 printf ( "\nFORNECER UM CARACTERE QUALQUER: " );
 scanf ( "%c", &X );
 getchar( ); // limpar a entrada de dados
 switch ( X )
 {
 case 'A':
 case 'E':
 case 'I':
 case 'O':
 case 'U': printf ( "FOI DIGITADO UMA VOGAL" );
 break;
 case '0':
 case '1':
 case '2':
 case '3':
 case '4':
 case '5':
 case '6':
 case '7':
 case '8':
 case '9': printf ( "FOI DIGITADO UM ALGARISMO" );
 printf ( "\nO NUMERO CORRESPONDENTE = %d", (X-48) );
 break;
 default: printf ( "FOI DIGITADO UM OUTRO CARACTERE QUALQUER" );
 } // IDENTIFICACAO DE UM CARACTERE
 printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar
} // end method_30()

/** 
  Metodo 31.
*/
void method_31 ( void ){
    // PROGRAMA PARA LER E IMPRIMIR 03 VALORES INTEIROS
// VARIAVEIS :
 int X = 0,
 CONTADOR = 0;
// identificar
 printf ( "EXEMPLO0401 - LER E IMPRIMIR 03 VALORES INTEIROS" );
 printf ( "\n" ); // mudar de linha
 CONTADOR = 1;
 while( CONTADOR <= 3 ) // REPETIR
 {
 printf ( "\n" ); // mudar de linha
 printf ( "%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
 CONTADOR = CONTADOR + 1;
 } // ENQUANTO ( CONTADOR <= 3 )
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_31()

/** 
  Metodo 32.
*/
void method_32 ( void ){
    // PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
// VARIAVEIS :
 int X = 0, N = 0, CONTADOR = 0;
// identificar
 printf ( "EXEMPLO0402 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
 printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
 scanf ( "%d", &N );
 getchar( ); // limpar a entrada de dados
 CONTADOR = 1;
 while( CONTADOR <= N )
 {
 printf ( "\n%d", CONTADOR );
 printf ( " FORNECER UM VALOR INTEIRO QUALQUER : " );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
 CONTADOR = CONTADOR + 1;
 } // ENQUANTO ( CONTADOR <= N )
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_32()

/** 
  Metodo 33.
*/
void method_33 ( void ){
    // PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
// VARIAVEIS :
 int X = 0, N = 0;
// identificar
 printf ( "EXEMPLO0403 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
 printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
 scanf ( "%d", &N );
 getchar( ); // limpar a entrada de dados
 while( N > 0 ) // REPETIR
 {
 printf ( "\n%d", N );
 printf ( " FORNECER UM VALOR INTEIRO QUALQUER : " );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
 N = N - 1;
 } // ENQUANTO N > 0
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_33()

/** 
  Metodo 34.
*/
void method_34 ( void ){
    // PROGRAMA PARA LER E IMPRIMIR 03 VALORES INTEIROS
// VARIAVEIS :
 int X = 0,
 CONTADOR = 0;
// identificar
 printf ( "EXEMPLO0404 - LER E IMPRIMIR 03 VALORES INTEIROS\n" );
 for( CONTADOR = 1; CONTADOR <= 3; CONTADOR = CONTADOR+1)
 {
 printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
 } // PARA CONTADOR EM [1:3]
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_34()

/** 
  Metodo 35.
*/
void method_35 ( void ){
    // PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
// VARIAVEIS :
 int X = 0,
 N = 0,
 CONTADOR = 0;
// identificar
 printf ( "EXEMPLO0405 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
 printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
 scanf ( "%d", &N );
 getchar( ); // limpar a entrada de dados
 for( CONTADOR = 1; CONTADOR <= N; CONTADOR++ )
 {
 printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nO VALOR DIGITADO FOI : %d", X );
 } // PARA CONTADOR EM [1:N]
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_35()

/** 
  Metodo 36.
*/
void method_36 ( void ){
    // PROGRAMA PARA LER E IMPRIMIR 03 VALORES INTEIROS
// VARIAVEIS :
 int X = 0,
 CONTADOR = 0;
// identificar
 printf ( "EXEMPLO0406 - LER E IMPRIMIR 03 VALORES INTEIROS\n" );
 CONTADOR = 1;
 do // REPETIR
 {
 printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
 CONTADOR = CONTADOR + 1;
 }
 while( CONTADOR <= 3 ); // ATE' ( CONTADOR > 3 )
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_36()

/** 
  Metodo 37.
*/
void method_37 ( void ){
    // PROGRAMA PARA LER E IMPRIMIR (N) VALORES INTEIROS
// VARIAVEIS :
 int X = 0,
 CONTADOR = 0;
// identificar
 printf ( "EXEMPLO0407 - LER E IMPRIMIR (N) VALORES INTEIROS\n" );
 printf ( "\nFORNECER O NUMERO DE VEZES (N) : " );
 scanf ( "%d", &CONTADOR );
 getchar( ); // limpar a entrada de dados
 do // REPETIR
 {
 printf ( "\n%d. FORNECER UM VALOR INTEIRO : ", CONTADOR );
 scanf ( "%d", &X );
 printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
 CONTADOR = CONTADOR - 1;
 }
 while( CONTADOR > 0 ); // ATE' ( CONTADOR <= 3 )
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_37()

/** 
  Metodo 38.
*/
void method_38 ( void ){
    // PROGRAMA PARA LER E IMPRIMIR INTEIROS DIFERENTES DE ZERO
// VARIAVEL :
 int X = 0;
// identificar
 printf ( "EXEMPLO0408 - LER E IMPRIMIR INTEIROS NAO NULOS\n" );
 printf ( "\nFORNECER UM VALOR INTEIRO (0 = PARAR) : " );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 while ( X != 0 ) // REPETIR
 {
 printf ( "\nO VALOR DIGITADO FOI : %d\n", X );
 printf ( "\nDIGITE UM VALOR INTEIRO QUALQUER : " );
 scanf ( "%d", &X );
 } // ENQUANTO X DIFERENTE DE ZERO
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_38()

/** 
  Metodo 39.
*/
void method_39 ( void ){
    // PROGRAMA PARA LER UM INTEIRO DIFERENTE DE ZERO
// VARIAVEL :
 int X = 0;
// identificar
printf ( "EXEMPLO0409 - PARA LER UM INTEIRO NAO NULO\n" );
 printf ( "\nFORNECER UM VALOR DIFERENTE DE ZERO : " );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 while( X == 0 ) // REPETIR
 {
 printf ( "\nFORNECER UM VALOR DIFERENTE DE ZERO : " );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 } // ENQUANTO X IGUAL A ZERO
 printf ( "\nDIGITADO UM NUMERO DIFERENTE DE ZERO\n" );
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_39()

/** 
  Metodo 40.
*/
void method_40 ( void ){
    // PROGRAMA PARA LER UM INTEIRO DIFERENTE DE ZERO
// VARIAVEL :
 int X = 0;
// identificar
 printf ( "EXEMPLO0410 - LER UM INTEIRO NAO NULO\n" );
 do // REPETIR
 {
 printf ( "\nFORNECER UM VALOR DIFERENTE DE ZERO : " );
 scanf ( "%d", &X );
 getchar( ); // limpar a entrada de dados
 }
 while( X == 0 ); // ATE' X DIFERENTE DE ZERO
 printf ( "\nDIGITADO UM NUMERO DIFERENTE DE ZERO\n" );
// encerrar
 printf ( "\n%s\n", "APERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_40()

/** 
  Metodo 41.
*/
void method_41 ( void ){
    // PROGRAMA PARA CHAMADA DE PROCEDIMENTO SEM PARAMETROS
// identificar
 printf ( "EXEMPLO0501 - CHAMADA A UM PROCEDIMENTO" );
 P1 (1);// chamada ao procedimento
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_41()

/** 
  Metodo 42.
*/
void method_42 ( void ){
    // PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
// identificar
 printf ( "EXEMPLO0502 - CHAMADA COM VARIAVEL GLOBAL\n" );
 for ( X = 1; X <= 5; X = X + 1 )
 P1 (5);// chamar 5 vezes
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_42()

/** 
  Metodo 43.
*/
void method_43 ( void ){
// PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
// identificar
 printf ( "EXEMPLO0503 - CHAMADA/RETORNO COM VARIAVEL GLOBAL\n" );
 X = 0;
 P1 (5); // OBSERVAR A RECURSIVIDADE !
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_43()

/** 
  Metodo 44.
*/
void method_44 ( void ){
    // PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
// identificar
 printf ( "EXEMPLO0904 - CHAMADA/RETORNO COM PARAMETRO\n" );
 P1 ( 1 ); // OBSERVAR REPETICAO FINITA, SEM VARIAVEL GLOBAL !
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_44()

/** 
  Metodo 45.
*/
void method_45 ( void ){
    // PROGRAMA PARA MOSTRAR PASSAGEM DE PARAMETRO POR VALOR
// identificar
 printf ( "EXEMPLO0505 - CHAMADA/RETORNO COM PARAMETRO\n" );
 P1 ( 5 ); // OBSERVAR REPETICAO FINITA, SEM VARIAVEL GLOBAL !
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_45()

/** 
  Metodo 46.
*/
void method_46 ( void ){
    // PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
// identificar
 printf ( "EXEMPLO0506 - CHAMADA/RETORNO COM PARAMETRO\n\n" );
 P1 ( 1 ); // OBSERVAR RECURSIVIDADE INDIRETA !
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_46()

/** 
  Metodo 47.
*/
void method_47 ( void ){
    // PROGRAMA PARA MOSTRAR PASSAGEM DE PARAMETRO POR REFERENCIA
// VARIAVEL LOCAL
 int X;
// identificar
 printf ( "EXEMPLO0507 - CHAMADA/RETORNO COM REFERENCIA\n" );
 X = 0;
 P1 ( X ); // OBSERVAR REPETICAO FINITA !
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR." );
 getchar ( ); // para esperar
} // end method_47()

/** 
  Metodo 48.
*/
void method_48 ( void ){
    // PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
// identificar
 printf ( "EXEMPLO0508 - MULTIPLAS CHAMADAS/RETORNOS\n\n" );
 P1 ( 1 );
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR." );
 getchar( ); // para esperar
} // end method_48()

/** 
  Metodo 49.
*/
void method_49 ( void ){
    // PROGRAMA PARA MOSTRAR O USO DE MODULOS
// identificar
 println ( "EXEMPLO0509 - USO DE MODULOS" );
// encerrar
 pause ( "APERTAR <Enter> PARA TERMINAR." );
} // end method_49()

/** 
  Metodo 50.
*/
void method_50 ( void ){
    // PROGRAMA PARA MOSTRAR O USO DE MODULOS
// VARIAVEIS :
 char* text = "MUDAR DE LINHA";
// identificar
 println ( "EXEMPLO0510 - USO DE MODULOS" );
 printf ( "%c" , EOF );
 printf ( "%s%c", text, EOF );
// encerrar
 pause ( "PRESSIONAR <Enter> PARA TERMINAR." );
} // end method_50()

/** 
  Metodo 51.
*/
void method_51 ( void ){
    // PROGRAMA PARA CONTAR DE 1 ATE' 5, RECURSIVAMENTE
// identificar
 printf ( "EXEMPLO0601 - CONTAR DE 1 A 5 RECURSIVAMENTE\n" );
 CONTAR ( 5 );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_51()

/** 
  Metodo 52.
*/
void method_52 ( void ){
    // PROGRAMA PARA CONTAR 5 10 ATE' 1, RECURSIVAMENTE
// identificar
 printf ( "EXEMPLO0602 - CONTAR DE 5 A 1 RECURSIVAMENTE\n" );
 CONTAR ( 5 );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_52()

/** 
  Metodo 53.
*/
void method_53 ( void ){
    // PROGRAMA RECURSIVO PARA MOSTRAR PARES
// identificar
 printf ( "EXEMPLO0603 - MOSTRAR OS PARES <= 10\n" );
 PARES ( 10 );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_53()

/** 
  Metodo 54.
*/
void method_54 ( void ){
    // PROGRAMA RECURSIVO PARA MOSTRAR PARES
// identificar
 printf ( "EXEMPLO0604 - MOSTRAR OS 5 PRIMEIROS PARES\n" );
 PARES ( 5 );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_54()

/** 
  Metodo 55.
*/
void method_55 ( void ){
    // PROGRAMA RECURSIVO PARA SOMAR PARES
    // DADO:
 int S;
// identificar
 printf ( "EXEMPLO0605 - SOMAR OS 5 PRIMEIROS PARES\n" );
 PARES ( 5 );
 printf ( "\nSOMA DOS 5 PRIMEIROS PARES = %d\n", S );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_55()

/** 
  Metodo 56.
*/
void method_56 ( void ){
    // PROGRAMA RECURSIVO PARA SOMAR PARES
// DADO :
 int SOMA = 0;
// identificar
 printf ( "EXEMPLO0606 - SOMAR OS 5 PRIMEIROS PARES\n" );
 SOMA = PARES ( 5 );
 printf ( "\nSOMA DOS 5 PRIMEIROS PARES = %d\n", SOMA );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_56()

/** 
  Metodo 57.
*/
void method_57 ( void ){
    // PROGRAMA RECURSIVO PARA CONTAR PARES
// identificar
 printf ( "EXEMPLO0607 - CONTAR OS PARES <= 10\n" );
 printf ( "\nPARES <= 10 = %d\n", PARES( 10 ) );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_57()

/** 
  Metodo 58.
*/
void method_58 ( void ){
    // PROGRAMA RECURSIVO PARA ACHAR A POSICAO DE UMA LETRA
// DADO :
 char L = '_';
 STRING30 S = "";
// identificar
 printf ( "EXEMPLO0608 - PROCURAR UMA LETRA EM UMA SENTENCA\n" );
 printf ( "\nFORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : " );
 fgets(S, 30, stdin);
 printf ( "\nFORNECER UMA LETRA PARA SER PROCURADA : " );
 L = getchar ( );
 getchar ( ); // para limpar a entrada de dados
 printf ( "\nRESPOSTA = %d\n", PROCURAR( L,S,0 ) );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_58()

/** 
  Metodo 59.
*/
void method_59 ( void ){
    
// PROGRAMA RECURSIVO PARA PROCURAR UMA LETRA
// DADO :
 char L = '_';
 STRING30 S = "" ;
// identificar
 printf ( "EXEMPLO0609 - POSICAO DE UMA LETRA EM UMA SENTENCA\n" );
 printf ( "\nFORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : " );
 fgets(S, 30, stdin);
 printf ( "\nFORNECER UMA LETRA PARA SER PROCURADA : " );
 L = getchar ( );
 getchar ( ); // para limpar a entrada de dados
 printf ( "\nRESPOSTA = %d\n", PROCURAR ( L,S,0 ) );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_59()

/** 
  Metodo 60.
*/
void method_60 ( void ){
// PROGRAMA RECURSIVO PARA PROCURAR OCORRENCIAS DE UMA LETRA
// DADO :
 char L = '_';
 STRING30 S = "";
 printf ( "EXEMPLO0610 - PROCURAR OCORRENCIAS DE UMA LETRA\n" );
 printf ( "\nFORNECER UMA SENTENCA COM MENOS DE 30 CARACTERES : " );
 fgets(S, 30, stdin);
 printf ( "\nFORNECER UMA LETRA PARA SER PROCURADA : " );
 L = getchar ( );
 getchar ( ); // para limpar a entrada de dados
 printf ( "\nRESPOSTA = %d\n", PROCURAR( L,S,0 ) );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_60()

/** 
  Metodo 61.
*/
void method_61 ( void ){
    // PROGRAMA PARA LER UMA TABELA DE INTEIROS
// VARIAVEIS:
 TABELA V;
 int X = 0;
// identificar
 printf ( "EXEMPLO0701 - LER UM TABELA DE 10 INTEIROS\n" );
// REPETIR PARA CADA POSICAO
 for ( X = 0; X < 10; X++ )
 { // a primeira posicao e' zero !
 printf ( "\nFORNECER O %d o. INTEIRO : ",(X+1) );
 scanf ( "%d", &V[ X ] );
 getchar ( ); // para limpar a entrada de dados
 } // FIM REPETIR
 printf ( "\nVETOR LIDO: \n" );
// REPETIR PARA CADA POSICAO
 for ( X = 0; X < 10; X++ )
 {
 printf ( "%d ", V[ X ] );
 } // FIM REPETIR
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_61()

/** 
  Metodo 62.
*/
void method_62 ( void ){
    // PROGRAMA PARA SOMAR UMA TABELA DE INTEIROS
// VARIAVEIS :
 TABELA V;
 int X = 0,
 SOMA = 0;
// identificar
 printf ( "EXEMPLO0702 - SOMAR UM TABELA DE 10 INTEIROS\n" );
// REPETIR PARA CADA POSICAO
 for ( X = 0; X < 10; X++ )
 {
 printf ( "\nFORNECER O %do. INTEIRO : ",(X+1) );
 scanf ( "%d", &V[ X ] );
 getchar ( ); // para limpar a entrada de dados
 } // FIM REPETIR
 SOMA = 0;
// REPETIR PARA CADA POSICAO
 for ( X = 0; X < 10; X++ )
 SOMA = SOMA + V[ X ];
 printf ( "\nSOMA = %d",SOMA );
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_62()

/** 
  Metodo 63.
*/
void method_63 ( void ){
    // PROGRAMA PARA CALCULAR A MEDIA DE UMA TABELA DE INTEIROS
// VARIAVEIS :
 TABELA V;
 float MEDIA = 0.0;
 int X = 0 ,
 SOMA = 0 ;
// identificar
 printf ( "EXEMPLO0703 - MEDIA DE UMA TABELA DE 10 INTEIROS\n" );
// REPETIR PARA CADA POSICAO
 for ( X = 0; X < 10; X++ )
 {
 printf ( "\nFORNECER O %do. INTEIRO : ",(X+1) );
 scanf ( "%d", &V[ X ] );
 getchar ( ); // para limpar a entrada de dados
 } // FIM REPETIR
 SOMA = 0;
// REPETIR PARA CADA POSICAO
 for ( X = 0; X < 10; X++ )
 SOMA = SOMA + V[ X ];
 MEDIA = SOMA / 10.0;
 printf ( "\nMEDIA = %f\n", MEDIA );
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_63()

/** 
  Metodo 64.
*/
void method_64 ( void ){
// PROGRAMA PARA LER UMA PALAVRA
// VARIAVEIS :
 STRING10 PALAVRA;
 int X = 0;
// identificar
 printf ( "EXEMPLO0704 - LER UMA PALAVRA\n" );
 printf ( "\nFORNECER UMA PALAVRA (NO MAXIMO 09 LETRAS) : " );
 fgets ( PALAVRA, 10, stdin );
 printf ( "\nLETRAS DA PALAVRA LIDA : " );
// REPETIR PARA CADA POSICAO
 for ( X = 0; X < strlen( PALAVRA ); X++ )
 printf ( "%c ", PALAVRA[ X ] );
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_64()

/** 
  Metodo 65.
*/
void method_65 ( void ){
    // PROGRAMA PARA PROCURAR LETRA EM PALAVRA
// VARIAVEIS :
 STRING10 PALAVRA;
 char LETRA = '_';
 int X = 0 ;
 bool ACHAR = false;
// identificar
 printf ( "EXEMPLO0705 - PROCURAR LETRA EM UMA PALAVRA\n" );
 printf ( "\nDIGITAR UMA PALAVRA (NO MAXIMO 09 LETRAS) : " );
 fgets ( PALAVRA, 10, stdin );
 printf ( "\nFORNECER A LETRA A SER PROCURADA : " );
 LETRA = getchar ( );
 getchar ( ); // para limpar a entrada de dados
 ACHAR = false;
 X = 0;
// REPETIR PARA CADA POSICAO
 while ( X < strlen( PALAVRA ) && ! ACHAR )
 {
 if( PALAVRA[ X ] == LETRA )
 ACHAR = true;
 else
 X = X + 1;
 } // FIM REPETIR
 if ( ACHAR )
 printf ( "LETRA ENCONTRADA" );
 else
 printf ( "LETRA NAO ENCONTRADA" );
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_65()

/** 
  Metodo 66.
*/
void method_66 ( void ){
// PROGRAMA PARA AVALIAR UM POLINOMIO
// VARIAVEIS :
 POLINOMIO P;
 int Y = 0 , N = 0 ;
 double X = 0.0, PX = 0.0;
// identificar
 printf ( "EXEMPLO0706 - LER COEFICIENTES DE UM POLINOMIO\n" );
 printf ( "\nFORNECER O GRAU DO POLINOMIO : " );
 scanf ( "%d", &N );
 getchar ( ); // para limpar a entrada de dados
// REPETIR PARA CADA POSICAO
 for ( Y = 0; Y <= N; Y++ )
 {
 printf ( "\nFORNECER O %do. COEFICIENTE : ", (Y+1) );
 scanf ( "%lf", &P[ Y ] );
 getchar ( ); // para limpar a entrada de dados
 } // FIM REPETIR
 printf ( "\nFORNECER O PONTO DE AVALIACAO : " );
 scanf ( "%lf", &X );
 getchar ( ); // para limpar a entrada de dados
 PX = 0.0;
// REPETIR PARA CADA POSICAO
// DA ULTIMA ATE' A PRIMEIRA
 for ( Y = N; Y >= 0; Y-- )
 PX = PX * X + P[ Y ];
 printf ( "\nP(%lf) = %lf", X, PX );
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_66()

/** 
  Metodo 67.
*/
void method_67 ( void ){
    
// PROGRAMA PARA AVALIAR O COMPRIMENTO DE UM VETOR
// VARIAVEIS :
 VETOR1 V;
 int X = 0 ;
 double SOMA = 0.0;
// identificar
 printf ( "EXEMPLO0707 - COMPRIMENTO DE UM VETOR\n" );
 printf ( "\nFORNECER O VALOR DE X : " );
 scanf ( "%d", &V[0] );
 getchar ( ); // para limpar a entrada de dados
 printf ( "\nFORNECER O VALOR DE Y : " );
 scanf ( "%d", &V[1] );
 getchar ( ); // para limpar a entrada de dados
 printf ( "\nFORNECER O VALOR DE Z : " );
 scanf ( "%d", &V[2] );
 getchar ( ); // para limpar a entrada de dados
 SOMA = 0.0;
// REPETIR PARA CADA POSICAO
 for( X = 0; X < 3; X++ )
 SOMA = SOMA + V[ X ]*V[ X ];
 printf ( "\nCOMPRIMENTO = %lf", sqrt( SOMA ) );
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_67()

/** 
  Metodo 68.
*/
void method_68 ( void ){
    // PROGRAMA PARA LER UMA MATRIZ
// VARIAVEIS :
 MATRIZ M;
 int X = 0, Y = 0;
// identificar
 printf ( "EXEMPLO0708 - LER UMA MATRIZ INTEIRA 2x2\n" );
// REPETIR PARA CADA LINHA
 for ( X = 0; X < 2; X++ )
 { // REPETIR PARA CADA COLUNA
 for ( Y = 0; Y < 2; Y++ )
 {
 printf ( "\nFORNECER ELEMENTO %d, %d : ",(X+1), (Y+1) );
 scanf ( "%d", &M[ X ][ Y ] );
 getchar ( ); // para limpar a entrada de dados
 } // FIM REPETIR
 } // FIM REPETIR
 printf ( "\n" );
// REPETIR PARA CADA LINHA
 for ( X = 0; X < 2; X++ )
 { // REPETIR PARA CADA COLUNA
 for ( Y = 0; Y < 2; Y++ )
 printf ( "%d ", M[ X ][ Y ] );
 printf ( "\n" );
 } // FIM REPETIR
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_68()

/** 
  Metodo 69.
*/
void method_69 ( void ){
    // PROGRAMA PARA MONTAR A TRANSPOSTA DE UMA MATRIZ
// VARIAVEIS :
 MATRIZ M, // MATRIZ ORIGINAL
 MT; // MATRIZ TRANSPOSTA
 int X = 0, Y = 0;
// identificar
 printf ( "EXEMPLO0709 - TRANSPOR UMA MATRIZ INTEIRA 2x2\n" );
// REPETIR PARA CADA LINHA
 for ( X = 0; X < 2; X++ )
 { // REPETIR PARA CADA COLUNA
 for ( Y = 0; Y < 2; Y++ )
 {
 printf ( "\nFORNECER ELEMENTO %d, %d : ",(X+1), (Y+1) );
 scanf ( "%d", &M[ X ][ Y ] );
 getchar ( ); // para limpar a entrada de dados
 MT[ Y ][ X ] = M[ X ][ Y ];
 } // FIM REPETIR
 } // FIM REPETIR
 printf ( "\n" );
// REPETIR PARA CADA LINHA
 for ( X = 0; X < 2; X++ )
 { // REPETIR PARA CADA COLUNA
 for ( Y = 0; Y < 2; Y++ )
 printf ( "%d ", M[ X ][ Y ] );
 printf ( "\n" );
 } // FIM REPETIR
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_69()

/** 
  Metodo 70.
*/
void method_70 ( void ){
    // PROGRAMA PARA MOSTRAR A DIAGONAL DE UMA MATRIZ
// VARIAVEIS :
 MATRIZ M;
 int X = 0, Y = 0;
// identificar
 printf ( "EXEMPLO0710 - MOSTRAR A DIAGONAL DE UMA MATRIZ\n" );
// REPETIR PARA CADA LINHA
 for ( X = 0; X < ORDEM; X++ )
 { // REPETIR PARA CADA COLUNA
 for ( Y = 0; Y < ORDEM; Y++ )
 {
 printf ( "\nFORNECER ELEMENTO %d, %d : ",(X+1), (Y+1) );
 scanf ( "%d", &M[ X ][ Y ] );
 getchar ( ); // para limpar a entrada de dados
 } // FIM REPETIR
 } // FIM REPETIR
 printf ( "\n" );
// REPETIR PARA CADA LINHA
 for ( X = 0; X < ORDEM; X++ )
 { // REPETIR PARA CADA COLUNA
 for ( Y = 0; Y < ORDEM; Y++ )
 {
 if ( X == Y ) // SE ESTIVER NA DIAGONAL
 printf ( "%d ", M[ X ][ Y ] );
 } // FIM REPETIR
 } // FIM REPETIR
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_70()

/** 
  Metodo 71.
*/
void method_71 ( void ){
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
 PONTOS P1, P2, P3;
 double D = 0.0;
// identificar
 printf ( "EXEMPLO0801 - DISTANCIA ENTRE PONTOS\n" );
 printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
 scanf ( "%lf %lf %lf", &P1.X, &P1.Y, &P1.Z );
 getchar ( ); // para limpar a entrada de dados
 printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
 scanf ( "%lf %lf %lf", &P2.X, &P2.Y, &P2.Z );
 getchar ( ); // para limpar a entrada de dados
 P3.X = P2.X - P1.X;
 P3.Y = P2.Y - P1.Y;
 P3.Z = P2.Z - P1.Z;
 D = sqrt ( pow(P3.X, 2.0) +
 pow(P3.Y, 2.0) +
 pow(P3.Z, 2.0) );
 printf ( "\n DISTANCIA = %lf", D );
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_71()

/** 
  Metodo 72.
*/
void method_72 ( void ){
    // PROGRAM PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
 PONTOS P1, P2;
 double D = 0.0;
// identificar
 printf ("EXEMPLO0802 - DISTANCIA ENTRE PONTOS\n" );
 printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
 scanf ( "%lf %lf %lf", &P1.X, &P1.Y, &P1.Z );
 getchar ( ); // para limpar a entrada de dados
 printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
 scanf ( "%lf %lf %lf", &P2.X, &P2.Y, &P2.Z );
 getchar ( ); // para limpar a entrada de dados
 D = sqrt ( pow(P2.X-P1.X, 2.0) +
 pow(P2.Y-P1.Y, 2.0) +
 pow(P2.Z-P1.Z, 2.0) );
 printf ( "\n DISTANCIA = %lf", D );
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_72()

/** 
  Metodo 73.
*/
void method_73 ( void ){
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
 VETOR V;
 double D = 0.0;
// identificar
 printf ( "EXEMPLO0803 - DISTANCIA ENTRE PONTOS\n" );
 printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
 scanf ( "%lf %lf %lf", &V[0].X, &V[0].Y, &V[0].Z );
 getchar ( ); // para limpar a entrada de dados
 printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
 scanf ( "%lf %lf %lf", &V[1].X, &V[1].Y, &V[1].Z );
 getchar ( ); // para limpar a entrada de dados
 D = sqrt ( pow(V[1].X-V[0].X, 2.0) +
 pow(V[1].Y-V[0].Y, 2.0) +
 pow(V[1].Z-V[0].Z, 2.0) );
 printf ("\n DISTANCIA = %lf", D );
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_73()

/** 
  Metodo 74.
*/
void method_74 ( void ){
// PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
 VETOR5 V;
 double D = 0.0;
// identificar
 printf("EXEMPLO0804 - DISTANCIA ENTRE PONTOS\n"); 
 printf("\nENTRE COM O PRIMEIRO PONTO:\n");
 scanf("%lf %lf %lf", &V.P1.X, &V.P1.Y, &V.P1.Z);
 getchar(); // para limpar o buffer de entrada
 printf("\nENTRE COM O SEGUNDO PONTO:\n");
 scanf("%lf %lf %lf", &V.P2.X, &V.P2.Y, &V.P2.Z);  getchar(); // para limpar o buffer de entrada
 D = sqrt(pow(V.P2.X - V.P1.X, 2.0) + pow(V.P2.Y - V.P1.Y, 2.0) + pow(V.P2.Z - V.P1.Z, 2.0));
 printf("\nDISTANCIA = %lf", D);
 printf("\n\nAPERTAR <Enter> PARA TERMINAR");
 getchar(); // para esperar
} // end method_74()

/** 
  Metodo 75.
*/
void method_75 ( void ){
// PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
 PONTO P;
 double D = 0.0;
// identificar
 printf ( "EXEMPLO0805 - DISTANCIA ENTRE PONTOS\n" );
 printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
 scanf ( "%lf %lf %lf", &P.P1.X, &P.P1.Y, &P.P1.Z );
 getchar ( ); // para limpar a entrada de dados
 printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
 scanf ( "%lf %lf %lf", &P.P2.X, &P.P2.Y, &P.P2.Z );
 getchar ( ); // para limpar a entrada de dados
 D = sqrt ( pow(P.P2.X-P.P1.X, 2.0) +
 pow(P.P2.Y-P.P1.Y, 2.0) +
 pow(P.P2.Z-P.P1.Z, 2.0) );
 printf ( "\n DISTANCIA = %lf", D );
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_75()

/** 
  Metodo 76.
*/
void method_76 ( void ){
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
 PONTO3 P;
 double D = 0.0;
// identificar
 printf ( "EXEMPLO0806 - DISTANCIA ENTRE PONTOS\n" );
 printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
 scanf ( "%lf %lf %lf", &P.X, &P.Y, &P.Z );
 getchar ( ); // para limpar a entrada de dados
 printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
 scanf ( "%lf %lf %lf", &P.X, &P.Y, &P.Z);
 getchar ( ); // para limpar a entrada de dados
 D = sqrt ( pow(P.X-P.X, 2.0) +
 pow(P.Y-P.Y, 2.0) +
 pow(P.Z-P.Z, 2.0) );
 printf ( "\n DISTANCIA = %lf", D );
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_76()

/** 
  Metodo 77.
*/
void method_77 ( void ){
// PROGRAMA PARA CALCULAR
// A DISTANCIA ENTRE PONTOS
// DADOS:
 PONTO3 P[2];
 double D = 0.0;
// identificar
 printf("EXEMPLO0807 - DISTANCIA ENTRE PONTOS\n");    
 printf("\nENTRE COM O PRIMEIRO PONTO:\n");
 scanf("%lf %lf %lf", &P[0].X, &P[0].Y, &P[0].Z);
 getchar(); // para limpar o buffer de entrada
 printf("\nENTRE COM O SEGUNDO PONTO:\n");
 scanf("%lf %lf %lf", &P[1].X, &P[1].Y, &P[1].Z);
 getchar(); // para limpar o buffer de entrada
 D = sqrt(pow(P[1].X - P[0].X, 2.0) + pow(P[1].Y - P[0].Y, 2.0) + pow(P[1].Z - P[0].Z, 2.0));
 printf("\nDISTANCIA = %lf", D);
 printf("\n\nAPERTAR <Enter> PARA TERMINAR");
 getchar(); // para esperar
} // end method_77()

typedef struct {
double P[3]; // Definindo um vetor de coordenadas (X, Y, Z)
} VETOR9;
/** 
  Metodo 78.
*/
void method_78 ( void ){
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
 VETOR9 P[2];
 double D = 0.0;
// identificar
 printf("EXEMPLO0808 - DISTANCIA ENTRE PONTOS\n");    
 printf("\nENTRE COM O PRIMEIRO PONTO:\n");
 scanf("%lf %lf %lf", &P[0].P[0], &P[0].P[1], &P[0].P[2]);
 getchar(); // para limpar o buffer de entrada
 printf("\nENTRE COM O SEGUNDO PONTO:\n");
 scanf("%lf %lf %lf", &P[1].P[0], &P[1].P[1], &P[1].P[2]);
 getchar(); // para limpar o buffer de entrada
 D = sqrt(pow(P[1].P[0] - P[0].P[0], 2.0) + pow(P[1].P[1] - P[0].P[1], 2.0) + pow(P[1].P[2] - P[0].P[2], 2.0));
 printf("\nDISTANCIA = %lf", D);
 printf("\n\nAPERTAR <Enter> PARA TERMINAR");
 getchar(); // para esperar
} // end method_78()

/** 
  Metodo 79.
*/
void method_79 ( void ){
    // PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
 VETOR P;
 double D = 0.0;
// identificar
 printf ( "EXEMPLO0809 - DISTANCIA ENTRE PONTOS\n" );
 printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n " );
 scanf ( "%lf%lf%lf", &(P[0].X), &(P[0].Y), &(P[0].Z));
 getchar ( ); // para limpar a entrada de dados
 printf ( "\n ENTRE COM O SEGUNDO PONTO : \n " );
 scanf ( "%lf%lf%lf", &(P[1].X), &(P[1].Y), &(P[1].Z));
 getchar ( ); // para limpar a entrada de dados
 D = sqrt ( pow(P[1].X-P[0].X, 2.0) +
 pow(P[1].Y-P[0].Y, 2.0) +
 pow(P[1].Z-P[0].Z, 2.0) );
 printf ( "\n DISTANCIA = %lf", D );
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_79()

/** 
  Metodo 80.
*/
void method_80 ( void ){
// PROGRAMA PARA CALCULAR A DISTANCIA ENTRE PONTOS
// DADOS:
 PONTO P;
 double D = 0.0;
// identificar
 printf ( "EXEMPLO0810 - DISTANCIA ENTRE PONTOS\n");
 printf ( "\n ENTRE COM O PRIMEIRO PONTO : \n ");
 scanf ( "%lf%lf%lf", &(P.P1.X), &(P.P1.Y), &(P.P1.Z));
 getchar ( ); // para limpar a entrada de dados
 printf ( "\n ENTRE COM O SEGUNDO PONTO : \n ");
 scanf ( "%lf%lf%lf", &(P.P2.X), &(P.P2.Y), &(P.P2.Z));
 getchar ( ); // para limpar a entrada de dados
 D = sqrt ( pow(P.P2.X-P.P1.X, 2.0) +
 pow(P.P2.Y-P.P1.Y, 2.0) +
 pow(P.P2.Z-P.P1.Z, 2.0) );
 printf ( "\n DISTANCIA = %lf", D );
// encerrar
 printf ( "\n\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_80()

/** 
  Metodo 81.
*/
void method_81 ( void ){
// PROGRAMA PARA GRAVAR COORDENADAS DE PONTOS
// DADOS:
 PONTOS P;
 int X = 0;
 FILE *A;
// identificar
 printf ( "EXEMPLO0901 - GRAVAR COORDENADAS DE PONTOS \n" );
 A = fopen ( "PONTOS1.TXT", "wt" );
 for ( X = 1; X <= 2; X++ )
 {
 printf ( "\nENTRE COM AS COORDENADAS DE UM PONTO : \n" );
 scanf ( "%lf%lf%lf", &P.X, &P.Y, &P.Z );
 getchar ( ); // para limpar a entrada de dados
 fprintf ( A, "%lf %lf %lf\n", P.X, P.Y, P.Z );
 } // FIM REPETIR
 fclose ( A );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_81()

/** 
  Metodo 82.
*/
void method_82 ( void ){
// PROGRAMA PARA LER ARQUIVO DE PONTOS
// VARIAVEIS :
 PONTOS P;
 int X = 0;
 FILE * A ;
// identificar
 printf ( "EXEMPLO0902 - LER ARQUIVO DE PONTOS \n" );
 A = fopen ( "PONTOS1.TXT", "rt" );
 for ( X = 1; X <= 2; X++ )
 {
 fscanf ( A, "%lf%lf%lf", &P.X, &P.Y, &P.Z );
 printf ( "\nPONTO %d : %lf %lf %lf", X, P.X, P.Y, P.Z );
 } // FIM REPETIR
 fclose ( A );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar ( ); // para esperar
} // end method_82()

/** 
  Metodo 83.
*/
void method_83 ( void ){
// PROGRAMA PARA GRAVAR COORDENADAS DE PONTOS
// DADOS:
 PONTOS P;
 int X = 0;
 FILE * A;
// identificar
 printf ( "EXEMPLO0903 - GRAVAR COORDENADAS DE PONTOS \n" );
 A = fopen ( "PONTOS2.DAT", "wb" );
 for ( X = 1; X <= 2; X++ )
 {
 printf ( "\nENTRE COM AS COORDENADAS DE UM PONTO : \n" );
 scanf ( "%lf%lf%lf", &P.X, &P.Y, &P.Z );
 getchar( ); // para limpar a entrada de dados
 fwrite ( &P, sizeof(PONTOS), 1, A );
 } // FIM REPETIR
 fclose ( A );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar ( ); // para esperar
} // end method_83()

/** 
  Metodo 84.
*/
void method_84 ( void ){
// PROGRAMA PARA LER ARQUIVO DE PONTOS
// DADOS:
 PONTOS P;
 int X = 0;
 FILE *A;
// identificar
 printf ( "EXEMPLO0904 - LER ARQUIVO DE PONTOS \n" );
 A = fopen ( "PONTOS2.DAT", "rb" );
 for( X = 1; X <= 2; X++ )
 {
 fread ( &P, sizeof(PONTOS), 1, A );
 printf ( "\nPONTO %d : %6.2lf %6.2lf %6.2lf\n", X, P.X, P.Y, P.Z );
 } // FIM REPETIR
 fclose(A);
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_84()

/** 
  Metodo 85.
*/
void method_85 ( void ){
// PROGRAMA PARA COPIAR O ARQUIVO COM COORDENADAS DE PONTOS
// DADOS:
 PONTOS P;
 int X = 0;
 FILE *A1, *A2;
// identificar
 printf ( "EXEMPLO0905 - COPIAR COORDENADAS DE PONTOS \n" );
 A1 = fopen ( "PONTOS1.TXT", "rt" );
 A2 = fopen ( "NOVO1.DAT" , "wb" );
 for ( X = 1; X <= 2; X++ )
 {
 fscanf ( A1, "%lf%lf%lf\n", &P.X, &P.Y, &P.Z );
 fwrite ( &P, sizeof(PONTOS), 1, A2 );
 printf ( "\nCOPIADO %d : %6.2lf %6.2lf %6.2lf\n", X, P.X, P.Y, P.Z );
 } // FIM REPETIR
 fclose ( A1 );
 fclose ( A2 );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_85()

/** 
  Metodo 86.
*/
void method_86 ( void ){
// PROGRAMA PARA ACRESCENTAR COORDENADAS DE PONTOS
// DADOS:
 PONTOS P;
 int X = 0;
 FILE *A;
// identificar
 printf ( "EXEMPLO0906 - ACRESCENTAR COORDENADAS DE PONTOS \n" );
 A = fopen ( "PONTOS2.DAT", "r+b" );
 while( ! feof(A) )
 fread ( &P, sizeof(PONTOS), 1, A ); // LER ATE' O FIM DE ARQUIVO
 fseek ( A, 0L, SEEK_CUR ); // MARCAR A POSICAO
 for ( X = 3; X <= 4; X++ )
 {
 printf ( "\nENTRE COM AS COORDENADAS DE OUTRO PONTO (%d): \n", X );
 scanf ( "%lf%lf%lf", &P.X, &P.Y, &P.Z );
 getchar ( ); // para limpar a entrada de dados
 fwrite ( &P, sizeof(PONTOS), 1, A );
 } // FIM REPETIR
 fseek ( A, 0L, SEEK_SET ); // VOLTAR AO INICIO
 fread ( &P, sizeof(PONTOS), 1, A ); // LER O PRIMEIRO DO ARQUIVO
 while( ! feof(A) )
 {
 printf ( "\nPONTO %d : %6.2lf %6.2lf %6.2lf\n", X, P.X, P.Y, P.Z );
 fread ( &P, sizeof(PONTOS), 1, A ); // LER ATE' O FIM DE ARQUIVO
 } // FIM REPETIR
 fclose ( A );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_86()

/** 
  Metodo 87.
*/
void method_87 ( void ){
    // PROGRAMA PARA ACRESCENTAR COORDENADAS DE PONTOS
// DADOS:
 PONTOS P;
 int X = 0;
 FILE *A;
// identificar
 printf ( "EXEMPLO0907 - ACRESCENTAR COORDENADAS DE PONTOS \n" );
 A = fopen ( "PONTOS1.TXT", "at" );
 for( X = 1; X <= 2; X++ )
 {
 printf ( "\nENTRE COM AS COORDENADAS DE OUTRO PONTO : \n" );
 scanf ( "%lf%lf%lf", &P.X, &P.Y, &P.Z );
 getchar ( ); // para limpar a entrada de dados
 fprintf ( A, "%lf %lf %lf", P.X, P.Y, P.Z );
 fprintf ( A, "%s", "\n" );
 } // FIM REPETIR
 fclose ( A );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_87()

/** 
  Metodo 88.
*/
void method_88 ( void ){
// PROGRAMA PARA PROCURAR COORDENADAS DE PONTOS
// DADOS:
 PONTOS P,
 PROCURADO;
 bool ACHAR = false;
 FILE *A;
// identificar
 printf ( "EXEMPLO0908 - PROCURAR COORDENADAS DE PONTOS \n" );
 printf ( "\nENTRE COM AS COORDENADAS DO PONTO A PROCURAR : \n" );
 scanf ( "%lf%lf%lf", &PROCURADO.X, &PROCURADO.Y, &PROCURADO.Z );
 ACHAR = false;
 A = fopen ( "PONTOS1.TXT", "rt" );
 fscanf ( A, "%lf %lf %lf", &P.X, &P.Y, &P.Z );
 while ( ! feof( A ) && ! ACHAR )
 {
 if ( P.X==PROCURADO.X && P.Y==PROCURADO.Y && P.Z==PROCURADO.Z )
 ACHAR = true;
 fscanf ( A, "%lf%lf%lf", &P.X, &P.Y, &P.Z );
 } // FIM REPETIR
 fclose ( A );
 if ( ACHAR )
 printf ( "\nCOORDENADAS ENCONTRADAS" );
 else
 printf ( "\nCOORDENADAS NAO ENCONTRADAS" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_88()

/** 
  Metodo 89.
*/
void method_89 ( void ){
    // PROGRAMA PARA ALTERAR COORDENADAS DE PONTOS
// DADOS:
 PONTOS P;
 int X = 0;
 FILE *A;
// identificar
 printf ( "EXEMPLO0909 - ALTERAR COORDENADAS DE PONTOS \n" );
 A = fopen( "PONTOS2.DAT", "r+b" );
 for ( X = 1; X <= 2; X++ )
 {
 fseek ( A, (X-1)*sizeof(PONTOS), SEEK_SET ); // o primeiro e' zero
 fread ( &P, sizeof(PONTOS), 1, A );
 printf ( "\nATUAL %d : %6.2lf %6.2lf %6.2lf\n", X, P.X, P.Y, P.Z );
 printf ( "\nENTRE COM AS NOVAS COORDENADAS DO PONTO : \n" );
 scanf ( "%lf%lf%lf", &P.X, &P.Y, &P.Z );
 getchar( ); // para limpar a entrada de dados
 fseek ( A, (X-1)*sizeof(PONTOS), SEEK_SET );
 fwrite ( &P, sizeof(PONTOS), 1, A );
 } // FIM REPETIR
 fclose(A);
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_89()

/** 
  Metodo 90.
*/
void method_90 ( void ){
    // PROGRAMA PARA LER ARQUIVO DE PONTOS DIRETAMENTE
// DADOS:
 PONTOS P;
 int X = 0;
 FILE *A;
// identificar
 printf ( "EXEMPLO0910 - LER ARQUIVO DE PONTOS DIRETAMENTE \n" );
 A = fopen ( "PONTOS2.DAT", "r" );
 for ( X = 2; X > 0; X-- )
 {
 fseek ( A, (X-1) * sizeof (PONTOS), SEEK_SET ); // o primeiro e' zero
 fread ( &P, sizeof(PONTOS), 1, A );
 printf ( "\nPONTO %d : %6.2lf %6.2lf %6.2lf\n", X, P.X, P.Y, P.Z );
 } // FIM REPETIR
 fclose( A );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_90()

/** 
  Metodo 91.
*/
void method_91 ( void ){
    // PROGRAMA PARA DEFINIR E MONTAR CELULA DE DADOS
// DADOS:
 CELULA P;
 P.VALOR = 0;
 P.LINK = NULL;
// identificar
 printf ( "EXEMPLO1001 - MONTAR CELULA \n" );
 printf ( "VALOR = " );
 scanf ( "%d", &P.VALOR );
 getchar ( );
 printf ( "VALOR = %d LINK = %p\n", P.VALOR, P.LINK );
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_91()

/** 
  Metodo 92.
*/
void method_92 ( void ){
    // PROGRAMA PARA DEFINIR E MONTAR CELULA DE DADOS
// DADOS:
 CELULA *P; // APONTADOR PARA CELULA
 P = malloc ( 1*sizeof(CELULA) ); // RESERVAR ESPACO
 (*P).VALOR = 0;
 (*P).LINK = NULL;
// identificar
 printf ( "EXEMPLO1002 - MONTAR CELULA \n" );
 printf ( "VALOR = " );
 scanf ( "%d", &(*P).VALOR );
 getchar ( );
 printf ( "VALOR = %d LINK = %p\n", (*P).VALOR, (*P).LINK );
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_92()

/** 
  Metodo 93.
*/
void method_93 ( void ){
    // PROGRAMA PARA DEFINIR E MONTAR CELULA DE DADOS
// DADOS:
 CELULA *P; // APONTADOR PARA CELULA
 P = malloc ( 1*sizeof(CELULA) ); // RESERVAR ESPACO
 P->VALOR = 0; // OUTRA NOTACAO
 P->LINK = NULL;
// identificar
 printf ( "EXEMPLO1003 - MONTAR CELULA \n" );
 printf ( "VALOR = " );
 scanf ( "%d", &P->VALOR );
 getchar ( );
 printf ( "VALOR = %d LINK = %p\n", P->VALOR, P->LINK );
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_93()

/** 
  Metodo 94.
*/
void method_94 ( void ){
    // PROGRAMA PARA DEFINIR E MONTAR CELULA DE DADOS
// DADOS:
 CELULA *P; // APONTADOR PARA CELULA
 P = calloc ( 1, sizeof(CELULA) ); // OUTRA FORMA DE RESERVAR
 P->VALOR = 0; // OUTRA NOTACAO
 P->LINK = NULL;
// identificar
 printf ( "EXEMPLO1004 - MONTAR CELULA \n" );
 printf ( "VALOR = " );
 scanf ( "%d", &P->VALOR );
 getchar ( );
 printf ( "VALOR = %d LINK = %p\n", P->VALOR, P->LINK );
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_94()

/** 
  Metodo 95.
*/
void method_95 ( void ){
    // PROGRAMA PARA DEFINIR E MONTAR CELULA DE DADOS
// DADOS:
 REF_CELULA P; // APONTADOR PARA CELULA
 P = calloc ( 1, sizeof(CELULA) ); // OUTRA FORMA DE RESERVAR
 P->VALOR = 0; // OUTRA NOTACAO
 P->LINK = NULL;
// identificar
 printf ( "EXEMPLO1005 - MONTAR CELULA \n" );
 printf ( "VALOR = " );
 scanf ( "%d", &P->VALOR );
 getchar ( );
 printf ( "VALOR = %d LINK = %p\n", P->VALOR, P->LINK );
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_95()

/** 
  Metodo 96.
*/
void method_96 ( void ){
    // PROGRAMA PARA DEFINIR E MONTAR CELULA DE DADOS
// DADOS:
 REF_CELULA P = NEW_CELULA ( 0 ); // APONTADOR PARA CELULA
// identificar
 printf ( "EXEMPLO1006 - MONTAR CELULA \n" );
 printf ( "VALOR = " );
 scanf ( "%d", &P->VALOR );
 getchar ( );
 printf ( "VALOR = %d LINK = %p\n", P->VALOR, P->LINK );
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_96()

/** 
  Metodo 97.
*/
void method_97 ( void ){
    // PROGRAMA PARA DEFINIR E MONTAR CELULAS DE DADOS
// DADOS:
 REF_CELULA P1 = NEW_CELULA ( 0 ); // APONTADOR PARA CELULA
 REF_CELULA P2 = NEW_CELULA ( 0 ); // APONTADOR PARA CELULA
// identificar
 printf ( "EXEMPLO1007 - MONTAR CELULAS \n" );
 printf ( "P1: VALOR = " );
 scanf ( "%d", &P1->VALOR );
 getchar ( );
 printf ( "P2: VALOR = " );
 scanf ( "%d", &P2->VALOR );
 getchar ( );
 printf ( "P1: VALOR = %d LINK = %p\n", P1->VALOR, P1->LINK );
 printf ( "P2: VALOR = %d LINK = %p\n", P2->VALOR, P2->LINK );
 P1->LINK = P2; // ligar uma celula a outra
 printf ( "P1: VALOR = %d LINK = %p\n", P1->VALOR, P1->LINK );
 printf ( "P2: VALOR = %d LINK = %p\n", 
 P1->LINK->VALOR, P1->LINK->LINK );
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_97()

/** 
  Metodo 98.
*/
void method_98 ( void ){
    // PROGRAMA PARA DEFINIR E MONTAR CELULAS DE DADOS
// DADOS:
 REF_CELULA P1 = NEW_CELULA ( 0 ); // APONTADOR PARA CELULA
 REF_CELULA P2 = NEW_CELULA ( 0 ); // APONTADOR PARA CELULA
// identificar
 printf ( "EXEMPLO1008 - MONTAR CELULAS \n" );
 printf ( "P1: VALOR = " );
 scanf ( "%d", &P1->VALOR ); getchar ( );
 printf ( "P2: VALOR = " );
 scanf ( "%d", &P2->VALOR ); getchar ( );
 printf ( "P1: VALOR = %d LINK = %p\n", P1->VALOR, P1->LINK );
 printf ( "P2: VALOR = %d LINK = %p\n", P2->VALOR, P2->LINK );
 P1->LINK = P2; // ligar uma celula a outra
 P2 = NEW_CELULA ( 0 );
 printf ( "P3: VALOR = " );
 scanf ( "%d", &P2->VALOR ); getchar ( );
 P1->LINK->LINK = P2; // ligar 'a terceira
 printf ( "P1: VALOR = %d LINK = %p\n", P1->VALOR, P1->LINK );
 printf ( "P2: VALOR = %d LINK = %p\n", 
 P1->LINK->VALOR, P1->LINK->LINK );
 printf ( "P3: VALOR = %d LINK = %p\n", 
 P1->LINK->LINK->VALOR, P1->LINK->LINK->LINK );
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR<Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_98()

/** 
  Metodo 99.
*/
void method_99 ( void ){
    // PROGRAMA PARA DEFINIR E MONTAR CELULAS DE DADOS
// DADOS:
 REF_CELULA P1 = NEW_CELULA ( 0 ); // APONTADOR PARA CELULA
 REF_CELULA P2 = NEW_CELULA ( 0 ); // APONTADOR PARA CELULA
// identificar
 printf ( "EXEMPLO1009 - MONTAR CELULAS \n" );
 printf ( "P1: VALOR = " );
 scanf ( "%d", &P1->VALOR ); getchar ( );
 printf ( "P2: VALOR = " );
 scanf ( "%d", &P2->VALOR ); getchar ( );
 printf ( "P1: VALOR = %d LINK = %p\n", P1->VALOR, P1->LINK );
 printf ( "P2: VALOR = %d LINK = %p\n", P2->VALOR, P2->LINK );
 P1->LINK = P2; // ligar uma celula a outra
 P2 = NEW_CELULA ( 0 );
 printf ( "P3: VALOR = " );
 scanf ( "%d", &P2->VALOR ); getchar ( );
 P1->LINK->LINK = P2; // ligar 'a terceira
 P2 = P1; // comecar no primeiro
 while ( P2 != NULL )
 { // mostrar valor
 printf ( "VALOR = %d LINK = %p\n", P2->VALOR, P2->LINK );
 P2 = P2->LINK; // passar ao proximo
 } // end while
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar ( ); // para esperar
} // end method_99()
/*
  Metodo 100.
*/
void method_100 ( void ){
    // PROGRAMA PARA DEFINIR E MONTAR CELULAS DE DADOS
// DADOS:
 REF_CELULA P1 = NULL; // APONTADOR ESTRUTURAL
 REF_CELULA P2 = NULL; // APONTADOR DE SERVICO
 int x = 0, y = 0;
// identificar
 printf ( "EXEMPLO1010 - MONTAR CELULAS \n" );
 printf ( "VALOR = " );
 scanf ( "%d", &x ); getchar ( );
 P1 = NEW_CELULA ( x ); // montar o primeiro
 for ( y=0; y<4; y=y+1 )
 {
 printf ( "VALOR = " );
 scanf ( "%d", &x ); getchar ( );
 P2 = P1; // comecar no primeiro
 while ( P2->LINK != NULL ) // procurar o ultimo
 P2 = P2->LINK;
 P2->LINK = NEW_CELULA ( x ); // anexar mais outro
 } // end for
 P2 = P1; // comecar no primeiro
 while ( P2 != NULL )
 { // mostrar valor
 printf ( "VALOR = %d LINK = %p\n", P2->VALOR, P2->LINK );
 P2 = P2->LINK; // passar ao proximo
 } // end while
 printf ( "\n" );
// encerrar
 printf ( "\nAPERTAR <Enter> PARA TERMINAR" );
 getchar( ); // para esperar
} // end method_100()


 
/* 
  Funcao principal. 
  @return codigo de encerramento 
  @param argc - quantidade de parametros na linha de comandos 
  @param argv - arranjo com o grupo de parametros na linha de comandos 
*/ 
int main ( int argc, char* argv [ ] ){ 
 // definir dados / resultados 
// definir dados / resultados 
    int opcao = 0; 
 
 // identificar 
    printf ( "%s\n", "Exemplo0005 - Programa = v0.0" ); 
    printf ( "%s\n", "Autor: ___Felipe Rivetti Mizher __" ); 
    printf ( "\n" ); // mudar de linha 
 
 // acoes 
 
 // repetir 
    do 
    { 
// para mostrar opcoes 
    printf ( "\n%s\n", "Opcoes:"        ); 
    printf ( "\n%s"   , "0  - Terminar\n"  ); 
// Adicionei um loop for para mostrar as opções de 1 a 100 para o usúario, para precisar perder tanto tampo digitando.
    for (int i = 1; i <= 100; i++) {
        printf("%d - Metodo %02d\n", i, i);
    }
    printf ( "\n" ); 
 
// ler a opcao do teclado 
    printf  ( "\n%s", "Opcao = " ); 
    scanf  ( "%d", &opcao ); 
    getchar( );  // para limpar a entrada de dados 
 
// para mostrar a opcao lida 
    printf  ( "\n%s%d", " Opcao = ", opcao ); 
 
// escolher acao dependente da opcao 
// Tentei utilizar o loop for para nao precisar digitar os 100 casos do switch, mas nâo consegui implementar para que funcionasse.
    switch ( opcao ) 
    { 
        case 0:  // nao fazer nada 
                break; 
        case 1:  // executar metodo 01 
                method_01(); 
                break; 
        case 2:  // executar metodo 02 
                method_02(); 
                break;
        case 3:  // executar metodo 03 
                method_03(); 
                break;
        case 4:  // executar metodo 04 
                method_04(); 
                break;
        case 5:  // executar metodo 05 
                method_05(); 
                break;
        case 6:  // executar metodo 06 
                method_06(); 
                break;
        case 7:  // executar metodo 07 
                method_07(); 
                break;
        case 8:  // executar metodo 08 
                method_08(); 
                break;
        case 9:  // executar metodo 09
                method_09(); 
                break;
        case 10:  // executar metodo 10 
                method_10(); 
                break;
        case 11:  // executar metodo 11 
                method_11(); 
                break;
        case 12:  // executar metodo 12 
                method_12(); 
                break;
        case 13:  // executar metodo 13 
                method_13(); 
                break;
        case 14:  // executar metodo 14 
                method_14(); 
                break;
        case 15:  // executar metodo 15 
                method_15(); 
                break;
        case 16:  // executar metodo 16 
                method_16(); 
                break;
        case 17:  // executar metodo 17 
                method_17(); 
                break;
        case 18:  // executar metodo 18 
                method_18(); 
                break;
        case 19:  // executar metodo 19 
                method_19(); 
                break;
        case 20:  // executar metodo 20 
                method_20(); 
                break;
        case 21:  // executar metodo 21 
                method_21(); 
                break;
        case 22:  // executar metodo 22 
                method_22(); 
                break;
        case 23:  // executar metodo 23 
                method_23(); 
                break;
        case 24:  // executar metodo 24 
                method_24(); 
                break;
        case 25:  // executar metodo 25 
                method_25(); 
                break;
        case 26:  // executar metodo 26 
                method_26(); 
                break;
        case 27:  // executar metodo 27 
                method_27(); 
                break;
        case 28:  // executar metodo 28 
                method_28(); 
                break;
        case 29:  // executar metodo 29 
                method_29(); 
                break;
        case 30:  // executar metodo 30 
                method_30(); 
                break;
        case 31:  // executar metodo 31 
                method_31(); 
                break;
        case 32:  // executar metodo 32 
                method_32(); 
                break;
        case 33:  // executar metodo 33 
                method_33(); 
                break;
        case 34:  // executar metodo 34 
                method_34(); 
                break;
        case 35:  // executar metodo 35 
                method_35(); 
                break;
        case 36:  // executar metodo 36 
                method_36(); 
                break;
        case 37:  // executar metodo 37 
                method_37(); 
                break;
        case 38:  // executar metodo 38 
                method_38(); 
                break;
        case 39:  // executar metodo 39 
                method_39(); 
                break;
        case 40:  // executar metodo 40 
                method_40(); 
                break;
        case 41:  // executar metodo 41 
                method_41(); 
                break;
        case 42:  // executar metodo 42 
                method_42(); 
                break;
        case 43:  // executar metodo 43 
                method_43(); 
                break;
        case 44:  // executar metodo 44 
                method_44(); 
                break;
        case 45:  // executar metodo 45 
                method_45(); 
                break;
        case 46:  // executar metodo 46 
                method_46(); 
                break;
        case 47:  // executar metodo 47 
                method_47(); 
                break;
        case 48:  // executar metodo 48 
                method_48(); 
                break;
        case 49:  // executar metodo 49 
                method_49(); 
                break;
        case 50:  // executar metodo 50 
                method_50(); 
                break;
        case 51:  // executar metodo 51 
                method_51(); 
                break;
        case 52:  // executar metodo 52 
                method_52(); 
                break;
        case 53:  // executar metodo 53 
                method_53(); 
                break;
        case 54:  // executar metodo 54 
                method_54(); 
                break;
        case 55:  // executar metodo 55 
                method_55(); 
                break;
        case 56:  // executar metodo 56 
                method_56(); 
                break;
        case 57:  // executar metodo 57 
                method_57(); 
                break;
        case 58:  // executar metodo 58 
                method_58(); 
                break;
        case 59:  // executar metodo 59 
                method_59(); 
                break;
        case 60:  // executar metodo 60 
                method_60(); 
                break;
        case 61:  // executar metodo 61 
                method_61(); 
                break;
        case 62:  // executar metodo 62 
                method_62(); 
                break;
        case 63:  // executar metodo 63 
                method_63(); 
                break;
        case 64:  // executar metodo 64 
                method_64(); 
                break;
        case 65:  // executar metodo 65 
                method_65(); 
                break;
        case 66:  // executar metodo 66 
                method_66(); 
                break;
        case 67:  // executar metodo 67 
                method_67(); 
                break;
        case 68:  // executar metodo 68 
                method_68(); 
                break;
        case 69:  // executar metodo 69 
                method_69(); 
                break;
        case 70:  // executar metodo 70 
                method_70(); 
                break;
        case 71:  // executar metodo 71 
                method_71(); 
                break;
        case 72:  // executar metodo 72 
                method_72(); 
                break;
        case 73:  // executar metodo 73 
                method_73(); 
                break;
        case 74:  // executar metodo 74 
                method_74(); 
                break;
        case 75:  // executar metodo 75 
                method_75(); 
                break;
        case 76:  // executar metodo 76 
                method_76(); 
                break;
        case 77:  // executar metodo 77 
                method_77(); 
                break;
        case 78:  // executar metodo 78 
                method_78(); 
                break;
        case 79:  // executar metodo 79 
                method_79(); 
                break;
        case 80:  // executar metodo 80 
                method_80();
                break;
        case 81:  // executar metodo 81 
                method_81(); 
                break;
        case 82:  // executar metodo 82 
                method_82(); 
                break;
        case 83:  // executar metodo 83 
                method_83(); 
                break;
        case 84:  // executar metodo 84 
                method_84(); 
                break;
        case 85:  // executar metodo 85 
                method_85(); 
                break;
        case 86:  // executar metodo 86 
                method_86(); 
                break;
        case 87:  // executar metodo 87 
                method_87(); 
                break;
        case 88:  // executar metodo 88 
                method_88(); 
                break;
        case 89:  // executar metodo 89 
                method_89(); 
                break;
        case 90:  // executar metodo 90 
                method_90(); 
                break;
        case 91:  // executar metodo 91 
                method_91(); 
                break;
        case 92:  // executar metodo 92 
                method_92(); 
                break;
        case 93:  // executar metodo 93 
                method_93(); 
                break;
        case 94:  // executar metodo 94 
                method_94(); 
                break;
        case 95:  // executar metodo 95 
                method_95(); 
                break;
        case 96:  // executar metodo 96 
                method_96(); 
                break;
        case 97:  // executar metodo 97 
                method_97(); 
                break;
        case 98:  // executar metodo 98 
                method_98(); 
                break;
        case 99:  // executar metodo 99 
                method_99(); 
                break;
        case 100:  // executar metodo 100 
                method_100(); 
                break;
    default: // comportamento padrao 
                printf ( "\nERRO: Opcao invalida.\n" ); 
                break; 
    } // end switch 
}
    while ( opcao != 0 );
 // encerrar 
    printf    ( "\n\nApertar ENTER para terminar." ); 
    getchar( );  // aguardar por ENTER 
    return   ( 0 ); // voltar ao SO (sem erros) 
} // end main () 
