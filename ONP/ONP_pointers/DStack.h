//Stack na doublach
#ifndef dSTACK_H  
#define dSTACK_H
#include "ONPFUN.h"


typedef struct tagDStackItem
{
	double DHead;
	tagDStackItem* pDNext;
}DStackItem;

DStackItem* initDStack();

void dEmptyStack( DStackItem** pDStack ) ;
void dpush( double c, DStackItem** pDStack );
double dpop ( DStackItem** pDStack );
double dtop( DStackItem* pDStack );
void ddel( DStackItem** pDStack );
double disEmpty( DStackItem* pDStack );








#endif
