#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool verificar(char line[]){
    bool resp = false;
    int count = 0;

    for(int i = 0; i < strlen(line); i++){
        char c = line[i];

        if(c == '('){
            count++;
        } else if(c == ')'){
            count--;
            if(count < 0){
                i = strlen(line);
            }
        }
    }

    if(count == 0){
        resp = true;
    }

    return resp;
}

int main(void){
    char line[100];

    while(scanf("%s", line) != EOF){
        if(verificar(line)){
            printf("correct\n");
        } else{
            printf("incorrect\n");
        }
    }
  return 0;
}