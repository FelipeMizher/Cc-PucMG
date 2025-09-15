// Felipe Rivetti Mizher - 821811
// Exercicio 4

#include <stdio.h>

void verificar(int array[], int tamanho){
    int maior = array[0];
    int menor = array[tamanho - 1];
    
    printf("Menor: %d\n", menor);
    printf("Maior: %d\n", maior);

}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selecao(int *array, int n){
    for (int i = 0; i < (n - 1); i++) {
      int menor = i;
      for (int j = (i + 1); j < n; j++){
         if (array[menor] > array[j]){
            menor = j;
         }
      }
      swap(&array[menor], &array[i]);
   }
}

int main(){
    int array[5];
    int tamanho = sizeof(array) / sizeof(array[0]);

    for(int i = 0; i < tamanho; i++){
        scanf("%d", &array[i]);
    }

    selecao(array, tamanho);

    verificar(array, tamanho);

  return 0;
}