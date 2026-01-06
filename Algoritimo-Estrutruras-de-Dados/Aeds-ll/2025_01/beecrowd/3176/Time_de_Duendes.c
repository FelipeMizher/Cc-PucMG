#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
} Duende;

typedef struct{
    Duende array[1000];
    int topo;
} Pilha;

void iniciarPilha(Pilha *p){
    p->topo = 0;
}

void empilhar(Pilha *p, Duende d){
    p->array[p->topo++] = d;
}

Duende desempilhar(Pilha *p){
    return p->array[--p->topo];
}

int comparar(Duende a, Duende b){
    if(a.idade < b.idade){
        return 1;
    } else if(a.idade > b.idade){
        return 0;
    } else{
        return strcmp(a.nome, b.nome) > 0;
    }
}

void swap(Duende *a, Duende *b){
    Duende temp = *a;
    *a = *b;
    *b = temp;
}

void ordenar(Duende duendes[], int n){
    for(int i = 0; i < n - 1; i++){
        int maior = i;
        for(int j = i + 1; j < n; j++){
            if(comparar(duendes[maior], duendes[j])){
                maior = j;
            }
        }
        swap(&duendes[i], &duendes[maior]);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    
    Duende duendes[1000];

    for(int i = 0; i < N; i++){
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
    }

    ordenar(duendes, N);

    int times = N / 3;

    Pilha lideres, entregadores, pilotos;
    iniciarPilha(&lideres);
    iniciarPilha(&entregadores);
    iniciarPilha(&pilotos);

    for(int i = times - 1; i >= 0; i--){
        empilhar(&lideres, duendes[i]);
    }

    for(int i = 2 * times - 1; i >= times; i--){
        empilhar(&entregadores, duendes[i]);
    }

    for(int i = 3 * times - 1; i >= 2 * times; i--){
        empilhar(&pilotos, duendes[i]);
    }

    for(int i = 1; i <= times; i++){
        printf("Time %d\n", i);

        Duende lider = desempilhar(&lideres);
        Duende entregador = desempilhar(&entregadores);
        Duende piloto = desempilhar(&pilotos);

        printf("%s %d\n", lider.nome, lider.idade);
        printf("%s %d\n", entregador.nome, entregador.idade);
        printf("%s %d\n\n", piloto.nome, piloto.idade);
    }

    return 0;
}
