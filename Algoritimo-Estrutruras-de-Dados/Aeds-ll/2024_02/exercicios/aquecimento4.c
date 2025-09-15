#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contador(char str[], int x){
    int count = 0;
    int tam = strlen(str);

    if(x == strlen(str)){
        return 0;
    }

    if(str[x] >= 'A' && str[x] <= 'Z'){
        count = 1;
    }

   return  count + contador(str, x + 1);
}

int main(void){
    char line[100];

    scanf("%[^\n]", line);

    while(strcmp(line, "FIM") != 0){
        printf("%d\n", contador(line, 0));
        getchar();
        scanf("%[^\n]", line);
    }

  return 0;
}