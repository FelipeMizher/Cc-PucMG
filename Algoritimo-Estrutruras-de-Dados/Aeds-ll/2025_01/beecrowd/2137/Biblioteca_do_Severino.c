#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bolha(int *array, int n){
    int i, j;

    for(i = 0; i < (n-1); i++){
        for(j = 0; j < (n-1); j++){
            if(array[j] > array[j + 1]){
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main(void){
    int N = 0;

    while(scanf("%d", &N) != EOF){
        int cadastrados[N];

        for(int i = 0; i < N; i++){
            scanf("%d", &cadastrados[i]);
        }

        bolha(cadastrados, N);

        for(int i = 0; i < N; i++){
            printf("%04d\n", cadastrados[i]);
        }
    }

  return 0;
}