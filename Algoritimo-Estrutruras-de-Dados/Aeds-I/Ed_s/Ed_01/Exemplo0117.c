// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0117 - v0.0. - 27 / 08 / 2023
 Author: ____Felipe Rivetti Mizher____

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0117 exemplo0117.c
 Windows: gcc -o exemplo0117 exemplo0117.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0117
 Windows: exemplo0117
*/

// Incluir bibliotecas.
#include <stdio.h>
#include <math.h>

// Função para calcular o volume do cubo
void calcularVolume(double X){
// Declarar variavel para o calculo.
    double volume;
    
// Calculos para descobrir o volume.
    X = X * 7;
    volume = pow(X, 3);
    
// Exibir o valor do volume com o lado 7 vezes maior.
    printf("o volume do cubo e': %.2lf\n" , volume);
}

int main(void){
// Declarar variavel.
    double lado;
    
// Pedir ao usuario o valor para o calculo.
    printf("Digite o valor do lado do cubo: ");
    scanf("%lf" , &lado); getchar();
    
// Pular uma linha.
    printf("\n");
    
// Chamar a função com parametro 'LADO' e exibir o resultado do volume.
    calcularVolume(lado);
    
// Encerrar.
    printf("\n\nAperte 'ENTER' para encerrar.");
// Esperar pelo ENTER.
    getchar();
    return 0;
}