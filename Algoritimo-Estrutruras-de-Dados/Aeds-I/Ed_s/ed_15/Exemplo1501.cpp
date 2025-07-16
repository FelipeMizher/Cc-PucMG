// 821811 - Felipe Rivetti Mizher

/* 
   Exemplo1501 - v0.0. - 01 / 12 / 2023 
   Author: _______Felipe Rivetti Mizher_________ 
 
 */ 
 
// ----------------------------------------------- preparacao 
 
// dependências 
 
#include <iostream> 
#include "io.h"
 
// ----------------------------------------------- definicoes globais 
 
using namespace std; 
 
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
        cout << "EXEMPLO1501 - Programa - v0.0\n " << endl; 
 
     // mostrar opcoes 
        cout << "Opcoes    " << endl; 
        cout << " 0 - parar    " << endl; 
        cout << " 1 - adicionar um caractere ao final " << endl; 
 
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
          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); 
 
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