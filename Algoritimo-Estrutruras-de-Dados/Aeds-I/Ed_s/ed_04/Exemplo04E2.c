// 821812 - Felipe Rivetti Mizher

/*
 Exemplo04E2 - v0.0. - 11 / 09 / 2023
 Author: ____Felipe Rivetti Mizher___
*/
// dependencias
#include "io.h" // para definicoes proprias

/**
 Funcao para determinar se valor inteiro e' positivo.
 @return true, se positivo; false, caso contrario
 @param x - valor a ser testado
*/
bool positive ( int x )
{
// definir dado local
 bool result = false;
// testar a condicao
 if ( x > 0 )
 {
 result = true;
 } // end if
 return ( result );
} // end positive ( )

/**
 Funcao para determinar se valor inteiro pertence a intervalo aberto.
 @return true, se pertencer; false, caso contrario
 @param x - valor a ser testado
 @param inferior - limite inferior do intervalo
 @param superior - limite superior do intervalo
*/
bool belongsTo ( int x, int inferior, int superior )
{
// definir dado local
 bool result = false;
// testar a condicao
 if ( inferior < x && x < superior )
 {
 result = true;
 } // end if
 return ( result );
} // end belongsTo ( )

/**
 Funcao para determinar se valor inteiro e' par.
 @return true, se par; false, caso contrario
 @param x - valor a ser testado
*/
bool even ( int x )
{
// definir dado local
 bool result = false;
// testar a condicao ( resto inteiro (%) da divisao por 2 igual a zero )
 if ( x % 2 == 0 )
 {
 result = true;
 } // end if
 return ( result );
} // end even ( )

/**
 Funcao para determinar se caractere e' letra minuscula.
 @return true, se par; false, caso contrario
 @param x - valor a ser testado
*/
bool isLowerCase ( char x )
{
// definir dado local
 bool result = false;
// testar a condicao
 if ( 'a' <= x && x <= 'z' )
 {
 result = true;
 } // end if
 return ( result );
} // end isLowerCase ( )

/**
 Funcao para determinar se caractere e' digito.
 @return true, se par; false, caso contrario
 @param x - valor a ser testado
*/
bool isDigit ( char x )
{
// definir dado local
 bool result = false;
// testar a condicao
 if ( '0' <= x && x <= '9' )
 {
 result = true;
 } // end if
 return ( result );
} // end isDigit ( )

/**
 Funcao para determinar se caractere e' digito.
 @return true, se par; false, caso contrario
 @param x - valor a ser testado
*/
bool isADigit ( char x )
{
 return ( '0' <= x && x <= '9' );
} // end isADigit ( )
/**

/**
 Funcao para concatenar 'a cadeia de caracteres mais um digito.
 @return cadeia de caracteres acrescida de mais um digito
 @param digits - cadeia de caracteres
 @param digit - simbolo a ser acrescentado 'a cadeia de caracteres
*/
chars concatADigit ( chars string, char digit )
{
// testar a existencia da cadeia de caracteres
 if ( string )
 { 
 string [ strlen(string) + 1 ] = '\0'; // avançar o terminador
 string [ strlen(string) ] = digit; // guardar o digito
 } // end if
 return ( string );
} // end concatADigit ( )

int letraMaiuscula(char c) {
    return c >= 'A' && c <= 'Z';
}

