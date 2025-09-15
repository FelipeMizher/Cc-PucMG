#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    int nivel_poder;
    int deuses_mortos;
    int mortes;
} Deus;

void cadastrarDeuses(Deus deus[], int n){
    for(int i = 0; i < n; i++){
        scanf(" %[^\n]", deus[i].nome);
        scanf("%d", &deus[i].nivel_poder);
        scanf("%d", &deus[i].deuses_mortos);
        scanf("%d", &deus[i].mortes);
    }
}

int compararDeuses(Deus d1, Deus d2){
    int resultado = 0;

    if(d1.nivel_poder != d2.nivel_poder){
        resultado = d1.nivel_poder - d2.nivel_poder;
    } else if(d1.deuses_mortos != d2.deuses_mortos){
        resultado = d1.deuses_mortos - d2.deuses_mortos;
    } else if(d1.mortes != d2.mortes){
        resultado = d2.mortes - d1.mortes; 
    } else{
        resultado = strcmp(d2.nome, d1.nome);
    }

    return resultado;
}

Deus encontrarMaiorDeus(Deus deuses[], int n){
    Deus maior = deuses[0];
    for(int i = 1; i < n; i++){
        if(compararDeuses(deuses[i], maior) > 0){
            maior = deuses[i];
        }
    }

    return maior;
}

int main(void){
    int N = 0;
    Deus deus[100];

    scanf("%d", &N);
    cadastrarDeuses(deus, N);

    Deus maior = encontrarMaiorDeus(deus, N);

    printf("%s => poder: %d, deuses mortos: %d, mortes: %d\n", maior.nome, maior.nivel_poder, maior.deuses_mortos, maior.mortes);

  return 0;
}