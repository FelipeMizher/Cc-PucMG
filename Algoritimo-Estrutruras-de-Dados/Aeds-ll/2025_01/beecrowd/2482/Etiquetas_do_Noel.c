#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    char traducao[100];
} Idioma;

int main(){
    int N, M;
    scanf("%d", &N);
    getchar();

    Idioma idiomas[N];

    for(int i = 0; i < N; i++){
        fgets(idiomas[i].nome, sizeof(idiomas[i].nome), stdin);
        idiomas[i].nome[strcspn(idiomas[i].nome, "\n")] = '\0'; 

        fgets(idiomas[i].traducao, sizeof(idiomas[i].traducao), stdin);
        idiomas[i].traducao[strcspn(idiomas[i].traducao, "\n")] = '\0'; 
    }

    scanf("%d", &M);
    getchar();

    for(int i = 0; i < M; i++){
        char nomeCrianca[100];
        char idiomaCrianca[50];

        fgets(nomeCrianca, sizeof(nomeCrianca), stdin);
        nomeCrianca[strcspn(nomeCrianca, "\n")] = '\0';

        fgets(idiomaCrianca, sizeof(idiomaCrianca), stdin);
        idiomaCrianca[strcspn(idiomaCrianca, "\n")] = '\0';

        char saudacao[100] = "";

        for(int j = 0; j < N; j++){
            if(strcmp(idiomas[j].nome, idiomaCrianca) == 0){
                strcpy(saudacao, idiomas[j].traducao);
                j = N;
            }
        }

        printf("%s\n", nomeCrianca);
        printf("%s\n\n", saudacao);
    }

    return 0;
}
