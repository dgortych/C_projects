#include "SORTFUN.H"

void Update( int* ntab, int l, int p );
void Sort( int* ntab, int l, int p );

void InsertionSort( int* ntab, int nSize )
{
	for( int i = 1; i < nSize; i++ )
    {
        int x = ntab[i];
        int j = i - 1;
        while( ( j >= 0 ) && ( ntab[j] > x ) )
            ntab[j + 1] = ntab[j--];
        ntab[j + 1] = x;
    }
}
void SelectionSort( int* ntab, int nSize )
{
    for( int i = 0; i < nSize - 1; i++ )
    {
        int min = ntab[i];
        int ix = i;
        for( int j = i + 1; j < nSize ; j++ )
            if( ntab[j]<min )
            {
                min = ntab[j];
                ix = j;
            }
        ntab[ix] = ntab[i];
        ntab[i] = min;
    }
}
void BubbleSort( int* ntab, int nSize )
{
    for( int i = 0; i < nSize; i++ )
    {
        for( int j = nSize - 1; j > i; j-- )
            if( ntab[j] < ntab[j - 1] )
            {
                int tmp = ntab[j];
                ntab[j] = ntab[j - 1];
                ntab[j - 1] = tmp;
            }       
    }
}
void ShakeSort( int* ntab, int nSize )  
{
    int l = 1;
    int p = nSize - 1 ;
    int k = nSize - 1 ;
    do
    {
        for( int j = p; j >= l; j-- )        
            if( ntab[j - 1] > ntab[j] )
            {
                int tmp = ntab[j - 1];
                ntab[j - 1] = ntab[j];
                ntab[j] = tmp;
                k = j;
            }
            l = k + 1;
        for( int j = l; j <= p; j++ )      
            if( ntab[j - 1] > ntab[j] )
            {
                int tmp = ntab[j - 1];
                ntab[j - 1] = ntab[j];
                ntab[j] = tmp;
                k = j;
            }     
            p = k - 1;        
    } while( l <= p );
}
void BinarySort( int* ntab,int nSize )
{
    for( int i = 1; i < nSize;i++ )
    {
        int tmp = ntab[i];
        int l = 0;
        int p = i - 1;
        while( l <= p )
        {
            int m = ( l + p ) / 2;
            if( tmp < ntab[m] )  p = m - 1;
            else l = m + 1;
        }
        for( int j = i - 1; j >= l; j-- )
            ntab[j + 1] = ntab[j];
        ntab[l] = tmp;
    }
}
void HeapSort( int* ntab, int nSize ) 
{    
    for( int j = (nSize / 2) ; j >= 0 ; j-- )              
     Update( ntab, j , nSize - 1 );
    
    for( int j = nSize - 1; j > 0 ; j-- )   
    {
        int tmp = ntab[0];
        ntab[0] = ntab[j];
        ntab[j] = tmp;        
         Update( ntab, 0 , j - 1  );
    }
}
void Update( int* ntab,int l,int p )
 {
     if( l >= p ) return;
     int i = l;
     int j = 2 * i + 1 ;
     int tmp = ntab[i];
     while( j <= p ) 
     {
         if( j < p )  
             if( ntab[j] < ntab[j + 1] ) j++; // > 
         if( tmp >= ntab[j] ) break; // <=
         ntab[i] = ntab[j];
         i = j;
         j = 2 * i + 1;
     }
     ntab[i] = tmp;
 }
void Sort( int* ntab, int l, int p )
 {
    int i = l ;
    int j = p;
    int x = ntab[(i+j) / 2];
    do
    {
        while( ntab[i] < x ) i++;
        while( x < ntab[j] ) j--;
        if( i <= j )
        {
            int tmp = ntab[i];
            ntab[i] = ntab[j];
            ntab[j] = tmp;
            i++;
            j--;
        }      
    } while( i <= j );

        if( l < j ) Sort( ntab,l,j );
        if( i < p ) Sort( ntab,i,p );  
 }
void QuickSort( int* ntab, int nSize ) 
{
     Sort( ntab, 0, nSize - 1 );
}
