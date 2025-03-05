// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0116 - v0.0. - 27 / 08 / 2023
 Author: ____Felipe Rivetti Mizher____

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0116 exemplo0116.c
 Windows: gcc -o exemplo0116 exemplo0116.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0116
 Windows: exemplo0116
*/

// Incluir biblioteca.
#include <stdio.h>
#include <math.h>

// Função para calcular a area do triangulo a altura pela metado.
void calcularArea(double X){
// Declarar variaveis para o calculo.
    double altura, area, perimetro;
    
// Calculos para descobrir a altura, area e o perimetro do triangulo.
    X = X * 2;
    altura = (sqrt(3) * X) / 2;
    area = (X * altura) / 2;
    perimetro = X * 3;
        
// Exibir o valor da altura, area e perimetro do triangulo.
    printf("A altura do triangulo com o dobro da altura e': %.2lf\n" , altura);
    printf("A area do triangulo com o dobro da altura e': %.2lf\n" , area);
    printf("O perimetro do triangulo com o dobro da altura e': %.2lf\n" , perimetro);
}

int main(){
// Declarar variavel.
    double lado;
    
// Pedir ao usuario os valores para o calculo.
    printf("Digite o valor do lado do triangulo: \n");
    scanf("%lf" , &lado); getchar();
    
// Pular uma linha.
    printf("\n");
    
// Chamar a função com parametro 'LADO' e exibir o resultado da altura, da area e do perietro.
    calcularArea(lado);
    
// Encerrar.
    printf("\n\nAperte 'ENTER' para encerrar.");
// Esperar pelo ENTER.
    getchar();
    return 0;
}