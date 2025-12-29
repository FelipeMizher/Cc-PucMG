#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[51];
    int peso;
} Atleta;

Atleta* NewAtleta(char* nome, int peso){
    Atleta* atleta = (Atleta*)malloc(sizeof(Atleta));
    strcpy(atleta->nome, nome);
    atleta->peso = peso;

    return atleta;
}

void DelAtleta(Atleta* atleta){
    free(atleta);
}

int Comparar(Atleta a, Atleta b){
    int result = 0; 

    if(a.peso >  b.peso){
        result = -1;
    } else if(a.peso < b.peso){
        result = 1;
    } else{
        result = strcmp(a.nome, b.nome);
    }

    return result;
}

void Swap(Atleta* a, Atleta* b){
    Atleta temp = *a;
    *a = *b;
    *b = temp;
}

void OrdenarAtletas(Atleta* atletas[], int n){
    for(int i = 0; i < n; i++){
        int max = i;
        for(int j = i + 1; j < n; j++){
            if(Comparar(*atletas[j], *atletas[max]) < 0){
                max = j;
            }
        }
        Swap(atletas[i], atletas[max]);
    }
}

int LerAtletas(Atleta* atletas[]){
    char nome[51];
    int n = 0, peso = 0;

    while(scanf(" %s %d", nome, &peso) != EOF){
        Atleta* atleta = NewAtleta(nome, peso);
        atletas[n] = atleta;
        n++;
    }

    return n; 
}

void ImprimirAtletas(Atleta* atletas[], int n){
    for(int i = 0; i < n; i++){
        printf("%s %d\n", atletas[i]->nome, atletas[i]->peso);
    }
}

void DelAtletas(Atleta* atletas[], int n){
    for(int i = 0; i < n; i++){
        DelAtleta(atletas[i]);
    }
}

int main(void){
    int n = 0;
    Atleta* atletas[100];

    n = LerAtletas(atletas);
    OrdenarAtletas(atletas, n);
    ImprimirAtletas(atletas, n);
    DelAtletas(atletas, n);

    return 0;
}