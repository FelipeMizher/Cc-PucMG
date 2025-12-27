#include <stdio.h>
#include <string.h>

int IsFim(char str[]){
    int result = 1;

    if(str[0] == 'F' && str[1] == 'I' && str[2] == 'M'){
        result = 0;
    }

    return result;
}

int ContarRec(char str[], int index){
    int count = 0;
    int n = strlen(str);

    if(index < n){
        if(str[index] >= 'A' && str[index] <= 'Z'){
            count++;
        }
        count = count + ContarRec(str, index + 1);
    }

    return count;
}

int Contar(char str[]){
    return ContarRec(str, 0);
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