#include "functions.h"

int main( int argc, char* argv[] )
{
    if( argc!=2 )
    {
        printf( "Usage: %s <plik_we>", argv[0] );
        return 1;
    }

    int** DepthTab = createTab( N, M );  
    if( !DepthTab )
    {
        perror( "ERROR: ALLOCATION (DepthTab)" );
        return 2;
    }

    int** RootTab = createTab( N, M );   
    if( !RootTab )
    {
        perror( "ERROR: ALLOCATION (RootTab)" );
        return 3;
    }
   
    if( readDepthTab( argv[1], DepthTab, N, M ) )
    {       
       if( root( DepthTab, N, M, SHIP_DEPTH, 0, 0, RootTab, N - 1, M - 1 ) )
       {
            printf( "Udalo sie\n" );
            printTab( RootTab, N, M );
       }
       else
            printf( "** Nie ma mozliwosci doplynac do portu!!\n\n" );   
    }       
    freeTab( &DepthTab );
    freeTab( &RootTab );         
    return 4;
}
