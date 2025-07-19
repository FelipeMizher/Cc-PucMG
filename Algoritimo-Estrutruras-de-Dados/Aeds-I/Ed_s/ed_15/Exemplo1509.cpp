// 821811 - Felipe Rivetti Mizher

/* 
   Exemplo1509 - v0.0. - 02 / 12 / 2023 
   Author: _______Felipe Rivetti Mizher_________ 
 
 */ 
 
// ----------------------------------------------- preparacao 
 
// dependências 
 
#include <iostream> 
#include "io.h"
 
// ----------------------------------------------- definicoes globais 
 
using namespace std; 

typedef  struct s_intArray{ 
    int length; 
    int *data; 
} intArray; 
 
typedef intArray* ref_intArray; 
 
// ----------------------------------------------- metodos 
 
/** 
   Method_00 - nao faz nada. 
 */ 
void method_00 ( ) 
{ 
 // nao faz nada 
} // end method_00 ( ) 
 
char* str_push_back( char *s ){
 // definir dados
    char c;
    
 // pedir o caractere ao usuario
    std::cout << "Digite o caractere a ser inserido: ";
    std::cin >> c; getchar();

 // Encontrar o final da cadeia
    char *temp = s;
    while (*temp != '\0') {
        temp++;
    }

 // Alocar espaço para o novo caractere e o caractere nulo
    char *new_str = new char[strlen(s) + 2];

 // Copiar a cadeia existente para o novo espaço
    strcpy(new_str, s);

 // Adicionar o novo caractere ao final da cadeia
    new_str[temp - s] = c;
    
 // Adicionar o caractere nulo ao final da cadeia
    new_str[temp - s + 1] = '\0';

    return new_str;
}
/** 
   Method_01 - Adicionar um caractere ao final
 */ 
void method_01 ( ) 
{ 
 // definir dados 
    char *cadeia = new char[50]; 
    cadeia[0] = '\0'; 
    char *cadeiaOriginal = cadeia;
    int d = 0;
    
 // identificar 
    cout << "\nMethod_01 - v0.0\n" << endl;

    cout << "digite o numero de caracteres que deseja inserir: ";
    cin >> d;
    
    std::cout << "Cadeia inicial: \n" << cadeia << std::endl;

 // chamar a função para adicionar um caracteres à cadeia
    for(int x = 0; x < d; x = x + 1){
        cadeia = str_push_back(cadeia);
        std::cout << "Cadeia atualizada: \n" << cadeia << std::endl;
    }

 // Liberar a memória alocada para a cadeia
    delete[] cadeiaOriginal; 
 
 // encerrar 
    printf("\nAperte ENTER para encerrar");
    std::cin.ignore();  
} // end method_01 ( ) 

char* str_pop_back(char *s) {
 // Verificar se a cadeia está vazia
    if (s == nullptr || *s == '\0') {
        return s;
    }

 // Encontrar o final da cadeia
    char *temp = s;
    while (*temp != '\0') {
        temp++;
    }

 // Remover o último caractere, se houver mais de um caractere na cadeia
    if (temp != s) {
        temp--;
        *temp = '\0';
    }

    return s;
}
/** 
   Method_02 - Remover um caractere do final
 */ 
void method_02 ( ) 
{ 
 // definir dados 
    char cadeia[] = "Casa";
    std::cout << "Cadeia inicial: " << cadeia << std::endl; getchar();

 // identificar 
    cout << "\nMethod_02 - v0.0\n" << endl;
    
 // mostrar cadeia inicial
 std::cout << "Cadeia inicial: " << cadeia << std::endl;
    
 // Remover o último caractere
    str_pop_back(cadeia);
    std::cout << "Cadeia atualizada: " << cadeia << std::endl; 
    
 // encerrar 
    printf("\nAperte ENTER para encerrar\n");
    std::cin.ignore();  
} // end method_02 ( )

char* str_push_front( char *s ){
 // definir dados
    char c;
    
 // pedir o caractere ao usuario
    std::cout << "Digite o caractere a ser inserido: ";
    std::cin >> c; getchar();
    
 // Calcular o novo comprimento da cadeia
    size_t new_length = strlen(s) + 2;

 // Alocar espaço para o novo caractere e o caractere nulo
    char *new_str = new char[new_length];

 // Adicionar o novo caractere ao inicio da cadeia
    new_str[0] = c;
    
 // Copiar a cadeia existente para o novo espaço
    strcpy(new_str + 1, s);

    return new_str;
}
/** 
   Method_03 - Adicionar um caractere ao inicio
 */ 
