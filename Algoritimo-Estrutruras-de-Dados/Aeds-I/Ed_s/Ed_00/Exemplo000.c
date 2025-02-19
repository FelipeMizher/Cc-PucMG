// 821811 - Felipe Rivetti Mizher 

/* 
Exemplo000 - v0.0. - 21 / 08 / 2023 
Author: ____Felipe Rivetti Mizher _____ 
    
Para compilar em terminal (janela de comandos): 
Linux      : gcc -o exemplo000        exemplo000.c 
Windows: gcc -o exemplo000        exemplo000.c 
 
Para executar em terminal (janela de comandos): 
Linux      :  ./Exemplo000 
Windows:    Exemplo000
 */ 
// dependencias 
#include <stdio.h> // para as entradas e saidas 
#include <stdlib.h> // para outras funcoes de uso geral 
#include <stdbool.h> // para valores logicos
#include <string.h> // para lidar com caracteres
#include <math.h> // para operacoes matematicas
#include "my_lib.h"

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
    for (int i = 1; i <= 50; i++) {
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
