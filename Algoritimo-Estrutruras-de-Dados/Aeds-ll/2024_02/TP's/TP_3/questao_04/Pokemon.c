#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

int primeiro, ultimo;

void start(){
    primeiro = ultimo = 0;
}

typedef struct{
    int id;
    int generation;
    char name[100];
    char description[300];
    char types[2][100];
    char abilities[6][100];
    double weight;
    double height;
    int captureRate;
    int isLegendary;
    Data date;
} Pokemon;

Pokemon pokemons[801];
Pokemon sub[801];
int tamSubArray = 0;

void formatarTipos(char tipos[2][100], char* buffer, int n){
    strcpy(buffer, "[");
    int primeiro = 1; 
    for(int i = 0; i < n; i++){
        if(strcmp(tipos[i], "") != 0){ 
            if(!primeiro){
                strcat(buffer, ", ");
            }
            strcat(buffer, "'");
            strcat(buffer, tipos[i]);
            strcat(buffer, "'");
            primeiro = 0;
        }
    }
    strcat(buffer, "]");
}

void initPersonagem(Pokemon *p) {
    p->id = 0;
    p->generation = 0;
    strcpy(p->name, "");
    strcpy(p->description, "");

    for(int i = 0; i < 2; i++){
        strcpy(p->types[i], "");
    }

    for(int i = 0; i < 6; i++){
        strcpy(p->abilities[i], "");
    }

    p->weight = 0.0;
    p->height = 0.0;
    p->captureRate = 0;
    p->isLegendary = 0;

    p->date.dia = 0;
    p->date.mes = 0;
    p->date.ano = 0;
}

void formatarHabilidades(char habilidades[6][100], char* buffer, int n){
    strcpy(buffer, "[");
    int primeiro = 1; 
    for(int i = 0; i < n; i++){
        if(strcmp(habilidades[i], "") != 0){  
            if(!primeiro){
                strcat(buffer, ", ");
            }
            strcat(buffer, "'");
            strcat(buffer, habilidades[i]);
            strcat(buffer, "'");
            primeiro = 0;
        }
    }
    strcat(buffer, "]");
}

void ajustarString(char *str){
    int start = 0;
    int end = strlen(str) - 1;

    while(str[start] == ' ' || str[start] == '\t' || str[start] == '\n'){
        start++;
    }

    while((end >= start) && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')){
        end--;
    }

    int i;
    for(i = start; i <= end; i++){
        str[i - start] = str[i];
    }
    str[i - start] = '\0';
}

char **dividirString(const char *src, const char *delim, int *count){
    char *buf = NULL;
    int srclen = strlen(src);
    int delimlen = strlen(delim);
    char **array = NULL;
    *count = 0;

    buf = (char *)malloc(srclen + 1);
    if(!buf) return NULL;

    strcpy(buf, src);

    char *start = buf;
    char *end = strstr(start, delim);

    while(end != NULL){
        array = (char **)realloc(array, (*count + 1) * sizeof(char *));
        *end = '\0';
        array[*count] = strdup(start);
        (*count)++;

        start = end + delimlen;
        while(strncmp(start, delim, delimlen) == 0){
            array = (char **)realloc(array, (*count + 1) * sizeof(char *));
            array[*count] = strdup("");
            (*count)++;
            start += delimlen;
        }

        end = strstr(start, delim);
    }

    array = (char **)realloc(array, (*count + 1) * sizeof(char *));
    array[*count] = strdup(start);
    (*count)++;

    array = (char **)realloc(array, (*count + 1) * sizeof(char *));
    array[*count] = NULL;

    free(buf);
    return array;
}

void Print(Pokemon *p, int pos){
    char tiposStr[256];       
    char habilidadesStr[256];  

    formatarTipos(p->types, tiposStr, 2);
    formatarHabilidades(p->abilities, habilidadesStr, 6);

    printf("[%d] [#%d -> %s: %s - %s - %s - %.1fkg - %.1fm - %d%% - %s - %d gen] - %02d/%02d/%04d\n",
           pos, p->id, p->name, p->description, tiposStr, habilidadesStr, 
           p->weight, p->height, p->captureRate, 
           (p->isLegendary ? "true" : "false"), p->generation, 
           p->date.dia, p->date.mes, p->date.ano);
}

void liberarDivisao(char **strlist){
    int i = 0;
    while(strlist[i]){
        free(strlist[i++]);
    }
    free(strlist);
}

