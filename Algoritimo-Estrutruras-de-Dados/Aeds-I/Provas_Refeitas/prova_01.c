#include <stdio.h>
#include "io.h"
#include <math.h>

void method_00 ( void )
{
    // nao faz nada
} // end method_00 ( )

int f1a(int x, int y, int z){
    int w = 0;
    
    while(x < y - 1){
        x = x + 1;
        if(x % 2 == 0 && x % z == 0){
            printf("%d ", x);
            w = w + 1;
        }
    }
    return(w);
} // end f1a
void p_01(void){
    printf("Questao_01\n");
    printf("\n");
    printf(">%d", f1a(12, 45, 3));
    
    IO_pause("Aperte ENTER para encerrar");
} // end p_01

int f2a(char *text, char c, char d, int y){
    for(int x = strlen(text) - 1; x >= 0; x = x - 1){
        if(c == text[x] && y > 0){
            text[x] = d; 
            y = y - 1;
            if(y == 0) x = 0;
        }
    }
    return(y);
} // end f2a
void p_02(void){
    char s[10] = "batata";
    
    printf("Questao_02\n");
    int d = f2a(s, 'a', 'A', 2);
    
    printf("\n%d[%s]\n", d, s);
    printf("\n");
    
    IO_pause("Aperte ENTER para encerrar");
} // end p_02

int f3a(int x){
    int y = 0;
    int z = 0;
    
    while(x > 0){
        z = x % 10;
        if(z % 2 != 0){
            y = y * 10 + x % 10;
        }
        x = x / 10;
    }
    return(y);
} // end f3a
void p_03(void){
    printf("Questao_03\n");
    printf("\n%d\n", f3a(123456));
    printf("\n");
    
    IO_pause("Aperte ENTER para encerrar");
} // end p_03

int f4a(int x){
    int w = 6;
    
    while(x - 1 > 0){
        w = w + 1;
        if(w % 7 == 0){
            if(w % 10 % 2 != 0){
                printf("%d ", w);
            }
            w = w + 13;
        }
        x = x - 1;
    }
    return(w + 1);
} // end f4a
void p_04(void){
    printf("Questao_04\n");
    printf("\n");
    printf(">%d\n", f4a(5));
    
    IO_pause("Aperte ENTER para encerrar");
}

int f5a(int x, int y, int z){
    if(x > 0){
        z = z + y;
        y = y + 2;
        x = x - 1;
        z = f5a(x, y, z);
    }
    return(z);
} // end f5a
void p_05(){
    printf("Questao_05\n");
    printf("\n");
    
    printf("a. f5a(2, 1, 0) = %d - errado\n", f5a(2, 1, 0));
    printf("b. f5a(3, 1, 0) = %d - errado\n", f5a(3, 1, 0));
    printf("c. f5a(4, 1, 0) = %d - errado\n", f5a(4, 1, 0));
    printf("d. f5a(5, 1, 0) = %d - correto\n", f5a(5, 1, 0));
    
    IO_pause("Aperte ENTER para encerrar");
} // end p_05

int norep(char *palavra){
    int x = 0;
    int i = 0;
    int j = i + 1;
    
   while (i < strlen(palavra) - 1) {
        j = i + 1;
        while (j < strlen(palavra)) {
            if (palavra[i] == palavra[j]) {
                return 1; 
            }
            j++;
        }
        i++;
    }
    
    return 0;  
} // end norep 

void p_06(){
    char palavra[80];
    int resultado = 0;
    
    printf("Questao_06\n");
    printf("\n");
    printf("%s", "Digite uma palavra: ");
    scanf("%s", palavra); getchar();
    
    resultado = norep(palavra);
    
    if(resultado == 1){
        printf("A palavra possui letras iguais\n");
    } else{
        printf("A palavra nao possui letras iguais\n");
    }
    
    IO_pause("Aperte ENTER para encerrar");
} // end p_06

void p_07(int n){
    int x = 0;
    int i = 0;
    
    printf("Questoa_07\n");
    printf("\n");
    //printf("%s", "Digite um valor inteiro para 'n': ");
    //scanf("%d", &n); getchar();
    
    for(i = 0; i <= n/2; i = i + 1){
        for(x = 0; x <= i; x = x + 1){
            printf("*");
        }
        printf("\n");
    }
    
      for(i = n/2 - 1; i >= 0; i = i - 1){
        for(x = 0; x <= i; x = x + 1){
            printf("*");
        }
        printf("\n");
    }
    
    IO_pause("Aperte ENTER para encerrar");
} // end p_07

double somar(int n){
    int i = 0;
    int termo = 0;
    int expoente = 0;
    double soma = 0.0;
    
for (i = 0; i < n; i++) {
        termo = i * 4 + 1;  // Calcula o numerador
        expoente = i * 2;   // Calcula o expoente de 3
        
        double valor_termo = (double)termo / pow(3, expoente);
        
        if (i % 2 == 0) {
            soma = soma + valor_termo;
        } else {
            soma = soma - valor_termo;
        }

        printf("(n=%d): %lf\n", i + 1, soma);
    }
    return(soma);
} // end somar

void p_08(void){
 // definir dados
    int n = 0;
    double resultado = 0.0;
    double proximo_impar = 0;
    double diferenca = 0;
 // ler dados
    printf("%s", "Digite um valor inteiro para 'n': ");
    scanf("%d", &n); getchar();
 // calcular a soma
    resultado = somar(n);
 // mostrar o resultado
    if (n % 2 == 1) {
        proximo_impar = somar(n + 2);
        diferenca = proximo_impar - resultado;
        printf("\n%s%lf\n", "Diferença para o próximo ímpar: ", diferenca);
    } else {
        printf("\n%s%lf\n", "Valor da soma: ", resultado);
    }
 // encerrar    
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
 case 7: p_07 (7); break;
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
