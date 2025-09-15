#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contador(char str[]){
    int count = 0;
    int tam = strlen(str);

    for(int i = 0; i < tam; i++){
        char c = str[i];

        if(isupper(c)){
            count++;
        }
    }

   return  count;
}

int main(void){
    char line[100];

    scanf("%[^\n]", line);

    while(strcmp(line, "FIM") != 0){
        printf("%d\n", contador(line));
        getchar();
        scanf("%[^\n]", line);
    }

  return 0;
}