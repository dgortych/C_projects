#include "Matrix.h"

void Complement( double** pTabO, double** pTabI, int nRow, int nCol, int nDim );// wycina wiersz i kolumne z tab we pTabI i reszte kopiuje do tab wyjsciowej pTabO 
void ComplMatrix( double** pTabD, double** pTab, int nDim ); //macierz dopelnien

int CreateMatrix( double*** pTab, int nSize )
{
    *pTab = (double**)malloc( nSize * sizeof(double*) );
    if( !pTab ) return 0;

    memset( *pTab, 0, nSize * sizeof(double*) );

    double** temp = *pTab;  // pomocniczy wska¿nik alokacji

    for( int i = 0; i < nSize; i++ )
    {
        *temp = (double*)malloc( nSize * sizeof(double) );
        if( !*temp ) return 0;
        memset( *temp++, 0, nSize * sizeof(double) );
    }
    return 1;
}
void DeleteMatrix( double*** pTab, int nSize )
{
    double** temp = *pTab;
    for( int i = 0; i < nSize; i++ )
        free( *temp++ );
    free( *pTab );
    *pTab = NULL;
}
void TransMatrix( double** pTab, int nDim )
{
    double** p = pTab;
    for( int i = 0; i < nDim  ; i++ , p++ )
    {
        double* v =  *p + i + 1 ;
        for( int j = i + 1; j < nDim; j++ )
        {
            double t = *v;      
            *v++ = pTab[j][i];
            pTab[j][i] = t;
        }
    }
}
void InverseMatrix( double** pInv, double** pTab, int nSize, double det )
{
    ComplMatrix( pInv, pTab, nSize );
    TransMatrix( pInv, nSize );

    double** p = pInv;
    for( int i = 0; i < nSize; i++ )
    {
        double* v = *p++;
        for( int j = 0; j < nSize; j++, v++ )
        {
            *v /= det;
        }               
    }                
}

double Det( double** pTab, int nSize )
{           
    if( nSize==1 ) return **pTab;      
    if( nSize==2 ) return pTab[0][0] * pTab[1][1] - pTab[0][1] * pTab[1][0];

    double res = 0; 
    int coef = 1;
    double** tmp = NULL;
    CreateMatrix( &tmp, nSize - 1 );
    if( !tmp )
    {
        perror( "CreatetmpMatrix (Det) ERROR" );
        return 1;
    }  
    double* p = *pTab;
    for( int i = 0; i < nSize; i++, p++ )
    {       
        coef = -coef;
        Complement( tmp, pTab, 0, i, nSize );
        res += coef * *p * Det( tmp, nSize - 1 );
    }    
    DeleteMatrix( &tmp, nSize - 1 );
    return res;
} 
 void LayoutEqu( double** pInv, double* pB, double* pRes, int nSize )
{  
    for( int i = 0; i < nSize; i++, pInv++, pRes++ )
    {
        double* n = *pInv;   
        double* v = pB;
        for( int j = 0; j < nSize; j++, n++, v++ )
        {
            *pRes += *n * (*v);
        }
    }
}
void PrintMatrix( double** pTab, int nSize ) 
{
    for( int i = 0; i < nSize; i++ )
    {
        double* v = *pTab++;
        for( int j = 0; j < nSize; j++ )
        {
            printf( "%lf ", *v++ );
        }
         printf( "\n" );        
    }    
} 
	   
void Complement( double** pTabO, double** pTabI, int nRow, int nCol, int nDim )
{  
     for( int i = 0; i < nDim; ++i, pTabI++ )    
     {
         if( i==nRow )
             continue;   
         double* v1 = *pTabO++;
         double* v2 = *pTabI;       
          for( int j = 0; j < nDim; ++j, v2++ )
          {
              if( j==nCol )
                   continue;
               *v1++ = *v2;               
          }                             
     }          
}

void ComplMatrix( double** pTabD, double** pTab, int nDim )   //macierz dopelnien
{	         
   double** matrix = NULL;
   CreateMatrix( &matrix, nDim - 1 );
   if( !matrix )
   {
       perror( "CreateMatrix (ComplMatrix) ERROR" );
       return;
   }
   for( int i = 0; i < nDim; i++ , pTabD++ )
   {
       int coef = i%2 ? -1 : 1 ;
       double* v = *pTabD;       
		for( int j = 0; j < nDim; j++ )
		{			                    			
			Complement( matrix, pTab, i, j, nDim );           
            *v++ = coef * Det( matrix, nDim - 1 );
            coef = -coef;
		}	
   }
   DeleteMatrix( &matrix, nDim - 1 );
}

