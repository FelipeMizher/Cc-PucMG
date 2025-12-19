#include <stdio.h>

//Atuvudade que complementa o Exemplo1.c e Exemplo2.c
//Usar junto com o pub_tipo3.in

void ProcessarRegistro(int id, double preco, char tempo[], char cidade[]) {
    printf("Registro lido: %d %.2lf %s %s\n", id, preco, tempo, cidade);
}

int main(void) {
    int id;
    double preco;
    char tempo[6]; 
    char cidade[50];

    while(scanf(" %d", &id) == 1 && id != 0){
        scanf(" %lf %s %[^\n]", &preco, tempo, cidade);
        ProcessarRegistro(id, preco, tempo, cidade);
    }

    return 0;
}
