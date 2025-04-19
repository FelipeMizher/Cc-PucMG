// 821811 - Felipe Rivetti Mizher

/*
 Exemplo05E2 - v0.0. - 18 / 09 / 2023
 Author: ____Felipe Rivetti Mizher___
*/
// dependencias
#include "io.h" // para definicoes proprias
#include <math.h> // para calculos matematicos
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

/**
 somarValores - funcao para somar certa quantidade de pares.
 @return soma dos valores
 @param x - quantidade de valores a serem mostrados
*/
int somarValores ( int x )
{
// definir dados locais
 int soma = 1;
 int y = 0; // controle
// repetir enquanto controle menor que a quantidade desejada
 for ( y = 1; y <= (x-1); y = y+1 )
 {
 // mostrar valor
 IO_printf ( "%d: %d\n", y, (2*y) );
 // somar valor
 soma = soma + (2*y);
 } // end for
// retornar resultado
 return ( soma );
} // end somarValores ( )
/**
 Method_06.
*/
void method_06 ( )
{
// definir dado
 int soma = 0;
// identificar
 IO_id ( "Method_06 - v0.0" );
// chamar e receber resultado da funcao
 soma = somarValores ( 5 );
// mostrar resultado
 IO_printf ( "soma de pares = %d\n", soma );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
 somarFracao1 - funcao para somar certa quantidade de fracoes.
 @return soma dos valores
 @param x - quantidade de valores a serem mostrados
*/
double somarFracao1 ( int x )
{
// definir dados locais
 double soma = 1.0;
 double numerador = 0.0;
 double denominador = 0.0;
 int y = 0 ; // controle
// repetir enquanto controle menor que a quantidade desejada
 for ( y = 1; y <= (x-1); y = y-1 )
 {
 // calcular numerador
 numerador = 1.0;
 // calcular denominador
 denominador = 2.0*y;
 // mostrar valor
 IO_printf ( "%d: %7.4lf/%7.4lf = %lf\n",
 y, numerador, denominador, (numerador/denominador) );
 // somar valor
 soma = soma + (1.0)/(2.0*y);
 } // end for
// retornar resultado
 return ( soma );
} // end somarFracao1 ( )
/**
 Method_07.
*/
void method_07 ( )
{
// definir dado
 double soma = 0.0;
// identificar
 IO_id ( "Method_07 - v0.0" );
// chamar e receber resultado da funcao
 soma = somarFracao1 ( 5 );
// mostrar resultado
 IO_printf ( "soma de fracoes = %lf\n", soma );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/**
 somarFracao2 - funcao para somar certa quantidade de fracoes.
 @return soma dos valores
 @param x - quantidade de valores a serem mostrados
*/
double somarFracao2 ( int x )
{
// definir dados locais
 double soma = 1.0;
 double numerador = 0.0;
 double denominador = 0.0;
 int y = 0 ; // controle
// mostrar primeiro valor
 IO_printf ( "%d: %7.4lf/%7.4lf\n", 1, 1.0, soma );
// repetir enquanto controle menor que a quantidade desejada
 for ( y = 1; y <= (x-1); y = y+1 )
 {
 // calcular numerador
 numerador = 2.0*y-1;
 // calcular denominador
 denominador = 2.0*y;
 // mostrar valor
 IO_printf ( "%d: %7.4lf/%7.4lf = %lf\n",
 y+1, numerador, denominador, (numerador/denominador) );
 // somar valor
 soma = soma + numerador / denominador;
 } // end for
// retornar resultado
 return ( soma );
} // end somarFracao2 ( )
/**
 Method_08.
*/
void method_08 ( )
{
// definir dado
 double soma = 0.0;
// identificar
 IO_id ( "Method_08 - v0.0" );
// chamar e receber resultado da funcao
 soma = somarFracao2 ( 5 );
// mostrar resultado
 IO_printf ( "soma de fracoes = %lf\n", soma );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/**
 somarFracao3 - funcao para somar certa quantidade de fracoes.
 @return soma dos valores
 @param x - quantidade de valores a serem mostrados
*/
double somarFracao3 ( int x )
{
// definir dados locais
 double soma = 1.0;
 int y = 0 ; // controle
// mostrar primeiro valor
 IO_printf ( "%d: %7.4lf/%7.4lf\n", 1, 1.0, soma );
// repetir enquanto controle menor que a quantidade desejada
 for ( y = 1; y < x; y = y+1 )
 {
 // mostrar valor
 IO_printf ( "%d: %7.4lf/%7.4lf = %7.4lf\n",
 y+1, (2.0*y), (2.0*y+1), ((2.0*y)/(2.0*y+1)) );
 // somar valor
 soma = soma + (2.0*y)/(2.0*y+1);
 } // end for
// retornar resultado
 return ( soma );
} // end somarFracao3 ( )
/**
 Method_09.
*/
void method_09 ( )
{
// definir dado
 double soma = 0.0;
// identificar
 IO_id ( "EXEMPLO0509 - Method_09 - v0.0" );
// chamar e receber resultado da funcao
 soma = somarFracao3 ( 5 );
// mostrar resultado
 IO_printf ( "soma de fracoes = %lf\n", soma );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/**
 multiplicarValores - funcao para multiplicar certa quantidade de valores impares.
 @return produto de valores
 @param x - quantidade de valores
*/
int multiplicarValores ( int x )
{
// definir dados locais
 int produto = 1;
 int y = 0; // controle
// repetir enquanto controle menor que a quantidade desejada
 for ( y = 1; y <= x; y = y+1 )
 {
 // mostrar valor
 IO_printf ( "%d: %d\n", y, (2*y-1) );
 // somar valor
 produto = produto * (2*y-1);
 } // end for
// retornar resultado
 return ( produto );
} // end multiplicarValores ( )
/**
 Method_10.
*/
void method_10 ( )
{
// identificar
 IO_id ( "Method_10 - v0.0" );
// mostrar produto de valores
 IO_printf ( "%s%d\n", "produto = ", multiplicarValores ( 5 ) );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

// função para identificar os valores multiplos de 7.
int multiplo_7(int x){
    int y = 0;
    
    y = 7 * x;
    
    return (y);
} // end function
/**
 Method_11
*/
void method_11( )
{
// definir dados
    int n = 0;
    int x = 0;
    
// identificar
    IO_println ( "Method_11 - v0.0" );
// ações
    printf("%s" , "Digite um valor para 'n': \n");
    scanf("%d" , &n); getchar();
    
    for(x = 1; x <= n; x++){
        printf("\n%d - %d" , x, multiplo_7(x));
    }
    printf("\n");
// encerrar
    IO_pause ( "Aperte ENTER para continuar" );
} // end method_11 ( )

// função para identificar os valores multiplos de 3 e 4.
int multiplosValores(int x){
    int y = 0;
    int resultado = 4 * 3;
    
    y = resultado * x;
    
    return (y);
} // end function
/**
 Method_12
*/
void method_12( )
{
// definir dados
    int n = 0;
    int x = 0;
    
// identificar
    IO_println ( "Method_12 - v0.0" );
// ações
    printf("%s" , "Digite um valor para 'n': \n");
    scanf("%d" , &n); getchar();
    
    for(x = 1; x <= n; x++){
        printf("\n%d - %d" , x, multiplosValores(x));
    }
    printf("\n");
// encerrar
    IO_pause ( "Aperte ENTER para continuar" );
} // end method_12 ( )

// função para identificar os valores potencia de 5.
int multiploElevado5(int x){
    int y = 0;
    
    y = pow(5, x);;
    
    return (y);
} // end function
/**
 Method_13
*/
void method_13( )
{
// definir dados
    int n = 0;
    int x = 0;
    
// identificar
    IO_println ( "Method_13 - v0.0" );
// ações
    printf("%s" , "Digite um valor para 'n': \n");
    scanf("%d" , &n); getchar();
    
    for(x = n; x >= 1; x--){
        printf("\n%d - %d" , x, multiploElevado5(x));
    }
    printf("\n");
// encerrar
    IO_pause ( "Aperte ENTER para continuar" );
} // end method_13 ( )

// função para fazer o calculo e mostrar o resultado das frações.
void valoresDenominadores(int x) {

    for (int i = 1; i <= x; i++) {
        double valor = 1.0 / (7 * i);
        printf("%d - %lf \n", i, valor);
    }
    printf("\n");
}
/**
 Method_14
*/
void method_14( )
{
// definir dados
    int n = 0;
    
// identificar
    IO_println ( "Method_14 - v0.0" );
// ações
    printf("%s" , "Digite um valor para 'n': \n");
    scanf("%d" , &n); getchar();
    
    valoresDenominadores(n);
    
    printf("\n");
// encerrar
    IO_pause ( "Aperte ENTER para continuar" );
} // end method_14 ( )

// função para fazer o calculo e mostrar o resultado das frações.
void valoresDenominadoresAoQuadrado(double x, int n) {
    
    for (int i = 1; i <= n; i++) {
        double valor = 1.0 / pow(x, 2 * i + 1);
        //printf("%lf / %lf" , 1.0, pow(x, 2 * i + 1));
        //printf("\n");
        printf("%d - %lf \n", i, valor);
    }
    printf("\n");
}
/**
 Method_15
*/
void method_15( )
{
// definir dados
    int n = 0;
    double x;
    
// identificar
    IO_println ( "Method_15 - v0.0" );
// ações
    printf("%s" , "Digite um valor para 'n': \n");
    scanf("%d" , &n); getchar();
    
    printf("%s" , "Digite um valor real x: \n");
    scanf("%lf", &x); getchar();
    
    valoresDenominadoresAoQuadrado(x, n);
    
    printf("\n");
// encerrar
    IO_pause ( "Aperte ENTER para continuar" );
} // end method_15 ( )

// função para fazer o calculo e mostrar o resultado das frações.
int SomaValores(int n) {
    int soma = 0;
    int valor = 3;
    int x;
    
    for (x = 1; x <= n; valor++) {
        if (valor % 3 == 0 && valor % 4 != 0) {
            soma = soma + valor;
            printf("%d - %d\n" , x, valor);
            x++;
        }
    }
    
    return(soma);
}
/**
 Method_16
*/
void method_16( )
{
// definir dados
    int n = 0;
    
// identificar
    IO_println ( "Method_16 - v0.0" );
// ações
    printf("%s" , "Digite um valor para 'n': \n");
    scanf("%d" , &n); getchar();
    
    printf("\n%s%d" , "O resultado da soma e': " , SomaValores(n));
    
    printf("\n");
// encerrar
    IO_pause ( "Aperte ENTER para continuar" );
} // end method_16 ( )

// função para fazer o calculo e mostrar o resultado das frações.
double SomarFracao(int n) {
    double soma = 0.0;
    int valor = 7;
    int x = 0;
    
    for (x; x <= n; x++) {
        if (valor % 7 == 0 && valor % 5 != 0) {
            soma = soma + 1.0 / valor;
            printf("%d - %lf / %d\n" , x, 1.0, valor);
        }
        valor = valor + 7;
    }
    
    return(soma);
}
/**
 Method_17
*/
void method_17( )
{
// definir dados
    int n = 0;
    double resultado;
    
// identificar
    IO_println ( "Method_17 - v0.0" );
// ações
    printf("%s" , "Digite um valor para 'n': \n");
    scanf("%d" , &n); getchar();
    
    resultado = SomarFracao(n);
    
    printf("\n%s%lf" , "O resultado e': " , resultado);
    
    printf("\n");
// encerrar
    IO_pause ( "Aperte ENTER para continuar" );
} // end method_17 ( )

// função para fazer o calculo e mostrar o resultado das frações.
int SomarNaturais(int n) {
    int soma = 0;
    int valor = 7;
    int x = 1;
    
    for (x; x <= n; x++) {
        soma = soma + valor;
        printf("%d - %d\n" , x, valor);
        valor = valor + 1; 
    }
    
    return(soma);
}
/**
 Method_18
*/
void method_18( )
{
// definir dados
    int n = 0;
    int resultado;
    
// identificar
    IO_println ( "Method_18 - v0.0" );
// ações
    printf("%s" , "Digite um valor para 'n': \n");
    scanf("%d" , &n); getchar();
    
    resultado = SomarNaturais(n);
    
    printf("\n%s%d" , "O resultado e': " , resultado);
    
    printf("\n");
// encerrar
    IO_pause ( "Aperte ENTER para continuar" );
} // end method_18 ( )

// função para fazer o calculo e mostrar o resultado das frações.
int SomarNaturaisAoQuadrado(int n) {
    int soma = 0;
    int valor = 7;
    int x = 1;
    
    for (x; x <= n; x++) {
        soma = soma + pow(valor, 2);
        printf("%d - %.0lf\n" , x, pow(valor, 2));
        valor = valor + 1; 
    }
    
    return(soma);
}
/**
 Method_19
*/
void method_19( )
{
// definir dados
    int n = 0;
    int resultado;
    
// identificar
    IO_println ( "Method_19 - v0.0" );
// ações
    printf("%s" , "Digite um valor para 'n': \n");
    scanf("%d" , &n); getchar();
    
    resultado = SomarNaturaisAoQuadrado(n);
    
    printf("\n%s%d" , "O resultado e': " , resultado);
    
    printf("\n");
// encerrar
    IO_pause ( "Aperte ENTER para continuar" );
} // end method_19 ( )

// função para fazer o calculo e mostrar o resultado das frações.
double SomarFracaoNatural(int n) {
    double soma = 0.0;
    int valor = 6;
    int x = 0;
    
    for (x; x <= n; x++) {
        soma = soma + 1.0 / valor;
        printf("%d - %lf / %d\n" , x, 1.0, valor);
    valor = valor + 1;
    }
    
    return(soma);
}
/**
 Method_20
*/
void method_20( )
{
// definir dados
    int n = 0;
    double resultado;
    
// identificar
    IO_println ( "Method_20 - v0.0" );
// ações
    printf("%s" , "Digite um valor para 'n': \n");
    scanf("%d" , &n); getchar();
    
    resultado = SomarFracaoNatural(n);
    
    printf("\n%s%lf" , "O resultado e': " , resultado);
    
    printf("\n");
// encerrar
    IO_pause ( "Aperte ENTER para continuar" );
} // end method_20 ( )

// função para calcular o fatorial de um numero 'n'.
int CalcularFatorial(int n){
    int x;
    int fatorial;
    
    if(n < 0){
        return (0);
    } else if(n == 0){
        return (1);
    } else {
        fatorial = 1;
        for(x = 1; x <= n; x++){
            fatorial = fatorial * x;
        }
        return(fatorial);
    }
}
/**
Method_21
*/
void method_21( ){
    // definir dados
    int n = 0;
    int resultado;
    
// identificar
    IO_println ( "Method_21 - v0.0" );
// ações
    printf("%s" , "Digite um valor para 'n': \n");
    scanf("%d" , &n); getchar();

    
    
    if(n < 0){
        printf("Nao e' possivel calcular o fatorial de 0.");
    }else{
        resultado = CalcularFatorial(n);
        printf("\n%s%d" , "O resultado e': " , resultado);
    }
    
    printf("\n");
// encerrar
    IO_pause ( "Aperte ENTER para continuar" );
} // end method_21

// função para calcular o fatorial de um numero 'n'.
int calcularFatorial(int n) {
    unsigned long long fatorial = 1;
    for (int i = 1; i <= n; i++) {
        fatorial *= i;
    }
    return fatorial;
}

// Função para calcular o valor de f(n)
double calcularFdeN(int n) {
    double resultado = 1.0;
    int numerador = 3;
    int denominador = 5;
    
    for (int i = 0; i < n; i++) {
        resultado *= (1.0 + (double)numerador / calcularFatorial(denominador));
        numerador++;
        denominador += 2;
    }
    
    return resultado;
}
/**
Method_22
*/
void method_22( ){
    // definir dados
    int n = 0;
    double resultado;
    
// identificar
    IO_println ( "Method_22 - v0.0" );
// ações
    printf("%s" , "Digite um valor para 'n': \n");
    scanf("%d" , &n); getchar();

    resultado = calcularFdeN(n);
        
    printf("\n%s%lf" , "O resultado e': " , resultado);
    
    printf("\n");
// encerrar
    IO_pause ( "Aperte ENTER para continuar" );
} // end method_22

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
 IO_println ( "6 - method_06" );   
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
 IO_println ( "20 - method_20" );  
 IO_println ( "21 - method_21" );
 IO_println ( "22 - method_22" );     
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
 case 20: method_20 ( ); break;
 case 21: method_21 ( ); break;
 case 22: method_22 ( ); break;
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