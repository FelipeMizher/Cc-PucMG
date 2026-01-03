#include <stdio.h>
#include <string.h>

void contar(int N){
    while(N > 0){
        int L = 0;
        scanf("%d", &L);
        getchar();

        int result = 0;
        for(int i = 0; i < L; i++){
            char line[51];
            fgets(line, sizeof(line), stdin);
            int len = strlen(line) - 1;

            for(int j = 0; j < len; j++){
                int valor = (line[j] - 'A') + i + j;
                result = result + valor; 
            }
        }

        printf("%d\n", result);
        N--;
    }
}

int main(void){
    int N = 0;
    int result = 0;

    scanf("%d", &N);
    contar(N);

   return 0;
}