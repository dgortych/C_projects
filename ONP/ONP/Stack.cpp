#include "Stack.h"
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>// do memseta
using namespace std;

#define MAXSTACK 20

char Stack[MAXSTACK] = { 0 };
int nHead = 0; // indeks pierwszwgo pustego elementu stosu

void EmptyStack()
{
	memset( Stack, 0, MAXSTACK * sizeof(char) );  // Zerowanie tablicy 
	nHead = 0;
}
void push (char c )
{
	if (nHead >= MAXSTACK)
	{
		perror("Stack overflow\n");
		return;
	}
	Stack[nHead++] = c;
}
char pop()
{
	char c = top();
	if (c)
	{
		del();
		return c;
	}
	perror("ERROR : Stack underflow\n");
	return 0;
}
char top()  // jezeli stos jest pusty to zwraca 0 i nie ma komunikatu
{
	if (!isEmpty())
		return Stack[ (nHead - 1) ];
	return 0;
}
void del()
{
	if (!isEmpty())
	{
		nHead--;
		// Stack[nHead] = 0;   nie jest konieczne
	}
	else
		perror( "ERROR: Stack underflow\n");
}
int isEmpty()
{
	return !nHead;
}

