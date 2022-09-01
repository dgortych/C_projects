//Stack na doublach
#pragma once
#ifndef dSTACK_H  // musi byc unikalny
#define dSTACK_H
#include <stdio.h>

// stos znakowy
void dEmptyStack();
void dpush( double c ); //wklada na stos
double dpop(); 
double dtop();  //zdejmuje ze stosu szczytowy i go zwraca
void ddel();    //kasuje element szczytowy
double disEmpty();  //zwraca prawde jesli stos pusty


#endif
