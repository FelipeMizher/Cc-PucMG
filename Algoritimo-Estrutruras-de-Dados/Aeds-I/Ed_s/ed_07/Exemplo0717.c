// 821812 - Felipe Rivetti Mizher

/*
 Exemplo0717 - v0.0. - 04 / 10 / 2023
 Author: ____Felipe Rivetti Mizher___
*/
// dependencias
#include "io.h" // para definicoes proprias
#include <math.h>
/**
 Method_00 - nao faz nada.
*/
void method_00 ( void )
{
    // nao faz nada
} // end method_00 ( )

/**
 writeInts - Gravar em arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void writeInts ( chars fileName, int x )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "wt" );
 int y = 0;
// repetir para a quantidade de dados
 for ( y = 1; y <= x; y = y + 1 )
 {
 // gravar valor
 fprintf ( arquivo, "%d\n", y );
 } // end for
// fechar arquivo (INDISPENSAVEL para gravacao)
 fclose ( arquivo );
} // end writeInts ( )
/**
 Method_01 - Mostrar certa quantidade de valores.
*/
void method_01 ( )
{
// identificar
 IO_id ( "Method_01 - v0.0" );
// executar o metodo auxiliar
 writeInts ( "DADOS1.TXT", 10 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
 readInts - Ler de arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void readInts ( chars fileName )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "rt" );
 int x = 0;
// tentar ler o primeiro
 fscanf ( arquivo, "%d", &x );
// repetir enquanto houver dados
 while ( ! feof ( arquivo ) )
 {
 // mostrar valor
 printf ( "%d\n", x );
 // tentar ler o proximo
 fscanf ( arquivo, "%d", &x );
 } // end while
// fechar arquivo (RECOMENDAVEL para leitura)
 fclose ( arquivo );
} // end readInts ( )
/**
 Method_02.
*/
void method_02 ( )
{
// identificar
 IO_id ( "Method_02 - v0.0" );
// executar o metodo auxiliar
 readInts ( "DADOS1.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
 writeDoubles - Gravar em arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void writeDoubles ( chars fileName, int x )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "wt" );
 int y = 0;
// gravar quantidade de valores
 IO_fprintf ( arquivo, "%d\n", x );
// repetir para a quantidade de dados
 for ( y = 1; y <= x; y = y + 1 )
 {
 // gravar valor
 IO_fprintf ( arquivo, "%lf\n", (0.1*y) );
 } // end for
// fechar arquivo (INDISPENSAVEL para gravacao)
 fclose ( arquivo );
} // end writeDoubles ( )
/**
 Method_03.
*/
void method_03 ( )
{
// identificar
 IO_id ( "Method_03 - v0.0" );
// executar o metodo auxiliar
 writeDoubles ( "DADOS2.TXT", 10 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
 readDoubles - Ler de arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void readDoubles ( chars fileName )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "rt" );
 int x = 0 ;
 int y = 1 ;
 double z = 0.0;
// tentar ler a quantidade de dados
 fscanf ( arquivo, "%d", &x );
// repetir enquanto houver dados e
// quantidade nao tiver sido alcancada
 while ( ! feof ( arquivo ) && y <= x )
 {
 // tentar ler
 fscanf ( arquivo, "%lf", &z );
 // mostrar valor
 printf ( "%2d: %lf\n", y, z );
 // passar ao proximo
 y = y + 1;
 } // end while
// fechar arquivo (RECOMENDAVEL para leitura)
 fclose ( arquivo );
} // end readDoubles ( )
/**
 Method_04.
*/
void method_04 ( )
{
// identificar
 IO_id ( "Method_04 - v0.0" );
// executar o metodo auxiliar
 readDoubles ( "DADOS2.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
 writeText - Gravar em arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void writeText ( chars fileName )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "wt" );
 chars linha = IO_new_chars ( STR_SIZE );
// repetir ate' desejar parar
 IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" );
 do
 {
 // ler do teclado
 strcpy ( linha, IO_readln ( "" ) );
 // gravar valor
 IO_fprintf ( arquivo, "%s\n", linha );
 }
 while ( strcmp ( "PARAR", linha ) != 0 );
// fechar arquivo (INDISPENSAVEL para gravacao)
 fclose ( arquivo );
} // end writeText ( )
/**
 Method_05.
*/
void method_05 ( )
{
// identificar
 IO_id ( "Method_05 - v0.0" );
// executar o metodo auxiliar
 writeText ( "DADOS3.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
 readText - Ler de arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
*/
void readText ( chars fileName )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "rt" );
 chars linha = IO_new_chars ( STR_SIZE );
// tentar ler o primeiro
 strcpy ( linha, IO_freadln ( arquivo ) );
// repetir enquanto houver dados
 while ( ! feof (arquivo) &&
 strcmp ( "PARAR", linha ) != 0 )
 {
 // mostrar valor
 printf ( "%s\n", linha );
 // tentar ler o proximo
 strcpy ( linha, IO_freadln ( arquivo ) );
 } // end while
// fechar arquivo (RECOMENDAVEL para leitura)
 fclose ( arquivo );
} // end readText ( )
/**
 Method_06.
*/
void method_06 ( )
{
// identificar
 IO_id ( "Method_06 - v0.0" );
// executar o metodo auxiliar
 readText ( "DADOS3.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
 copyText - Copiar arquivo texto.
 @param fileOut - nome do arquivo de saida (destino)
 @param fileIn - nome do arquivo de entrada (origem )
*/
void copyText ( chars fileOut, chars fileIn )
{
// definir dados
 FILE* saida = fopen ( fileOut, "wt" );
 FILE* entrada = fopen ( fileIn , "rt" );
 chars linha = IO_new_chars ( STR_SIZE );
 int contador = 0;
// ler da origem
 strcpy ( linha, IO_freadln ( entrada ) );
// repetir enquanto houver dados
 while ( ! feof ( entrada ) )
 {
 // contar linha lida
 contador = contador + 1;
 // gravar no destino,
 // EXCEPCIONALMENTE sem a ultima linha, nesse caso
 if ( strcmp ( "PARAR", linha ) != 0 )
 {
 IO_fprintln ( saida, linha );
 } // end if
 // ler da origem
 strcpy ( linha, IO_freadln ( entrada ) );
 } // end while
// informar total de linhas copiadas
 IO_printf ( "Lines read = %d\n", contador );
// fechar arquivos
 fclose ( saida );
 fclose ( entrada );
} // end copyText ( )
/**
 Method_07.
*/
void method_07 ( )
{
// identificar
 IO_id ( "Method_07 - v0.0" );
// executar o metodo auxiliar
 copyText ( "DADOS4.TXT", "DADOS3.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/**
 appendText - Gravar em arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void appendText ( chars fileName )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "at" );
 chars linha = IO_new_chars ( STR_SIZE );
// repetir ate' desejar parar
 IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" );
 do
 {
 // ler do teclado
 strcpy ( linha, IO_readln ( "" ) );
 // gravar valor
 IO_fprintln ( arquivo, linha );
 }
 while ( strcmp ( "PARAR", linha ) != 0 );
// fechar arquivo (INDISPENSAVEL para gravacao)
 fclose ( arquivo );
} // end appendText ( )
/**
 Method_08.
*/
void method_08 ( )
{
// identificar
 IO_id ( "EXEMPLO0710 - Method_08 - v0.0" );
// executar o metodo auxiliar
 appendText ( "DADOS4.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/**
 readWords - Ler palavras de arquivo.
 @param fileName - nome do arquivo
*/
void readWords ( chars fileName )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "rt" );
 chars linha = IO_new_chars ( STR_SIZE );
// tentar ler a primeira
 strcpy ( linha, IO_fread ( arquivo ) );
// repetir enquanto houver dados
 while ( ! feof (arquivo) &&
 strcmp ( "PARAR", linha ) != 0 )
 {
 // mostrar valor
 printf ( "%s\n", linha );
 // tentar ler o proximo
 strcpy ( linha, IO_fread ( arquivo ) );
 } // end while
// fechar arquivo (RECOMENDAVEL para leitura)
 fclose ( arquivo );
} // end readWords ( )
/**
 Method_09.
*/
void method_09 ( )
{
// identificar
 IO_id ( "Method_09 - v0.0" );
// executar o metodo auxiliar
 readWords ( "DADOS4.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/**
 searchWord - Procurar palavra em arquivo.
 @return true, se encontrar; false, caso contrario
 @param fileName - nome do arquivo
 @param word - palavra a procurar
*/
bool searchWord ( chars fileName, chars word )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "rt" );
 chars linha = IO_new_chars ( STR_SIZE );
// tentar ler a primeira
 strcpy ( linha, IO_fread ( arquivo ) );
// repetir enquanto houver dados
 while ( ! feof (arquivo) &&
 strcmp ( word, linha ) != 0 )
 {
 // tentar ler o proximo
 strcpy ( linha, IO_fread ( arquivo ) );
 } // end while
// fechar arquivo (RECOMENDAVEL para leitura)
 fclose ( arquivo );
 
// retornar resultado
 return ( strcmp ( word, linha ) == 0 );
} // end ifarchdWord ( )
/**
 Method_10.
*/
void method_10 ( )
{
// identificar
 IO_id ( "Method_10 - v0.0" );
// procurar palavra
 IO_printf ( "Procurar (\"%s\") = %d\n", "pqr", searchWord ( "DADOS4.TXT", "pqr" ) );
 IO_printf ( "Procurar (\"%s\") = %d\n", "pqs", searchWord ( "DADOS4.TXT", "pqs" ) );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

void multiplo3(char* fileName, int n){
 // definir dados
    FILE* arquivo = fopen(fileName, "wt");
    int y = 9;
    int x = 0;
 // loop para mostrar e gravar os multiplos de 3 e impares  
    for(y = 9; x < n; y = y + 6){
        printf("%d\n" , y);
        fprintf(arquivo, "%d\n" , y);
        x++;
    }
 // fechar arquivo
    fclose(arquivo);
} // end multiplo3
/**
 Method_11
*/
void method_11(){
 // definir dados
    int n = 0;
 // identificar
    IO_println ( "Methdo_11 - v0.0" );
 // pedir ao usuario um numero para 'n' 
    printf("%s\n", "Digite uma valor inteiro para 'n': ");
    scanf("%d" , &n); getchar();
 // executar metodo auxiliar
    multiplo3("DADOS5.TXT", n);
 // encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_11 ( )

void multiplo7(char* fileName, int n){
 // definir dados
    FILE* arquivo = fopen(fileName, "wt");
    int y = 77;
    int x = 0;
 // loop para mostrar e gravar os multiplos de 7 em ordem decrescente com 21 no final.  
    while (x < n && y >= 21) {
        if (y % 2 != 0) { // Verifica se é ímpar
            printf("%d\n" , y);
            fprintf(arquivo , "%d\n" , y);
            x++;
        }
        y -= 14;
    }
 // fechar arquivo
    fclose(arquivo);
} // end multiplo7
/**
 Method_12
*/
void method_12(){
 // definir dados
    int n = 0;
 // identificar
    IO_println ( "Methdo_12 - v0.0" );
 // pedir ao usuario um numero para 'n' 
    printf("%s\n", "Digite uma valor inteiro para 'n': ");
    scanf("%d" , &n); getchar();
 // executar metodo auxiliar
    multiplo7("DADOS5.TXT", n);
 // encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_12 ( )

void multiplo_7(char* fileName, int n){
 // definir dados
    FILE* arquivo = fopen(fileName, "wt");
    int x = 1;
    int i = 0;
 // loop para mostrar e gravar os numeros multiplicados por 7 em sequência até os 'n' numeros digitado pelo usuario.  
    for(i; i < n; i++) {
        printf("%d " , x);
        fprintf(arquivo , "%d " , x);
        x = x * 7;
    }
 // fechar arquivo
    fclose(arquivo);
} // end multiplo_7
/**
 Method_13
*/
void method_13(){
 // definir dados
    int n = 0;
 // identificar
    IO_println ( "Methdo_13 - v0.0" );
 // pedir ao usuario um numero para 'n' 
    printf("%s\n", "Digite uma valor inteiro para 'n': ");
    scanf("%d" , &n); getchar();
 // executar metodo auxiliar
    multiplo_7("DADOS5.TXT", n);
 // encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_13 ( )

void multiplo_1_7(char* fileName, int n){
 // definir dados
    FILE* arquivo = fopen(fileName, "wt");
    double x = 1.0;
    int i = 0;
 // Encontre o valor inicial de x
    for (i = 1; i < n; i++) {
        x = x * 7;
    }

 // loop para mostrar e gravar os números em ordem decrescente
    for (i = n; i >= 1; i--) {
        printf("(1/%.1lf) = %lf\n", x, 1 / x);
        fprintf(arquivo, "(1/%.1lf) = %lf\n", x, 1 / x);
        x = x / 7;
    }
 // fechar arquivo
    fclose(arquivo);
} // end multiplo_1_7
/**
 Method_14
*/
void method_14(){
 // definir dados
    int n = 0;
 // identificar
    IO_println ( "Methdo_14 - v0.0" );
 // pedir ao usuario um numero para 'n' 
    printf("%s\n", "Digite uma valor inteiro para 'n': ");
    scanf("%d" , &n); getchar();
 // executar metodo auxiliar
    multiplo_1_7("RESULTADO4.TXT", n);
 // encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_14 ( )

void expoente(char* fileName, int n, double x){
 // definir dados
    FILE* arquivo = fopen(fileName, "wt");
    int i = 0;
    double valor = 0.0;
    
    printf("(%.2lf^%d) = %lf\n" , x, 0, 1.0);
 // Encontre o valor inicial de x
    for (i = 2; i <= n; i++) {
        valor = pow(x, i);
        printf("(%.2lf^%d) = %lf\n" , x, i, valor);
        fprintf(arquivo, "(%.2lf^%d) = %lf\n" , x, i, valor);
    }
 // fechar arquivo
    fclose(arquivo);
} // end expoente
/**
 Method_15
*/
void method_15(){
 // definir dados
    int n = 0;
    double x = 0.0;
 // identificar
    IO_println ( "Methdo_15 - v0.0" );
 // pedir ao usuario um numero para 'n' 
    printf("%s\n", "Digite uma valor inteiro para 'n': ");
    scanf("%d" , &n); getchar();
    
    printf("%s\n", "Digite uma valor real para 'x': ");
    scanf("%lf" , &x); getchar();
 // executar metodo auxiliar
    expoente("DADOS5.TXT", n, x);
 // encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_15 ( )

void somar_dados(char* entradaFile, char* saidaFile, int n){
 // definir dados
    FILE* entradaArquivo = fopen(entradaFile, "rt");
    FILE* resultadoArquivo = fopen(saidaFile, "wt");
    double valor;
    double soma = 0;
    int i = 0;
 // mostrar a quantidade de numeros a serem somados e salvar no arquivo
    printf("%s%d\n" , "A quantidade de valores a serem somadas: " , n);
    fprintf(resultadoArquivo, "%s%d\n" , "A quantidade de valores a serem somadas: " , n);
 // loop para somar os 'n' numeros 
    for(i = 0; i < n; i++){
        if (fscanf(entradaArquivo, "%*s = %lf", &valor) == 1) {
            soma += valor;
        }
    }
 // somar mais um para deixar o resultado correto
    soma = soma + 1;
 // mostrar o resultado da soma e salvar
    printf("O resultado total = %lf\n" , soma);
    fprintf(resultadoArquivo, "O resultado total = %lf\n" , soma);
 // fecha os aquivos
    fclose(entradaArquivo);
    fclose(resultadoArquivo);
}
/**
 Method_16
*/
void method_16(){
 // definir dados
    int n = 0;
    double x = 0.0;
 // identificar
    IO_println ( "Methdo_16 - v0.0" );
 // pedir ao usuario um numero para 'n' 
    printf("%s\n", "Digite uma valor inteiro para 'n': ");
    scanf("%d" , &n); getchar();
    
    printf("%s\n", "Digite uma valor real para 'x': ");
    scanf("%lf" , &x); getchar();
 // executar metodo auxiliar
    expoente("DADOS5.TXT", n, x);
    
    somar_dados("DADOS5.TXT", "RESULTADO06.TXT", n);
 // encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_16 ( )

void somar_dados2(char* entradaFile, char* saidaFile, int n){
 // definir dados
    FILE* entradaArquivo = fopen(entradaFile, "rt");
    FILE* resultadoArquivo = fopen(saidaFile, "wt");
    double valor;
    double soma = 0;
    int i = 0;
 // mostrar a quantidade de numeros a serem somados e salvar no arquivo
    printf("%s%d\n" , "A quantidade de valores a serem somadas: " , n);
    fprintf(resultadoArquivo, "%s%d\n" , "A quantidade de valores a serem somadas: " , n);
 // loop para somar os 'n' numeros e mostrar esses no arquivo e para o usuario
    for(i = 0; i < n; i++){
        if (fscanf(entradaArquivo, "%*s = %lf", &valor) == 1) {
            printf("%lf\n", valor);
            fprintf(resultadoArquivo, "%lf\n", valor);
            soma += valor;
        }
    }
 // somar mais um para deixar o resultado correto
    soma = soma + 1;
 // mostrar o resultado da soma e salvar
    printf("O resultado total = %lf\n" , soma);
    fprintf(resultadoArquivo, "O resultado total = %lf\n" , soma);
 // fecha os aquivos
    fclose(entradaArquivo);
    fclose(resultadoArquivo);
} // endo somar_dados2
/**
 Method_17
*/
void method_17(){
 // definir dados
    int n = 0;
    double x = 0.0;
 // identificar
    IO_println ( "Methdo_17 - v0.0" );
 // pedir ao usuario um numero para 'n' 
    printf("%s\n", "Digite uma valor inteiro para 'n': ");
    scanf("%d" , &n); getchar();
 // executar metodo auxiliar
    somar_dados2("RESULTADO4.TXT", "RESULTADO07.TXT", n);
 // encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_17 ( )

int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "EXEMPLO0300 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 - method_01" ); 
 IO_println ( "2 - method_02" );
 IO_println ( "3 - method_03" );
 IO_println ( "4 - method_04" );
 IO_println ( "5 - method_05" );
 IO_println ( "6 - method_06" );
 IO_println ( "7 - method_07" );
 IO_println ( "8 - method_08" );
 IO_println ( "9 - method_09" );
 IO_println ( "10 - method_10" );
 IO_println ( "11 - method_11" );
 IO_println ( "12 - method_12" );
 IO_println ( "13 - method_13" );
 IO_println ( "14 - method_14" );
 IO_println ( "15 - method_15" );
 IO_println ( "16 - method_16" );
 IO_println ( "17 - method_17" );
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
 case 7: method_07 ( ); break;
 case 8: method_08 ( ); break;
 case 9: method_09 ( ); break;
 case 10: method_10 ( ); break;
 case 11: method_11 ( ); break;
 case 12: method_12 ( ); break;
 case 13: method_13 ( ); break;
 case 14: method_14 ( ); break;
 case 15: method_15 ( ); break;
 case 16: method_16 ( ); break;
 case 17: method_17 ( ); break;
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