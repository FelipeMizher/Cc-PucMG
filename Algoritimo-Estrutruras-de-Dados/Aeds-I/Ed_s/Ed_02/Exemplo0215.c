// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0215 - v0.0. - 29 / 08 / 2023
 Author: ___Felipe Rivetti Mizher_______
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0215 exemplo0215.c
 Windows: gcc -o exemplo0215 exemplo0215.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0215
 Windows: exemplo0215
*/
// Dependencias
#include <stdio.h> // Para as entradas e saidas
#include <stdlib.h> // Para outras funcoes de uso geral

/**
 Method_01.
*/
void method_01 ( void ){
// Definir dados.
    int X;
// Identificar.
    printf ( "%s\n", " Method_01" );
// Ler do teclado.
    printf("Entre com um valor inteiro: ");
    scanf("%d" , &X); getchar();
// Verificar se o numero é impar ou par.
    if(X % 2 == 0){
        printf("O numero e' par (%d)\n" , X);
    } else {
        printf("O numero e' impar (%d)\n" , X);
    }
// Encerrar
 printf ( "\nApertar ENTER para continuar.\n" );
 getchar ( );
} // End method_01 ( )

/**
 Method_02.
*/
void method_02 ( void ){
// Definir dados.
    int X;
// Identificar.
    printf ( "%s\n", " Method_02" );
// Ler do teclado.
    printf("Entre com um valor inteiro: ");
    scanf("%d" , &X); getchar();
// Verificar se o numero é impar e menor que -15 ou par e maior que 15.
    if(X % 2 == 0){
        if(X > 15){
            printf("O numero e' par e maior que 15 (%d)\n" , X);
        } else{
            printf("O numero e' par e menor ou igual a 15 (%d)\n" , X);
        }
    } else {
        if(X < -15){
            printf("O numero e' impar e menor que -15 (%d)\n" , X);
        } else {
            printf("O numero e' impar e maior ou igua a -15 (%d)\n" , X);
        }
    }
// Encerrar
 printf ( "\nApertar ENTER para continuar.\n" );
 getchar ( );
} // End method_02 ( )

/**
 Method_03.
*/
void method_03 ( void ){
// Definir dados.
    int X;
// Identificar.
    printf ( "%s\n", " Method_03" );
// Ler do teclado.
    printf("Entre com um valor inteiro: ");
    scanf("%d" , &X); getchar();
// Verificar se o numero está mo intervalo de numero 25 - 65.
    if(X > 25 && X < 65){
        printf("O numero (%d) pertence ao intervalo.\n" , X);
    } else {
        printf("o numero (%d) nao pertence ao intervalo.\n" , X);
    }
// Encerrar
 printf ( "\nApertar ENTER para continuar.\n" );
 getchar ( );
} // End method_03 ( )

/**
 Method_04.
*/
void method_04 ( void ){
// Definir dados.
    int X;
// Identificar.
    printf ( "%s\n", " Method_04" );
// Ler do teclado.
    printf("Entre com um valor inteiro: ");
    scanf("%d" , &X); getchar();
// Verificar se o numero esta no intervalo de numero 20 - 60,
    if(X >= 20 && X <= 60){
        printf("O numero (%d) pertence ao intervalo.\n" , X);
    } else {
        printf("o numero (%d) nao pertence ao intervalo.\n" , X);
    }
// Encerrar
 printf ( "\nApertar ENTER para continuar.\n" );
 getchar ( );
} // End method_04 ( )

/**
 Method_05.
*/
void method_05 ( void ){
// Definir dados.
    int X;
// Identificar.
    printf ( "%s\n", " Method_05" );
// Ler do teclado.
    printf("Entre com um valor inteiro: ");
    scanf("%d" , &X); getchar();
// Verificar se o numero pertence à interseção ou a apenas a um dos intervalos [15:30] e [25:50].
    if(X >= 25 && X <= 30){
        printf("O numero pertence aos dois intervalos. (%d)\n" , X);
    } else if(X >= 15 && X < 25){
        printf("O numero pertence ao primeiro intervalo. (%d)\n" , X);
    } else if(X > 25 && X <= 50){
        printf("O numero pertence ao segundo intervalo. (%d)\n" , X);
    } else{
        printf("O numero nao pertence a nenhum intervalo. (%d)\n" , X);
    }
// Encerrar
 printf ( "\nApertar ENTER para continuar.\n" );
 getchar ( );
} // End method_05 ( )

/*
 Funcao principal.
 @return codigo de encerramento
 @param argc - quantidade de parametros na linha de comandos
 @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// Definir dado
 int opcao = 0;
// Identificar
 printf ( "%s\n", "Exemplo0200 - Programa = v0.0" );
 printf ( "%s\n", "Autor: ______Felipe Rivetti Mizher______" );
 printf ( "\n" ); // Mudar de linha
// Acoes
// Repetir
 do
 {
 // Para mostrar opcoes
 printf ( "\n%s\n", "Opcoes:" );
 printf ( "\n%s" , "0 - Terminar" );
 printf ( "\n%s" , "1 - Method_01" );
 printf ( "\n%s" , "2 - Method_02" );
 printf ( "\n%s" , "3 - Method_03" );
 printf ( "\n%s" , "4 - Method_04" );
 printf ( "\n%s" , "5 - Method_05" );
 printf ( "\n" );
 // Ler a opcao do teclado
 printf ( "\n%s", "Opcao = " );
 scanf ( "%d", &opcao );
 getchar( ); // Para limpar a entrada de dados
 // Para mostrar a opcao lida
 printf ( "\n%s%d", "Opcao = ", opcao );
 // Escolher acao dependente da opcao
 switch ( opcao )
 {
 case 0: /* nao fazer nada */ break;
 case 1: method_01 ( ); break;
 case 2: method_02 ( ); break;
 case 3: method_03 ( ); break;
 case 4: method_04 ( ); break;
 case 5: method_05 ( ); break;
 default: // Comportamento padrao
 printf ( "\nERRO: Opcao invalida.\n" );
 break;
 } // Rnd switch
 }
 while ( opcao != 0 );
// Encerrar
 printf ( "\n\nApertar ENTER para terminar." );
 getchar( ); // Aguardar por ENTER
 return ( 0 ); // Voltar ao SO (sem erros)
} // End main ( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios

    Sem erros ao executar o problema.
    
----------------------------------------------------------
*/
