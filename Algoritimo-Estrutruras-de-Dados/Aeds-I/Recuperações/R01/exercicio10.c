// 821811 - Felipe Rivetti Mizher

/*
  exercicio10 - v0.0. - 25 / 10 / 2023
 Author: ____Felipe Rivetti Mizher___
*/
// dependencias
#include "io.h"
#include <math.h>
#include <string.h>
/**
 Method_00 - nao faz nada.
*/
void method_00 ( void )
{
// nao faz nada
} // end method_00 ( )

int somaDivisoresImpares(int numeros){
 // definir dados
    int soma = 0;
    int x = 0;
 
 // looping para verificar os dvisores impares de cada valor do array e somar esses divisores caso exista.
    for(x = 1; x <= numeros; x = x + 1){
        if(numeros % x == 0 && numeros % 2 != 0){
             soma = soma + x;
        }
    }
 // retornar o valor da soma
    return soma;
} // end somaDivisoresImpares
void method_01(){
 // definir dados
    int n = 0;
    int x = 0;
 // identificar
    printf("exercicio_01\n");
    
 // pedir dados
    printf("\n%s", "Digite a quantidade 'n': ");
    scanf("%d", &n); getchar();
    
 // declarar um array para salvar os valores
    int valores[n];
    
 // ler os 'n' valores para o array
    for(x = 1; x <= n; x = x + 1){
        printf("Digite o %d° valor: ", x);
        scanf("%d", &valores[x]); getchar();
    }
    
 // chamar a função para mostrar a soma dos divisores impares de cada numero do array
    printf("\nSomas dos divisores ímpares para cada valor:\n");
    for (x = 1; x <= n; x = x + 1) {
        printf("%d - a soma dos divisores ímpares e': %d\n", valores[x], somaDivisoresImpares(valores[x]));
    }
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end method_01

int verificarPrimo(int numero){
 // definir dados
    int i = 0;
    
 // verificar se o valor do array é menor ou igual a 1, caso seja retornara '0' indicando que não é um numero primo
    if(numero <= 1){
        return 0;
    }
    
 // verificar se um numero é primo ou não
    for (i = 2; i * i <= numero; i = i + 1) {
        if (numero % i == 0) {
            return 0; // retornar '0' para não primos
        }
    }
    return 1; // retornar '1' para primos
} // end verificarPrimo
void method_02(){
 // definir dados
    int n = 0;
    int x = 0;
    int resultado = 0;
    
 // identificar
    printf("exercicio_02\n");
    
 // pedir dados
    printf("\n%s", "Digite a quantidade 'n': ");
    scanf("%d", &n); getchar();
    
 // declarar um array com 'n' termos
    int valores[n];
    
 // looping para ler os 'n' valores do array
    for(x = 1; x <= n; x = x + 1){
        printf("Digite o %d° valor: ", x);
        scanf("%d", &valores[x]); getchar();
    }
    
 // exibir o resultado para saber se cada numero inserido no array é primo ou nao
    printf("\nResultado:\n");
    for (x = 1; x <= n; x = x + 1) {
        resultado = verificarPrimo(valores[x]);
        if(resultado == 1){
            printf("%d - E' um numero primo.\n", valores[x]);
        } else{
            printf("%d - Nao e'um numero primmo.\n", valores[x]);
        }
    }
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end method_02

int identificarSimbolos(char c){
 // verificar cada termo de uma cadeia de caracteres e retornar um numero diferente para cada um destes termos caso sejam de categorias diferentes 
    if(c == '&' || c == '|' || c == '!'){
        return 1;
    } else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){
        return 2;
    } else if(c == '>' || c == '<' || c == '='){
        return 3;
    } else if(c == ' ' || c == '.' || c == ',' || c == ';' || c == ':' || c == '_'){
        return 4;
    } else if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
        return 5;
    } else{
        return 6;
    }
}
void method_03(){
 // definir dados
    char cadeia[80];
    int resultado = 0;
    int x = 0;
    
 // identificar
    printf("exercicio_03\n");
    
 // pedir dados
    printf("\n%s", "Digite uma cadeia de caracteres: ");
    scanf("%s", cadeia); getchar();
     
 // looping para chamar a função para cada termo da cadeia de caracteres e mostrar a classificação para cada termo da cadeia.
    for(x = 0; x < strlen(cadeia); x = x + 1){
        resultado = identificarSimbolos(cadeia[x]);
            
        switch (resultado) {
            case 1:
                printf("%c é um operador lógico\n", cadeia[x]);
                break;
            case 2:
                printf("%c é um operador aritmético\n", cadeia[x]);
                break;
            case 3:
                printf("%c é um operador relacional\n", cadeia[x]);
                break;
            case 4:
                printf("%c é um separador\n", cadeia[x]);
                break;
            case 5:
                printf("%c é uma letra\n", cadeia[x]);
                break;
            default:
                printf("%c é outro símbolo\n", cadeia[x]);
        }
    } 
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end method_03

int identificarSimbolos2(char c){
 // verificar cada termo de uma cadeia de caracteres e retornar um numero diferente para cada um destes termos caso sejam de categorias diferentes
    if(c == '&' || c == '|' || c == '!'){
        return 1;
    } else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){
        return 2;
    } else if(c == '>' || c == '<' || c == '='){
        return 3;
    } else if(c == ' ' || c == '.' || c == ',' || c == ';' || c == ':' || c == '_'){
        return 4;
    } else if(c >= 'A' && c <= 'Z'){
        return 5;
    } else if(c >= 'a' && c <= 'z'){
        return 6;
    } else if(c >= '0' && c <= '9'){
        return 7;
    } else{
        return 8;
    }
}
int contarSimbolos(char *cadeia, int tipo){
 // definir dados
    int x = 0;
    int count = 0;
    
 // looping para ir adicionando um ao contador para cada termo da cadeia
    for (x = 0; x < cadeia[x]; x = x + 1){
        char c = cadeia[x];
        if (identificarSimbolos2(c) == tipo){
            count++;
        }
    }
 // retornar o valor final do contador
    return count;
}
void method_04(){
 // definir dados
    char cadeia[80];
    
 // identificar
    printf("exercicio_03\n");
    
 // pedir dados
    printf("\n%s", "Digite uma cadeia de caracteres: ");
    scanf("%s", cadeia); getchar();
    
 // definir os termos que devem conter os valores para serem mostrados e chamando a função para cade simbolo diferente passando como parametro a propria cadeia e o valor referente ao simbolo da função anterior
    int maiusculas = contarSimbolos(cadeia, 5);
    int minusculas = contarSimbolos(cadeia, 6);
    int digitos = contarSimbolos(cadeia, 7);
    int operadores = contarSimbolos(cadeia, 1) + contarSimbolos(cadeia, 2) + contarSimbolos(cadeia, 3);
    int separadores = contarSimbolos(cadeia, 4);

 // exibir os resultados de acordo com cada simbolo
    printf("\nResultados:\n");
    printf("Letras maiúsculas: %d\n", maiusculas);
    printf("Letras minúsculas: %d\n", minusculas);
    printf("Dígitos: %d\n", digitos);
    printf("Operadores: %d\n", operadores);
    printf("Separadores: %d\n", separadores);
    
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end method_04 

double encontrarMaior(double media1, double media2, double media3) {
 // ver qual a maior media para retornar para o metodo
    if (media1 >= media2 && media1 >= media3) {
        return media1;
    } else if (media2 >= media1 && media2 >= media3) {
        return media2;
    } else {
        return media3;
    }
}
double calcularMedia(int n, double *valor){
// definir dados
    double soma_menor = 0.0;
    double soma_entre = 0.0;
    double soma_maior = 0.0;
    
    double media_menor = 0.0;
    double media_entre = 0.0;
    double media_maior = 0.0;
    
 // somar os valores do array de acordo com a especificação de cada numero
    for(int x = 0; x < n; x = x + 1){
        if(valor[x] < -13.25){
            soma_menor = soma_menor + valor[x];
        } else if(valor[x] >= -13.25 && valor[x] <= 83.75){
            soma_entre = soma_entre + valor[x]; 
        } else{
            soma_maior = soma_maior + valor[x];
        }
    }
    
 // pegar as medias dos valores somados do array e dividir pelo numero 'n' digitado pelo usuario
    media_menor = soma_menor / n;
    media_entre = soma_entre / n;
    media_maior = soma_maior / n;
    
    printf("\n");
    
 // mostrar os valores das medias calculadas
    printf("Média dos valores menores que -13.25: %.2lf\n", media_menor);
    printf("Média dos valores entre -13.25 e 83.75: %.2lf\n", media_entre);
    printf("Média dos valores maiores que 83.75: %.2lf\n", media_maior);
    
 // retornar os valores da media chamando outra função para ver qual a maior media
    return encontrarMaior(media_menor, media_entre, media_maior);
}
void method_05(){
 // definir dados
    int n = 0;
    int x = 0;
    double resultado = 0;
    
 // identificar
    printf("exercicio_02\n");
    
 // pedir dados
    printf("\n%s", "Digite a quantidade 'n': ");
    scanf("%d", &n); getchar();
    
 // declarar um array com 'n' termos
    double valores[n];
    
 // looping para ler os 'n' valores do array
    for(x = 1; x <= n; x = x + 1){
        printf("Digite o %d° valor: ", x);
        scanf("%lf", &valores[x]); getchar();
    }
    
 // chamar função para exibir o resultado
    resultado = calcularMedia(n, valores);
    
    // Exibir a maior média de todas
    printf("A maior média de todas: %.2lf\n", resultado);
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end method_05

double calcularSoma(int inicio, int final){
 // definir dados
    double soma = 0;
    int valor = 0;
    
 // looping para pedir os dados, com a condição para para em '-1', com as condições para ver se os valores estão dentre os limites digitados pelo usuario e fazer a soma dos cubos dos inversos (1/x3) dos ímpares
    do{
        printf("%s", "Digite um valor inteiro(-1 para sair): ");
        scanf("%d", &valor); getchar();
        
        if (valor % 2 != 0 && valor > inicio && valor < final) {
            soma += 1.0 / pow(valor, 3);
        }
    } while(valor != -1);
  
 // retornar o valor da soma
    return soma;
}
void method_06(){
 // definir dados
    int a = 0, b = 0;
    double resultado = 0;
    
 // identificar
    printf("execicio_06\n");
    
 // pedir dados
    printf("\n%s", "Digite o valor para o inicio do limite: \n");
    scanf("%d", &a); getchar();
    
    printf("%s", "Digite o valor para o final do limite: \n");
    scanf("%d", &b); getchar();
    
 // chamar a função passando como parametros 'a' e 'b'
    resultado = calcularSoma(a, b);
    
 // exibir o resultado da soma
    printf("%s%lf\n", "O valor da soma dos cubos dos inversos (1/x3) dos ímpares e': ", resultado);
    
    IO_pause("Aperte ENTER para encerrar");
} // end method_06

void calcularValores(int inicio, int final, int *dentro, int *fora, double *porcentagemAcima, double *porcentagemAbaixo){
 // definir dados
    double valor;
    *dentro = 0;
    *fora = 0;
    int acimaIntervalo = 0;
    int abaixoIntervalo = 0;

 // pedir os valores para o usuario
    printf("\n%s", "Digite valores reais (0 para sair): \n");
    while (1) {
        scanf("%lf", &valor); getchar();
 // se for digitado o '0' encerrar
        if (valor == 0) {
            break;
        }
 // ir acrescentando 1 ao contador para os dados de acordo com as especificaçõs
        if (valor > inicio && valor < final) {
            (*dentro)++;
        } else{
            (*fora)++;
        if (valor > final) {
            acimaIntervalo++;
        } else{
            abaixoIntervalo++;
        }
    }
}
 // calcular a porcentagem para os valores acima e abaixo do intervalo
    if (*fora > 0) {
        *porcentagemAcima = (acimaIntervalo * 100.0) / *fora;
        *porcentagemAbaixo = (abaixoIntervalo * 100.0) / *fora;
    } else {
        *porcentagemAcima = 0.0;
        *porcentagemAbaixo = 0.0;
    }
} // end calcularValres
void method_07(){
 // definir dados
    int a = 0, b = 0;
    int dentroIntervalo, foraIntervalo;
    double porcentagemAcima, porcentagemAbaixo;
 // identificar
    printf("execicio_07\n");
    
 // pedir dados
    printf("\n%s", "Digite o valor para o inicio do limite: ");
    scanf("%d", &a); getchar();
    
    printf("%s", "Digite o valor para o final do limite: ");
    scanf("%d", &b); getchar();
    
// Chamar a função passando como parâmetros 'a', 'b' e as variáveis para armazenar os resultados
    calcularValores(a, b, &dentroIntervalo, &foraIntervalo, &porcentagemAcima, &porcentagemAbaixo);
    
// Exibir os resultados
    printf("\nRESULTADOS:\n");
    printf("Valores dentro do intervalo: %d\n", dentroIntervalo);
    printf("Valores fora do intervalo: %d\n", foraIntervalo);
    printf("Porcentagem acima do intervalo: %.2lf%%\n", porcentagemAcima);
    printf("Porcentagem abaixo do intervalo: %.2lf%%\n", porcentagemAbaixo);
 
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end method_07

int verificarOrdem(double x, double y, double z) {
    if (x <= y && y <= z) {
        return 1; // Ordem crescente
    } else if (x >= y && y >= z) {
        return 2; // Ordem decrescente
    } else {
        return 0; // Nenhuma das ordens
    }
}
void method_08(){
 // definir dados
    double x = 0, y = 0, z = 0;
    int resultado = 0;

 // identificar
    printf("exercicio_08\n");
    
 // pedir dados
    printf("%s", "Digite o valor 'x': ");
    scanf("%lf", &x); getchar();
    
    printf("%s", "Digite o valor 'y': ");
    scanf("%lf", &y); getchar();
    
    printf("%s", "Digite o valor 'z': ");
    scanf("%lf", &z); getchar();
    
 // chamar função passando 'x', 'y' e 'z' como parametros 
    resultado = verificarOrdem(x, y, z);
   
 // pegar o resultado da função para ver se esta em ordem crescente, decrescente ou nenhum dos dois, e mostrar qual o menor eo maior caso nao esteja em nenhuma ordem
    printf("\n%s\n", "RESULTADO");
    if(resultado == 1){
        printf("Os valores estão em ordem crescente.\n");
    } else if(resultado == 2){
        printf("Os valores estão em ordem decrescente.\n");
    } else{
        double menor, maior;

        if(x < y && x < z){
            menor = x;
        } else if(y < z){
            menor = y;
        } else{
            menor = z;
        }
        if(x > y && x > z){
            maior = x;
        } else if(y > z){
            maior = y;
        } else{
            maior = z;
        }

 // mostrar o maior e o menor caso esteja fora de ordem
        printf("\nOs valores não estão em ordem crescente nem decrescente.\n");
        printf("O menor valor é %.2lf\n", menor);
        printf("O maior valor é %.2lf.\n", maior);
    }
    
 // encerrar
    IO_pause("Aperte ENTER para encerra");
} // end method_08

int verificarOrdemC(char x, char y, char z) {
 // verificar em qual ordem esta e mandar um numero para o metodo falando a resposta
    if(strcmp(&x, &y) <= 0 && strcmp(&y, &z) <= 0){
        return 1;
    } else if(strcmp(&x, &y) >= 0 && strcmp(&y, &z) >= 0){
        return 2;
    } else{
        return 0;
    }
}
void method_09(){
 // definir dados
    char x, y, z;
    int resultado = 0;

 // identificar
    printf("exercicio_09\n");
    
 // pedir dados
    printf("%s", "Digite o valor 'x': ");
    scanf("%c", &x); getchar();
    
    printf("%s", "Digite o valor 'y': ");
    scanf("%c", &y); getchar();
    
    printf("%s", "Digite o valor 'z': ");
    scanf("%c", &z); getchar();
    
 // chamar função passando 'x', 'y' e 'z' como parametros 
    resultado = verificarOrdemC(x, y, z);
   
 // pegar o resultado da função para ver se esta em ordem crescente, decrescente ou se nao estao em ordem
    printf("\n%s\n", "RESULTADO");
    if(resultado == 1){
        printf("%s", "Os caracteres estão em ordem crescente.\n");
    } else if(resultado == 2){
        printf("%s", "Os caracteres estão em ordem decrescente.\n");
    } else{
        printf("%s", "Os caracteres nao estao em nenhuma ordem.\n");
    }
    
 // encerrar
    IO_pause("Aperte ENTER para encerra");
} // end method_09

int verificarOrdemS(char *x, char *y, char *z){
    int comparacao_xy = strcmp(x, y);
    int comparacao_yz = strcmp(y, z);
    
     if (comparacao_xy < 0 && comparacao_yz < 0) {
        return 1;
    } else if (comparacao_xy > 0 && comparacao_yz > 0) {
        return 2;
    } else {
        return 0;
    }
}
void method_10(){
 // definir dados
    char x[80], y[80], z[80];
    int resultado = 0;

 // identificar
    printf("exercicio_10\n");
    
 // pedir dados
    printf("%s", "Digite o valor 'x': ");
    scanf("%s", x); getchar();
    
    printf("%s", "Digite o valor 'y': ");
    scanf("%s", y); getchar();
    
    printf("%s", "Digite o valor 'z': ");
    scanf("%s", z); getchar();
    
 // Declarar as variáveis comparacao_xy e comparacao_yz
    int comparacao_xy = strcmp(x, y);
    int comparacao_yz = strcmp(y, z);
    
 // chamar função passando 'x', 'y' e 'z' como parametros 
    resultado = verificarOrdemS(x, y, z);
    
 // exibir o resultado puxando da função o resultado, e caso esteja fora de ordemmostrar qual é maior e qual é menor
    printf("\n%s\n", "RESULTADO:");
    if(resultado == 1){
        printf("%s", "As cadeias estão em ordem alfabética crescente.\n");
    } else if(resultado == 2){
        printf("%s", "As cadeias estão em ordem alfabética decrescente.\n");
    } else{
        char *menor, *maior;

        if (comparacao_xy < 0) {
            menor = x;
            maior = z;
        } else if (comparacao_yz < 0) {
            menor = y;
            maior = z;
        } else {
            menor = x;
            maior = y;
        }

        printf("%s", "Os caracteres não estão em ordem crescente nem decrescente.\n");
        printf("%s%s\n", "O menor caractere é: ", menor);
        printf("%s%s\n", "O maior caractere é: ", maior);
    }    
 // encerrar
    IO_pause("Aperte ENTER para encerra");
} // end method_10

int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "exercicio_10 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 -  exercicio_01" );
 IO_println ( "2 -  exercicio_02" );   
 IO_println ( "3 -  exercicio_03" );
 IO_println ( "4 -  exercicio_04" );
 IO_println ( "5 -  exercicio_05" );
 IO_println ( "6 -  exercicio_06" );
 IO_println ( "7 -  exercicio_07" );
 IO_println ( "8 -  exercicio_08" );
 IO_println ( "9 -  exercicio_09" );
 IO_println ( "10 -  exercicio_10" );
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