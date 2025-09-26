#include <stdio.h>
#include <string.h>

int IsFim(char line[]){
    int result = 1;

    if(line[0] == 'F' && line[1] == 'I' && line[2] == 'M' && line[3] == '\0'){
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

int SomarRec(char str[], int start, int index){
    int soma = 0;

    if(start < index){
        soma = (str[start] - '0') + SomarRec(str, start + 1, index);
    }

    return soma;
}

int Somar(char str[]){
    int tam = Contar(str);

    return SomarRec(str, 0, tam);
}

int main(void){
    char line[500];

    scanf("%[^\n]", line);
    while(IsFim(line) != 0){
        printf("%d\n", Somar(line));
        scanf(" %[^\n]", line);
    }

    return 0;
}