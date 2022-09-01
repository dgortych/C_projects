#include "functions.h"


int move( int** pDepthTab, int nRow, int nCol, int nDepth,
    int nextMove, int x, int y, int* px, int* py, int** pRoot )
{
    switch( nextMove )
    {
     case 1: *px = x - 1;  *py = y; break;   //UP           
    
     case 2: *px = x ; *py = y + 1; break;   //RIGHT
               
     case 3: *px = x + 1 ; *py = y; break;   //DOWN
              
     case 4: *px = x;  *py = y - 1; break;   //LEFT                
    }

    if( ( *px >= nRow ) || ( *py >= nCol ) || ( *px < 0 ) || ( *py < 0 ) ) return 0;  // poza zakresem 
                    
    if( pDepthTab[*px][*py] >= nDepth || pRoot[*px][*py] != 0 ) return 0;  // za plytko lub  statek juz tu byl
     
    return 1;
}

int root( int** pDepthTab, int nRow, int nCol, int nDepth,
    int x, int y, int** pRoot, int x_dest, int y_dest )
{
    static int road = 1;  
    pRoot[x][y] = road++;

    if( ( x == x_dest ) && ( y == y_dest ) ) return 1;  //koniec trasy
  
    int ix = 0;
    int iy = 0;   
      
    for( int i = UP; i <= LEFT; i++ )
    {
        if( move( pDepthTab, N, M, SHIP_DEPTH, i, x, y, &ix, &iy, pRoot ) )
        {                        
            if( root( pDepthTab, nRow, nCol, nDepth, ix, iy, pRoot, x_dest, y_dest ) )  return 1;
        }       
    }
   
    road--;
    pRoot[x][y] = 0; 
    return 0;
}

int readDepthTab( char* sFile, int** pTab, int nRow, int nCol )
{   
    FILE* f = fopen( sFile, "r" );     // otwiera plik do odczytu 
    if( !f )
    {
       printf( "ERROR: %s opening failure", sFile );
        return 0;
    }

    for( int i = 0; i < nRow; i++ )
    {
        int* p = *pTab++;        

        for( int j = 0; j < nCol; j++ )
            fscanf( f, "%d", p++ );                
    }   
    fclose(f);
    return 1;
}

int** createTab( int nRow, int nCol )
{  
    int** pRow = (int**)malloc( nRow * sizeof(int*) );
    int* pCol = (int*)malloc( nRow * nCol* sizeof(int) );
    if( !pRow || !pCol )
    {
        perror("ERROR: ALLOCATION (createTab)");
        return 0;
    }
    int** tmp = pRow;  // pomocniczy wskaznik alokacji

     memset( pRow, 0, nRow * sizeof(int) );
     memset( pCol, 0, nRow * nCol * sizeof(int) );
    for( int i = 0; i < nRow; i++ )
    {
        *tmp++ = pCol;
        pCol += nCol;
    }
     return pRow;
}


void printTab( int** pRoot, int nRow, int nCol )
{
    for( int i = 0; i < nRow; i++ )
    {
        int* v = *pRoot++;
        for( int j = 0; j < nCol; j++ )
        {
            printf( "%d ", *v++ );
        }
         printf( "\n" );        
    }    
}

void freeTab(int*** pTab)
{
    free(**pTab);
    free(*pTab);    
    *pTab = NULL;
}

