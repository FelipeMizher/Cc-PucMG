#include <stdio.h>

int Contar(char str[]){
    int count = 0;

    while(str[count] != '\0'){
        count++;
    }

    return count;
}

void Combinar(char line1[], char line2[]){
    int tam1 = Contar(line1);
    int tam2 = Contar(line2);
    int tamMax = tam1 > tam2 ? tam1 : tam2;
    char result[tam1 + tam2 + 1];
    int j = 0;

    for(int i = 0; i < tamMax; i++){
        if(i < tam1){
            result[j++] = line1[i];
        }
        if(i < tam2){
            result[j++] = line2[i];
        }
    }
    result[j] = '\0';
    printf("%s\n", result);
}

int main(void){
    char line1[100];
    char line2[100];

    while(scanf(" %s %s", line1, line2) == 2){
        Combinar(line1, line2);
    }

  return 0;
}