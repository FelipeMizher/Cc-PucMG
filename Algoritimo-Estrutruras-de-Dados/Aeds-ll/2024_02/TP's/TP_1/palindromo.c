#include <stdio.h>
#include <string.h>

int palindromo(char str[]){
    int result = 1; 
    int start = 0; 
    int end = strlen(str) - 1;

    while(start < end){
        if (str[start] != str[end]){
            result = 0;
            start = end;
        }
        start++;
        end--;
    }
    
    return result;
}

int main(void){
    char line[500];

    scanf("%[^\n]", line);

    while(strcmp(line, "FIM") != 0){
        if(palindromo(line) == 1){
            printf("SIM\n");
        } else{
            printf("NAO\n");
        }
        scanf(" %[^\n]", line);
    }

  return 0;
}
