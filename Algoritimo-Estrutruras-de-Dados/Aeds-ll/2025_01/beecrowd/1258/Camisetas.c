#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[100];
    char cor[100];
    char tamanho;
} Camisa;

typedef struct{
    Camisa camisas[1000];
    int n;
} Lista;

void inserir(Lista *lista, Camisa c){
    if(lista->n >= 1000){
        printf("Erro ao inserir!\n");
        exit(1);
    }
    lista->camisas[lista->n++] = c;
}

Camisa get(Lista *lista, int i){
    return lista->camisas[i];
}

int tamanho(Lista *lista){
    return lista->n;
}

void ordenar(Lista *lista){
    for(int i = 0; i < lista->n - 1; i++){
        for(int j = 0; j < lista->n - i - 1; j++){
            Camisa *a = &lista->camisas[j];
            Camisa *b = &lista->camisas[j + 1];

            int cmpCor = strcmp(a->cor, b->cor);
            if(cmpCor > 0 ||
                (cmpCor == 0 && a->tamanho < b->tamanho) ||
                (cmpCor == 0 && a->tamanho == b->tamanho &&
                 strcmp(a->nome, b->nome) > 0)){
                Camisa temp = *a;
                *a = *b;
                *b = temp;
            }
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    getchar();

    while(N != 0){
        Lista lista;
        lista.n = 0;

        for(int i = 0; i < N; i++){
            Camisa c;
            fgets(c.nome, 100, stdin);
            c.nome[strcspn(c.nome, "\n")] = '\0';

            scanf("%s %c", c.cor, &c.tamanho);
            getchar();

            inserir(&lista, c);
        }

        ordenar(&lista);

        for(int i = 0; i < tamanho(&lista); i++){
            Camisa c = get(&lista, i);
            printf("%s %c %s\n", c.cor, c.tamanho, c.nome);
        }

        printf("\n");
        scanf("%d", &N);
        getchar();
    }

    return 0;
}