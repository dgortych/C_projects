// Stack na doublach

#include "pch.h"
#include "dStack.h"
#include <stdio.h>
#include <memory.h>  // do memseta
#include <float.h>  // potrzeby do DBL_MIN
using namespace std;

#define MAXSTACK 20

double dStack[MAXSTACK] = { 0 };
int ndHead = 0; // indeks pierwszego pustego elementu stosu

void dEmptyStack()
{
	memset(dStack, 0, MAXSTACK * sizeof( double ));  // Zerowanie tablicy 
	ndHead = 0;
}
void dpush( double x )
{
	if (ndHead >= MAXSTACK)
	{
		perror("Stack overflow1\n");
		return;
	}
	dStack[ndHead++] = x;		
}
double dpop()
{
	if (!disEmpty())
	{
		double x = dtop();
		ddel();
		return x;
	}
	perror("ERROR : Stack underflow2!\n");
		return DBL_MIN;
}
double dtop()  // jezeli stos jest pusty to zwraca 0 i nie ma komunikatu
{
	if (!disEmpty())
		return dStack[(ndHead - 1)];
	perror("Stack underflow3");
	return DBL_MIN;  //tylko dla stosu znakowego

}
void ddel()
{
	if (!disEmpty())
	{
		ndHead--;
		// dStack[ndHead] = 0;   nie jest konieczne
	}
	else
		perror("ERROR: Stack underflow4\n");
}
double disEmpty()
{
	return !ndHead;
}