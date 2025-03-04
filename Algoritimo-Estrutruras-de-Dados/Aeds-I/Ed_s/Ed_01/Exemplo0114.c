// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0114 - v0.0. - 27 / 08 / 2023
 Author: ____Felipe Rivetti Mizher____

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0114 exemplo0114.c
 Windows: gcc -o exemplo0114 exemplo0114.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0114
 Windows: exemplo0114
*/

// Incluir biblioteca.
#include <stdio.h>

// Função para calcular a area do retangulo com os lados quatro vezes maiores.
void calcularArea(double X, double Y){
// Declarar variavel para o calculo.
    double area;
    double perimetro;
    
// Calculos para descobrir a area e o perimetro do retangulo. 
    X = X / 5;
    Y = Y / 5; 
    area = X * Y;
    perimetro = (X * 2) + (Y * 2);
    
// Exibir o valor da area e do perimetro do retangulo.
    printf("A area do retangulo com os lados cinco veze menor e': %.2lf\n" , area);
    printf("O perimetro do retangulo com os lados cinco vezes menor e': %.2lf\n" , perimetro);
}

int main(){
// Declarar variaveis.
    int X, Y;
    
// Pedir ao usuario que insira os valores para o calculo.
    printf("Digite dois lados de um retangulo: ");
    scanf("%d %d" , &X, &Y); getchar();
    
// Pular uma linha.
    printf("\n");
    
// Chamar a função com parametro 'X' e 'Y' e exibir o resultado da area e do perimetro.
    calcularArea(X, Y);
    
// Encerrar.
    printf("\n\nAperte 'ENTER' para encerrar.");
// Esperar pelo ENTER.
    getchar();
    return 0;
}