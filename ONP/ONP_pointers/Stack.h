#ifndef STACK_H
#define STACK_H
#include "ONPFUN.h"

typedef struct tagStackItem
{
	char cHead;
	tagStackItem* pNext;
}StackItem;

StackItem* initStack();

void emptyStack( StackItem** pStack );
void push( char c , StackItem** pStack );  //wklada na stos
char pop( StackItem** pStack );  //zdejmuje ze stosu szczytowy i go zwraca
char top( StackItem* pStack );  // zwraca wartosc elementu szczytowego na stosie
void del( StackItem** pStack );  //kasuje element szczytowy
int isEmpty( StackItem* pStack );  //zwraca prawde jesli stos pusty








#endif