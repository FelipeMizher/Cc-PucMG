#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int count = 0;
float tempo = 0.0;
clock_t inicio;
clock_t fim;

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

typedef struct No{
    Pokemon elemento;
    struct No *esq, *dir;
    int nivel;
} No;

No *novoNo(Pokemon p);
void start();
int max(int a, int b);
int altura(No *no);
int fatorBalanceamento(No *no);
No *rotacionarDir(No *no);
No *rotacionarEsq(No *no);
void inserir(Pokemon elemento);
No *inserirRec( Pokemon elemento, No *no);
No *balancear(No *no);
void pesquisar(char x[]);
bool pesquisarRec(No *i, char x[]);
void caminharPre();
void caminharPreRec(No* i);

No *novoNo(Pokemon p){
    No *novo = (No *)malloc(sizeof(No));

    novo->elemento = p;
    novo->dir = NULL;
    novo->esq = NULL;
    novo->nivel = 1;

    return novo;
}

No* raiz;

void start(){
    raiz = NULL;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int altura(No *no){
    if(no == NULL){
        return 0;
    }

    return no->nivel;
}

int fatorBalanceamento(No *no){
    if(no == NULL){
        return 0;
    }

    return altura(no -> dir) - altura(no -> esq);
}

No *rotacionarDir(No *no){
    No *noEsq = no->esq;
    No *noEsqDir = noEsq->dir;

    noEsq->dir = no;
    no->esq = noEsqDir;
    no->nivel = max(altura(no->esq), altura(no->dir)) + 1;
    noEsq->nivel = max(altura(noEsq->esq), altura(noEsq->dir)) + 1;

    return noEsq;
}

No *rotacionarEsq(No *no){
    No *noDir = no->dir;
    No *noDirEsq = noDir->esq;

    noDir->esq = no;
    no->dir = noDirEsq;
    no->nivel = max(altura(no->esq), altura(no->dir)) + 1;
    noDir->nivel = max(altura(noDir->esq), altura(noDir->dir)) + 1;

    return noDir;
}   

void inserir(Pokemon elemento){
    raiz = inserirRec(elemento, raiz);
}

No *inserirRec(Pokemon elemento, No *no){
    if(no == NULL){
        return novoNo(elemento);
    }
    int comparacao = strcmp(elemento.name, no->elemento.name);

    if(comparacao < 0){
        no->esq = inserirRec(elemento, no->esq);
    } else if(comparacao > 0){
        no->dir = inserirRec(elemento, no->dir);
    } else{
        no->elemento = elemento;
        return no;
    }
    balancear(no);
}

No *balancear(No *no){
    no->nivel = 1 + max(altura(no->esq), altura(no->dir));
    int fator = fatorBalanceamento(no);

    if(fator > 1){
        if(fatorBalanceamento(no->dir) < 0){
            no->dir = rotacionarDir(no->dir);
        }
        return rotacionarEsq(no);
    }

    if(fator < -1){
        if(fatorBalanceamento(no->esq) > 0){
            no->esq = rotacionarEsq(no->esq);
        }
        return rotacionarDir(no);
    }
    return no;
}

void pesquisar(char *nome) {
    printf("%s \nraiz", nome);
    count = 0;

    if(pesquisarRec(raiz, nome)) {
        printf(" SIM\n");
    } else {
        printf(" NAO\n");
    }
}

bool pesquisarRec(No *no, char *nome){
    if (no == NULL){
        return false;
    }
    int comparacao = strcmp(nome, no->elemento.name);
    count++;

    if (comparacao == 0) {
        return true;
    }
    else if (comparacao > 0) {
        printf(" dir");
        return pesquisarRec(no->dir, nome);
    }
    else {
        printf(" esq");
        return pesquisarRec(no->esq, nome);
    }
}

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

void initPersonagem(Pokemon *p){
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

Pokemon procurar(Pokemon array[], char *id){
    Pokemon p;

    if(id[strlen(id) + 2] == '\n'){
        id[strlen(id) + 2] = '\0';
    }

    for(int i = 0; i < 803; i++){
        if(pokemons[i].id == atoi(id)){
            p = array[i];
            i = 803;
        }
    }
    return p;
}

void inserirArvore(Pokemon array[]){
    char id[40];

    scanf("%s", id);
    while(isFim(id) != 0){
        Pokemon x = procurar(array, id);
        inserir(x);
        scanf("%s", id);
    }
}

void procurarNaArvore(){
    char nome[100];

    inicio = clock();
    scanf(" %[^\n\r]", nome);
    while(isFim(nome) != 0){
        pesquisar(nome);
        scanf(" %[^\n\r]", nome);
    }
    fim = clock();
    tempo = ((double)(inicio - fim)) / CLOCKS_PER_SEC;
}

void registroLog(){
    FILE *arquivo;

    arquivo = fopen("821811_avl.txt", "w");

    fprintf(arquivo, "Matrícula: 821811\t Tempo de execução: %.6f segundos\t Número de comparações: %d", tempo, count);

    fclose(arquivo);
}

int main(){
    Pokemon array[803];

    lerDados(array); 
    start();
    inserirArvore(array);
    procurarNaArvore();
    registroLog();

    return 0;
}
