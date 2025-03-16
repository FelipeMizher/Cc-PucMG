// 821811 - Felipe Rivetti Mizher

/*
 Exemplo02E1 - v0.0. - 29 / 08 / 2023
 Author: ___Felipe Rivetti Mizher_______
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo02E1 exemplo02E1.c
 Windows: gcc -o exemplo02E1 exemplo02E1.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo02E1
 Windows: exemplo02E1
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

/**
 Method_06.
*/
void method_06 ( void ){
// Definir dados.
    int X, Y;
// Identificar.
    printf ( "%s\n", " Method_06" );
// Ler do teclado.
    printf("Entre com um valor inteiro: ");
    scanf("%d" , &X); getchar();
    
    printf("Entre com um valor inteiro: ");
    scanf("%d" , &Y); getchar();
    
// Pular linha.
    printf("\n");
// Verificar se o primeiro numero é par e se o segundo é impar.
    if (X % 2 == 0) {
        printf("O primeiro valor e' par (%d)\n", X);
    } else {
        printf("O primeiro valor e' impar (%d)\n", X);
    }

    if (Y % 2 == 0) {
        printf("O segundo valor e' par (%d)\n", Y);
    } else {
        printf("O segundo valor e' impar (%d)\n", Y);
    }
// Encerrar
    printf ( "\nApertar ENTER para continuar.\n" );
    getchar ( );
} // End method_06 ( )

/**
 Method_07.
*/
void method_07 ( void ){
// Definir dados.
    int X, Y;
// Identificar.
    printf ( "%s\n", " Method_07" );
// Ler do teclado.
    printf("Entre com um valor inteiro: ");
    scanf("%d" , &X); getchar();
    
    printf("Entre com um valor inteiro: ");
    scanf("%d" , &Y); getchar();
    
// Pular linha.
    printf("\n");
// Verificar se o primeiro numero é par e se o segundo é impar.
    if (X % 2 != 0 && X < 0) {
        printf("O primeiro valor e' impar e negativo (%d)\n" , X);
    } else {
        printf("O primeiro valor e' nao impar nem negativo (%d)\n" , X);
    }
    
    if (Y % 2 == 0 && Y > 0) {
        printf("O segundo valor e' par e positivo (%d)\n" , Y);
    } else {
        printf("O segundo valor e' nao par nem positivo (%d)\n" , Y);
    }

// Encerrar
    printf ( "\nApertar ENTER para continuar.\n" );
    getchar ( );
} // End method_07 ( )

/**
 Method_08.
*/
void method_08 ( void ){
// Definir dados.
    double X, Y;
// Identificar.
    printf ( "%s\n", " Method_08" );
// Ler do teclado.
    printf("Entre com um valor real: ");
    scanf("%lf" , &X); getchar();
    
    printf("Entre com um valor real: ");
    scanf("%lf" , &Y); getchar();
    
// Pular linha.
    printf("\n");  
// Calculos para verificar os numeros.
    X = X * 2.0;
// Verificar se o segundo numero é menor, maior ou igual ao dobro do primeiro numero.
    if(X == Y){
        printf("Os numeros sao iguais.\n");
    } else if(X > Y){
        printf("O primeiro e' maior que o segundo.\n");
    } else{
        printf("O segundo e' maior que o primeiro.\n");
    }
    
// Encerrar
    printf ( "\nApertar ENTER para continuar.\n" );
    getchar ( );
} // End method_08 ( )

/**
 Method_09.
*/
void method_09 ( void ){
// Definir dados.
    double X, Y, Z;
// Identificar.
    printf ( "%s\n", " Method_09" );
// Ler do teclado.
    printf("Entre com o primeiro valor real: ");
    scanf("%lf" , &X); getchar();
    
    printf("Entre com o segundo valor real: ");
    scanf("%lf" , &Y); getchar();
    
    printf("Entre com o terceiro valor real: ");
    scanf("%lf" , &Z); getchar();
    
// Pular linha.
    printf("\n");
// Verificar se o ultimo numero esta entre os dois peimeiros digitados.
    if(Z >= X && Z <= Y){
        printf("O numero (%.4lf) esta dentro do intervalo dos outros dois numeros (%.4lf) (%.4lf)\n" , Z , X , Y);
    } else if(Z <= X && Z >= Y){
        printf("O numero (%.4lf) esta dentro do intervalo dos outros dois numeros (%.4lf) (%.4lf)\n" , Z , Y , X);
    } else {
        printf("O numero (%.4lf) nao esta dentro do intervalo dos outros dois numeros (%.4lf) (%.4lf)\n" , Z , X , Y);
    }

// Encerrar
    printf ( "\nApertar ENTER para continuar.\n" );
    getchar ( );
} // End method_09 ( )

