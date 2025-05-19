// 821811 - Felipe Rivetti Mizher

/*
 Exemplo0916 - v0.0. - 19 / 10 / 2023
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

/** 
   freadMatrixRows  - Ler tamanho (linhas) da matriz com valores inteiros. 
   @return quantidade de linhas da matriz 
   @param fileName - nome do arquivo 
 */ 
int freadMatrixRows ( chars fileName ) 
{ 
 // definir dados locais 
    int   n = 0; 
    FILE* arquivo = fopen ( fileName, "rt" ); 
    ints  array   = NULL; 
 
 // ler a quantidade de dados 
    IO_fscanf ( arquivo, "%d", &n ); 
 
    if ( n <= 0 ) 
    { 
       IO_println ( "ERRO: Valor invalido." ); 
       n = 0; 
    } // end if 
 
 // retornar dado lido 
    return ( n ); 
} // end freadMatrixRows ( ) 
/** 
   freadMatrixColumns - Ler tamanho (colunas) da matriz com valores inteiros. 
   @return quantidade de colunas da matriz 
   @param fileName     - nome do arquivo 
 */ 
int freadMatrixColumns ( chars fileName ) 
{ 
 // definir dados locais 
    int   n = 0; 
    FILE* arquivo = fopen ( fileName, "rt" ); 
 
 // ler a quantidade de dados 
    IO_fscanf ( arquivo, "%d", &n ); 
    IO_fscanf ( arquivo, "%d", &n ); 
 
    if ( n <= 0 ) 
    { 
       IO_println ( "ERRO: Valor invalido." ); 
       n = 0; 
    } // end if 
 
 // retornar dado lido 
    return ( n ); 
} // end freadMatrixColumns ( )  
/** 
   freadIntMatrix        - Ler arranjo bidimensional com valores inteiros. 
   @param fileName  - nome do arquivo 
   @param rows        - quantidade de valores 
   @param columns  - quantidade de valores 
   @param matrix      - grupo de valores inteiros 
 */ 
void freadIntMatrix ( chars fileName, int rows, int columns, int matrix[ ][columns] ) 
{ 
 // definir dados locais 
    int x = 0; 
    int y = 0; 
    int z = 0; 
    FILE* arquivo = fopen ( fileName, "rt" ); 
 
 // ler a quantidade de dados 
    IO_fscanf ( arquivo, "%d", &x ); 
    IO_fscanf ( arquivo, "%d", &y ); 
 
    if ( rows       <= 0 || rows       > x  || 
         columns <= 0 || columns > y ) 
    { 
       IO_println ( "ERRO: Valor invalido." ); 
    } 
    else 
    { 
     // ler e guardar valores em arranjo 
        x = 0; 
        while ( ! feof ( arquivo ) && x < rows ) 
        { 
            y = 0; 
            while ( ! feof ( arquivo ) && y < columns ) 
            { 
             // ler valor 
                IO_fscanf ( arquivo, "%d", &z ); 
             // guardar valor 
                matrix [ x ][ y ] = z; 
             // passar ao proximo 
                y = y+1; 
            } // end while 
         // passar ao proximo 
            x = x+1; 
        } // end while 
    } // end if 
 
 // fechar arquivo 
    fclose ( arquivo ); 
} // end  freadIntMatrix ( )  
/** 
   Method_04. 
 */ 
