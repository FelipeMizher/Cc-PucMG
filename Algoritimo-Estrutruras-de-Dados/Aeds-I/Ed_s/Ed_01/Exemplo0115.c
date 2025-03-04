// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0115 - v0.0. - 27 / 08 / 2023
 Author: ____Felipe Rivetti Mizher____

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0115 exemplo0115.c
 Windows: gcc -o exemplo0115 exemplo0115.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0115
 Windows: exemplo0115
*/

// Incluir biblioteca.
#include <stdio.h>

// Função para calcular a area do triangulo a altura pela metado.
void calcularArea(double X, double Y){
// Declarar variavel para o calculo.
    double area;
    
// Calculos para descobrir a area do retangulo.
    Y = Y / 2;    
    area = (X * Y) / 2;
    
// Exibir o valor da area do triangulo.
    printf("A area do triangulo com a metade da altura e': %.2lf\n" , area);
}

int main(){
// Declarar variaveis.
    double base, altura;
    
// Pedir ao usuario os valores para o calculo.
    printf("Digite a base a altura respecivamente: \n");
    scanf("%lf%lf" , &base, &altura); getchar();
    
// Pular uma linha.
    printf("\n");
    
// Chamar a função com parametro 'BASE' e 'ALTURA' e exibir o resultado da area.
    calcularArea(base, altura);
    
// Encerrar.
    printf("\n\nAperte 'ENTER' para encerrar.");
// Esperar pelo ENTER.
    getchar();
    return 0;
}