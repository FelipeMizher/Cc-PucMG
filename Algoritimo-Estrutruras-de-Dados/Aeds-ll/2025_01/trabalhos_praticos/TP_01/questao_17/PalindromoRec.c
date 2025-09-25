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

int VerificarRec(char str[], int start, int end){
    int result = 1;

    if(start < end){
        if(str[start] != str[end]){
            result = 0;
        } else{
            result = VerificarRec(str, start + 1, end - 1);
        }
    }

    return result;
}

int Verificar(char str[]){
    int end = Contar(str) - 1;

    return VerificarRec(str, 0, end);
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