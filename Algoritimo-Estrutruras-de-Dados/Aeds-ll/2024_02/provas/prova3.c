#include <stdio.h>

void verificarArvore(int N){
    for(int i = 0; i < N; i++){
        int result = 1;
        int altura = 0, espessura = 0, galhos = 0;

        scanf("%d %d %d", &altura, &espessura, &galhos);

        if(altura < 200 || altura > 300){
            result = 0;
        } else if(espessura < 50){
            result  = 0;
        } else if(galhos < 150){
            result = 0;
        }

        if(result == 1){
            printf("SIM\n");
        } else{
            printf("NAO\n");
        }
    }
}

int main(void){
    int N = 0;

    scanf("%d", &N);
    verificarArvore(N);

   return 0;
}