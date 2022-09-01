#ifndef ONPFUN_H
#define ONPFUN_H
#include <stdio.h>
#include <math.h>
#include <memory.h> 
#include <iostream>
#include <float.h>
#include <stdlib.h>

using namespace std;

int isOper( char nOper );
int prior( char nOper );
double GetNum();
int isDigit( char c );
char getOper();
void skipSpaces();
double calcONP();
//void ONP();
#endif
