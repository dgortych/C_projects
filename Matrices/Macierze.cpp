#include "Matrix.h"
#define _DEBUG_
void ReadData( FILE* fin, double** pMatrix, double* b, int nDim );
void PrintVector( double* pVec, int nSize ); // funkcja do drukowania wektora


int main( int argc, char* argv[] )
{
    if( argc!=2 )
    {
        printf( "Usage: %s <plik_we>", argv[0] );
        return 1;
    }

    FILE* f = fopen( argv[1], "r" );     // otwiera plik do odczytu 
    if( !f )
    {
       printf( "ERROR: %s opening failure", argv[1] );
        return 2;
    }

    int nSize = 0;
    fscanf( f, "%d", &nSize );          // wczytanie rozmiaru macierzy

    double** pMatrix = NULL;

    CreateMatrix( &pMatrix, nSize );
    if( !pMatrix )
    {
        perror( "CreateMatrix ERROR" );
            return 3;
    }
   
    double* vector = (double*)malloc( nSize * sizeof(double) );     //kreowanie wektora
    if( !vector )
    {
        perror( "vector create ERROR" );
        return 4;
    }

    memset( vector, 0, nSize * sizeof(double) );
    
    ReadData( f,pMatrix,vector,nSize );
    fclose(f);

#ifdef _DEBUG_
    printf( "Macierz:\n" );
    PrintMatrix( pMatrix, nSize );
    printf( "Wektor wyrazow wolnych :\n" );
    PrintVector( vector, nSize );
#endif

   double d = Det( pMatrix, nSize );
   if( fabs( d ) <= 1e-15 ) 
   {
       perror( "Macierz jest osobliwa!!!" );
       return 5;
   }
  
   double** OpMatrix = NULL;             //macierz do odwrócenia
   CreateMatrix( &OpMatrix, nSize );
   if( !OpMatrix )
   {
       perror( "Create OpMatrix ERROR" );
       return 6;
   }
   
   InverseMatrix( OpMatrix, pMatrix, nSize, d );

#ifdef _DEBUG_
   printf( "Wyznacznik : %lf\n", d );
   printf( "Macierz odwrocona:\n" );
   PrintMatrix ( OpMatrix, nSize );
#endif
  
   double* RESvector = (double*)malloc( nSize * sizeof(double) );  //kreowanie wektora wynikowego
   if( !RESvector )
   {
       perror( "RESvector create ERROR" );
       return 7;
   }
   memset( RESvector, 0, nSize * sizeof(double) );

   LayoutEqu( OpMatrix, vector, RESvector, nSize );


   printf( "Wynik: \n");
   PrintVector( RESvector, nSize );

   
   DeleteMatrix( &OpMatrix, nSize );
   DeleteMatrix( &pMatrix, nSize );
   free( vector );
   free( RESvector );

   return 0;
}

void ReadData( FILE* fin, double** pMatrix, double* b, int nDim )
{
    for( int i = 0; i < nDim; i++)
    {
        double* p = *pMatrix++;        

        for( int j = 0; j < nDim; j++ )
            fscanf( fin, "%lf", p++ );
       
        fscanf( fin, "%lf", b++ );        
    }   
} 
void PrintVector( double* pVec, int nSize )
{
    for(int i = 0; i < nSize; i++)
    {
        printf( "%lf\n", *pVec++ );       
    }
}





