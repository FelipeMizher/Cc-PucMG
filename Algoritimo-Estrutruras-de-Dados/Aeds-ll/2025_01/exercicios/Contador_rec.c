#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsFim(char line[]){
    int result = 1;

    if(line[0] == 'F' && line[1] == 'I' && line[2] == 'M'){
        result = 0;
    }

    return result;
}

int ContarRec(char line[], int pos){
    int count = 0;
    char c = line[pos];

    if(line[pos] == '\0'){ 
        count = 0;
    } else{
        count = ContarRec(line, pos + 1); 
        if(c >= 'A' && c <= 'Z'){  
            count++;
        }
    }

    return count; 
}

int Contar(char line[]){
    int count = ContarRec(line, 0);
    return count;
}

int main(){
    char line[100];

    scanf("%[^\n]", line);
    while(IsFim(line) != 0){
        printf("%d\n", Contar(line));
        scanf(" %[^\n]", line);
    }
}
