#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int count = 0, movimentacoes = 0;
float tempo = 0.0;
clock_t start;
clock_t end;

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

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

typedef struct Celula{
    struct Celula* prox;
    struct Celula* ant;
    Pokemon elemento;
}Celula;

Celula* primeiro;
Celula* ultimo;
int tamanho = 0;
Pokemon personagens[404];

Celula* novaCelula(Pokemon elemento) {
   Celula* nova = (Celula*) malloc(sizeof(Celula));
   nova->elemento = elemento;
   nova->prox = NULL; nova->ant = NULL;
   return nova;
}

void initPokemon(Pokemon *p);

void init() {
    Pokemon x;
    initPokemon(&x);
    primeiro = novaCelula(x);
    ultimo = primeiro;
}

void adicionar(Pokemon x) {
    if(tamanho < 404){
        ultimo->prox = novaCelula(x);
        ultimo->prox->ant = ultimo;
        ultimo = ultimo->prox;
        tamanho++;
    }   
}

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

void Print(Pokemon *p){
    char tiposStr[256];       
    char habilidadesStr[256];  

    formatarTipos(p->types, tiposStr, 2);
    formatarHabilidades(p->abilities, habilidadesStr, 6);

    printf("[#%d -> %s: %s - %s - %s - %.1fkg - %.1fm - %d%% - %s - %d gen] - %02d/%02d/%04d\n",
           p->id, p->name, p->description, tiposStr, habilidadesStr, 
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

void lerLinha(char *linha, Pokemon *p){
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

void lerDados(){
    char path[100];
    bool header = true;
    char line[500];
    int i = 0;

    strcpy(path, "/tmp/pokemon.csv");
    FILE *file = fopen(path, "r");
    if(file == NULL){
        perror("Erro ao abrir o arquivo");
        return;
    }

    while(fgets(line, sizeof(line), file)){
        if(header){
            header = false;
        } else{
            lerLinha(line, &pokemons[i]);
            i++;
            if(i >= 801) break; 
        }
    }
    fclose(file);
}

void swap(Celula *p1, Celula *p2){
    Pokemon tmp = p1->elemento;
    p1->elemento = p2->elemento;
    p2->elemento = tmp;
    movimentacoes += 3;
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

void initPokemon(Pokemon *p){
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

bool comparar(Pokemon a, Pokemon b){
    bool resultado;

    if(a.generation < b.generation){
        resultado = true;
    } else if(a.generation > b.generation){
        resultado = false;
    } else{
        if(strcmp(a.name, b.name) < 0){
            resultado = true;
        } else{
            resultado = false;
        }
    }

    return resultado;
}

int isFim(char *str){
    int result = 1;

    if(str[0] == 'F' && str[1] == 'I' && str[2] == 'M' && str[3] == '\0'){ 
        result = 0;
    }

    return result;
}

void subArray(){
    char id[50];

    scanf(" %s", id);
    while(isFim(id) != 0){
        int i = 0;
        while(i < 801){
            if(pokemons[i].id == atoi(id)){
                adicionar(pokemons[i]);
                i = 801;
            }
            i++;
        }
        scanf(" %s", id);
    }
}

bool verificar(Celula* i, Celula* pro){
    bool resposta = false;

    while(!resposta && i != NULL){
        if(i == pro){
            resposta = true;
        }
        i = i->prox;
    }

  return resposta;
}

void inserir(Celula* esq, Celula* dir){
    if(esq != dir && esq != dir->prox){
        Celula* i = esq; Celula* j = dir;
        Pokemon pivo = i->elemento;
        while(verificar(i, j)){
            while(comparar(i->elemento, pivo)){ 
                i = i->prox; 
                count++;
            }
            while(comparar(pivo, j->elemento)){ 
                j = j->ant; 
                count++;
            }
            if(verificar(i, j)){
                swap(i, j);
                i = i->prox; 
                j = j->ant;
                count++;
            }
        }
        inserir(esq, j);
        inserir(i, dir);
    }
}

void quicksort(){
    start = clock();
    inserir(primeiro->prox, ultimo);
    end = clock();
    tempo = ((double)(end - start)) / CLOCKS_PER_SEC;
}

void Exibir(){
    for(Celula *i = primeiro->prox;i != NULL;i = i->prox){
        Print(&i->elemento);
    }
}

void registroLog(){
    FILE *arquivo;

    arquivo = fopen("/tmp/821811_quicksort2.txt", "w");

    fprintf(arquivo, "Matrícula: 821811\t Tempo de execução: %.6f segundos\t Número de comparações: %d \t Número de movimentações: %d", tempo, count, movimentacoes);

    fclose(arquivo);
}

int main(){

    lerDados(); 
    init();
    subArray();
    quicksort();
    Exibir();
    registroLog();

    return 0;
}
