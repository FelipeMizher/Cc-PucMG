#include <stdio.h>

int verificar(char* line){
    int abertos = 0;

    for(int i = 0; line[i] != '\0'; i++){
        char c = line[i];

        if(c == '('){
            abertos++;
        } else if(c == ')'){
            if(abertos > 0){
                abertos--;
            }
        }
    }

    return abertos;
}

int main(void){
    char line[1000];
    int pendentes = 0;

    scanf("%[^\n]", line);
    pendentes = verificar(line);

    if(pendentes > 0){
        printf("Ainda temos %d assunto(s) pendente(s)!\n", pendentes);
    } else{
        printf("Partiu RU!");
    }

   return 0;
}