#include "SORTFUN.H"
#define _DEBUG_

typedef void (*pF)( int*, int );

void Print( int* ntab, int nSize );     //drukuje tablice
void FillTab( int* ntab, int nSize );   //wypelnia losowo tablice
void SortTime( pF* sortTab, const char** stringTab, int nSize, int SortSize );    // bada czas sortowan

int main( int argc, char* argv[] )
{
    if( argc != 2 )
    {
        printf( "Usage: %s <tab_size>", argv[0] );
        return 1;
    }

    int nSize = atoi( argv[1] );  // wczytanie rozmiaru tablicy

    pF pSortTab[] = { InsertionSort,SelectionSort,BubbleSort,ShakeSort,BinarySort,HeapSort,QuickSort };

    int SortSize = sizeof( pSortTab ) / sizeof( pF );   // ilosc funckji sortujacych w tablicy

    const char* StringTab[] = { "InsertionSort","SelectionSort","BubbleSort","ShakeSort","BinarySort","HeapSort","QuickSort" };
       
    SortTime( pSortTab, StringTab, nSize, SortSize );
     
    return 0;
}

void Print( int* ntab, int nSize )
{
    for( int i = 0; i < nSize; i++ )
    {                        
        printf( "%d ", *ntab++ );       
        if( !( ( i+1 ) % 10) ) printf( "\n" );
    }
    printf( "\n" );
}
void FillTab( int* ntab, int nSize )
{
    srand( (unsigned)time(NULL) );

	for( int i = 0; i < nSize; i++ )	
		*ntab++ = rand() % nSize;			
}
void SortTime( pF* sortTab, const char** stringTab, int nSize, int SortSize )
{  
    int* ptab = (int*)malloc( sizeof(int) * nSize );
    int* pCopyTab = (int*)malloc( sizeof(int) * nSize );
    if( !( ptab && pCopyTab ) )
    {
        printf( "Allocation ERROR" );   
        return;
    }

        memset( ptab, 0, nSize * sizeof(int) );
        memset( pCopyTab, 0, nSize * sizeof(int) );
        FillTab( ptab, nSize );
   
        clock_t start;
        double time;

        for( int i = 0; i < SortSize ; i++ )
        {
          memcpy( pCopyTab, ptab, nSize*sizeof( ptab ) );

          #ifdef _DEBUG_
          printf( "Przed sortowaniem:\n" );
          Print( pCopyTab, MAX );
          #endif

          printf( "Nazwa sortowania:  %s ", *stringTab++ );     
          printf( "Czas sortowania: ");
          start = clock();       
          (*sortTab++)( pCopyTab,nSize );             
          time = clock() - start  ;      
          printf( "%lf\n", time );   

          #ifdef _DEBUG_
          printf( "Po sortowaniu:\n" );
          Print( pCopyTab, MAX );
          #endif
        }
    
     free( ptab );
     free( pCopyTab );   
}