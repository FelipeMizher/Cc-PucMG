#include <stdio.h>

typedef struct No{
    int elemento;
    struct No *esq, *dir;
}No;

No *newNo(int elemento){
    No* no = (No*) malloc(sizeof(No));
    no->elemento = elemento;
    no->esq = no->dir = NULL;
    return no;
}

void delNo(No* no){
    free(no);
}

typedef struct{
    No* raiz;
}ABP;

ABP* newABP(){
    ABP* abp = (ABP*) malloc(sizeof(ABP));
    abp->raiz = NULL;
    return abp;
}

void delABP(){
    //desalocar todos os nos
    free(abp);
}

int pesquisar(ABP* abp, int x){
    return pesquisarRec(abp->raiz, x);
}

int pesquisarRec(No* i, int x){
    int resp;

    if(i == NULL){
        resp = 0;
    } else if(x == i->elemento){
        resp = 1;
    } else if(x < i->elemento){
        pesquisarRec(i->esq, x);
    } else{
        pesquisarRec(i->dir, x);
    }

    return resp;
}

void caminharCentral(ABP* abp){
    caminharCentralRec(abp->raiz);
}

void caminharCentralRec(No* i){
    if(i != NULL){
        caminharCentralRec(i->esq);
        printf("%d ", i->elemento);
        caminharCentralRec(i->dir);
    }
}

void inserir(ABP* abp, int x){
    inserirRec(, x)
}

void inserirRec(No** i, int x){

}

int main(void){
    
  return 0;
}