#include <stdio.h>
#include <string.h>

int IsFim(char line[]){
    int result = 1;

    if(line[0] == 'F' && line[1] == 'I' && line[2] == 'M'){
        result = 0;
    }

    return result;
}

int Contar(char str[]){
    int count = 0;
    int i = 0;
    char c = str[i];

    while(c != '\0'){
        count++;
        i++;
        c = str[i];
    }

    return count;
}

int Verificar(char str[]){
    int result = 1;
    int i = 0, j = Contar(str) - 1;

    while(i < j){
        if(str[i] != str[j]){
            result = 0;
            i = j;
        }
        i++;
        j--;
    }

    return result;
}

int main(void){
    char line[500];

    scanf("%[^\n]", line);
    while(IsFim(line) != 0){
        if(Verificar(line) != 0){
            printf("SIM\n");
        } else{
            printf("NAO\n");
        }
        scanf(" %[^\n]", line);
    }

    return 0;
}