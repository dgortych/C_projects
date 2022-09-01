#include "ONPFUN.h"
#include "dSTACK.h"

DStackItem* initDStack()
{
	return NULL;
}

void dEmptyStack( DStackItem** pDStack )
{
	while ( !disEmpty( *pDStack ) )
		ddel( pDStack );
}
void dpush( double c , DStackItem** pDStack )
{
	DStackItem* ptr = (DStackItem*)malloc( sizeof(DStackItem) );
	if ( !ptr )
	{
		perror( "ERROR: Allocation Error (dpush)" );
		return;
	}
	ptr->DHead = c;
	ptr->pDNext = *pDStack;
	*pDStack = ptr;
}
double dpop( DStackItem** pDStack )
{
	if (!disEmpty( *pDStack ) )
	{
		double x = dtop( *pDStack );
		ddel( pDStack );
		return x;
	}
	perror( "ERROR : Stack underflow (dpop)" );
	return DBL_MIN;
}	
double dtop ( DStackItem* pDStack )  
{
	if ( !disEmpty( pDStack ) )
		return pDStack-> DHead;
	perror( "Error : Stack underflow (dtop)" );
	return  DBL_MIN;
}
void ddel(DStackItem** pDStack)
{
	if ( !disEmpty( *pDStack ) )
	{
		DStackItem* ptr = *pDStack;
		*pDStack = ptr->pDNext;
		free(ptr);
	}
	else
		perror( "ERROR: Stack underflow (ddel)" );
}
double disEmpty(DStackItem* pDStack)
{
	return !pDStack;
}