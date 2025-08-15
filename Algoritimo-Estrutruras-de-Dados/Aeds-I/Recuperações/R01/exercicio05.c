// 821811 - Felipe Rivetti Mizher

/*
  exercicio05 - v0.0. - 25 / 10 / 2023
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

int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "exercicio_05 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 -  exercicio_01" );
 IO_println ( "2 -  exercicio_02" );   
 IO_println ( "3 -  exercicio_03" );
 IO_println ( "4 -  exercicio_04" );
 IO_println ( "5 -  exercicio_05" );
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