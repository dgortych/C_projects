#pragma once
#ifndef STACK_H
#define STACK_H

#include <stdio.h>

// stos znakowy
void EmptyStack();
void push( char c ); //wklada na stos
char pop(); //zdejmuje ze stosu szczytowy i go zwraca
char top(); // zwraca wartosc elementu szczytowego na stosie
void del(); //kasuje element szczytowy
int isEmpty(); //zwraca prawde jesli stos pusty

#endif