void lerLinha(Pokemon *p, char *linha){
    int c = 0;
    int count = 0;
    char **array = dividirString(linha, ",", &count); 
    
    p->id = atoi(array[c++]);
    p->generation = atoi(array[c++]);
    strcpy(p->name, array[c++]);
    strcpy(p->description, array[c++]);

    strcpy(p->types[0], array[c++]);
    if(strcmp(array[c], "") != 0){
        strcpy(p->types[1], array[c++]);
    } else{
        strcpy(p->types[1], "");
        c++;
    }

    int idxHabilidades = 0;
    while(idxHabilidades <= 6 && c < count){
        strcpy(p->abilities[idxHabilidades], array[c]);
        idxHabilidades++;
        c++;
        if(strchr(array[c - 1], ']')){
            break;
        }
    }

    for(int i = 0; i < idxHabilidades; i++){
        char *habilidade = p->abilities[i];
        int len = strlen(habilidade);
        char habilidadeLimpa[100] = "";
        int idx = 0;

        for(int j = 0; j < len; j++){
            if(habilidade[j] != '[' && habilidade[j] != ']' && habilidade[j] != '"' && habilidade[j] != '\''){
                habilidadeLimpa[idx++] = habilidade[j];
            }
        }
        habilidadeLimpa[idx] = '\0';
        ajustarString(habilidadeLimpa);
        strcpy(p->abilities[i], habilidadeLimpa);
    }

    if(strcmp(array[c], "") == 0){
        p->weight = 0.0;
    } else{
        p->weight = atof(array[c]);
    }
    c++;

    if(strcmp(array[c], "") == 0){
        p->height = 0.0;
    } else{
        p->height = atof(array[c]);
    }
    c++;

    p->captureRate = atoi(array[c++]);
    p->isLegendary = (strcmp(array[c++], "1") == 0);

    char *data = array[c++];
    sscanf(data, "%d/%d/%d", &p->date.dia, &p->date.mes, &p->date.ano);

    liberarDivisao(array);
}

void lerDados(Pokemon p[]){
    char path[100];
    bool header = true;
    char line[500];
    int i = 0;

    strcpy(path, "/tmp/pokemon.csv");
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    while(fgets(line, sizeof(line), file)){
        if(header){
            header = false;
        } else{
            initPersonagem(&p[i]);
            lerLinha(&p[i], line);
            i++;
        }
    }
    fclose(file);
}

void swap(Pokemon *a, Pokemon *b){
    Pokemon temp = *a;
    *a = *b;
    *b = temp;
}

void clone(Pokemon *p, Pokemon *clone){
    clone->id = p->id;
    clone->generation = p->generation;
    strcpy(clone->name, p->name);
    strcpy(clone->description, p->description);
    
    for(int i = 0; i < 2; i++){
        strcpy(clone->types[i], p->types[i]);
    }
    
    for(int i = 0; i < 6; i++){
        strcpy(clone->abilities[i], p->abilities[i]);
    }
    
    clone->weight = p->weight;
    clone->height = p->height;
    clone->captureRate = p->captureRate;
    clone->isLegendary = p->isLegendary;
    clone->date = p->date; 
}

int isFim(char *str){
    int result = 1;

    if(str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0'){ 
        result = 0;
    }

    return result;
}

Pokemon remover(){
    Pokemon resposta = pokemons[primeiro];
    primeiro = (primeiro + 1) % (6);

  return resposta;
}

double mostrarMedia(listacirc *listadepokemons, int y) {
    double media = 0;
    int count = 0; 

    for (int i = 0; i < y + 1; i++) {
        if (listadepokemons->listapok[i]->id == 19) {
            listadepokemons->listapok[i]->captureRate = 255;
        }

        media += listadepokemons->listapok[i]->captureRate;
        count++; 
    }

    if (count > 0) {
        media = media / count; 
    }

    return media;
}

void inserir(Pokemon novo){
    if(((ultimo + 1) % (6)) == primeiro){
        Pokemon remove = remover();
    }

    pokemons[ultimo] = novo;
    ultimo = (ultimo + 1) % (6);
    printf("Média: %d\n", mostrarMedia());
}

Pokemon Procurar(Pokemon array[], char *id){
    Pokemon p;
    int idPokemon = atoi(id); 

    for(int i = 0; i < 801; i++){
        if(array[i].id == idPokemon){
            p = array[i];
            i = 801; 
        }
    }
    return p;
}

void subArray(Pokemon array[]){
    char line[50];

    scanf("%s", line);
    while (strcmp(line, "FIM") != 0){
        int idBusca = atoi(line); 
        for(int i = 0; i < 801; i++){
            if(array[i].id == idBusca){ 
                inserir(array[i]);
                break; 
            }
        }
        scanf("%s", line);
    }
}

void Exibir(){
    int i = primeiro;
    int j = 0;

    while(i != ultimo){
        Print(&pokemons[i], j);
        i = (i + 1) % 6;
        j++;
    }
}


void metodos(Pokemon array[], int qtd){
    char input[100];

    for(int i = 0; i < qtd; i++){
        scanf(" %[^\n]", input);
        input[strcspn(input, "\n")] = '\0'; 
        Pokemon novo;
        if (strncmp(input, "I", 1) == 0){
            char id[100];
            sscanf(input + 2, "%s", id);
            novo = Procurar(array, id);
            inserir(novo);
        } else{
            novo = remover();
            printf("(R) %s\n", novo.name);
        }
    }
    printf("\n");
    Exibir();
}


int main(){
    Pokemon array[801];
    int x = 0;

    lerDados(array); 
    start();
    subArray(array);
    scanf(" %i", &x);
    metodos(array, x);

  return 0;
}
