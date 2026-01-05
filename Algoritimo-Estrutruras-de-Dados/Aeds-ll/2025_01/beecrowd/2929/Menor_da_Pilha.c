#include <stdio.h>
#include <string.h>

typedef struct{
    int elementos[1000];
    int topo;
    int tamanho;
} Pilha;

void iniciarPilha(Pilha *p, int tamanho){
    p->topo = -1;
    p->tamanho = tamanho;
}

int isVazia(Pilha *p){
    return p->topo == -1;
}

int isCheia(Pilha *p){
    return p->topo == p->tamanho - 1;
}

void empilhar(Pilha *p, int elemento){
    if(isCheia(p)){
        printf("Pilha cheia! Não é possível empilhar.\n");
    } else{
        p->topo++;
        p->elementos[p->topo] = elemento;
    }
}

int desempilhar(Pilha *p){
    if(isVazia(p)){
        printf("Pilha vazia! Não é possível desempilhar.\n");
        return -1;
    } else{
        int result = p->elementos[p->topo];
        p->topo--;
        return result;
    }
}

int verificarMenor(Pilha *p){
    if(isVazia(p)){
        printf("A pilha está vazia!\n");
        return -1;
    } else{
        int menor = p->elementos[0];
        for(int i = 1; i <= p->topo; i++){
            if(p->elementos[i] < menor){
                menor = p->elementos[i];
            }
        }
        return menor;
    }
}

int main(){
    int N;
    Pilha pilha;

    scanf("%d", &N);
    iniciarPilha(&pilha, N);

    for(int i = 0; i < N; i++){
        char comando[10];
        scanf("%s", comando);

        if(strcmp(comando, "PUSH") == 0){
            int valor;
            scanf("%d", &valor);
            empilhar(&pilha, valor);
        } else if(strcmp(comando, "POP") == 0){
            desempilhar(&pilha);
        } else if(strcmp(comando, "MIN") == 0){
            int menor = verificarMenor(&pilha);
            if (menor != -1){
                printf("%d\n", menor);
            }
        }
    }

    return 0;
}