/**
 Method_00 - nao faz nada.
*/
void method_00 ( void )
{
// nao faz nada
} // end method_00 ( )
/**

/**
 Method_01 - Repeticao para ler certa quantidade de valores.
*/
void method_01 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
// identificar
 IO_id ( "Method 01 - v0.0" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
 printf ( "\nquantidade = %d\n", quantidade );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat ( 
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 printf ( "\nvalor = %d\n", valor );
 // passar ao proximo valor
 controle = controle + 1;
 } // end while
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
 Method_02 - Ler valores e contar positivos.
*/
void method_02 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
// identificar
 IO_id ( "Method02 - v0.0" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo
 if ( positive ( valor ) )
 {
 contador = contador + 1;
 } // end if
 // passar ao proximo valor
 controle = controle + 1;
 } // end while
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
 Method_03 - Ler valores e contar positivos menores que 100.
*/
void method_03 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
// identificar
 IO_id ( "Method_03 - v0.0" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo
 if ( belongsTo ( valor, 0, 100 ) )
 {
 contador = contador + 1;
 } // end if
 // passar ao proximo valor
 controle = controle + 1;
 } // end while
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos menores que 100 = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
 Method_04 - Ler valores e contar positivos menores que 100 e pares.
*/
void method_04 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
// identificar
 IO_id ( "Method_04 - v0.0" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo menor que 100 e par
 if ( belongsTo ( valor, 0, 100 ) && even ( valor ) )
 {
 contador = contador + 1;
 } // end if
 // passar ao proximo valor
 controle = controle + 1;
 } // end while
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
 Method05 - Ler valores e contar positivos menores que 100 e pares (alternativo).
*/
void method_05 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
 bool ok = false;
// identificar
 IO_id ( "EXEMPLO0405 - Method05 - v0.0" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo menor que 100 e par
 ok = belongsTo ( valor, 0, 100 );
 ok = ok && even ( valor );
 if ( ok )
 {
 contador = contador + 1;
 } // end if
 // passar ao proximo valor
 controle = controle + 1;
 } // end while
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
 Method_06 - Ler palavra e contar letras minusculas.
*/
void method_06 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 int contador = 0;
// identificar
 IO_id ( "Method06 - v0.0" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar se caractere e' letra minuscula
 if ( isLowerCase ( simbolo ) )
 {
 contador = contador + 1;
 } // end if
 } // end for
// mostrar a quantidade de minusculas
 IO_printf ( "%s%d\n", "Minusculas = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
 Method_07 - Ler palavra, contar e mostrar letras minusculas.
*/
void method_07 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 int contador = 0;
// identificar
 IO_id ( "Method07 - v0.0" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar se caractere e' letra minuscula
 if ( isLowerCase ( simbolo ) )
 {
 // mostrar
 IO_printf ( "%c ", simbolo );
 // contar
 contador = contador + 1;
 } // end if
 } // end for
// mostrar a quantidade de minusculas
 IO_printf ( "\n%s%d\n", "Minusculas = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/**
 Method_08 - Ler palavra, contar e mostrar letras minusculas (alternativo).
*/
void method_08 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 int contador = 0;
 chars minusculas = IO_new_chars ( STR_SIZE );
 strcpy ( minusculas, STR_EMPTY ); // vazio
// identificar
 IO_id ( "Method08 - v0.0" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar as letras minusculas de uma palavra
 if ( isLowerCase ( simbolo ) )
 {
 // concatenar simbolo encontrado
 minusculas = IO_concat ( minusculas, IO_toString_c ( simbolo ) );
 // contar
 contador = contador + 1;
 } // end if
 } // end for
// mostrar a quantidade de minusculas
 IO_printf ( "\n%s%d [%s]\n", "Minusculas = ", contador, minusculas );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/**
 Method_09 - Ler palavra e contar os algarismos.
*/
void method_09 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 int contador = 0;
// identificar
 IO_id ( "Method09 - v0.0" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com caracteres: " );
// determinar a quantidade de simbolos
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar os algarismos em uma cadeia de caracteres
 if ( isDigit ( simbolo ) )
 {
 // mostrar
 IO_printf ( "%c ", simbolo );
 // contar
 contador = contador + 1;
 } // end if
 } // end for
// mostrar a quantidade de digitos
 IO_printf ( "\n%s%d\n", "Algarismos = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/**
 Method_10.
*/
void method_10 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 chars digitos = IO_new_chars ( STR_SIZE );
 strcpy ( digitos, STR_EMPTY ); // vazio
// identificar
 IO_id ( "Method_10 - v0.0" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar os algarismos em uma cadeia de caracteres
 if ( isADigit ( simbolo ) )
 {
 // concatenar simbolo encontrado
 digitos = concatADigit ( digitos, simbolo );
 } // end if
 } // end for
// mostrar a quantidade de digitos
 IO_printf ( "\n%s%d [%s]\n", "Algarismos = ", (int)strlen( digitos ), digitos );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

/**
 Method_11. 
*/
void method_11() {
    float a, b;
    int n, x;
    int count_I = 0;
    int count_O = 0;

// Identificação
    printf("Method 11 - v0.0\n");

// Ler do teclado
    printf("Digite o valor de A: \n");
    scanf("%f", &a);
    getchar();

    printf("Digite o valor de B: \n");
    scanf("%f", &b);
    getchar();

    printf("Digite o valor de N: \n");
    scanf("%d", &n);
    getchar();

// Repetir para a quantidade de vezes informada
    float numero;
    for (x = 0; x < n; x++) {
        printf("Digite o %dº valor: ", x + 1);
        scanf("%f", &numero);
        getchar();
// Verificar se o valor está dentro ou fora do intervalo (a-b)
        if (numero >= a && numero <= b) {
            count_I++;
            printf("%.2f está dentro do intervalo\n", numero);
        } else {
            count_O++;
            printf("%.2f está fora do intervalo\n", numero);
        }
    }
// Mostrar o total de valores dentro e fora do intervalo
    printf("\nTotal de valores dentro do intervalo (%.2f:%.2f): %d\n", a, b, count_I);
    printf("Total de valores fora do intervalo (%.2f:%.2f): %d\n", a, b, count_O);

    // Encerrar
    printf("Apertar ENTER para continuar\n");
    getchar();
} // end method_11 ( )

/**
 Method_12. 
*/
void method_12() {
    char C [1000];
    int count = 0;

// Identificação
    printf("Method 12 - v0.0\n");

// Ler do teclado
    printf("%s\n" , "Digite uma cadeia de caracteres:");

// Repetir para a quantidade de vezes informada
if (fgets(C, sizeof(C), stdin) != NULL) {

        for (int i = 0; C[i] != '\0'; i++) {
            char c = C[i];
            
            if (letraMaiuscula(c) && c > 'K') {
                count++;
            }
        }

        printf("\nQuantidade de letras maiúsculas maiores que 'K': %d\n", count);
    }
    // Encerrar
    printf("Apertar ENTER para continuar\n");
    getchar();
} // end method_12 ( )

// função para contar caracteres maiores que K.
void countCaracteres(char *C){
    int count = 0;

        for (int i = 0; C[i] != '\0'; i++) {
            char c = C[i];
            
            if (letraMaiuscula(c) && c > 'K') {
                count++;
            }     
    }
    printf("\nQuantidade de letras maiúsculas maiores que 'K': %d\n\n", count);
}
/**
 Method_13. 
*/
void method_13() {
    char C [80];
    int count = 0;

// Identificação
    printf("Method 13 - v0.0\n");

// Ler do teclado
    printf("%s\n" , "Digite uma cadeia de caracteres:");
    fgets(C, sizeof(C), stdin);
// Chamar função para mostrar quantos caracteres são maiores que K.
    countCaracteres(C);
    // Encerrar
    printf("Apertar ENTER para continuar\n");
    getchar();
} // end method_13 ( )

// função para mostrar caracteres maiores que K.
void showCaracteres(char *C){
    for (int i = 0; C[i] != '\0'; i++) {
        char c = C[i];
            
        if (letraMaiuscula(c) && c > 'K') {
            printf("\n%c\n" , C[i]);
        }     
    }

}
/**
 Method_14. 
*/
void method_14() {
    char C [80];
    int count = 0;

// Identificação
    printf("Method 14 - v0.0\n");

// Ler do teclado
    printf("%s\n" , "Digite uma cadeia de caracteres:");
    fgets(C, sizeof(C), stdin);
// Chamar função para mostrar oscaracteres maiores que K.
    showCaracteres(C);
    // Encerrar
    printf("Apertar ENTER para continuar\n");
    getchar();
} // end method_14 ( )

// função para contar caracteres maiores que 'K' e 'k'.
void countCaracteres2(char *C){
    int count = 0;

        for (int i = 0; C[i] != '\0'; i++) {
            char c = C[i];
            
            if (c > 'K' && c <= 'Z' ||
                c > 'k' && c <= 'z') {
                count++;
            }     
    }
    printf("\nQuantidade de letras maiores que 'K' e 'k' = %d\n\n", count);
}
/**
 Method_15. 
*/
void method_15() {
    char C [80];

// Identificação
    printf("Method 15 - v0.0\n");

// Ler do teclado
    printf("%s\n" , "Digite uma cadeia de caracteres:");
    fgets(C, sizeof(C), stdin);
// Chamar função para mostrar quantos caracteres são maiores que 'K' e 'k'.
    countCaracteres2(C);
    // Encerrar
    printf("Apertar ENTER para continuar\n");
    getchar();
} // end method_15 ( )

// função para mostrar caracteres maiores que K.
void showCaracteres2(char *C){
    for (int i = 0; C[i] != '\0'; i++) {
        char c = C[i];
            
        if (c > 'K' && c <= 'Z' ||
            c > 'k' && c <= 'z') {
            printf("\n%c\n" , C[i]);
        }  
    }

}
/**
 Method_16. 
*/
void method_16() {
    char C [80];

// Identificação
    printf("Method 16 - v0.0\n");

// Ler do teclado
    printf("%s\n" , "Digite uma cadeia de caracteres:");
    fgets(C, sizeof(C), stdin);
// Chamar função para mostrar oscaracteres maiores que K.
    showCaracteres2(C);
    // Encerrar
    printf("Apertar ENTER para continuar\n");
    getchar();
} // end method_16 ( )

// função para contar caracteres impares.
void countCaracteresI(char *C){
    int count = 0;

        for (int i = 0; C[i] != '\0'; i++) {
            char c = C[i];
            
            if (c >= '1' && c <= '9' && (c - '0') % 2 != 0) {
                count++;
            }     
    }
    printf("\nQuantidade de algarismos impares = %d\n\n", count);
}
/**
 Method_17. 
*/
void method_17() {
    char C [80];

// Identificação
    printf("Method 17 - v0.0\n");

// Ler do teclado
    printf("%s\n" , "Digite uma cadeia de caracteres:");
    fgets(C, sizeof(C), stdin);
// Chamar função para mostrar quantos caracteres impares existem.
    countCaracteresI(C);
    // Encerrar
    printf("Apertar ENTER para continuar\n");
    getchar();
} // end method_17 ( )

// função para mostrar simbolos nao alfanumericos.
void showCaracteres3(char *C){
    for (int i = 0; C[i] != '\0'; i++) {
        char c = C[i];
            
        if (!(c >= 'A' && c <= 'z' &&
              c >= '0' && c <= '9')) {
            printf("\n%c\n" , C[i]);
        }  
    }

}
/**
 Method_18. 
*/
void method_18() {
    char C [80];

// Identificação
    printf("Method 18 - v0.0\n");

// Ler do teclado
    printf("%s\n" , "Digite uma cadeia de caracteres:");
    fgets(C, sizeof(C), stdin);
// Chamar função para mostrar os simbolos nao alfanumericos.
    showCaracteres3(C);
    // Encerrar
    printf("Apertar ENTER para continuar\n");
    getchar();
} // end method_18 ( )

// função para mostrar algarismos alfanumericos.
void showCaracteresA(char *C){
    for (int i = 0; C[i] != '\0'; i++) {
        char c = C[i];
            
        if (c >= 'A' && c <= 'z' ||
            c >= '0' && c <= '9'){
            printf("\n%c\n" , C[i]);
        }
    }
}
/**
 Method_19. 
*/
void method_19() {
    char C [80];

// Identificação
    printf("Method 19 - v0.0\n");

// Ler do teclado
    printf("%s\n" , "Digite uma cadeia de caracteres:");
    fgets(C, sizeof(C), stdin);
// Chamar função para mostrar os simbolos nao alfanumericos.
    showCaracteresA(C);
    // Encerrar
    printf("Apertar ENTER para continuar\n");
    getchar();
} // end method_19 ( )

// função para mostrar algarismos alfanumericos.
void showAndCountCaracteres(char *C){
    int count = 0;
    
    for (int i = 0; C[i] != '\0'; i++) {
        char c = C[i];
            
        if (c >= 'A' && c <= 'z' ||
            c >= '0' && c <= '9'){
            printf("\n%c\n" , C[i]);
            count++;
        }
    }
    printf("%s%d\n" , "Contagem de algarisomos: " , count);
}
/**
 Method_20. 
*/
void method_20() {
    char C [80];

// Identificação
    printf("Method 20 - v0.0\n");

// Ler do teclado
    printf("%s\n" , "Digite uma cadeia de caracteres:");
    fgets(C, sizeof(C), stdin);
// Chamar função para mostrar os simbolos nao alfanumericos.
    showAndCountCaracteres(C);
    // Encerrar
    printf("Apertar ENTER para continuar\n");
    getchar();
} // end method_20 ( )

// função para mostrar algarismos alfanumericos.
void showAndCountCaracteres2(char *C){
    int count = 0;
    int countE = 0;
    
    for (int i = 0; C[i] != '\0'; i++) {
        char c = C[i];
            
        if (c >= 'A' && c <= 'z' ||
            c >= '0' && c <= '9'){
            printf("\n%c\n" , C[i]);
            count++;
        } else if(c == ' '){
            countE++;
        }
    }
    printf("%s%d\n" , "Contagem de algarisomos: " , count);
    printf("%s%d\n" , "Contagem de espaços: " , countE);
}
/**
 Method_21. 
*/
void method_21() {
    char C [80];

// Identificação
    printf("Method 21 - v0.0\n");

// Ler do teclado
    printf("%s\n" , "Digite uma cadeia de caracteres:");
    fgets(C, sizeof(C), stdin);
// Chamar função para mostrar os simbolos nao alfanumericos.
    showAndCountCaracteres2(C);
    // Encerrar
    printf("Apertar ENTER para continuar\n");
    getchar();
} // end method_21 ( )

// Função para contar a quantidade de dígitos em uma cadeia de caracteres
int contarDigitos(char *cadeia) {
    int contador = 0;
    for (int i = 0; cadeia[i] != '\0'; i++) {
        if (cadeia[i] >= '0' && cadeia[i] <= '9') {
            contador++;
        }
    }
    return contador;
}
    
// função para mostrar algarismos alfanumericos.
int compararCadeia(char *C1 , char *C2){
     int digitosCadeia1 = contarDigitos(C1);
     int digitosCadeia2 = contarDigitos(C2);

    if (digitosCadeia1 > digitosCadeia2) {
        return 1;
    } else if (digitosCadeia2 > digitosCadeia1) {
        return 2;
    } else {
        return 0;
    }
}
/**
 Method_22. 
*/
void method_22() {
    char C1 [80];
    char C2 [80];
    int resultado;
// Identificação
    printf("Method 22 - v0.0\n");

// Ler do teclado
    printf("%s\n" , "Digite a primeira cadeia de caracteres:");
    fgets(C1, sizeof(C1), stdin);
    
    printf("%s\n" , "Digite a segunda cadeia de caracteres:");
    fgets(C2, sizeof(C2), stdin);
// Chamar função para mostrar os simbolos nao alfanumericos.
    resultado = compararCadeia(C1, C2);
    
    if (resultado == 1) {
        printf("\nA primeira cadeia tem mais dígitos.\n");
    } else if (resultado == 2) {
        printf("\nA segunda cadeia tem mais dígitos.\n");
    } else {
        printf("\nAs cadeias têm a mesma quantidade de dígitos.\n");
    }
    printf("\n");
    // Encerrar
    printf("Apertar ENTER para continuar\n");
    getchar();
} // end method_22 ( )

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
 IO_println ( "18 - method_18" );
 IO_println ( "19 - method_19" );
 IO_println ( "20 - method_20" );     
 IO_println ( "21 - method_21" );
 IO_println ( "22 - method_22" );
 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 printf ( "\nx = %d", x );
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
 case 18: method_18 ( ); break;
 case 19: method_19 ( ); break;
 case 20: method_20 ( ); break;
 case 21: method_21 ( ); break;
 case 22: method_22 ( ); break;
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

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) -1
b.) 0
c.) 5 e { 1, 2, 3, 4, 5 }
---------------------------------------------- historico
Versao Data Modificacao
 0.1 11/09 esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. (OK) identificacao de programa
*/