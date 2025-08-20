// 821811 - Felipe Rivetti Mizher

/*
 exercicio06 - v0.0. - 20 / 11 / 2023
 Author: ____Felipe Rivetti Mizher___
*/
// dependencias
#include "io.h" // para definicoes proprias
/**
 Method_00 - nao faz nada.
*/
void method_00 ( void )
{
    // nao faz nada
} // end method_00 ( ) 

/** 
    Função para trocar de lugar os dados
*/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
} // end swap
/**
    Função para verificar se o array esta em ordem
*/
int verificarOrdem(int tamanho, int array[]){
 // definir dados
    int x = 0; 
    
    for(x = 0; x < tamanho - 1; x = x + 1){
        if(array[x] < array[x + 1]){
            return 0; // Não esta em ordem decrescente
        } 
    } 
    return 1; // esta em ordem decrescente
} // end verificarOrdem( )
/**
    Função para colocar os dados em ordem
*/
void ordernar(int tamanho, int array[]){
 // definir dados
    int troca = 0;
    int x = 0;
    
    do{
        troca = 0;
        
        for(x = 0; x < tamanho - 1; x = x + 1){
            if (array[x] < array[x + 1]) {
                swap(&array[x], &array[x + 1]);
                troca = 1;
            }
        }
    } while(troca);
} // end ordernar( )
/** 
   Method_01  
 */ 
void method_01 ( ) 
{ 
 // definir dados
    FILE *arquivo1;
    FILE *arquivo2;
    int tamanho = 0;
    int x = 0;
    
 // identificar 
    IO_id( "Method_01 - v0.0" ); 
    
 // abrir arquivo1
    arquivo1 = fopen("DADOS1.TXT", "rt");
    
 // ler o tamanho do array
    fscanf(arquivo1, "%d", &tamanho);
 
 // ler os dados do array
    int dados[tamanho];
    for(x = 0; x < tamanho; x = x + 1){
        fscanf(arquivo1, "%d ", &dados[x]);
    } // end for
    
 // fechar arquivo1
    fclose(arquivo1);
    
 // abrir arquivo2
    arquivo2 = fopen("DECRESCENTE.TXT", "wt");
    
 // verificar se esta em ordem, e se não estiver colocar em ordem
    while(verificarOrdem(tamanho, dados) == 0){
        ordernar(tamanho, dados);
    } // end while
    
 // salvar o tamanho do array
    fprintf(arquivo2, "%d\n", tamanho);
    
 // salvar os dados em ordem no arquivo2
    for(x = 0; x < tamanho; x = x + 1){
        fprintf(arquivo2, "%d ", dados[x]);
    } // end for
    
 // fechar arquivo2
    fclose(arquivo2);
    
 // exibir mensagem de que foi salvo o novo arquivo
    printf("\nArquivo salvo com sucesso.\n");
    
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
    Função para inverter os dados do array
*/
void inverterArray(int tamanho, int array[]){
 // definir dados
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio < fim) {
 // Trocar o primeiro elemento com o último
        int temp = array[inicio];
        array[inicio] = array[fim];
        array[fim] = temp;
 // Mover os índices para a próxima interação
        inicio++;
        fim--;
    }
}
/** 
   Method_02  
 */ 