void method_03 ( ) 
{ 
 // Definir dados  
    char cadeia[50] = "Casa";
    char *cadeiaOriginal = strdup(cadeia);
    int d = 0;
    
 // Identificar 
    cout << "\nMethod_03 - v0.0\n" << endl;

 // pedir dados
    cout << "Digite o numero de caracteres que deseja inserir: ";
    cin >> d;
    
// mostrar a cadeia inicial
    std::cout << "Cadeia inicial: \n" << cadeia << std::endl;

 // Chamar a função para adicionar caracteres à cadeia
    for(int x = 0; x < d; x = x + 1){
        char *nova_cadeia = str_push_front(cadeia);
        strcpy(cadeia, nova_cadeia);
        delete[] nova_cadeia;
        
        std::cout << "Cadeia atualizada: \n" << cadeia << std::endl;
    }

 // Liberar a memória alocada para a cadeia
    free(cadeiaOriginal); 

 // Encerrar 
    printf("\nAperte ENTER para encerrar");
    std::cin.ignore();  
} // end method_03 ( )

char* str_pop_front(char *s) {
 // Verificar se a cadeia está vazia
    if (s == nullptr || *s == '\0') {
        return s;
    }
    
 // Mover o ponteiro para o segundo caractere
    char *temp = s + 1;

 // Mover os caracteres restantes para a frente
    while (*temp != '\0') {
        *s = *temp;
        s++;
        temp++;
    }

 // Definir o último caractere como nulo
    *s = '\0';

    return s;
}
/** 
   Method_04 - Remover um caractere do inicio
 */ 
void method_04 ( ) 
{ 
 // definir dados 
    char cadeia[] = "Casa";
    std::cout << "Cadeia inicial: " << cadeia << std::endl; getchar();

 // identificar 
    cout << "\nMethod_04 - v0.0\n" << endl;
    
 // mostrar cadeia inicial
 std::cout << "Cadeia inicial: " << cadeia << std::endl;
    
 // Remover o último caractere
    str_pop_front(cadeia);
    std::cout << "Cadeia atualizada: " << cadeia << std::endl; 
    
 // encerrar 
    printf("\nAperte ENTER para encerrar\n");
    std::cin.ignore();  
} // end method_04 ( )

char* str_chr(char *s, char c) {
 // Percorrer a cadeia
    while (*s != '\0') {
 // Verificar se o caractere atual é o procurado
        if (*s == c) {
 // Se encontrado, retornar o ponteiro para o caractere na cadeia
            return s;
        }
        s++;
    }

 // Se o caractere não for encontrado, retornar nullptr
    return nullptr;
}
/** 
   Method_05 - Procurar caractere na cadeia
 */ 
void method_05 ( ) 
{ 
 // definir dados 
    char cadeia[] = "Casa";
    char c;
    char *resultado;
    
 // identificar 
    cout << "\nMethod_05 - v0.0\n" << endl;
    
 // pedir dados
    cout << "digite o caractere a ser procurado: ";
    cin >> c; getchar();
    
 // mostrar cadeia inicial
 std::cout << "Cadeia: " << cadeia << std::endl; 
    
    resultado = str_chr(cadeia, c);
    
 // exibir o resultado 
    if(resultado != nullptr){
        cout << "O caractere '"<< c << "' foi encontrado na cadeia: "<< cadeia << endl;
    } else{
        cout << "O caractere '"<< c << "' nao foi encontrado na cadeia: "<< cadeia << endl;
    }

 // encerrar 
    printf("\nAperte ENTER para encerrar\n");
    std::cin.ignore();  
} // end method_05 ( )