/**
 Method_10.
*/
void method_10 ( void ){
// Definir dados.
    double X, Y, Z;
// Identificar.
    printf ( "%s\n", " Method_10" );
// Ler do teclado.
    printf("Entre com o primeiro valor real: ");
    scanf("%lf" , &X); getchar();
    
    printf("Entre com o segundo valor real: ");
    scanf("%lf" , &Y); getchar();
    
    printf("Entre com o terceiro valor real: ");
    scanf("%lf" , &Z); getchar();
    
// Pular linha.
    printf("\n");
// Verificar se o ultimo numero nao esta entre os dois primeiros e se sao diferentes entre si.
    if(Z == X || Z == Y || X == Y){
        printf("Existe algum numero semelhante ao outro na hora da verificacao (%.4lf) (%.4lf) (%.4lf)\n" , X , Y , Z);
    } else if(Z >= X && Z <= Y){
        printf("O numero (%.4lf) esta dentro do intervalo dos outros dois numeros (%.4lf) (%.4lf)\n" , Z , X , Y);
    } else if(Z <= X && Z >= Y){
        printf("O numero (%.4lf) esta dentro do intervalo dos outros dois numeros (%.4lf) (%.4lf)\n" , Z , Y , X);
    } else {
        printf("O numero (%.4lf) nao esta dentro do intervalo dos outros dois numeros (%.4lf) (%.4lf)\n" , Z , X , Y);
    }
// Encerrar
    printf ( "\nApertar ENTER para continuar.\n" );
    getchar ( );
} // End method_10 ( )

/**
 Method_11.
*/
void method_11 ( void ){
// Definir dados.
    char X, Y, Z;
// Identificar.
    printf ( "%s\n", " Method_11" );
// Ler do teclado.
    printf("Entre com o primeiro caractere: ");
    scanf(" %c" , &X); getchar();
    
    printf("Entre com o segundo caractere: ");
    scanf(" %c" , &Y); getchar();
    
    printf("Entre com o terceiro caractere: ");
    scanf(" %c" , &Z); getchar();
    
// Pular linha.
    printf("\n");
// Verificar se existe algum valor do primeiro caractere é igual a algum outro e se o mesmo esta entre os outros dois.
    if(X == Y || X == Z){
        printf("O primeiro valor é igual a pelo menos um dos outros dois.\n");
    } else if((X > Y && X < Z) || (X < Y && X > Z)){
        printf("O primeiro valor está entre os outros dois.\n");
    } else {
        printf("O primeiro valor não está entre os outros dois nem é igual a nenhum deles.\n");
    }
// Encerrar
    printf ( "\nApertar ENTER para continuar.\n" );
    getchar ( );
} // End method_11 ( )

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
 printf ( "%s\n", "Autor: ______Felipe Rivetti Mizher___" );
 printf ( "\n" ); // Mudar de linha
// Acoes
// Repetir
 do
 {
 // Para mostrar opcoes
 printf ( "\n%s\n", "Opcoes:" );
 printf ( "\n%s" , "0 - Terminar" );
 for(int i = 1; i <= 9; i++){
      printf ( "\n%d - Method_0%d" , i, i );
 }
 printf ( "\n%s" , "10 - Method_10" );
 printf ( "\n%s" , "11 - Method_11" );
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
 case 6: method_06 ( ); break;
 case 7: method_07 ( ); break;
 case 8: method_08 ( ); break;
 case 9: method_09 ( ); break;
 case 10: method_10 ( ); break;
 case 11: method_11 ( ); break;
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
