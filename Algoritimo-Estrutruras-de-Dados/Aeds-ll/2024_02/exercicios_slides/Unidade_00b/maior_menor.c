// Felipe Rivetti Mizher - 821811
// Exercicio 3

#include <stdio.h>

void verificar(int array[], int tamanho){
    int maior = array[0], menor = array[0];

    for(int i = 0; i < tamanho; i++){
        if(array[i] > maior){
            maior = array[i];
        }
        if(array[i] < menor){
            menor = array[i];
        }
    }
    
    printf("Menor: %d\n", menor);
    printf("Maior: %d\n", maior);

}

int main(){
    int array[5];
    int tamanho = sizeof(array) / sizeof(array[0]);

    for(int i = 0; i < tamanho; i++){
        scanf("%d", &array[i]);
    }

    verificar(array, tamanho);

  return 0;
}