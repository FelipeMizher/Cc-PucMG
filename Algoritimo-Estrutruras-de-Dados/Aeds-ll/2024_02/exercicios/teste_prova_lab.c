#include <stdio.h>
#include <string.h>
#include <stdio.h>

const char FLAG_OESTE[] = "-1";
const char FLAG_NORTE[] = "-3";
const char FLAG_SUL[] = "-2";
const char FLAG_LESTE[] = "-4";

typedef struct{
  char id[5];
} Aviao;

int main(void){
  char line[20]; 
  char flagAtual[20];
  int numAvioesOeste = 0;
  int numAvioesNorte = 0;
  int numAvioesSul = 0;
  int numAvioesLeste = 0;
  Aviao avioesOeste[20];
  Aviao avioesNorte[20];
  Aviao avioesSul[20];
  Aviao avioesLeste[20];

  scanf(" %s", line);

  while(strcmp(line, "0") != 0){
    if(strcmp(line, FLAG_OESTE) == 0 || strcmp(line, FLAG_NORTE) == 0 || 
      strcmp(line, FLAG_SUL) == 0 || strcmp(line, FLAG_LESTE) == 0){
        strcpy(flagAtual, line);
      } else{
        if(strcmp(flagAtual, FLAG_OESTE) == 0){
          strcpy(avioesOeste[numAvioesOeste].id, line);
          numAvioesOeste++;
        } else if(strcmp(flagAtual, FLAG_NORTE) == 0){
          strcpy(avioesNorte[numAvioesNorte].id, line);
          numAvioesNorte++;
        } else if(strcmp(flagAtual, FLAG_SUL) == 0){
          strcpy(avioesSul[numAvioesSul].id, line);
          numAvioesSul++;
        } else if(strcmp(flagAtual, FLAG_LESTE) == 0){
          strcpy(avioesLeste[numAvioesLeste].id, line);
          numAvioesLeste++;
        }
      }
      scanf(" %s", line);
  }

  int n = numAvioesOeste;
  if(numAvioesNorte > n){
    n = numAvioesNorte;
  }
  if(numAvioesSul > n){
    n = numAvioesSul;
  }
  if(numAvioesLeste > n){
    n = numAvioesLeste;
  }

  for(int i = 0; i < n; i++){
    if(i < numAvioesOeste){
      printf("%s ", avioesOeste[i].id);
    }
    if(i < numAvioesNorte){
      printf("%s ", avioesNorte[i].id);
    }
    if(i < numAvioesSul){
      printf("%s ", avioesSul[i].id);
    }
    if(i < numAvioesLeste){
      printf("%s ", avioesLeste[i].id);
    }
  }

  return 0;
}