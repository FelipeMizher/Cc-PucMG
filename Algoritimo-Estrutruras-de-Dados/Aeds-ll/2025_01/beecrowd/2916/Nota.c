#include <stdio.h>

void bubbleSort(int notas[], int N){
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - 1 - i; j++){
            if(notas[j] > notas[j + 1]){
                int temp = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = temp;
            }
        }
    }
}

void preencher(int notas[], int N){
    for(int i = 0; i < N; i++){
        scanf("%d", &notas[i]);
    }
}

int somar(int notas[], int N, int k){
    int soma = 0;

    for(int i = N - 1; i >= N - k; i--){
        soma += notas[i];
    }

   return soma;
}

int main(void){
    int N, K = 0;

    while(scanf("%d %d", &N, &K) == 2){
        int notas[N];

        preencher(notas, N);
        bubbleSort(notas, N);
        int resultado = somar(notas, N, K);
        printf("%d\n", resultado);
    }

   return 0;
}