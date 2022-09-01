#ifndef PRINTF_H
#define PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <iostream>

void outDec(int n );  //  znakowo wypisuje liczbe calkowita
void outChar(char c);  // wypisuje znak putchar()
void outStr( char* c );   //wypsiuje znakowo string
void outDouble(double d);    //wypisuje znakowo licze double
void outNum(int n );     // wypisuje znakowo liczbe int > 0 rekurencyjnie

int Printf(const char* sFormat, ...);
int PrintfV(const char* sFormat, va_list arg_list);



#endif

