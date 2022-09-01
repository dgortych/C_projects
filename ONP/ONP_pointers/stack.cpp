#include "ONPFUN.h"
#include "Stack.h"

StackItem* initStack()
{
	return NULL;
}

void emptyStack( StackItem** pStack )
{
	while ( !isEmpty( *pStack ) ) 
		del( pStack );
}
void push( char c, StackItem** pStack )
{	
	StackItem* ptr = (StackItem*)malloc( sizeof(StackItem) );
	if(!ptr)
	{
		perror( "ERROR: Allocation Error (push)" );
	    return;
	}
	ptr->cHead = c;
	ptr->pNext = *pStack;
	*pStack = ptr;
}
char pop( StackItem** pStack )
{
	char c = top( *pStack );
	if (c)
	{
		del( pStack );
		return c;
	}
	perror( "ERROR : Stack underflow (pop) " );
	return 0; 
}
char top( StackItem* pStack )  
{
	if ( !isEmpty( pStack ) )
		return pStack -> cHead;
	return 0;
}
void del( StackItem** pStack )
{
	if ( !isEmpty( *pStack ) )
	{
		StackItem* ptr = *pStack;
		*pStack = ptr -> pNext;
		free( ptr );
	}
	else
		perror( "ERROR: Stack underflow (del) " );
}
int isEmpty( StackItem* pStack )
{
	return !pStack;
}