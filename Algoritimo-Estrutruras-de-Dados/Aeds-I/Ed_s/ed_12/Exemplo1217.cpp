// 821811 - Felipe Rivetti Mizher

/* 
   Exemplo1217 - v0.0. - 30 / 10 / 2023 
   Author: ______Felipe Rivetti Mizher______ 
 
 */ 
// dependencias 
#include <iostream> // std::cin, std::cout, std:endl 
#include <limits> // std::numeric_limits 
#include <string> // para cadeias de caracteres 
 
// ----------------------------------------------- definicoes globais 
 
void pause ( std::string text ) 
{ 
    std::string dummy; 
    std::cin.clear ( ); 
    std::cout << std::endl << text; 
    std::cin.ignore( ); 
    std::getline(std::cin, dummy); 
    std::cout << std::endl << std::endl; 
} // end pause ( ) 
 
 
// ----------------------------------------------- classes / pacotes 
 
#include "mymatrix.hpp" 
 
using namespace std; 
 
// ----------------------------------------------- metodos 
 
/** 
   Method_00 - nao faz nada. 
 */ 
void method_00 ( ) 
{ 
 // nao faz nada 
} // end method_00 ( )  
    
/** 
   Method_01 - Mostrar certa quantidade de valores. 
 */ 
void method_01 ( ) 
{ 
 // definir dados 
    Matrix <int> int_matrix ( 2, 2, 0 ); 
 
    int_matrix.set ( 0, 0, 1 ); int_matrix.set ( 0, 1, 2 ); 
    int_matrix.set ( 1, 0, 3 ); int_matrix.set ( 1, 1, 4 ); 
 
 // identificar 
    cout << "\nMethod_01 - v0.0\n" << endl; 
 
 // mostrar dados 
    int_matrix.print ( ); 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( )

/** 
   Method_02. 
 */ 
void method_02 ( ) 
{ 
 // definir dados 
    Matrix <int> matrix ( 2, 2, 0 ); 
 
 // identificar 
    cout << endl << "Method_02 - v0.0" << endl; 
 
 // ler dados 
    matrix.read  ( ); 
 
 // mostrar dados 
    matrix.print ( ); 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_02 ( ) 

/** 
   Method_03. 
 */ 
void method_03 ( ) 
{ 
 // definir dados 
    Matrix <int> matrix ( 2, 2, 0 ); 
 
 // identificar 
    cout << endl << "Method_03 - v0.0" << endl; 
 
 // ler dados 
    matrix.read  ( ); 
 
 // mostrar dados 
    matrix.print ( ); 
 
 // gravar  dados 
    matrix.fprint( "MATRIX1.TXT" ); 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_03 ( ) 

/** 
   Method_04. 
 */ 
void method_04 ( ) 
{ 
 // definir dados 
    Matrix <int> matrix ( 1, 1, 0 ); 
 
 // identificar 
    cout <<  endl << "Method_04 - v0.0" << endl; 
 
 // ler dados 
    matrix.fread  ( "MATRIX1.TXT" ); 
 
 // mostrar dados 
    matrix.print ( ); 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_04 ( ) 

/** 
   Method_05. 
 */ 
void method_05 ( ) 
{ 
 // definir dados 
    Matrix <int> int_matrix1 ( 1, 1, 0 ); 
    Matrix <int> int_matrix2 ( 1, 1, 0 ); 
 
 // identificar 
    cout << endl << "Method_05 - v0.0" << endl; 
 
 // ler dados 
    int_matrix1.fread ( "MATRIX1.TXT" ); 
 
 // mostrar dados 
    cout << "\nOriginal\n" << endl; 
    int_matrix1.print ( ); 
 
 // copiar  dados 
    int_matrix2 = int_matrix1; 
 
 // mostrar dados 
    cout << "\nCopia\n" << endl; 
    int_matrix2.print ( ); 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_05 ( ) 

/** 
   Method_06. 
 */ 
void method_06 ( ) 
{ 
 // definir dados 
    Matrix <int> int_matrix ( 2, 2, 0 ); 
 
    int_matrix.set ( 0, 0, 0 );    int_matrix.set ( 0, 1, 0 ); 
    int_matrix.set ( 1, 0, 0 );    int_matrix.set ( 1, 1, 0 ); 
 
 // identificar 
    cout << endl << "Method_06 - v0.0" << endl; 
 
 // mostrar dados 
    int_matrix.print ( ); 
 
 // testar  condicao 
    cout << "Zeros = " << int_matrix.isZeros ( ) << endl; 
 
 // ler dados 
    int_matrix.fread ( "MATRIX1.TXT" ); 
 
 // mostrar dados 
    int_matrix.print ( ); 
 
 // testar  condicao 
    cout << "Zeros = " << int_matrix.isZeros ( ) << endl; 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_06 ( ) 

/** 
   Method_07. 
 */ 
void method_07 ( ) 
{ 
 // definir dados 
    Matrix <int> int_matrix1 ( 1, 1, 0 ); 
    Matrix <int> int_matrix2 ( 1, 1, 0 ); 
 
 // identificar 
    cout << endl << "Method_07 - v0.0" << endl; 
 
 // ler dados 
    int_matrix1.fread ( "MATRIX1.TXT" ); 
 
 // mostrar dados 
    cout << "\nMatrix_1\n"; 
    int_matrix1.print ( ); 
 
 // copiar  dados 
    int_matrix2 = int_matrix1; 
 
 // mostrar dados 
    cout << "\nMatrix_2\n"; 
    int_matrix2.print ( ); 
 
 // testar  condicao 
    cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl; 
 
 // alterar dados 
    int_matrix2.set ( 0, 0, (-1) ); 
 
 // mostrar dados 
    cout << "\nMatrix_1\n"; 
    int_matrix1.print ( ); 
 
 // mostrar dados 
    cout << "\nMatrix_2\n"; 
    int_matrix2.print ( ); 
 
 // testar  condicao 
    cout << "Diferentes = " << (int_matrix1!=int_matrix2) << endl; 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_07 ( ) 

/** 
   Method_08. 
 */ 
void method_08 ( ) 
{ 
 // definir dados 
    Matrix <int> int_matrix1 ( 1, 1, 0 ); 
    Matrix <int> int_matrix2 ( 1, 1, 0 ); 
    Matrix <int> int_matrix3 ( 1, 1, 0 ); 
 
 // identificar 
    cout << endl << "Method_08 - v0.0" << endl; 
 
 // ler dados 
    int_matrix1.fread ( "MATRIX1.TXT" ); 
 
 // mostrar dados 
    cout << "\nMatrix_1\n"; 
    int_matrix1.print ( ); 
 
 // copiar  dados 
    int_matrix2 = int_matrix1; 
 
 // mostrar dados 
    cout << "\nMatrix_2\n"; 
    int_matrix2.print ( ); 
 
 // operar  dados 
    int_matrix3 = int_matrix1 - int_matrix2; 
 
 // mostrar dados 
    cout << "\nMatrix_3\n"; 
    int_matrix3.print ( ); 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_08 ( )

/** 
   Method_09. 
 */ 
void method_09 ( ) 
{ 
 // definir dados 
    Matrix <int> int_matrix1 ( 2, 2, 0 ); 
 
    int_matrix1.set ( 0, 0, 1 ); 
    int_matrix1.set ( 0, 1, 0 ); 
    int_matrix1.set ( 1, 0, 0 ); 
    int_matrix1.set ( 1, 1, 1 ); 
 
    Matrix <int> int_matrix2 ( 1, 1, 0 ); 
    Matrix <int> int_matrix3 ( 1, 1, 0 ); 
 
 // identificar 
    cout << endl << "Method_09 - v0.0" << endl; 
 
 // ler dados 
    int_matrix2.fread ( "MATRIX1.TXT" ); 
 
 // mostrar dados 
    cout << "\nMatrix_1\n"; 
    int_matrix1.print ( ); 
 
 // mostrar dados 
    cout << "\nMatrix_2\n"; 
    int_matrix2.print ( ); 
 
 // operar  dados 
    int_matrix3 = int_matrix1 * int_matrix2; 
 
 // mostrar dados 
    cout << "\nMatrix_3\n"; 
    int_matrix3.print ( ); 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_09 ( ) 

/** 
   Method_10. 
 */ 
void method_10 ( ) 
{ 
 // definir dados 
    Matrix <int> int_matrix ( 3, 3, 0 ); 
    int x = 0; 
    int y = 0; 
 
 // identificar 
    cout <<  endl << "Method_10 - v0.0" << endl; 
 
 // ler dados 
    int_matrix.fread ( "MATRIX1.TXT" ); 
 
 // mostrar dados 
    cout << "\nMatrix\n"; 
    int_matrix.print ( ); 
 
 // operar  dados 
    for ( int x = 0; x < int_matrix.getRows ( ); x=x+1 ) 
    { 
        for ( int y = 0; y < int_matrix.getColumns ( ); y=y+1 ) 
        { 
            int_matrix.set ( x, y, int_matrix.get ( x, y ) * (-1) ); 
        } // end for 
    } // end for 
 
 // mostrar dados 
    cout << "\nMatrix\n"; 
    int_matrix.print ( ); 
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_10 ( )

/** 
   Method_11. 
 */ 
void method_11 ( ) 
{ 
 // definir dados 
    int M = 0; 
    int N = 0; 
 
 // identificar 
    cout <<  endl << "Method_11 - v0.0" << endl; 
 
 // ler dados 
    cout << "Digite o valor de M: ";
    cin >> M;
    cout << "Digite o valor do N: ";
    cin >> N;
    
 // montar matrix com M e N como linhas e colunas e os valores igual a 0
    Matrix<int> int_matrix(M, N, 0);
    
 // chamar a função para gerar numeros aleatorios de acordo com o tanto de elementos da matrix
    int_matrix.randomIntGenerate();
    
 // gravar a matrix com os numeros aleatorios em um arquivo
    int_matrix.fprint("DADOS.TXT");
    
 // mostrar a matrix 
    int_matrix.print ( );

 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_11 ( )

/** 
   Method_12. 
 */ 
void method_12 ( ) 
{ 
 // definir dados
    Matrix<int> matrix1;
    Matrix<int> matrix2;
    int N = 0;
    
 // identificar 
    cout <<  endl << "Method_12 - v0.0" << endl; 
    
 // ler dados
    cout << "Digite o valor para multiplicar: ";
    cin >> N;
    
 // ler a matrix no arquivo e salva em matrix1
    matrix1.fread("DADOS.TXT");
    
 // igualar a matrix2 com os dados da matrix1 multiplicados pela constante digitada pelo usuario
    matrix2 = matrix1.scalar(N);
    
 // Imprimir a matriz original
    cout << "Matrix1:\n";
    matrix1.print();

 // Imprimir a matriz escalada
    cout << "\nMatrix2:\n";
    matrix2.print();

 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_12 ( )

/** 
   Method_13. 
 */ 
void method_13 ( ) 
{ 
 // definir dados
    Matrix<int> matrix1;
    
 // identificar 
    cout <<  endl << "Method_13 - v0.0" << endl; 
    
 // ler a matrix no arquivo e salva em matrix1
    matrix1.fread("DADOS.TXT");
    
 // igualar a matrix2 com os dados da matrix1 multiplicados pela constante digitada pelo usuario
    bool result = matrix1.isIdentify();
    
    if(result == true){
        cout << "E uma matrix identidade\n";
    } else{
        cout << "Nao e uma matrix identidade\n";
    }

 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_13 ( )

/** 
   Method_14. 
 */ 
void method_14 ( ) 
{ 
 // definir dados
    Matrix<int> matrix1;
    Matrix<int> matrix2;
    
 // identificar 
    cout <<  endl << "Method_14 - v0.0" << endl; 
    
 // ler as matrizes nos arquivos e salva em matrix1 e matrix2
    matrix1.fread("DADOS.TXT");
    matrix2.fread("DADOS1.TXT");
    
 // igualar a matrix2 com os dados da matrix1 e verificar se são iguais
    bool result = matrix1.isEqual(matrix2);
    
    if(result == true){
        cout << "\nAs matrizes sao iguais\n";
    } else{
        cout << "\nAs matrizes nao sao iguais\n";
    }

 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_14 ( )

/** 
   Method_15. 
 */ 
void method_15() 
{ 
    // Definir dados
    Matrix<int> matrix1;
    Matrix<int> matrix2;
    
    // Identificar 
    cout <<  endl << "Method_15 - v0.0" << endl; 
    
    // Ler as matrizes nos arquivos e salvar em matrix1 e matrix2
    matrix1.fread("DADOS.TXT");
    matrix2.fread("DADOS1.TXT");
    
    // Imprimir as matrizes lidas
    cout << "Matrix1:\n";
    matrix1.print();
    
    cout << "\nMatrix2:\n";
    matrix2.print();
    
 // Somar as duas matrizes
    Matrix<int> soma = matrix1.add(matrix2);
    
 // Imprimir resultado
    cout << "\nResultado da Soma:\n";
    soma.print();

    // Encerrar 
    pause("Apertar ENTER para continuar"); 
} // end method_15 ( )

/** 
   Method_16. 
 */ 
void method_16() 
{ 
 // Definir dados
    Matrix<int> matrix1;
    int N = 0;
    
 // Identificar 
    cout <<  endl << "Method_16 - v0.0" << endl; 
    
 // pedir dados
    cout << "Digite o valor da constante: ";
    cin >> N;
    
 // ler os dados do arquivo
    matrix1.fread("DADOS.TXT");

 // Imprimir matriz original
    cout << "Original Matrix:\n";
    matrix1.print();

 // Operar duas linhas da matriz
    matrix1.addRows(0, 1, N);

 // Imprimir matriz após a operação
    cout << "\nMatrix depois da operacao:\n";
    matrix1.print();
    
 // Encerrar 
    pause("Apertar ENTER para continuar"); 
} // end method_16 ( )

/** 
   Method_17. 
 */ 
void method_17() 
{ 
 // Definir dados
    Matrix<int> matrix1;
    int N = 0;
    
 // Identificar 
    cout <<  endl << "Method_17 - v0.0" << endl; 
    
 // pedir dados
    cout << "Digite o valor da constante: ";
    cin >> N;
    
 // ler os dados do arquivo
    matrix1.fread("DADOS.TXT");

 // Imprimir matriz original
    cout << "Original Matrix:\n";
    matrix1.print();

 // Operar duas linhas da matriz
    matrix1.subtractRows(0, 1, N);

 // Imprimir matriz após a operação
    cout << "\nMatrix depois da operacao:\n";
    matrix1.print();
    
 // Encerrar 
    pause("Apertar ENTER para continuar"); 
} // end method_17 ( )
 
/* 
  Funcao principal. 
  @return codigo de encerramento 
*/ 
int main ( int argc, char** argv ) 
{ 
 // definir dado 
    int x = 0;   // definir variavel com valor inicial 
 
 // repetir até desejar parar 
    do 
    { 
     // identificar 
        cout << "EXEMPLO1217 - Programa - v0.0\n    " << endl; 
 
     // mostrar opcoes 
        cout << "Opcoes        " << endl; 
        cout << " 0 - parar       " << endl; 
        cout << " 1 - method_01 " << endl; 
        cout << " 2 - method_02 " << endl; 
        cout << " 3 - method_03 " << endl; 
        cout << " 4 - method_04 " << endl; 
        cout << " 5 - method_05 " << endl; 
        cout << " 6 - method_06 " << endl; 
        cout << " 7 - method_07 " << endl; 
        cout << " 8 - method_08 " << endl; 
        cout << " 9 - method_09 " << endl; 
        cout << "10 - method_10 " << endl;
        cout << "11 - method_11 " << endl;
        cout << "12 - method_12 " << endl;
        cout << "13 - method_13 " << endl;
        cout << "14 - method_14 " << endl;
        cout << "15 - method_15 " << endl;
        cout << "16 - method_16 " << endl;
        cout << "17 - method_17 " << endl;
 
     // ler do teclado 
        cout << endl << "Entrar com uma opcao: "; 
        cin  >> x; 
 
 
     // escolher acao 
        switch ( x ) 
        { 
          case 0:   method_00 ( );   break; 
          case 1:   method_01 ( );   break; 
          case 2:   method_02 ( );   break; 
          case 3:   method_03 ( );   break; 
          case 4:   method_04 ( );   break; 
          case 5:   method_05 ( );   break; 
          case 6:   method_06 ( );   break; 
          case 7:   method_07 ( );   break; 
          case 8:   method_08 ( );   break; 
          case 9:   method_09 ( );   break; 
          case 10:  method_10 ( );   break;
          case 11:  method_11 ( );   break;
          case 12:  method_12 ( );   break;
          case 13:  method_13 ( );   break;
          case 14:  method_14 ( );   break;
          case 15:  method_15 ( );   break;
          case 16:  method_16 ( );   break;
          case 17:  method_17 ( );   break;
          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); 
 
 // encerrar 
    pause  ( "Apertar ENTER para terminar" ); 
    return ( 0 ); 
} // end main ( ) 
