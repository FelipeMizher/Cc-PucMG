#include <stdio.h>

void inversos(FILE *arq, int linha){
    char numero[1000];
    int posicao = 0;

    fseek(arq, 0, SEEK_SET);
    
    while(fgets(numero, sizeof(numero), arq) != NULL){
        posicao++;
        if(linha == posicao){
            printf("%s", numero);
        }
    }
}

int main(void){
    int n = 0;
    double x = 0.0;
    FILE *arq = fopen("arquivo.txt", "wt"); 

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%lf", &x);
        fprintf(arq, "%g\n", x);
    }

    fclose(arq);

    arq = fopen("arquivo.txt", "rt");

    for(int i = n; i > 0; i--){
        inversos(arq, i);
    } 

    fclose(arq);

  return 0;
}