void method_04 ( ) 
{ 
 // definir dados 
    int  rows       = 0; 
    int  columns = 0; 
 
 // identificar 
    IO_id ( "Method_04 - v0.0" ); 
 
 // ler dados 
    rows        = freadMatrixRows      ( "MATRIX1.TXT" ); 
    columns = freadMatrixColumns ( "MATRIX1.TXT" ); 
     
    if ( rows <= 0 || columns <= 0 ) 
    { 
       IO_println ( "\nERRO: Valor invalido." ); 
    } 
    else 
    { 
     // definir armazenador 
        int matrix [ rows ][ columns ]; 
 
     // ler dados 
        freadIntMatrix ( "MATRIX1.TXT", rows, columns, matrix ); 
 
     // mostrar dados 
        IO_printf      ( "\n" ); 
        printIntMatrix ( rows, columns, matrix ); 
    } // end if 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_04 ( ) 

/** 
   copyIntMatrix        - Copiar matriz com valores inteiros. 
   @param rows        - quantidade de valores 
   @param columns  - quantidade de valores 
   @param matrix      - grupo de valores inteiros 
 */ 
void copyIntMatrix ( int rows, int columns, 
                                   int matrix2[ ][columns], int matrix1[ ][columns] ) 
{ 
 // definir dados locais 
    int x = 0; 
    int y = 0; 
 
    if ( rows <= 0 || columns <= 0 ) 
    { 
       IO_println ( "ERRO: Valor invalido." ); 
    } 
    else 
    { 
     // copiar valores em matriz 
        for ( x = 0; x < rows; x = x + 1 ) 
        { 
            for ( y = 0; y < columns; y = y + 1 ) 
            { 
             // copiar valor 
                matrix2 [ x ][ y ] = matrix1 [ x ][ y ]; 
            } // end for 
        } // end for 
    } // end if 
} // end copyIntMatrix ( ) 
 
/** 
   Method_05. 
 */ 
void method_05 ( ) 
{ 
 // definir dados 
    int  rows       = 0; 
    int  columns = 0; 
 
 // identificar 
    IO_id ( "Method_05 - v0.0" ); 
 
 // ler dados 
    rows         = freadMatrixRows      ( "MATRIX1.TXT" ); 
    columns  = freadMatrixColumns ( "MATRIX1.TXT" );      
    if ( rows <= 0 || columns <= 0 ) 
    { 
       IO_println ( "\nERRO: Valor invalido." ); 
    } 
    else 
    { 
     // definir armazenadores 
        int matrix [ rows ][ columns ]; 
        int other   [ rows ][ columns ]; 
 
     // ler dados 
        freadIntMatrix ( "MATRIX1.TXT", rows, columns, matrix ); 
 
     // copiar dados 
        copyIntMatrix  ( rows, columns, other, matrix ); 
 
     // mostrar dados 
        IO_printf      ( "\nOriginal\n" ); 
        printIntMatrix ( rows, columns, matrix ); 
 
     // mostrar dados 
        IO_printf      ( "\nCopia\n" ); 
        printIntMatrix ( rows, columns, other   ); 
    } // end if 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_05 ( ) 

/** 
   transposeIntMatrix  - Transpor valores inteiros em matriz. 
   @param rows           - quantidade de valores 
   @param columns     - quantidade de valores 
   @param matrix2       - grupo de valores inteiros (transposto) 
   @param matrix1       - grupo de valores inteiros 
 */ 
void transposeIntMatrix ( int rows, int columns, 
                                            int matrix2[ ][rows] , int matrix1[ ][columns] ) 
{ 
 // definir dados locais 
    int x       = 0; 
    int y       = 0; 

 // percorrer a matriz 
    for ( x = 0; x<rows; x=x+1 ) 
    { 
        for ( y = 0; y<columns; y=y+1 ) 
        { 
            matrix2[ y ][ x ] = matrix1 [ x ][ y ]; 
        } // end for 
    } // end for 
} // end transposeIntMatrix ( ) 
 
/** 
   Method_06. 
 */ 
void method_06 ( ) 
{ 
 // definir dados 
    int matrix1 [ ][2] = { {1, 0} , 
                                     {0, 1} }; 
    int matrix2 [ ][2] = { {0, 0} , 
                                     {0, 0} }; 
    int matrix3 [ ][3] = { {1, 2, 3} , 
                                     {4, 5, 6} }; 
    int matrix4 [ ][3] = { {1, 2, 3} , 
                                     {4, 5, 6} , 
                                     {7, 8, 9} }; 
 
 // identificar 
    IO_id ( "Method_06 - v0.0" ); 
 
 // testar dados 
    IO_println      ( "\nMatrix1 " ); 
    printIntMatrix( 2, 2, matrix1 ); 
 
    transposeIntMatrix ( 2, 2, matrix2, matrix1 ); 
 
    IO_println      ( "\nMatrix2"  ); 
    printIntMatrix( 2, 2, matrix2 ); 
 
    IO_println      ( "\nMatrix3"  ); 
    printIntMatrix( 2, 3, matrix3 ); 
 
    transposeIntMatrix ( 2, 3, matrix4, matrix3 ); 
 
    IO_println      ( "\nMatrix4"  ); 
    printIntMatrix( 3, 2, matrix4 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_06 ( )

/** 
   isIdentity               - Testar se matriz identidade. 
   @return                  - true, se todos os dados forem iguais a zero; 
                                     false, caso contrario 
   @param rows        - quantidade de valores 
   @param columns  - quantidade de valores 
   @param matrix      - grupo de valores inteiros 
 */ 
bool isIdentity (  int rows, int columns, int matrix[ ][columns] ) 
{ 
 // definir dados locais 
    bool result = false; 
    int    x         = 0; 
    int    y         = 0; 
 
// testar condicao de existencia 
    if ( rows <= 0 || columns <= 0 || 
         rows != columns ) 
    { 
       IO_printf ( "\nERRO: Valor invalido.\n" ); 
    } 
    else 
    { 
     // testar valores na matriz 
        x = 0; 
        result = true; 
        while ( x<rows && result ) 
        { 
            y = 0; 
            while ( y<columns && result ) 
            { 
             // testar valor 
                if ( x == y ) 
                { 
                   result = result && ( matrix [ x ][ y ] == 1 ); 
                } 
                else 
                { 
                   result = result && ( matrix [ x ][ y ] == 0 ); 
                } // end if 
             // passar ao proximo 
                y = y + 1; 
            } // end while 
         // passar ao proximo 
            x = x + 1; 
        } // end while 
    } // end if 
 
 // retornar resposta 
    return ( result ); 
} // end isIdentity ( )  
/** 
   Method_07. 
 */ 
void method_07 ( ) 
{ 
 // definir dados 
    int matrix1 [ ][2] = { {0, 0} , 
                                      {0, 0} }; 
    int matrix2 [ ][3] = { {1, 2, 3} , 
                                      {4, 5, 6} }; 
    int matrix3 [ ][2] = { {1, 0} , 
                                      {0, 1} }; 
 
 // identificar 
    IO_id ( "Method_07 - v0.0" ); 
 
 // testar dados 
    IO_println      ( "\nMatrix1"  ); 
    printIntMatrix( 2, 2, matrix1 ); 
    IO_printf        ( "isIdentity (matrix1) = %d", isIdentity (2, 2, matrix1) ); 
 
    IO_println      ( "\nMatrix2"  ); 
    printIntMatrix( 2, 3, matrix2 ); 
    IO_printf        ( "isIdentity (matrix2) = %d", isIdentity (2, 3, matrix2) ); 
 
    IO_println      ( "\nMatrix3"  ); 
    printIntMatrix( 2, 2, matrix3 ); 
    IO_printf        ( "isIdentity (matrix3) = %d", isIdentity (2, 2, matrix3) ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_07 ( ) 

/** 
   isEqual                  - Testar se matrizes iguais. 
   @return                  - true, se todos os dados forem iguais; 
                                     false, caso contrario 
   @param rows        - quantidade de valores 
   @param columns  - quantidade de valores 
   @param matrix1    - grupo de valores inteiros (1) 
   @param matrix2    - grupo de valores inteiros (2) 
 */ 
bool isEqual ( int rows, int columns, 
                         int matrix1[ ][columns], int matrix2[ ][columns] ) 
{ 
 // definir dados locais 
    bool result = true; 
    int    x         = 0; 
    int    y         = 0; 
 
 // mostrar valores na matriz 
    x = 0; 
    while ( x<rows && result ) 
    { 
        y = 0; 
        while ( y<columns && result ) 
        { 
         // testar valor 
            result = result &&  
                        ( matrix1 [ x ][ y ] == matrix2 [ x ][ y ] ); 
         // passar ao proximo 
            y = y + 1; 
        } // end while 
     // passar ao proximo 
        x = x + 1; 
    } // end while 
 
 // retornar resposta 
    return ( result ); 
} // end isEqual ( ) 
/** 
   Method_08. 
 */ 
void method_08 ( ) 
{ 
 // definir dados 
    int matrix1 [ ][2] = { {0, 0} , 
                                     {0, 0} }; 
    int matrix2 [ ][2] = { {1, 2} , 
                                     {3, 4} }; 
    int matrix3 [ ][2] = { {1, 0} , 
                                     {0, 1} }; 
 
 // identificar 
    IO_id ( "Method_08 - v0.0" ); 
    
 // testar dados 
    IO_println      ( "\nMatrix1"  ); 
    printIntMatrix( 2, 2, matrix1 ); 
 
    IO_println      ( "\nMatrix2"  ); 
    printIntMatrix( 2, 2, matrix2 ); 
 
    IO_printf        ( "isEqual (matrix1, matrix2) = %d", 
                               isEqual (2, 2, matrix1, matrix2) ); 
 
    copyIntMatrix ( 2, 2, matrix1, matrix3 ); 
    copyIntMatrix ( 2, 2, matrix2, matrix3 ); 
 
    IO_println      ( "\nMatrix1"  ); 
    printIntMatrix( 2, 2, matrix1 ); 
 
    IO_println      ( "\nMatrix3"  ); 
    printIntMatrix( 2, 2, matrix2 ); 
 
    IO_printf        ( "isEqual (matrix1, matrix2) = %d", 
                               isEqual (2, 2, matrix1, matrix2) ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_08 ( ) 

/** 
   addIntMatrix         - Somar matrizes com inteiros. 
   @param rows       - quantidade de valores 
   @param columns - quantidade de valores 
   @param matrix3   - grupo de valores inteiros resultante 
   @param matrix1   - grupo de valores inteiros (1) 
   @param k              - constante para multiplicar o segundo termo 
   @param matrix2   - grupo de valores inteiros (2) 
 */ 
void addIntMatrix ( int rows, int columns, 
                                 int matrix3[ ][columns], 
                                 int matrix1[ ][columns], int k, int matrix2[ ][columns] ) 
{ 
 // definir dados locais 
    int x = 0; 
    int y = 0; 
 
 
 
 // mostrar valores na matriz 
    for ( x=0; x<rows; x=x+1 ) 
    { 
        for ( y = 0; y < columns; y = y + 1 ) 
        { 
         // somar valores 
            matrix3 [ x ][ y ] = matrix1 [ x ][ y ] + k * matrix2 [ x ][ y ]; 
        } // end for 
    } // end for 
 
} // end addIntMatrix ( ) 
 
/** 
   Method_09. 
 */ 
void method_09 ( ) 
{ 
 // definir dados 
    int matrix1 [ ][2] = { {1, 2}, 
                                     {3, 4} }; 
    int matrix2 [ ][2] = { {1, 0}, 
                                     {0, 1} }; 
    int matrix3 [ ][2] = { {0, 0}, 
                                     {0, 0} }; 
 
 // identificar 
    IO_id ( "Method_09 - v0.0" ); 
 
 // testar dados 
    IO_println      ( "\nMatrix1"  ); 
    printIntMatrix( 2, 2, matrix1 ); 
 
    IO_println      ( "\nMatrix2"  ); 
    printIntMatrix( 2, 2, matrix2 ); 
 
 // soamr matrizes 
    addIntMatrix  ( 2, 2, matrix3, matrix1, (-2), matrix2 ); 
 
    IO_println      ( "\nMatrix3"  ); 
    printIntMatrix( 2, 2, matrix3 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_09 ( ) 

 
/** 
   mulIntMatrix           - Multiplicar matrizes com inteiros. 
   @param rows3       - quantidade de linhas     da matriz (3) 
   @param columns3 - quantidade de colunas da matriz (3) 
   @param matrix3     - grupo de valores inteiros resultante 
   @param rows1       - quantidade de linhas     da matriz (1) 
   @param columns1 - quantidade de colunas da matriz (1) 
   @param matrix1     - grupo de valores inteiros (1) 
   @param rows2       - quantidade de linhas     da matriz (2) 
   @param columns2 - quantidade de colunas da matriz (2) 
   @param matrix2     - grupo de valores inteiros (2) 
 */ 
void mulIntMatrix ( int rows3, int columns3, 
                                 int matrix3[ ][columns3], 
                                 int rows1, int columns1, 
                                 int matrix1[ ][columns1],  
                                 int rows2, int columns2, 
                                 int matrix2[ ][columns2] ) 
{ 
 // definir dados locais 
    int x        = 0; 
    int y        = 0; 
    int z        = 0; 
    int soma = 0; 
 
    if ( rows1 <= 0 || columns1 <= 0 || 
         rows2 <= 0 || columns2 <= 0 || 
         rows3 <= 0 || columns3 <= 0 || 
         columns1  != rows2 || 
         rows1        != rows3 || 
         columns2  != columns3 ) 
    { 
       IO_printf ( "\nERRO: Valor invalido.\n" ); 
    } 
    else 
    { 
      // percorrer valores na matriz resultante 
         for ( x=0; x<rows3; x=x+1 ) 
         { 
             for ( y = 0; y < columns3; y = y + 1 ) 
             { 
              // somar valores 
                 soma = 0; 
                 for ( z = 0; z < columns1; z = z + 1 )  // ou (z < rows2) 
                 { 
                     soma = soma + matrix1 [ x ][ z ] *  matrix2 [ z ][ y ]; 
                 } // end for 
              // guardar a soma 
                 matrix3 [ x ][ y ] = soma; 
             } // end for 
         } // end for 
    } // end if 
 
} // end  mulIntMatrix ( ) 
/** 
   Method_10. 
 */ 
void method_10 ( ) 
{ 
 // identificar 
    IO_id ( "Method_10 - v0.0" ); 
 
 // definir dados 
    int matrix1 [ ][2] = { {1, 2}, 
                                     {3, 4} }; 
    int matrix2 [ ][2] = { {1, 0}, 
                                     {0, 1} }; 
    int matrix3 [ ][2] = { {0, 0}, 
                                     {0, 0} }; 
 
 // identificar 
    IO_id ( "EXEMPLO0910 - Method_09 - v0.0" ); 
 
 // testar produto 
    IO_println      ( "\nMatrix1"  ); 
    printIntMatrix( 2, 2, matrix1 ); 
    IO_println      ( "\nMatrix2"  ); 
    printIntMatrix( 2, 2, matrix2 ); 
 
 // multiplicar matrizes 
    mulIntMatrix  ( 2, 2, matrix3, 2, 2, matrix1, 2, 2, matrix2 ); 
    IO_println      ( "\nMatrix3 = Matrix1 * Matrix2" ); 
    printIntMatrix( 2, 2, matrix3 ); 
 
 // outro teste 
    IO_println      ( "\nMatrix2"  ); 
    printIntMatrix( 2, 2, matrix2 ); 
    IO_println      ( "\nMatrix1"  ); 
    printIntMatrix( 2, 2, matrix1 ); 
 
 // multiplicar matrizes 
    mulIntMatrix  ( 2, 2, matrix3, 2, 2, matrix2, 2, 2, matrix1 ); 
    IO_println      ( "\nMatrix3 = Matrix2 * Matrix1" ); 
    printIntMatrix( 2, 2, matrix3 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_10 ( ) 

void readPositiveDoubleMatrix(int linha, int coluna, double matrix[][coluna]){
 // definir dados
    int i = 0;
    int j = 0;
    
 // verificar se os numeros de linhas e colunas são maiores que 0
    if(linha <= 0 || coluna <= 0){
        printf("%s", "\nValor invalido");
    } else{
 // montar a matrix
        printf("%s", "\nDigite os valores positivos para a matrix: \n");
        for(i = 0; i < linha; i = i + 1){
            for(j = 0; j < coluna; j = j + 1){
                printf("%d, %d: ", i, j);
                scanf("%lf", &matrix[i][j]); getchar();
            }
        }
    }
}
void printDoubleMatrix(int rows, int cols, double matrix[][cols]) {
    printf("\nA matriz resultante é:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}
void method_11(){
 // definir dados
    int linha = 0;
    int coluna = 0;
    
 // identificar
    IO_id ( "Method_11 - v0.0" );
    
 // ler dados
    printf("%s", "Digite o numero de linhas: ");
    scanf("%d", &linha); getchar();
    
    printf("%s", "Digite o numero de colunas: ");
    scanf("%d", &coluna); getchar();
    
 // definir matrix
    double positiveMatrix[linha][coluna];

 // chamar funções para ler e mostrar a matrix
    readPositiveDoubleMatrix(linha, coluna, positiveMatrix);
    printDoubleMatrix(linha, coluna, positiveMatrix);
    
 // encerrar
    IO_pause("Aperte ENTER para encerrar.");
} // end method_11

void fprintDoubleMatrix(chars fileName, int rows, int cols, double matrix[][cols]) {
    FILE* arquivo = fopen(fileName, "wt");
    
    printf("\nA matriz resultante é:\n");
    fprintf(arquivo, "\nA matriz resultante é:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2lf\t", matrix[i][j]);
            fprintf(arquivo, "%.2lf\n", matrix[i][j]);
        }
        printf("\n");
    }
    fclose(arquivo);
}
void method_12(){
 // definir dados
    int linha = 0;
    int coluna = 0;
    
 // identificar
    IO_id("Method_12 - v0.0");    
        
 // ler dados
    printf("%s", "Digite o numero de linhas: ");
    scanf("%d", &linha); getchar();
    
    printf("%s", "Digite o numero de colunas: ");
    scanf("%d", &coluna); getchar();
    
 // definir matrix
    double positiveMatrix[linha][coluna];

 // chamar funções para ler e mostrar a matrix
    readPositiveDoubleMatrix(linha, coluna, positiveMatrix);
    fprintDoubleMatrix("MATRIX_01.TXT",linha, coluna, positiveMatrix);

 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end method_12

void printDiagonalDoubleMatrix(int linha, int coluna, double matrix[][coluna]){
 // definir dados
    int i = 0;
    
 // mostrar somente os numeros da diagonal principal
    if(linha != coluna){
        printf("%s", "A matrix nao e' quadratica");
    } else{
        printf("\n%s\n", "A diagonal principal e': ");
        
        for(i = 0; i < linha ; i = i + 1){
            printf("%.2lf\n", matrix[i][i]);
        }
    }
}
void method_13(){
 // definir dados
    int linha = 0;
    int coluna = 0;
    
 // identificar 
    IO_id("Method_13 - v0.0");
        
 // ler dados
    printf("%s", "Digite o numero de linhas: ");
    scanf("%d", &linha); getchar();
    
    printf("%s", "Digite o numero de colunas: ");
    scanf("%d", &coluna); getchar();
    
 // definir matrix
    double positiveMatrix[linha][coluna];
    
 // chamar funções para ler e mostrar a diagonal principal da matrix
    readPositiveDoubleMatrix(linha, coluna, positiveMatrix);
    printDiagonalDoubleMatrix(linha, coluna, positiveMatrix);
    
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end method_13

void printSDiagonalDoubleMatrix(int linha, int coluna, double matrix[][coluna]){
 // definir dados
    int i = 0;
    
 // mostrar somente os numeros da diagonal secundaria
    if(linha != coluna){
        printf("%s", "A matrix nao e' quadratica");
    } else{
        printf("\n%s\n", "A diagonal principal e': ");
        
        for(i = 0; i < linha ; i = i + 1){
            printf("%.2lf\n", matrix[i][coluna - 1 - i]);
        }
    }
}
void method_14(){
 // definir dados
    int linha = 0;
    int coluna = 0;
    
 // identificar 
    IO_id("Method_14 - v0.0");
        
 // ler dados
    printf("%s", "Digite o numero de linhas: ");
    scanf("%d", &linha); getchar();
    
    printf("%s", "Digite o numero de colunas: ");
    scanf("%d", &coluna); getchar();
    
 // definir matrix
    double positiveMatrix[linha][coluna];
    
 // chamar funções para ler e mostrar a diagonal secundaria da matrix
    readPositiveDoubleMatrix(linha, coluna, positiveMatrix);
    printSDiagonalDoubleMatrix(linha, coluna, positiveMatrix);
    
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end method_14

void printLDTriangleDoubleMatrix(int linha, int coluna, double matrix[][coluna]){
 // definir dados
    int i = 0;
    int j = 0;
    
 // mostrar os valores da diagonal principal e abaixo dela
    if(coluna != linha){
        printf("%s", "A matrix nao e' quadratica");
    } else{
        printf("\n%s\n", "Valores da diagonal principal e abaixo dela:");
        
        for (i = 0; i < linha; i++) {
            for (j = 0; j < coluna; j++) {
                if (j <= i) {
                    printf("%.2lf\t ", matrix[i][j]);
                }
            }
            printf("\n");
        }
    }
} // end printLDTriangleDoubleMatrix 
void method_15(){
 // definir dados
    int linha = 0;
    int coluna = 0;
    
 // identificar 
    IO_id("Method_15 - v0.0");
        
 // ler dados
    printf("%s", "Digite o numero de linhas: ");
    scanf("%d", &linha); getchar();
    
    printf("%s", "Digite o numero de colunas: ");
    scanf("%d", &coluna); getchar();
    
 // definir matrix
    double positiveMatrix[linha][coluna];
    
 // chamar funções para ler e mostrar a diagonal secundaria da matrix
    readPositiveDoubleMatrix(linha, coluna, positiveMatrix);
    printLDTriangleDoubleMatrix(linha, coluna, positiveMatrix);
    
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end method_15

void printLUTriangleDoubleMatrix(int linha, int coluna, double matrix[][coluna]){
 // definir dados
    int i = 0;
    int j = 0;
    
 // mostrar os valores da diagonal principal e abaixo dela
    if(coluna != linha){
        printf("\n%s\n", "A matrix nao e' quadratica");
    } else{
        printf("\n%s\n", "Valores acima da diagonal principal:");
        
        for (i = 0; i < linha; i++) {
            for (j = 0; j < coluna; j++) {
                if (j > i) {
                    printf("%.2lf\t ", matrix[i][j]);
                }
            }
            printf("\n");
        }
    }
} // end printLDTriangleDoubleMatrix 
void method_16(){
 // definir dados
    int linha = 0;
    int coluna = 0;
    
 // identificar 
    IO_id("Method_16 - v0.0");
        
 // ler dados
    printf("%s", "Digite o numero de linhas: ");
    scanf("%d", &linha); getchar();
    
    printf("%s", "Digite o numero de colunas: ");
    scanf("%d", &coluna); getchar();
    
 // definir matrix
    double positiveMatrix[linha][coluna];
    
 // chamar funções para ler e mostrar a diagonal secundaria da matrix
    readPositiveDoubleMatrix(linha, coluna, positiveMatrix);
    printLUTriangleDoubleMatrix(linha, coluna, positiveMatrix);
    
 // encerrar
    IO_pause("Aperte ENTER para encerrar");
} // end method_16

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
 case 11: method_11 ( ); break;
 case 12: method_12 ( ); break;
 case 13: method_13 ( ); break;
 case 14: method_14 ( ); break;
 case 15: method_15 ( ); break;
 case 16: method_16 ( ); break;
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