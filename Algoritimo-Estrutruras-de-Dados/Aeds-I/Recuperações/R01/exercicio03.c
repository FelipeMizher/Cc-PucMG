// 821811 - Felipe Rivetti Mizher

/*
  exercicio03 - v0.0. - 25 / 10 / 2023
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

int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "exercicio_03 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 -  exercicio_01" );
 IO_println ( "2 -  exercicio_02" );   
 IO_println ( "3 -  exercicio_03" ); 
 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 // testar valor
 switch ( x )
 {
 case 0: method_00 ( ); break;
 case 1: method_01 ( ); break;
 case 2: method_02 ( ); break;  
 case 3: method_03 ( ); break; 
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