// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0112 - v0.0. - 27 / 08 / 2023
 Author: ____Felipe Rivetti Mizher____

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0112 exemplo0112.c
 Windows: gcc -o exemplo0112 exemplo0112.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0112
 Windows: exemplo0112
*/

// Incluir biblioteca.
#include <stdio.h>

// Função para calcular a area do quadrado e do quadrado seis vezes maior.
void calcularAreaPerimetro(int X){
// Declarar variaveis para o calculo.
    int area;
    int perimetroY;
    int Y;
    
// Calculos para descobrir a area e o perimetro do quadrado. 
    Y = X / 3;
    area = Y * Y;
    perimetroY = Y * 4;
    
// Exibir o valor inicial, o area quadrado e o perimetro, respectivamente.
    printf("O valor de entrada e': %.d\n" , X);
    printf("O valor da area e': %d\n" , area);
    printf("O valor do perimetro e': %d\n" , perimetroY);
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
    calcularAreaPerimetro(X);
    
// Encerrar.
    printf("\n\nAperte 'ENTER' para encerrar.");
// Esperar pelo ENTER.
    getchar();
    return 0;
}