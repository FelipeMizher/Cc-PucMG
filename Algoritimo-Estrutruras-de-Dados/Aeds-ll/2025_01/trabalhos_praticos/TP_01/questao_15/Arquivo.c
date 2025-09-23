#include <stdio.h>

int IsFim(char line[]){
    int result = 1;

    if(line[0] == 'F' && line[1] == 'I' && line[2] == 'M'){
        result = 0;
    }

    return result;
}

void Gravar(int n){
    double x = 0.0;
    FILE *arq = fopen("Arquivo.txt", "wt");

    for(int i = 0; i < n; i++){
        scanf("%lf", &x);
        fprintf(arq, "%g\n", x);
    }

    fclose(arq);
}

void Mostrar(int n){
    double numeros[n];
    FILE *arq = fopen("Arquivo.txt", "rt");

    for(int i = 0; i < n; i++){
        fscanf(arq, "%lf", &numeros[i]);
    }

    fclose(arq);

    for(int i = n - 1; i >= 0; i--){
        printf("%g\n", numeros[i]);
    }
}

int main(void){
    int n = 0;

    scanf("%d", &n);
    Gravar(n);
    Mostrar(n);

    return 0;
}