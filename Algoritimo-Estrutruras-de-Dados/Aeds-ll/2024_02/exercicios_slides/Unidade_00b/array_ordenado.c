// Felipe Rivetti Mizher - 821811
// Exercicio 2

#include <stdio.h>
#include <stdbool.h>

bool encontrar(int x, int array[], int tamanho){
    int inicio = 0, fim = tamanho -1;

    while(inicio <= fim){
        int meio = (inicio + fim) / 2;

        if(array[meio] == x){
            return true;
        } else if(array[meio] < x){
            inicio = meio + 1;
        } else{
            fim = meio - 1;
        }
    }

  return false;
}

int main(){
    int x = 0, array[5];
    int tamanho = sizeof(array) / sizeof(array[0]);

    for(int i = 0; i < tamanho; i++){
        scanf("%d", &array[i]);
    }

    scanf("%d", &x);

    if(encontrar(x, array, tamanho) == true){
        printf("Encontrado\n");
    } else{
        printf("Nao Encontrado\n");
    }

  return 0;
}