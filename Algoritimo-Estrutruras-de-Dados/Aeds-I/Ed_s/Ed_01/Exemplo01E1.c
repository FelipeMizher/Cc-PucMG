// 821811 - Felipe Rivetti Mizher

/*
 Exemplo01E1 - v0.0. - 27 / 08 / 2023
 Author: ____Felipe Rivetti Mizher____

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo01E1 exemplo01E1.c
 Windows: gcc -o exemplo01E1 exemplo01E1.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo01E1
 Windows: exemplo01E1
*/

// Incluir bibliotecas.
#include <stdio.h>
#include <math.h>

// Função para calcular o raio da circunferencia.
void calcularRaio(double X){
// Declarar variavel;
    double raio;
    
// Calculos para descobrir o valor do raio.
    raio = pow(X, M_PI);
    raio = raio / 3;
    
// Exibir o valor do raio com o parametro da area.
    printf("o raio da circunferencia com um terço do valor e': %lf\n" , raio);
}

int main(){
// Declarar variavel.
    double area;

// Pedir ao usuario o valor da area.
    printf("Digite o valor da area: ");
    scanf("%lf" , &area); getchar();
    
// Pular uma linha.
    printf("\n");
    
// Chamar a função passando a 'area' como parametro.
    calcularRaio(area);

// Encerrar.
    printf("\n\nAperte 'ENTER' para encerrar.");
// Esperar pelo ENTER.
    getchar();
    return 0;
}