// 821811 - Felipe Rivetti Mizher

/*
 Exemplo01E2 - v0.0. - 27 / 08 / 2023
 Author: ____Felipe Rivetti Mizher____

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo01E2 exemplo01E2.c
 Windows: gcc -o exemplo01E2 exemplo01E2.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo01E2
 Windows: exemplo01E2
*/

// Incluir bibliotecas.
#include <stdio.h>
#include <math.h>

// Função para calcular o raio e a area da superficie.
void calcularRaio(double X){
// Declarar variavel;
    double raio;
    double areaSuperficie;
    
// Calculos para descobrir o valor do raio e da area da superficie com três quartos do valo do volume.
    X = (X * 3) / 4;
    raio = cbrt((X * (3.0 / 4.0) / M_PI));
    areaSuperficie = 4.0 * M_PI * raio * raio;
    
// Exibir o valor do raio e da area da superficie com o parametro de três quartos do volume.
    printf("o raio da circunferencia com um terço do valor e': %lf\n" , raio);
    printf("A area da superficie e': %lf\n" , areaSuperficie);
}

int main(){
// Declarar variavel.
    double volume;

// Pedir ao usuario o valor do volume.
    printf("Digite o valor do volume da esfera: ");
    scanf("%lf" , &volume); getchar();
    
// Pular uma linha.
    printf("\n");
    
// Chamar a função passando o 'VOLUME' como parametro.
    calcularRaio(volume);

// Encerrar.
    printf("\n\nAperte 'ENTER' para encerrar.");
// Esperar pelo ENTER.
    getchar();
    return 0;
}