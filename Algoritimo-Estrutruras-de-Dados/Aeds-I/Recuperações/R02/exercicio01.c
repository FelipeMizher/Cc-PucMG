// 821811 - Felipe Rivetti Mizher

/*
 exercicio01 - v0.0. - 20 / 11 / 2023
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

int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "EXERCICIO-01 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 - exercicio_01" ); 
 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 // testar valor
 switch ( x )
 {
 case 0: method_00 ( ); break;
 case 1: method_01 ( ); break; 
 default:
 IO_pause ( IO_concat ( "Valor diferente das opcoes [0,1] (",
 IO_concat ( IO_toString_d ( x ), ")" ) ) );
 } // end switch
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // end main ( )