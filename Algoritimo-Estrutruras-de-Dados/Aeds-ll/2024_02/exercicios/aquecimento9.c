#include <stdio.h>

int verificar(int array1[], int array2[], int size){
    int count = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(array1[i] == array2[j] && i < j){
                count++;
            }
        }
    }

    return count;
}

int main(void){
    int N = 0;
    
    while(scanf("%d", &N) != EOF){

        int largada[N];
        int chegada[N];
        
        for(int i = 0; i < N; i++){
            scanf("%d", &largada[i]);
        }
        
        for(int i = 0; i < N; i++){
            scanf("%d", &chegada[i]);
        }

        printf("%d\n", verificar(largada, chegada, N));
    }

  return 0;
}
