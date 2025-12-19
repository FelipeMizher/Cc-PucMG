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

int Contar(char line[]){
    int count = 0;

    for(int i = 0; i < strlen(line); i++){
        char c = line[i];

        if(line[i] == '\0'){ 
            count = 0;
        } else {
            if(c >= 'A' && c <= 'Z'){  
                count++;
            }
        }
    }

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
