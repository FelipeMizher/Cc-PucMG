// 821811 - Felipe Rivetti Mizher

#include <stdio.h>
#include "io.h"
#include <math.h>

void method_00 ( void )
{
    // nao faz nada
} // end method_00 ( )

int q01(char *text){
    int result = 1;
    int x = strlen(text)/2, y = 0;
    
    if(text[x] == '-'){
        x = x - 1;
    } // end if
    
    while(y < x && text[y] == text[x + y + 2]){
        y = y + 1;
    } // end while
    
    return (y - x);
} // end q01
void p_01(void){
    
    printf("\n%d\n", q01("teco-teco"));
    
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end p_01

void q02(int x, int n, int a[]){
    if(x < n/2 && a[x] - a[n/2 + x] < 0){
        a[0] = a[x];
        a[x] = a[n/2 + x];
        a[n/2 + x] = a[0];
        a[0] = 0;
        q02(x + 1, n, a);
    }
} // end q02
void p_02(void){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
    
    printf("\n");
    for(int i = 0; i < 8; i = i + 1){
        q02(1, 8, a);
        printf("%d ", a[i]);
    }
    
 // encerrar
    IO_pause("\nAperte ENTER para encerrar");
} // end p_02

void q03(int m, int n, int a[][n]) {
    int v = 0, w = 1, x = 1, y = 0;
    
    while (x < n) {
        y = 0; 
        v = a[x][y];
        while (y < n) {
            a[x][y] = (-v * a[x - w][y] + a[x][y]);
            y = y + 1;
        } // end while
        x = x + 1;
        w = w + 1;
    } // end while
} // end q03 
void p_03(void){
    int a[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
     q03(3, 3, a);

    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end p_03

struct s {
    int nc;
    char *c;
};

void q04(struct s c) {
    int x = c.nc - 1;
    if (x >= 0) {
        c.c = calloc(c.nc + 1, sizeof(char));
        while (x >= 0) {
            if (x % 2 != 0 && x != c.nc - 1) {
                c.c[x] = '-';
            } else if (x % 2 == 0) {
                c.c[x] = '*';
            }
            x = x - 1;
        }
        if (c.nc % 2 == 0) {
            printf("\n%d%s", c.nc, c.c);
        }
        free(c.c);
    }
} // end q04
void p_04(void){

    for (int x = 0; x < 9; x = x + 1) {
        struct s a;
        a.nc = x;
        q04(a);
    }
     printf("\n");
    
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end p_04

void q05(int *m, int *n){
    m[1] = *n;
    
    while(*n > 1){
        *m = *m + 1;
        *n = *n/2;
    }
} // end q04
void p_05(void){
    int *m = malloc(2 * sizeof(int));
    int n = 129;
    m[0] = *m - *m; 
    *(m + 1) = n;
    
    q05(m, &n);
    
    printf("\nm = {%d, %d} n = %d\n", *m, m[1], n);
    
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end p_05

void encontrarMaiores(int tamanho, int arr[]){
 // definir dados
    int maior1 = arr[0];
    int maior2 = arr[1];

 // condição para ter no minimo 2 elementos no array
    if(tamanho < 2){
        printf("%s", "O array deve ter pelo menos dois elementos\n");
        return;
    }
    
 // verificar quais são os dois maiores numeros do array e se esses numeros são diferentes
    for (int i = 2; i <= tamanho; i = i + 1){
        if (arr[i] > maior1) {
            maior2 = maior1;
            maior1 = arr[i];
        } else if (arr[i] > maior2 && arr[i] != maior1){
            maior2 = arr[i];
        }
    }
    
 // exibir os dois maiores numeros do array
    printf("Os dois maiores e diferentes elementos são: %d e %d\n", maior1, maior2);
    
} // end encontrarMaiores
void p_06(){
 // definir dados
    int tamanho = 0;
    
 // loopig para pedir o tamanho até que satisfaça a exigencia do tamanho ser maior que 0
    do{
        printf("\n%s", "Digite o tamanho o arranjo: ");
        scanf("%d", &tamanho); getchar();
    } while(tamanho <= 0);
    
 // declarar array com o tamanho definido pelo usuario
    int array[tamanho];
    
 // preencher todos oselementos do array
    for(int i = 1; i <= tamanho; i = i + 1){
        printf("%d: ", i);
        scanf("%d", &array[i]);
    } getchar();
    
 // chamar função para calcular e mostrar os dois maiores nnumeros do array
    encontrarMaiores(tamanho, array);
    
 // encerrar
    IO_pause("Aperte ENTER para encerrar"); 
} // end p_06

void maioresNaDiagonal(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
 // Encontrar o maior elemento da linha
        int maior = matriz[i][0];
        int indiceMaior = 0;
        for (int j = 1; j < colunas; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                indiceMaior = j;
            }
        }
 // Trocar o maior elemento com a diagonal principal
        int temp = matriz[i][i];
        matriz[i][i] = matriz[i][indiceMaior];
        matriz[i][indiceMaior] = temp;
    }
} // end mairesNaDiagonal
void p_07() {
 // dedinir dados
    int linhas = 0, colunas = 0;

 // pedir dados
    printf("Digite a quantidade de linhas: ");
    scanf("%d", &linhas);

    printf("Digite a quantidade de colunas: ");
    scanf("%d", &colunas);
    
 // definir a matrix com as linhas e colunas digitadas pelo usuario
    int matriz[linhas][colunas];

 // pedir os elementos da matrix
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    } getchar();
    
 // exibir a matrix original
    printf("\nMatriz original:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

 // Chamar o procedimento para colocar os maiores elementos na diagonal principal
    maioresNaDiagonal(linhas, colunas, matriz);

 // exibir a matriz resultante
    printf("\nMatriz resultante:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end p_07

struct Data {
    int dia;
    int mes;
    int ano;
};

int compararDatas(struct Data data1, struct Data data2) {
    return ((data1.ano == data2.ano &&
            data1.mes == data2.mes &&
            data1.dia == data2.dia) || 
           (data1.dia == data2.ano &&
            data1.mes == data2.mes &&
            data1.ano == data2.dia));
}

void p_08() {
    FILE *arquivo1 = fopen("DATAS.TXT", "rt");
    FILE *arquivo2 = fopen("BOLETOS.TXT", "wt");
    float valor;
    struct Data dataAlvo;
    struct Data dataBoleto;

 // pedir a entrada da data ao usuário
    printf("Digite a data no formato dd-mm-aaaa ou aaaa-mm-dd: ");
    scanf("%d%d%d", &dataAlvo.dia, &dataAlvo.mes, &dataAlvo.ano); getchar();
 
    while (fscanf(arquivo1, "%d%d%d%f", &dataBoleto.dia, &dataBoleto.mes, &dataBoleto.ano, &valor) == 4) {
        printf("%.2f\n", valor);
 // Verificar se a data do boleto é igual à data alvo
        if (compararDatas(dataBoleto, dataAlvo)) {
 // Gravar o valor no arquivo de saída
            printf("%.2f\n", valor);
            fprintf(arquivo2, "%.2f\n", valor);
        }
    }

 // Fechar os arquivos
    fclose(arquivo1);
    fclose(arquivo2);

    printf("\nOperação concluída.\n");

 // Encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end p_08

int main(){
    int x = 0;
do
 {    
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 - p_01" );   
 IO_println ( "2 - p_02" );    
 IO_println ( "3 - p_03" );
 IO_println ( "4 - p_04" );
 IO_println ( "5 - p_05" );
 IO_println ( "6 - p_06" );
 IO_println ( "7 - p_07" );
 IO_println ( "8 - p_08" );
 x = IO_readint ( "Entrar com uma opcao: " );
    
switch ( x )
 {
 case 0: method_00 ( ); break;
 case 1: p_01 ( ); break;
 case 2: p_02 ( ); break;
 case 3: p_03 ( ); break;
 case 4: p_04 ( ); break;
 case 5: p_05 ( ); break;
 case 6: p_06 ( ); break;
 case 7: p_07 ( ); break;
 case 8: p_08 ( ); break;
 default:
 IO_pause ( IO_concat ( "Valor diferente das opcoes [0,8] (",
 IO_concat ( IO_toString_d ( x ), ")" ) ) );
 } // end switch
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // end main ( )