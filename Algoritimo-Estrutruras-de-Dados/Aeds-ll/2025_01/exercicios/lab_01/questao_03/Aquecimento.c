#include <stdio.h>
#include <string.h>

int IsFim(char str[]){
    int result = 1;

    if(str[0] == 'F' && str[1] == 'I' && str[2] == 'M'){
        result = 0;
    }

    return result;
}

int Contar(char str[]){
    int count = 0;
    int n = strlen(str);

    for(int i = 0; i < n; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            count++;
        }
    }

    return count;
}

int main(void){
    char line[100];

    scanf("%[^\n]", line);
    while(IsFim(line) != 0){
        printf("%d\n", Contar(line));

        scanf(" %[^\n]", line);
    }

  return 0;
}