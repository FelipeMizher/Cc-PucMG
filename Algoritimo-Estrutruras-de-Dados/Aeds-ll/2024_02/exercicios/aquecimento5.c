#include <stdio.h>
#include <string.h>

void Strings(char *str1, char *str2, char *resultado){
    int i = 0, j = 0, k = 0;
    int tam1 = strlen(str1);
    int tam2 = strlen(str2);
    
    while(i < tam1 && j < tam2){
        resultado[k++] = str1[i];
        resultado[k++] = str2[j];
        i++;
        j++;
    }
    
    while(i < tam1){
        resultado[k++] = str1[i++];
    }
    
    while(j < tam2){
        resultado[k++] = str2[j++];
    }
    
    resultado[k] = '\0';
}

int main(void){
    char str1[100], str2[100], resultado[200];
    
    while(scanf("%s %s", str1, str2) != EOF){  
        
        Strings(str1, str2, resultado);
        
        printf("%s\n", resultado);
    }
    
  return 0;
}