char* str_tok(char *s, char delimiter){
 // definir dados
    static char* lastToken = nullptr;

 // verificar se a string esta vazia ou não 
    if (s != nullptr) {
        lastToken = s;
    } else if (lastToken == nullptr || *lastToken == '\0') {
        return nullptr;
    }

 // Encontrar o início do próximo token, ignorando delimitadores consecutivos
    while (*lastToken != '\0' && *lastToken == delimiter) {
        ++lastToken;
    }

 // Se chegamos ao final da string, não há mais tokens
    if (*lastToken == '\0') {
        lastToken = nullptr;
        return nullptr;
    }

    char* tokenEnd = lastToken;
    while (*tokenEnd != '\0' && *tokenEnd != delimiter) {
        ++tokenEnd;
    }

    if (*tokenEnd == '\0') {
        lastToken = nullptr;
        return lastToken;
    }

    *tokenEnd = '\0';
    lastToken = tokenEnd + 1;

    return lastToken;
}
/** 
   Method_06 - Separar caracteres
 */ 
void method_06 ( ) 
{ 
 // definir dados 
    char cadeia[] = "Guarda - chuva";
    char delimiter = '-';
    char* resultado;
    
 // identificar 
    std::cout << "\nMethod_06 - v0.0\n" << std::endl;

 // exibir o resultado
    resultado = str_tok(cadeia, delimiter);
    while (resultado != nullptr) {
        std::cout << "Token encontrado: " << resultado << std::endl;
        resultado = str_tok(nullptr, delimiter);
    } getchar();  
    
 // encerrar 
    printf("\nAperte ENTER para encerrar\n");
    std::cin.ignore();  
} // end method_06 ( )

int intArray_cmp(ref_intArray p, ref_intArray q){
 // definir dados
    int x = 0;
    
 // verificar se os arrays são nulos ou não 
    if(p == nullptr || q == nullptr){
        return 0; // retornr 0, pois se os arrays forem nulos são iguais
    }
    
 // comparar o tamanho dos arquivos
    if(p -> length != q -> length){
        return p -> length - q -> length; // retornar a diferença
    }
    
 // comparar os elementos dos arrays
    for(x = 0; x < p -> length; x = x + 1){
        if(p -> data[x] != q -> data[x]){
            return p->data[x] - q->data[x]; // retorna a diferença de cada elemento
        }
    }
    
    return 0; // retornar 0 quando forem diferentes
} // end intArray_cmp
/** 
   Method_07 - Comparar arrays
 */ 
void method_07 ( ) 
{ 
 // definir dados
    int data1[] = {1, 2, 3, 4, 5};
    int data2[] = {1, 2, 3, 4, 5};
    int result = 0;

    intArray array1 = {5, data1};
    intArray array2 = {5, data2};
    
 // identificar 
    std::cout << "\nMethod_07 - v0.0\n" << std::endl;
    
 // chamar a função para comparar os arrays
    result = intArray_cmp(&array1, &array2);
        
 // exibir o resultado
    if(result == 0){
        std::cout << "Os arrays são iguais." << std::endl;
    } else if(result < 0){
        std::cout << "O segundo array e' maior." << std::endl;
    } else{
        std::cout << "O primeiro array e' maior." << std::endl;
    } getchar();
    
 // encerrar 
    printf("\nAperte ENTER para encerrar\n");
    std::cin.ignore();  
} // end method_07 ( )

ref_intArray intArray_cat(ref_intArray p, ref_intArray q){
 // definir dados
    int i = 0;
    
 // verifica se os ponteiros são nulos
    if (p == nullptr || q == nullptr) {
        return nullptr;
    }

 // calcula o comprimento do novo array
    int newLength = p->length + q->length;

 // aloca espaço para o novo array
    intArray *resultArray = new intArray;
    resultArray->length = newLength;
    resultArray->data = new int[newLength];

 // copia os elementos do primeiro array para o novo array
    for (i = 0; i < p->length; ++i) {
        resultArray->data[i] = p->data[i];
    }

 // copia os elementos do segundo array para o novo array
    for (i = 0; i < q->length; ++i) {
        resultArray->data[p->length + i] = q->data[i];
    }

    return resultArray; // retorna o novo array
}
/** 
   Method_08 - Juntar arrays
 */ 
