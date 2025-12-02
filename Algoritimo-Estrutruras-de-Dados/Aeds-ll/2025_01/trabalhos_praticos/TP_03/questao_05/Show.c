#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char toLower(char c){
    char resp = c;

    if(c >= 'A' && c <= 'Z'){
        resp = c + 32;
    }

    return resp;
}

int Strleng(char str[]){
    int length = 0;
    while(str[length] != '\0'){
        length++;
    }
    return length;
}

void Strcopy(char dest[], char src[]){
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int isEqual(char str1[], char str2[]){
    int i = 0;
    int resp = 1;
    int len1 = Strleng(str1);
    int len2 = Strleng(str2);

    if(len1 == len2){
        while(i < len1 && resp){
            if(str1[i] != str2[i]){
                resp = 0;
            }
            i++;
        }
    } else{
        resp = 0;
    }

    return resp;
}

typedef struct{
    int ano;
    char mes[20];
    int dia;
} Data;

void Init_Date(Data *data){
    data->ano = 0;
    Strcopy(data->mes, "NaN");
    data->dia = 0;
}

void parseDate(Data *data, const char *source){
    if(source == NULL || source[0]== '\0'){
        Strcopy(data->mes, "March");
        data->dia = 1;
        data->ano = 1900;
    } else{
        char aux[100] = "";
        int auxIndex = 0;
        int step = 0;
        int i = 0;
    
        while(source[i] != '\0'){
            if(source[i] != ' ' && source[i] != ','){
                aux[auxIndex++] = source[i];
                aux[auxIndex] = '\0';
            } else{
                if(step == 0){
                    Strcopy(data->mes, aux);
                } else if(step == 1){
                    data->dia = atoi(aux);
                }
                auxIndex = 0;
                aux[0] = '\0';
                step++;
            }
            i++;
        }
    
        if(!isEqual(aux, "")){
            data->ano = atoi(aux);
        }
    }
    
}

typedef struct{
    char show_id[20];
    char type[20];
    char title[200];
    char director[100];
    char **cast;
    int cast_count;     
    char country[100];
    Data data_added;
    int release_year;
    char rating[20];
    char duration[20];
    char **listed_in;
    int listed_count;
} Show;


void Show_init(Show *s){
    Strcopy(s->show_id, "NaN");
    Strcopy(s->type, "NaN");
    Strcopy(s->title, "NaN");
    Strcopy(s->director, "NaN");
    
    s->cast = (char **)malloc(sizeof(char *));
    s->cast[0] = (char *)malloc(20 * sizeof(char));
    Strcopy(s->cast[0], "NaN");
    s->cast_count = 1;
    
    Strcopy(s->country, "NaN");
    
    Init_Date(&s->data_added);
    
    s->release_year = 0;
    Strcopy(s->rating, "NaN");
    Strcopy(s->duration, "NaN");
    
    
    s->listed_in = (char **)malloc(sizeof(char *));
    s->listed_in[0] = (char *)malloc(20 * sizeof(char));
    Strcopy(s->listed_in[0], "NaN");
    s->listed_count = 1;
}

int compareStrings(char str1[], char str2[]){
    int i = 0;
    int result = 0;

    while(str1[i] != '\0' && str2[i] != '\0' && result == 0){
        char c1 = toLower(str1[i]);
        char c2 = toLower(str2[i]);
        if(c1 != c2){
            result = c1 -  c2;
        }
        i++;
    }

    if(result == 0){
        result = Strleng(str1) - Strleng(str2);
    }
    return result;
}

void OrdenarCast(char **cast, int size){
    int i, j;
    char temp[100];

    for(i = 0; i < size; i++){
        for(j = 0; j < size - 1; j++){
            if(compareStrings(cast[j], cast[j + 1]) > 0){
                Strcopy(temp, cast[j]);
                Strcopy(cast[j], cast[j + 1]);
                Strcopy(cast[j + 1], temp);
            }
        }
    }
}

void Show_Imprimir(Show *s){
    printf("=> %s ## %s ## %s ## %s ## [",
            s->show_id, s->title, s->type, s->director);

    for(int i = 0; i < s->cast_count; i++){
        printf("%s", s->cast[i]);
        if(i < s->cast_count - 1){
            printf(", ");
        }
    }

    printf("] ## %s ## %s %d, %d ## %d ## %s ## %s ## [",
           s->country, s->data_added.mes, s->data_added.dia,
           s->data_added.ano, s->release_year, s->rating, s->duration);

    for(int i = 0; i < s->listed_count; i++){
        printf("%s", s->listed_in[i]);
        if(i < s->listed_count - 1){
            printf(", ");
        }
    }

    printf("] ##\n");
}

void Show_Ler(Show *show, char* line){
    char temp[11][1000];
    int TMPindex[11] = {0};
    int i = 0;
    int campo = 0;

    while(line[i] != '\0' && campo < 11){
        if(line[i] == '"'){
            i++;
            while(line[i] != '"' || (line[i] == '"' && line[i + 1] == '"')){
                if(line[i] == '"' && line[i + 1] == '"'){
                    i += 2;
                } else{
                    temp[campo][TMPindex[campo]++] = line[i++];
                }
            }
            i++;
            if (line[i] == ',')
                i++;
            temp[campo][TMPindex[campo]] = '\0';
            campo++;
        } else{
            while(line[i] != ',' && line[i] != '\0'){
                temp[campo][TMPindex[campo]++] = line[i++];
            }
            if(line[i] == ','){
                i++;
            }
            temp[campo][TMPindex[campo]] = '\0';
            campo++;
        }
    }

    Strcopy(show->show_id, temp[0][0] ? temp[0] : "NaN");
    Strcopy(show->type, temp[1][0] ? temp[1] : "NaN");
    Strcopy(show->title, temp[2][0] ? temp[2] : "NaN");
    Strcopy(show->director, temp[3][0] ? temp[3] : "NaN");
    Strcopy(show->country, temp[5][0] ? temp[5] : "NaN");
    parseDate(&show->data_added, temp[6]);
    show->release_year = atoi(temp[7]);
    Strcopy(show->rating, temp[8][0] ? temp[8] : "NaN");
    Strcopy(show->duration, temp[9][0] ? temp[9] : "NaN");

    if(temp[4][0]){
        show->cast_count = 1;
        for(i = 0; temp[4][i]; i++){
            if(temp[4][i] == ','){
                show->cast_count++;
            }
        }

        show->cast = (char **)malloc(show->cast_count * sizeof(char *));
        for (i = 0; i < show->cast_count; i++)
        {
            show->cast[i] = (char *)malloc(100 * sizeof(char));
        }

        int IndexC = 0;
        int currentCast = 0;
        i = 0;
        while(temp[4][i]){
            if(temp[4][i] == ','){
                show->cast[currentCast][IndexC] = '\0';
                currentCast++;
                IndexC = 0;
                i++;
                while(temp[4][i] == ' '){
                    i++;
                }
            } else{
                show->cast[currentCast][IndexC++] = temp[4][i++];
            }
        }
        show->cast[currentCast][IndexC] = '\0';
        OrdenarCast(show->cast, show->cast_count);
    } else{
        show->cast_count = 1;
        show->cast = (char **)malloc(sizeof(char *));
        show->cast[0] = (char *)malloc(20 * sizeof(char));
        Strcopy(show->cast[0], "NaN");
    }

    if(temp[10][0]){
        show->listed_count = 1;
        for(i = 0; temp[10][i]; i++){
            if(temp[10][i] == ','){
                show->listed_count++;
            }
        }

        show->listed_in = (char **)malloc(show->listed_count * sizeof(char *));
        for(i = 0; i < show->listed_count; i++){
            show->listed_in[i] = (char *)malloc(100 * sizeof(char));
        }

        int IndexL = 0;
        int currentList = 0;
        i = 0;
        while (temp[10][i]){
            if(temp[10][i] == ','){
                show->listed_in[currentList][IndexL] = '\0';
                currentList++;
                IndexL = 0;
                i++;
                while(temp[10][i] == ' '){
                    i++;
                }
            } else{
                show->listed_in[currentList][IndexL++] = temp[10][i++];
            }
        }
        show->listed_in[currentList][IndexL] = '\0';
    } else{
        show->listed_count = 1;
        show->listed_in = (char **)malloc(sizeof(char *));
        show->listed_in[0] = (char *)malloc(20 * sizeof(char));
        Strcopy(show->listed_in[0], "NaN");
    }
}

void copyCast(Show *copy, Show *source){
    copy->cast_count = source->cast_count;
    copy->cast = (char**)malloc(copy->cast_count * sizeof(char*));
    
    for(int i = 0; i < copy->cast_count; i++){
        copy->cast[i] = (char*)malloc(100 * sizeof(char));
        Strcopy(copy->cast[i], source->cast[i]);
    }
}

void copyListed(Show *copy, Show *source){
    copy->listed_count = source->listed_count;
    copy->listed_in = (char**)malloc(copy->listed_count * sizeof(char*));
    
    for(int i = 0; i < copy->listed_count; i++){
        copy->listed_in[i] = (char*)malloc(100 * sizeof(char));
        Strcopy(copy->listed_in[i], source->listed_in[i]);
    }
}

void clone(Show *array, Show *source){
    Strcopy(array->show_id, source->show_id);
    Strcopy(array->type, source->type);
    Strcopy(array->title, source->title);
    Strcopy(array->director, source->director);
    Strcopy(array->country, source->country);
    array->release_year = source->release_year;
    Strcopy(array->rating, source->rating);
    Strcopy(array->duration, source->duration);

    array->data_added.ano = source->data_added.ano;
    array->data_added.dia = source->data_added.dia;
    Strcopy(array->data_added.mes, source->data_added.mes);

    copyCast(array,source);
    copyListed(array,source);
}

int Pesquisar_ID(Show shows[], int size, char* id){
    int resp = 0;
    int i = 0;

    while(i < size){
        if(isEqual(shows[i].show_id, id)){
            resp = i;
            i = size;
        }
        i++;
    }
    return resp;
}

int IsFim(char line[]){
    int resp = 1;

    if(line[0] == 'F' && line[1] == 'I' && line[2] == 'M'){
        resp = 0;
    }

    return resp;
}

void freeShow(Show *show){
    for(int i = 0; i < show->cast_count; i++){
        free(show->cast[i]);
    }
    free(show->cast);

    for(int i = 0; i < show->listed_count; i++){
        free(show->listed_in[i]);
    }
    free(show->listed_in);
}

int buscar(Show shows[], int size, char *id){
    int resp = 0;
    int i = 0;

    while(i < size){
        if(strcmp(shows[i].show_id, id) == 0){
            resp = i;
            i = size;
        }
        i++;
    }
    return resp;
}

typedef struct Celula{
	Show elemento;        
	struct Celula* prox; 
} Celula;

Celula* novaCelula(Show elemento){
   Celula* nova = (Celula*) malloc(sizeof(Celula));
   nova->elemento = elemento;
   nova->prox = NULL;
   return nova;
}

Celula* primeiro;
Celula* ultimo;

void start (){
    Show cabeca;
    primeiro = novaCelula(cabeca);
    ultimo = primeiro;
}

int tamanho(){
   int tamanho = 0;
   Celula* i;
   for(i = primeiro; i != ultimo; i = i->prox, tamanho++);
   return tamanho;
}

void inserirInicio(Show x){
    Celula* tmp = novaCelula(x);

    tmp->prox = primeiro->prox;
    primeiro->prox = tmp;
    if(primeiro == ultimo){                   
      ultimo = tmp;
    }
    tmp = NULL;
}

void inserirFim(Show x){
    ultimo->prox = novaCelula(x);
    ultimo = ultimo->prox;
}

void inserir(Show x, int pos){
   int tam = tamanho();

    if(pos < 0 || pos > tam){
        printf("Erro ao inserir posicao (%d/ tamanho = %d) invalida!", pos, tam);
        exit(1);
    } else if(pos == 0){
        inserirInicio(x);
    } else if(pos == tam){
        inserirFim(x);
    } else{
        int j;
        Celula* i = primeiro;
        for(j = 0; j < pos; j++, i = i->prox);

        Celula* tmp = novaCelula(x);
        tmp->prox = i->prox;
        i->prox = tmp;
        tmp = i = NULL;
   }
}

Show removerInicio(){
    if(primeiro == ultimo){
        printf("Erro ao remover!");
        exit(1);
    }

    Celula* tmp = primeiro;
    primeiro = primeiro->prox;
    Show resp = primeiro->elemento;
    tmp->prox = NULL;
    free(tmp);
    tmp = NULL;

    return resp;
}

Show removerFim(){
    if(primeiro == ultimo){
        printf("Erro ao remover!");
        exit(1);
    } 

    Celula* i;
    for(i = primeiro; i->prox != ultimo; i = i->prox);

    Show resp = ultimo->elemento;
    ultimo = i;
    free(ultimo->prox);
    i = ultimo->prox = NULL;

    return resp;
}

Show remover(int pos){
    Show resp;
    int tam = tamanho();

    if(primeiro == ultimo){
        printf("Erro ao remover (vazia)!");
        exit(1);
    } else if(pos < 0 || pos >= tam){
        printf("Erro ao remover posicao (%d/ tamanho = %d) invalida!", pos, tam);
        exit(1);
    } else if(pos == 0){
        resp = removerInicio();
    } else if(pos == tam - 1){
        resp = removerFim();
    } else{
        Celula* i = primeiro;
        int j;
        for(j = 0; j < pos; j++, i = i->prox);

        Celula* tmp = i->prox;
        resp = tmp->elemento;
        i->prox = tmp->prox;
        tmp->prox = NULL;
        free(tmp);
        i = tmp = NULL;
    }

    return resp;
}

void mostrar(){
    Celula* i;

    for(i = primeiro->prox; i != NULL; i = i->prox){
        Show_Imprimir(&i->elemento);
    }
}

Show procurar(Show shows[], int size, char *id){
    Show resp;
    int i = 0;

    while(i < size){
        if(strcmp(shows[i].show_id, id) == 0){
            resp = shows[i];
            i = size;
        }
        i++;
    }

    return resp;
}

void metodos(int j, Show shows[], int show_count){
    char comando [3];
    char id [5];
    int pos;

    while (j > 0) {
        scanf(" %s", comando);
        if(strcmp(comando,"II") == 0){
            scanf(" %s", id); 
            inserirInicio(procurar(shows,show_count, id));
        }else if(strcmp(comando,"IF") == 0){
            scanf(" %s", id);
            inserirFim(procurar(shows,show_count, id));
        }else if(strcmp(comando,"I*") == 0){
            scanf(" %d", &pos); 
            scanf(" %s", id);
            inserir(procurar(shows,show_count, id),pos);
        }else if(strcmp(comando,"RI") == 0) {
            printf("(R) %s\n", removerInicio().title);
        }else if(strcmp(comando,"RF") == 0) {
            printf("(R) %s\n", removerFim().title);
        }else{
            scanf(" %d", &pos);
            printf("(R) %s\n", remover(pos).title);
        }
        j--;
    }
}

int main(){
    Show shows[1368];
    char line[5000];
    int show_count = 0, x = 0;

    FILE *file = fopen("/tmp/disneyplus.csv", "r");
    if(!file){
        printf("Arquivo nao encontrado!");
        return 1;
    }

    fgets(line, sizeof(line), file);

    while(fgets(line, sizeof(line), file) && show_count < 1368){
        Show_init(&shows[show_count]);
        Show_Ler(&shows[show_count], line);
        show_count++;
    }
    fclose(file);

    char input[20];
    scanf("%s", input);
    start();

    while (!strcmp(input, "FIM") == 0){
        int index = buscar(shows, show_count, input);
        inserirFim(shows[index]);
        scanf(" %s", input);
    }

    int qtd;
    scanf("%d", &qtd);
    metodos(qtd, shows, show_count);
    mostrar();

    for(int i = 0; i < show_count; i++){
        freeShow(&shows[i]);
    }

    return 0;
}