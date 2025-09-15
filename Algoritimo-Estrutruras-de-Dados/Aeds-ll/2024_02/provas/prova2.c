#include <stdio.h>

int verificar(char* line){
    int count1 = 0, count2 = 0, count3 = 0, result = 0;

    for(int i = 0; line[i] != '\0'; i++){
        if(line[i] == '['){
            count1++;
        }
        if(line[i] == '{'){
            count2++;
        }
        if(line[i] == '('){
            count3++;
        }

        if(line[i] == ']'){
            count1--;
        }
        if(line[i] == '}'){
            count2--;
        }
        if(line[i] == ')'){
            count3--;
        }
        
        if(count1 < 0 || count2 < 0 || count3 < 0){
            return result = 0;
        }
    }

    if(count1 == 0 && count2 == 0 && count3 == 0){
        result = 1;
    } else{
        result = 0;
    }

    return result;
}

int main(){
    int x = 0;
    char line[50];

    scanf("%d", &x);
    while(x != 0){
        scanf(" %[^\n]", line);
        if(verificar(line) == 1){
            printf("S\n");
        } else{
            printf("N\n");
        }

        x--;
    }

   return 0;
}