void method_08 ( ) 
{ 
 // definir dados
    int data1[] = {1, 2, 3};
    int data2[] = {4, 5, 6};
    ref_intArray resultArray;
    
    intArray array1 = {3, data1};
    intArray array2 = {3, data2};
    
 // identificar 
    std::cout << "\nMethod_08 - v0.0\n" << std::endl;
    
 // chamar a função para juntar os arrays
    resultArray = intArray_cat(&array1, &array2);
    
 // exibir o resultado
    if (resultArray != nullptr) {
        std::cout << "Arrays concatenados: ";
        for (int i = 0; i < resultArray->length; ++i) {
            std::cout << resultArray->data[i] << " ";
        }
        std::cout << std::endl;

 // liberar memória alocada para o novo array
        delete[] resultArray->data;
        delete resultArray;
    } else {
 // caso a junção falhe
        std::cout << "Falha ao juntar os arrays." << std::endl;
    } getchar();
    
 // encerrar 
    printf("\nAperte ENTER para encerrar\n");
    std::cin.ignore();  
} // end method_08 ( )

int intArray_seek(ref_intArray a, int n){
 // definir dados
    int i = 0;
    
 // verificar se o array esta vazio
    if(a == nullptr){
        return 0;
    }
    
 // comparar o valor a ser procurado com os dados do array
    for(i = 0; i < a -> length; i = i + 1){
        if(a -> data[i] == n){
            return 1;
        }
    }
    
    return 0;
}
/** 
   Method_09 - Procurar valor no array
 */ 
void method_09 ( ) 
{ 
 // definir dados
    int data1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result = 0;
    int n = 0;
    
    intArray array1 = {10, data1};
    
 // identificar 
    std::cout << "\nMethod_09 - v0.0\n" << std::endl;
    
 // pedir dados
    cout << "Digite qual valor deseja encontrar: ";
    cin >> n;
    
 // chamar a função para juntar os arrays
    result = intArray_seek(&array1, n);
    
 // exibir resultado
    if(result == 1){
        cout << "\nValor: '" << n << "' encontrado no array.\n";
    } else{
        cout << "\nValor: '" << n << "' nao encontrado no array.\n";
    } getchar();
    
 // encerrar 
    printf("\nAperte ENTER para encerrar\n");
    std::cin.ignore();  
} // end method_09 ( )

// ----------------------------------------------- acao principal 
 
/* 
  Funcao principal. 
  @return codigo de encerramento 
*/ 
int main ( int argc, char** argv ) 
{ 
 // definir dado 
    int x = 0;  // definir variavel com valor inicial 
 
 // repetir até desejar parar 
    do 
    { 
     // identificar 
        cout << "EXEMPLO1509 - Programa - v0.0\n " << endl; 
 
     // mostrar opcoes 
        cout << "Opcoes    " << endl; 
        cout << " 0 - parar    " << endl; 
        cout << " 1 - adicionar um caractere ao final " << endl;
        cout << " 2 - remover um caractere do final " << endl;
        cout << " 3 - adicionar um caractere ao inicio " << endl;
        cout << " 4 - remover um caractere do inicio " << endl;
        cout << " 5 - procurar caractere na cadeia " << endl;
        cout << " 6 - separar caracteres " << endl;
        cout << " 7 - comparar arranjos " << endl;
        cout << " 8 - juntar arranjos " << endl;
        cout << " 9 - procurar valor no array " << endl;
 
     // ler do teclado 
        cout << endl << "Entrar com uma opcao: "; 
        cin  >> x; 
 
     // escolher acao 
        switch ( x ) 
        { 
          case 0: 
            method_00 ( ); 
           break; 
          case 1: 
            method_01 ( ); 
           break; 
          case 2:
            method_02 ( );
           break;
          case 3:
            method_03 ( );
           break;
          case 4:
            method_04 ( );
           break;
          case 5:
            method_05 ( );
           break;
          case 6:
            method_06 ( );
           break;
          case 7:
            method_07 ( );
           break;
          case 8:
            method_08 ( );
           break;
          case 9:
            method_09 ( );
           break;
          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); getchar();
 
 // encerrar 
    printf("\nAperte ENTER para encerrar\n");
    getchar();
    return ( 0 ); 
} // end main ( ) 
 
/* 
---------------------------------------------- documentacao complementar 

---------------------------------------------- notas / observacoes / comentarios 

---------------------------------------------- previsao de testes 

---------------------------------------------- historico 

Versao           Data                           Modificacao
0.1              01/12                          esboco 

---------------------------------------------- testes 
Versao          Teste
0.1             0.1 ( OK )                    identificacao do programa
*/ 