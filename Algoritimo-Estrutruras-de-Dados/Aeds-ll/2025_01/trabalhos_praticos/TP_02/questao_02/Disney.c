#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char mes[15];
    int dia;
    int ano;
} Data;

typedef struct {
    char show_id[50];
    char type[50];
    char title[50];
    char director[50];
    char cast[10][50];
    int cast_count;     
    char country[50];
    Data data;
    char release_year[50];
    char rating[50];
    char duration[50];
    char listed_in[10][50];
    int listed_count;
} Show;

Data Data_new(){
    Data d;
    d.mes[0] = '\0';
    d.dia = 0;
    d.ano = 0;
    return d;
}

void Show_init(Show *s){
    s->show_id[0] = '\0';
    s->type[0] = '\0';
    s->title[0] = '\0';
    s->director[0] = '\0';
    s->cast[0][0] = '\0';
    s->country[0] = '\0';
    s->data = Data_new();
    s->release_year[0] = '\0';
    s->rating[0] = '\0';
    s->duration[0] = '\0';
    s->listed_in[0][0] = '\0';
}

void ordenar(char arr[][50], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(strcmp(arr[i], arr[j]) > 0){
                char temp[100];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

void Show_imprimir(Show* s){
    printf("=> %s ## ", s->show_id);
    printf("%s ## ", s->title);
    printf("%s ## ", s->type);
    printf("%s ## [", s->director);

    if(strcmp(s->cast[0], "NaN") == 0){
        printf("NaN");
    } else{
        for(int i = 0; i < s->cast_count; i++){
            printf("%s", s->cast[i]);
            if(i < s->cast_count - 1) printf(", ");
        }
    }

    printf("] ## %s ## ", s->country);
    printf("%s %d, %d ## ", s->data.mes, s->data.dia, s->data.ano);
    printf("%s ## %s ## %s ## [", s->release_year, s->rating, s->duration);

    if(strcmp(s->listed_in[0], "NaN") == 0){
        printf("NaN");
    } else{
        for(int i = 0; i < s->listed_count; i++){
            printf("%s", s->listed_in[i]);
            if(i < s->listed_count - 1) printf(", ");
        }
    }

    printf("] ##\n");
}

Show Show_Ler(char* line){
    Show s;
    Show_init(&s); 

    char temp[12][100];
    int index = 0;
    int campoIndex = 0;
    int dentroAspas = 0;
    char campo[100];

    for(int i = 0; line[i] != '\0'; i++){
        char c = line[i];

        if(c == '"'){
            dentroAspas = !dentroAspas;
        } else if(c == ',' && !dentroAspas){
            campo[campoIndex] = '\0';
            if(campoIndex == 0){
                strcpy(temp[index++], "NaN");
            } else{
                strcpy(temp[index++], campo);
            }
            campoIndex = 0;
        } else {
            campo[campoIndex++] = c;
        }
    }

    campo[campoIndex] = '\0';
    if(campoIndex == 0){
        strcpy(temp[index], "NaN");
    } else{
        strcpy(temp[index], campo);
    }

    strcpy(s.show_id,      temp[0]);
    strcpy(s.type,         temp[1]);
    strcpy(s.title,        temp[2]);
    strcpy(s.director,     temp[3]);
    strcpy(s.country,      temp[5]);

    if(strcmp(temp[6], "NaN") != 0){
        sscanf(temp[6], "%s %d, %d", s.data.mes, &s.data.dia, &s.data.ano);
    }

    strcpy(s.release_year, temp[7]);
    strcpy(s.rating,       temp[8]);
    strcpy(s.duration,     temp[9]);

    if(strcmp(temp[4], "NaN") != 0){
        s.cast_count = 0;
        char* token = strtok(temp[4], ",");
        while(token != NULL && s.cast_count < 10){
            while(*token == ' ') token++; 
            strcpy(s.cast[s.cast_count++], token);
            token = strtok(NULL, ",");
        }
        ordenar(s.cast, s.cast_count);
    } else {
        strcpy(s.cast[0], "NaN");
        s.cast_count = 1;
    }

    if(strcmp(temp[10], "NaN") != 0){
        s.listed_count = 0;
        char* token = strtok(temp[10], ",");
        while(token != NULL && s.listed_count < 10){
            while(*token == ' ') token++;
            strcpy(s.listed_in[s.listed_count++], token);
            token = strtok(NULL, ",");
        }
        ordenar(s.listed_in, s.listed_count);
    } else{
        strcpy(s.listed_in[0], "NaN");
        s.listed_count = 1;
    }

    return s;
}

void Carregar(Show shows[]){
    FILE* arquivo = fopen("/tmp/disneyplus.csv", "r");
    if(arquivo == NULL){
        printf("Arquivo não encontrado!\n");
        return;
    }

    char line[3000];
    fgets(line, sizeof(line), arquivo);

    for(int i = 0; i < 1368; i++){
        if(fgets(line, sizeof(line), arquivo)){
            int j = 0;
            while(line[j] != '\0'){
                if(line[j] == '\n'){
                    line[j] = '\0';
                }
                j++;
            }
            shows[i] = Show_Ler(line);
        }
    }

    fclose(arquivo);
}

void Pesquisar_ID(Show shows[], char* id){
    for(int i = 0; i < 1368; i++){
        if(strcmp(shows[i].show_id, id) == 0){
            Show_imprimir(&shows[i]);
        }
    }
}

int IsFim(char line[]){
    return !(line[0] == 'F' && line[1] == 'I' && line[2] == 'M');
}

int main(){
    Show shows[1368];
    char line[100];

    Carregar(shows);

    scanf(" %[^\n]", line);
    while(IsFim(line)){
        Pesquisar_ID(shows, line);
        scanf(" %[^\n]", line);
    }

    return 0;
}
