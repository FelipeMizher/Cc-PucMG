// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0111 - v0.0. - 27 / 08 / 2023
 Author: ____Felipe Rivetti Mizher____

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0111 exemplo0111.c
 Windows: gcc -o exemplo0111 exemplo0111.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0111
 Windows: exemplo0111
*/

// Incluir biblioteca.
#include <stdio.h>

// Função para calcular a area do quadrado e do quadrado seis vezes maior.
void calcularArea(int X){
// Declarar variaveis para o calculo.
    int area;
    int resultado;
    int Y;
    
// Calculos para descobrir as areas dos dois quadrados. 
    area = X * X;
    Y = X * 6;
    resultado = Y * Y;
    
// Exibir o valor inicial, o primeiro quadrado e o segundo, respectivamente.
    printf("O valor de entrada e': %.d\n" , X);
    printf("O valor da area e': %d\n" , area);
    printf("O valor da area do quadrado com lado 6 vezes maior e': %d\n" , resultado);
}

int main(void){
// Declarar variavel.
    int X;
    
// Pedir ao usuario o valor para o calculo.
    printf("Digite um valor para o lado de um quadrado: ");
    scanf("%d" , &X); getchar();
    
// Pular uma linha.
    printf("\n");
    
// Chamar a função com o parametro 'X' para fazer e exibir os calculos.
    calcularArea(X);
    
// Encerrar.
    printf("\n\nAperte 'ENTER' para encerrar.");
// Esperar pelo ENTER.
    getchar();
    return 0;
}