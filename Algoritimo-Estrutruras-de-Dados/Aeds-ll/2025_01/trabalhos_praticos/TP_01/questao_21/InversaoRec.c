#include <stdio.h>

int IsFim(char str[]){
    int result = 1;

    if(str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0'){
        result = 0;
    }

    return result;
}

int Contar(char str[]){
    int count = 0;

    while (str[count] != '\0'){
        count++;
    }

    return count;
}

void InverterRec(char str[], char result[], int start, int tam){
    
    if(tam >= 0){
        result[start] = str[tam];
        InverterRec(str, result, start + 1, tam - 1);
    } else{
        result[start] = '\0';
    }
}

void Inverter(char str[]){
    int tam = Contar(str);
    char result[500];
  
    InverterRec(str, result, 0, tam - 1);
    printf("%s\n", result);
}

int main(){
    char line[500];

    scanf("%[^\n]", line);
    
    while(IsFim(line) != 0){
        Inverter(line);
        
        scanf(" %[^\n]", line);
    }
    
    return 0;
}