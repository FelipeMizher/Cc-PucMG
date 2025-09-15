#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Celula{
	int elemento;       
	struct Celula* prox;
} Celula;

Celula* novaCelula(int elemento){
   Celula* nova = (Celula*) malloc(sizeof(Celula));
   nova->elemento = elemento;
   nova->prox = NULL;

   return nova;
}   

Celula* primeiro;
Celula* ultimo;

void start(){
    primeiro = novaCelula(-1);
    ultimo = primeiro;
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

    strcpy(path, "C:/Users/felip_000/Desktop/AED_2/2024_02/TP's/TP_3/pokemon.csv");
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

int tamanho(){
    int tamanho = 0;
    Celula* i;
    for(i = primeiro; i != ultimo; i = i->prox, tamanho++);

    return tamanho;
}

void inserirInicio(int x) {
    Celula* tmp = novaCelula(x);
    tmp->prox = primeiro->prox;
    primeiro->prox = tmp;

    if(primeiro == ultimo){
        ultimo = tmp;
    }
}

void inserirFim(int x){
    Celula* tmp = novaCelula(x);
    ultimo->prox = tmp;
    ultimo = tmp;
}

void inserir(int x, int pos){
    int tam = tamanho();

    if(pos < 0 || pos > tam){
        printf("Erro ao inserir posicao (%d/ tamanho = %d) invalida!\n", pos, tam);
    } else if(pos == 0){
        inserirInicio(x);
    } else if(pos == tam){
        inserirFim(x);
    } else{
        Celula* i = primeiro;
        for (int j = 0; j < pos; j++, i = i->prox);

        Celula* tmp = novaCelula(x);
        tmp->prox = i->prox;
        i->prox = tmp;
    }
}

int removerInicio() {
    if(primeiro == ultimo){
        printf("Erro ao remover! Lista está vazia.\n");
    } else{
        Celula* tmp = primeiro->prox;
        primeiro->prox = tmp->prox;

        if(tmp == ultimo){
            ultimo = primeiro;
        }

        int resp = tmp->elemento;
        free(tmp);

        return resp;
    }
}

int removerFim(){
    if(primeiro == ultimo){
        printf("Erro ao remover! Lista está vazia.\n");
    } else{

        Celula* i = primeiro;
        while(i->prox != ultimo){
            i = i->prox;
        }

        int resp = ultimo->elemento;
        free(ultimo);
        ultimo = i;
        ultimo->prox = NULL;

        return resp;
    }
}

int remover(int pos){
    int tam = tamanho();

    if(primeiro == ultimo){
        printf("Erro ao remover! Lista está vazia.\n");
        return -1;
    } else if(pos < 0 || pos >= tam){
        printf("Erro ao remover posicao (%d/ tamanho = %d) invalida!\n", pos, tam);
        return -1;
    } else if(pos == 0){
        return removerInicio();
    } else if(pos == tam - 1){
        return removerFim();
    } else{
        Celula* i = primeiro;
        for (int j = 0; j < pos; j++, i = i->prox);

        Celula* tmp = i->prox;
        int resp = tmp->elemento;
        i->prox = tmp->prox;
        free(tmp);

        return resp;
    }
}

bool pesquisar(int x){
    bool retorno = false;
    Celula* i;

    for(i = primeiro->prox; i != NULL; i = i->prox){
        if(i->elemento == x){
            retorno = true;
            i = ultimo;
        }
    }
    
    return retorno;
}

void subArray(){
    char line[50];
    scanf("%s", line);

    scanf("%s", line);
    while(isFim(line) != 0){
        int id = atoi(line);

        if(id > 0 && id < 801){ 
            inserirFim(id);
        }
        scanf("%s", line);
    }
}

void mostrar(){
   Celula* i;
   int pos = 0;

    for(i = primeiro->prox; i != NULL; i = i->prox, pos++){
        Print(&pokemons[i->elemento - 1], pos);
    }
}

void metodos(int qtd){
    char input[100];

    for(int i = 0; i < qtd; i++){
        scanf(" %[^\n]", input);
        input[strcspn(input, "\n")] = '\0';
        
        int id;
        sscanf(input + 3, "%d", &id);
        
        if(strncmp(input, "II ", 3) == 0){
            if(!pesquisar(id)){
                inserirInicio(id);
            }
        } else if(strncmp(input, "IF ", 3) == 0){
            if(!pesquisar(id)){
                inserirFim(id);
            }
        } else if(strncmp(input, "I* ", 3) == 0){
            int posicao;
            sscanf(input + 3, "%d %d", &posicao, &id);
            if(!pesquisar(id)){
                inserir(id, posicao);
            }
        } else if(strncmp(input, "RI", 2) == 0){
            int removidoId = removerInicio();
            printf("(R) %s\n", pokemons[removidoId].name);
        } else if(strncmp(input, "RF", 2) == 0){
            int removidoId = removerFim();
            printf("(R) %s\n", pokemons[removidoId].name);
        } else if(strncmp(input, "R* ", 3) == 0){
            int posicao;
            sscanf(input + 3, "%d", &posicao);
            int removidoId = remover(posicao);
            printf("(R) %s\n", pokemons[removidoId].name);
        }
    }
}

int main(){
    start();
    lerDados(pokemons); 
    subArray();
    
    int x = 0;
    scanf("%d", &x);
    metodos(x);

    mostrar();

    return 0;
}
