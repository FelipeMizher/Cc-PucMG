#include <stdio.h>
#include <string.h>

void bubbleSort(char arr[][51], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(strcmp(arr[j], arr[j + 1]) > 0){
                char temp[51];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int main(){
    char line[51];

    while(fgets(line, sizeof(line), stdin) != NULL){
        if(line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';

        if(strcmp(line, "1") == 0){
            char pack[10][51];
            int count = 0;

            while(fgets(line, sizeof(line), stdin) != NULL){
                if(line[strlen(line) - 1] == '\n')
                    line[strlen(line) - 1] = '\0';

                if(strcmp(line, "0") == 0){
                    break;
                }

                strcpy(pack[count++], line);
            }

            bubbleSort(pack, count);

            for(int i = 0; i < count; i++){
                printf("%s\n", pack[i]);
            }

            printf("\n");
        }
    }

    return 0;
}
