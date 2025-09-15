#include <stdio.h>

int strCount(char *str){
    int count = 0;
    
    while(str[count] != '\0'){
        count++;
    }

    return count;
}

int isFinal(char* str){
        int result = 1;

        if(str[0] == 'F' && str[1] == 'I' && str[2] == 'M'){
            result = 0;
        }

        return result;
    }

int palindromo(char str[], int start, int end){
    int result = 1; 

    if(start < end){
        if(str[start] != str[end]){
                result = 0;
            } else{
                result = palindromo(str, start + 1, end - 1);
            }
    }
    
    return result;
}

int main(void){
    char line[500];

    scanf("%[^\n]", line);

    while(isFinal(line) != 0){
        if(palindromo(line, 0, strCount(line) - 1) == 1){
            printf("SIM\n");
        } else{
            printf("NAO\n");
        }
        scanf(" %[^\n]", line);
    }

  return 0;
}