void method_02 ( ) 
{ 
 // definir dados
    FILE *arquivo1;
    FILE *arquivo2;
    int x = 0, tamanho = 0;
    
 // identificar 
    IO_id( "Method_02 - v0.0" ); 
    
 // abrir arquivo1
    arquivo1 = fopen("DECRESCENTE.TXT", "rt");
    
 // ler o tamanho do array
    fscanf(arquivo1, "%d", &tamanho);
    
    int array[tamanho];
    for(x = 0; x < tamanho; x = x + 1){
        fscanf(arquivo1, "%d", &array[x]);
    } // end for
    
 // fechar arquivo1
    fclose(arquivo1);
    
 // abrir arquivo2
    arquivo2 = fopen("INVERTIDOS.TXT", "wt");
    
 // chamar a função para inverter a ordem do array
    inverterArray(tamanho, array);
    
 // salvar o tamanho do array no novo arquivo
    fprintf(arquivo2, "%d\n", tamanho);
    
 // looping para gravar os dados invertidos no arquivo
    for(x = 0; x < tamanho; x = x + 1){
        fprintf(arquivo2, "%d ", array[x]);
    } // end for
    
 // fechar arquivo2
    fclose(arquivo2);
    
 // exibir mensagem para sinalizar que foi salvo o novo arquivo
    printf("Arranjo invertido salvo com sucesso.\n");
    
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
    Função para ordenar um array
*/
void arrayOrdenar(int tamanho, int array[]){
 // definir dados
    int i = 0, j = 0;
    
 // colocar os dados em ordem
    for(i = 0; i < tamanho - 1; i = i + 1){
        for(j = 0; j < tamanho - i - 1; j = j + 1){
            if(array[j] > array[j + 1]){
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}
/**
    Função para calcular a mediana do arranjo
*/
float arranjo_mediana(int tamanho, int array[]) {
 // definir dados
    int i = 0, j = 0;
    int meio1 = 0, meio2 = 0;
 
 // chamar a função para colocar os dados em ordem
    arrayOrdenar(tamanho, array);
 
 // Calcular a mediana
    if (tamanho % 2 == 0) {
 // Se o tamanho for par, média dos dois valores do meio
        meio1 = array[tamanho / 2 - 1];
        meio2 = array[tamanho / 2];
        return (float)(meio1 + meio2) / 2.0;
    } else {
 // Se o tamanho for ímpar, valor do meio
        return array[tamanho / 2];
    }
}
/**
    Função para calcular a moda do arranjo
*/
void arranjo_moda(int tamanho, int array[]){
 // definir dados
    int contagem = 0, i = 0, j = 0;
    int moda = array[0];
    int maxContagem = 1;
    int atual = 0, contAtual = 0;

 // calcular a moda
    for(i = 0; i < tamanho - 1; i++){
        atual = array[i];
        contAtual = 1;

        for(j = i + 1; j < tamanho; j++){
            if(array[j] == atual){
                contAtual++;
            }
        }

        if(contAtual > maxContagem){
            moda = atual;
            maxContagem = contAtual;
        }
    }

 // exibir o valor da moda calculado
    printf("Moda: %d\n", moda);
}
/** 
   Method_03  
 */ 
void method_03 ( ) 
{ 
 // definir dados
    FILE *arquivo;
    int tamanho = 0, x = 0;
    float mediana = 0;
    
 // identificar 
    IO_id( "Method_03 - v0.0" ); 
    
 // abrir arquivo
    arquivo = fopen("DADOS1.TXT", "rt");
 
 // ler o tamanho do array
    fscanf(arquivo, "%d", &tamanho);
    
 // ler os elementos do array
    int array[tamanho];
    for(x = 0; x < tamanho; x = x + 1){
        fscanf(arquivo, "%d", &array[x]);
    } // end for
 
 // fechar arquivo   
    fclose(arquivo);
    
 // Calcular e imprimir a mediana
    mediana = arranjo_mediana(tamanho, array);
    printf("Mediana: %.2f\n", mediana);
    
 // Calcular e imprimir a moda
    arranjo_moda(tamanho, array);
    
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
    função para ler arquivos
*/
void lerArray(char *nomeArquivo, int *tamanho, int array[]) {
    FILE *arquivo = fopen(nomeArquivo, "rt");
    int i = 0;

 // Ler o tamanho do arranjo
    fscanf(arquivo, "%d", tamanho);

 // Ler os dados do arranjo
    for (i = 0; i < *tamanho; i++) {
        fscanf(arquivo, "%d", &array[i]);
    }

 // Fechar o arquivo
    fclose(arquivo);
}
/**
    fynção para filtrar os dados em comum dos arquivos
*/
void arranjo_filtrar(int *tamanhoResultado, int resultado[], int tamanho1, int array1[], int tamanho2, int array2[]) {
    int indiceResultado = 0;
    int i = 0, j = 0, k = 0, encontrado = 0, duplicado = 0;

 // Verificar cada elemento de A
    for (i = 0; i < tamanho1; i = i + 1) {
 // Verificar se o elemento de A está em B
        encontrado = 0;
        for (j = 0; j < tamanho2; j = j + 1) {
            if (array1[i] == array2[j]) {
                encontrado = 1;
                return;
            }
        }

 // Se encontrado, adicionar ao resultado se ainda não estiver lá
         if(encontrado){
            duplicado = 0;
            for(k = 0; k < indiceResultado; k++){
                 if(resultado[k] == array1[i]){
                    duplicado = 1;
                    return;
                }
            }

             if(!duplicado){
                resultado[indiceResultado++] = array1[i];
            }
        }
    }

 // Ajustar o tamanho do resultado
    *tamanhoResultado = indiceResultado;
}
/** 
   Method_04  
 */ 
void method_04 ( ) 
{ 
 // definir dados
    int tamanho1 = 0, tamanho2 = 0, tamanhoR = 0; 
    int MAX_TAMANHO = 100;
    int array1[MAX_TAMANHO], array2[MAX_TAMANHO], resultado[MAX_TAMANHO];
    FILE *arquivo;
    int x = 0;
    
 // identificar 
    IO_id( "Method_04 - v0.0" ); 
    
 // chamar a função para ler os arquivos 
    lerArray("DADOS1.TXT", &tamanho1, array1);    
    lerArray("DADOS2.TXT", &tamanho2, array2);
    
 // chamar a função para filtrar os dados em comum entre os dois arquivos lidos
    arranjo_filtrar(&tamanhoR, resultado, tamanho1, array1, tamanho2, array2);
    
 // abrir arquivo para gravar os dados em comum
    arquivo = fopen("FILTRADOS.TXT", "wt");
    
 // gravar o tamanho que terá o array
    fprintf(arquivo, "%d\n", tamanhoR);
    
 // gravar os dados que os arquivos tem em comum
    for(x = 0; x < tamanhoR; x = x + 1){
        fprintf(arquivo, "%d ", resultado[x]);
    }
    
 // fechar arquivo
    fclose(arquivo);
    
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
    Função para converter números binários para decimal
*/
int converterBinario(int tamanho, int binario[]) {
 // definir dados
    int decimal = 0, potencia = 1;
    int x = 0;

 // converter um binario para decimal
    for(x = tamanho - 1; x >= 0; x = x - 1){
        decimal = decimal + binario[x] * potencia;
        potencia = potencia * 2;
    }
 // retornar o decimal
    return decimal;
} // end converterBinario
/**
    Função para ler cadeia de caracteres binários
*/
void lerBinarios(char *fileName, int *tamanho, int **array) {
 // definir dados
    FILE *arquivo;
    int caractere, x = 0;

 // abrir arquivo
    arquivo = fopen(fileName, "rt");

 // Contar a quantidade de caracteres válidos (0 ou 1) no arquivo
    *tamanho = 0;
    while((caractere = fgetc(arquivo)) != EOF){
        if(caractere == '0' || caractere == '1'){
            (*tamanho)++;
        }
    }

 // Alocar memória para o arranjo
    *array = (int *)malloc((*tamanho) * sizeof(int));

 // Ler os caracteres válidos e converter para inteiros
    int indice = 0;
    fseek(arquivo, 0, SEEK_SET);
    while((caractere = fgetc(arquivo)) != EOF){
        if(caractere == '0' || caractere == '1'){
            (*array)[indice++] = caractere - '0';
        }
    }
 // fechar o arquivo
    fclose(arquivo);
} // end lerBinarios
/**
    Method_05
*/
void method_05() {
 // definir dados
    char *arquivo = "BINARIOS1.TXT";
    int tamanho = 0;
    int *array, decimal;
    int x = 0, j = 0;

 // identificar
    IO_id( "Method_05 - v0.0" );

 // Ler binários do arquivo e armazenar no arranjo
    lerBinarios(arquivo, &tamanho, &array);

 // Exibir cada conjunto de bits e seu valor decimal
    for (x = 0; x < tamanho; x = x + 4) {
        printf("Conjunto de bits: {");
        for (j = x; j < x + 4; j = j + 1) {
            printf("%d", array[j]);
            if (j < x + 3) {
                printf(" ");
            }
        }
        printf("} -> Valor decimal: %d\n", converterBinario(4, &array[x]));
    }

 // Liberar a memória alocada para o arranjo
    free(array);

 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end method_05 ( )

/**
    Função para ler a matriz do arquivo
*/
void lerMatrizDoArquivo(char *nomeArquivo, int **matriz, int *n){
 // definir dados
    FILE *arquivo;
    int i, j;

 // Abrir o arquivo
    arquivo = fopen(nomeArquivo, "r");

 // Ler a dimensão da matriz
    fscanf(arquivo, "%d", n);

 // Alocar memória para a matriz
    *matriz = (int *)malloc((*n) * (*n) * sizeof(int));

 // Ler os elementos da matriz do arquivo
    for(i = 0; i < *n; i = i + 1){
        for(j = 0; j < *n; j = j + 1){
            fscanf(arquivo, "%d", &(*matriz)[i * (*n) + j]);
        }
    }
 // Fechar o arquivo
    fclose(arquivo);
}
/**
    Função para montar, mostrar e gravar no arquivo MATRIZ2.TXT
*/
void mostrarGravarMatriz(int *matriz, int n){
 // definir dados
    FILE *arquivo;
    int i, j;

 // Abrir o arquivo para gravação
    arquivo = fopen("MATRIZ2.TXT", "wt");

 // Montar, mostrar e gravar a matriz tridiagonal crescente
    for(i = 0; i < n; i = i + 1){
        for(j = 0; j < n; j++){
            if(j <= i + 1 && j >= i - 1){
 // Matriz tridiagonal crescente
                fprintf(arquivo, "%3d ", matriz[i * n + j]);
                printf("%3d ", matriz[i * n + j]);
            } else{
 // Elementos fora da matriz tridiagonal
                fprintf(arquivo, "  0 ");
                printf("  0 ");
            }
        }
        fprintf(arquivo, "\n");
        printf("\n");
    }
 // Fechar o arquivo
    fclose(arquivo);
}
/**
    Method_06
*/
void method_06() {
 // definir dados
    int *matriz;
    int n = 0;
    
 // identificar
    IO_id( "Method_06 - v0.0" );

 // Ler dados para matrizes do arquivo MATRIZ1.TXT
    lerMatrizDoArquivo("MATRIZ1.TXT", &matriz, &n);

 // Montar, mostrar e gravar no arquivo MATRIZ2.TXT
    mostrarGravarMatriz(matriz, n);

 // Liberar a memória alocada para a matriz
    free(matriz);
    
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end method_06 ( )

int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "EXERCICIO-06 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 - exercicio_01" );
 IO_println ( "2 - exercicio_02" );
 IO_println ( "3 - exercicio_03" );
 IO_println ( "4 - exercicio_04" );     
 IO_println ( "5 - exercicio_05" );
 IO_println ( "6 - exercicio_06" );
 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 // testar valor
 switch ( x )
 {
 case 0: method_00 ( ); break;
 case 1: method_01 ( ); break;
 case 2: method_02 ( ); break;
 case 3: method_03 ( ); break;
 case 4: method_04 ( ); break;
 case 5: method_05 ( ); break;
 case 6: method_06 ( ); break;         
 default:
 IO_pause ( IO_concat ( "Valor diferente das opcoes [0,6] (",
 IO_concat ( IO_toString_d ( x ), ")" ) ) );
 } // end switch
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // end main ( )