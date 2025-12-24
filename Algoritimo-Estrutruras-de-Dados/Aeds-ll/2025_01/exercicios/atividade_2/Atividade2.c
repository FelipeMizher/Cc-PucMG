#include <stdio.h>

//Atuvudade que complementa o Exemplo1.c e Exemplo2.c
//Usar junto com o pub_tipo3.in

struct Duracao{
    int hora;
    int minuto;
};

typedef struct Duracao Duracao;

void ProcessarRegistro(int id, double preco, int tempo.hora, int tempo.minuto, char cidade[]){
    printf("Registro lido: %d %.2lf %d:%d %s\n", id, preco, tempo.hora. tempo.minuto, cidade);
}

int main(void){
    int id;
    double preco;
    Duracao tempo;
    char cidade[50];

    while(scanf(" %d", &id) == 1 && id != 0){
        scanf(" %lf %d %d %[^\n]", &preco, &tempo.hora, &tempo.minuto, cidade);
        ProcessarRegistro(id, preco, tempo.hora, tempo.minuto, cidade);
    }

    return 0;
}
