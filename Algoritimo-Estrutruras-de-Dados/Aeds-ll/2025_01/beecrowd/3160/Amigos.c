#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* nome[100];
    int n;
} Lista;

void inicializarLista(Lista *lista){
    lista->n = 0;
}

void inserirInicio(Lista *lista, const char *s){
    if(lista->n < 100){
        for(int i = lista->n; i > 0; i--){
            lista->nome[i] = lista->nome[i - 1];
        }

        lista->nome[0] = strdup(s);
        if(lista->nome[0] != NULL){
            lista->n++;
        }
    }
}

void inserirFim(Lista* lista, const char* s){
    if(lista->n < 100){
        lista->nome[lista->n] = strdup(s);
        lista->n++;
    }
}

void inserir(Lista* lista, const char* s, int pos){
    if(lista->n < 100 && pos >= 0 && pos <= lista->n){
        for(int i = lista->n; i > pos; i--) {
            lista->nome[i] = lista->nome[i - 1];
        }
        lista->nome[pos] = strdup(s);
        lista->n++;
    }
}

char* removerInicio(Lista* lista){
    char* resp = NULL;

    if(lista->n > 0){
        resp = lista->nome[0];

        for(int i = 0; i < lista->n - 1; i++){
            lista->nome[i] = lista->nome[i + 1];
        }
        lista->n--;
        lista->nome[lista->n] = NULL;
    }

    return resp;
}

char* removerFim(Lista* lista){
    char* resp = NULL;

    if(lista->n > 0){
        lista->n--;
        resp = lista->nome[lista->n];
        lista->nome[lista->n] = NULL;
    }

    return resp;
}

char* remover(Lista* lista, int pos){
    char* resp = NULL;

    if(lista->n > 0 && pos >= 0 && pos < lista->n){
        resp = lista->nome[pos];

        for(int i = pos; i < lista->n - 1; i++){
            lista->nome[i] = lista->nome[i + 1];
        }
        lista->n--;
        lista->nome[lista->n] = NULL;
    }

    return resp;
}

void mostrar(Lista* lista){
    for(int i = 0; i < lista->n; i++){
        printf("%s ", lista->nome[i]);
    }
    printf("\n");
}

int pesquisar(Lista* lista, const char* s){
    int resp = 0;

    for(int i = 0; i < lista->n; i++){
        if(strcmp(lista->nome[i], s) == 0){
            resp = 1;
        }
    }
    return resp;
}

int main(void) {
    Lista lista;
    inicializarLista(&lista);
    
    char linha1[1000], linha2[1000], indicado[100];

    fgets(linha1, sizeof(linha1), stdin);
    fgets(linha2, sizeof(linha2), stdin);
    fgets(indicado, sizeof(indicado), stdin);

    linha1[strcspn(linha1, "\n")] = 0;
    linha2[strcspn(linha2, "\n")] = 0;
    indicado[strcspn(indicado, "\n")] = 0;

    char* token = strtok(linha1, " ");
    while(token != NULL) {
        inserirFim(&lista, token);
        token = strtok(NULL, " ");
    }

    char* novos[100];
    int tam_novos = 0;
    token = strtok(linha2, " ");
    while(token != NULL && tam_novos < 100){
        novos[tam_novos++] = strdup(token);
        token = strtok(NULL, " ");
    }

    if(strcmp(indicado, "nao") != 0){
        int pos = -1;
        for(int i = 0; i < lista.n; i++){
            if(strcmp(lista.nome[i], indicado) == 0) {
                pos = i;
                i = lista.n;
            }
        }

        if(pos != -1){
            for(int i = 0; i < tam_novos; i++){
                inserir(&lista, novos[i], pos++);
            }
        } else{
            printf("Amigo nao encontrado!\n");
        }
    } else{
        for(int i = 0; i < tam_novos; i++){
            inserirFim(&lista, novos[i]);
        }
    }

    mostrar(&lista);
    return 0;
}
