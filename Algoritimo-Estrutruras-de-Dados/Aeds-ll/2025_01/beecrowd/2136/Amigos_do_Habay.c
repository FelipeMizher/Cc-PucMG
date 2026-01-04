#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char* nome[100];
  int n;
} Lista;

void inicializarLista(Lista *lista){
  lista->n = 0;
}

void inserir(Lista* lista, const char* s){
  if(lista->n < 100){
      lista->nome[lista->n] = strdup(s);
      lista->n++;
  }
}

int tamanho(Lista* lista){
  return lista->n;
}

int existe(Lista* lista, const char* s){
  int result = 0;

  for(int i = 0; i < lista->n; i++){
      if(strcmp(lista->nome[i], s) == 0){
          result = 1;
      }
  }

  return result;
}

void ordenar(Lista* lista){
  for(int i = 0; i < lista->n - 1; i++){
      for(int j = 0; j < lista->n - i - 1; j++){
          if(strcmp(lista->nome[j], lista->nome[j + 1]) > 0){
              char* temp = lista->nome[j];
              lista->nome[j] = lista->nome[j + 1];
              lista->nome[j + 1] = temp;
          }
      }
  }
}

char* encontrarAmigoDoHabay(Lista* lista){
  char* vencedor = NULL;
  int maior = -1;

  for(int i = 0; i < lista->n; i++){
      int len = strlen(lista->nome[i]);
      if(len > maior){
          maior = len;
          vencedor = lista->nome[i];
      }
  }

  return vencedor;
}

int main(void){
  Lista yesList, noList;
  inicializarLista(&yesList);
  inicializarLista(&noList);

  char nome[100], status[10];

  while(scanf("%s", nome) == 1 && strcmp(nome, "FIM") != 0){
      scanf("%s", status);

      if(strcmp(status, "YES") == 0){
          if(!existe(&yesList, nome)){
              inserir(&yesList, nome);
          }
      } else if(strcmp(status, "NO") == 0){
          if(!existe(&noList, nome)){
              inserir(&noList, nome);
          }
      } else{
          printf("Erro!\n");
      }
  }

  char* amigo = encontrarAmigoDoHabay(&yesList);

  ordenar(&yesList);
  ordenar(&noList);

  for(int i = 0; i < yesList.n; i++){
      printf("%s\n", yesList.nome[i]);
  }

  for(int i = 0; i < noList.n; i++){
      printf("%s\n", noList.nome[i]);
  }

  printf("\nAmigo do Habay:\n%s\n", amigo);

  for(int i = 0; i < yesList.n; i++) free(yesList.nome[i]);
  for(int i = 0; i < noList.n; i++) free(noList.nome[i]);

  return 0;
}
