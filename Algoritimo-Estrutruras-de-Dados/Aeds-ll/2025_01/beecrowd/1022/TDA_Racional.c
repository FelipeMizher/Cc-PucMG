#include <stdio.h>
#include <stdlib.h>

int calcular(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        int N1, D1, N2, D2;
        char op;

        scanf("%d / %d %c %d / %d", &N1, &D1, &op, &N2, &D2);

        int numResult = 0, denResult = 0;

        if(op == '+'){
            numResult = N1 * D2 + N2 * D1;
            denResult = D1 * D2;
        } else if(op == '-'){
            numResult = N1 * D2 - N2 * D1;
            denResult = D1 * D2;
        } else if(op == '*'){
            numResult = N1 * N2;
            denResult = D1 * D2;
        } else if(op == '/'){
            numResult = N1 * D2;
            denResult = N2 * D1;
        }

        int resp = calcular(abs(numResult), abs(denResult));
        int Num = numResult / resp;
        int Den = denResult / resp;

        printf("%d/%d = %d/%d\n", numResult, denResult, Num, Den);
    }

    return 0;
}