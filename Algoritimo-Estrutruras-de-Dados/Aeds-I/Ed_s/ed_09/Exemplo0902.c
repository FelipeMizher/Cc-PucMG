// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0902 - v0.0. - 18 / 10 / 2023
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

/** 
   printIntMatrix        - Mostrar arranjo bidimensional com valores inteiros. 
   @param rows       - quantidade de linhas 
   @param columns - quantidade de colunas 
   @param matrix     - grupo de valores inteiros 
 */ 
void printIntMatrix ( int rows, int columns, int matrix[ ][columns] ) 
{ 
 // definir dado local 
    int x = 0; 
    int y = 0; 
 
 // mostrar valores na matriz 
    for ( x=0; x<rows; x=x+1 ) 
    { 
        for ( y=0; y<columns; y=y+1 ) 
        { 
         // mostrar valor 
            IO_printf ( "%3d\t", matrix [ x ][ y ] ); 
        } // end for 
        IO_printf ( "\n" ); 
    } // end for 
} // end printIntMatrix ( ) 
 
/** 
   Method_01 - Mostrar certa quantidade de valores. 
 */ 
void method_01 ( ) 
{ 
 // definir dado 
    int matrix [ ][3] = {  
                                   {1, 2, 3}, 
                                   {4, 5, 6}, 
                                   {7, 8, 9} 
                                 }; 
 
 // identificar 
    IO_id ( "Method_01 - v0.0" ); 
 
 // executar o metodo auxiliar 
    printIntMatrix ( 3, 3, matrix ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( ) 

/** 
   readIntMatrix        - Ler arranjo bidimensional com valores inteiros. 
   @param rows       - quantidade de linhas 
   @param columns - quantidade de colunas 
   @param matrix     - grupo de valores inteiros 
 */ 
void readIntMatrix ( int rows, int columns, int matrix[ ][columns] ) 
{ 
 // definir dados locais 
    int x = 0; 
    int y = 0; 
    int z = 0; 
    chars text = IO_new_chars ( STR_SIZE ); 
 
 // ler e guardar valores em arranjo 
    for ( x=0; x<rows; x=x+1 ) 
    { 
        for ( y=0; y<columns; y=y+1 ) 
        { 
         // ler valor 
            strcpy ( text, STR_EMPTY ); 
            z = IO_readint ( IO_concat ( 
                                       IO_concat ( IO_concat ( text, IO_toString_d ( x ) ), ", "  ), 
                                       IO_concat ( IO_concat ( text, IO_toString_d ( y ) ), " : " ) ) ); 
         // guardar valor 
            matrix [ x ][ y ] = z; 
        } // end for 
    } // end for 
} // end readIntMatrix ( ) 
/** 
   Method_02. 
 */ 
void method_02 ( ) 
{ 
 // definir dados 
    int n = 2;  // quantidade de valores 
    int matrix [ n ][ n ]; 
 
 // identificar 
    IO_id ( "Method_02 - v0.0" ); 
 
 // ler dados 
    readIntMatrix  ( n, n, matrix ); 
 
 // mostrar dados 
    IO_printf      ( "\n" ); 
    printIntMatrix ( n, n, matrix ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_02 ( ) 

/** 
   fprintIntMatrix        - Gravar arranjo bidimensional com valores inteiros. 
   @param fileName  - nome do arquivo 
   @param rows         - quantidade de linhas 
   @param columns  - quantidade de colunas 
   @param matrix      - grupo de valores inteiros 
 */ 
void fprintIntMatrix ( chars fileName, int rows, int columns, int matrix[ ][columns] ) 
{ 
 // definir dados locais 
    FILE* arquivo = fopen ( fileName, "wt" ); 
    int x = 0; 
    int y = 0; 
 
 // gravar quantidade de dados 
    IO_fprintf ( arquivo, "%d\n", rows       ); 
    IO_fprintf ( arquivo, "%d\n", columns ); 
 // gravar valores no arquivo 
    for ( x=0; x<rows; x=x+1 ) 
    { 
        for ( y=0; y<columns; y=y+1 ) 
        { 
         // gravar valor 
            IO_fprintf ( arquivo, "%d\n", matrix [ x ][ y ] ); 
        } // end for 
    } // end for 
 
 // fechar arquivo 
    fclose ( arquivo ); 
} // end fprintIntMatrix ( ) 
 
/** 
   Method_03. 
 */ 
void method_03 ( ) 
{ 
 // definir dados 
    int rows       = 0; 
    int columns = 0; 
 
 // identificar 
    IO_id ( "Method_03 - v0.0" ); 
 
 // ler dados 
    rows        = IO_readint ( "\nrows       = "      ); 
    columns = IO_readint ( "\ncolumns = " ); 
    IO_printf ( "\n" ); 
 
    if ( rows <= 0 || columns <= 0 ) 
    { 
       IO_println ( "\nERRO: Valor invalido." ); 
    } 
    else 
    { 
     // reservar espaco 
        int matrix [ rows ][ columns ]; 
     // ler dados 
        readIntMatrix  ( rows, columns, matrix ); 
     // mostrar dados 
        IO_printf      ( "\n" ); 
        printIntMatrix ( rows, columns, matrix ); 
     // gravar dados 
        IO_printf      ( "\n" ); 
        fprintIntMatrix( "MATRIX1.TXT", rows, columns, matrix ); 
    } // end if 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_03 ( ) 

int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "EXEMPLO0900 - Programa - v0.0" );
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 - method_01" );
 IO_println ( "2 - method_02" );
 IO_println ( "3 - method_03" );
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