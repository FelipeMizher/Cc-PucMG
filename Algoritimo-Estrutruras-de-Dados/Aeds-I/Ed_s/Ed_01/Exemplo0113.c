// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0113 - v0.0. - 27 / 08 / 2023
 Author: ____Felipe Rivetti Mizher____

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0113 exemplo0113.c
 Windows: gcc -o exemplo0113 exemplo0113.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0113
 Windows: exemplo0113
*/

// Incluir biblioteca.
#include <stdio.h>

// Função para calcular a area do retangulo com os lados quatro vezes maiores.
void calcularArea(int X, int Y){
// Declarar variavel para o calculo.
    double area;
    
// Calculos para descobrir a area do retangulo. 
    X = X * 4;
    Y = Y * 4; 
    area = X * Y;
    
// Exibir o valor da area do retangulo.
    printf("A area do retangulo com os lados quatro vezes maior e': %.2lf\n" , area);
}

int main(){
// Declarar variavel.
    int X, Y;
    
// Pedir ao usuario os valores para o calculo.
    printf("Digite dois lados de um retangulo: ");
    scanf("%d %d" , &X, &Y); getchar();
    
// Pular uma linha.
    printf("\n");
    
// Chamar a função com parametro 'X' e 'Y' e exibir o resultado da area.
    calcularArea(X, Y);
    
// Encerrar.
    printf("\n\nAperte 'ENTER' para encerrar.");
// Esperar pelo ENTER.
    getchar();
    return 0;
}