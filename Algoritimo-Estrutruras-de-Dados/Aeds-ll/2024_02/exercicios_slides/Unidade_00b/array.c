// Felipe Rivetti Mizher - 821811
// Exercicio 1

#include <stdio.h>
#include <stdbool.h>

bool encontrar(int x, int array[]){

    for(int i = 0; i < 5; i++){
        if(x == array[i]){
            return true;
        }
    }
    return false;
}

int main(){
    int x = 0, array[5];

    for(int i = 0; i < 5; i++){
        scanf("%d", &array[i]);
    }

    scanf("%d", &x);

    if(encontrar(x, array) == true){
        printf("Encontrado\n");
    } else{
        printf("Nao Encontrado\n");
    }

  return 0;
}