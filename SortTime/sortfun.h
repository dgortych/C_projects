#ifndef SORTFUN_H
#define SORTFUN_H
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50

void InsertionSort( int* ntab, int nSize );  //wstawianie
void SelectionSort( int* ntab, int nSize );  //wybieranie
void BubbleSort( int* ntab, int nSize );     //babelkowe
void ShakeSort( int* ntab, int nSize );      //mieszane
void BinarySort( int* ntab, int nSize );     //polowkowe
void HeapSort( int* ntab, int nSize );       //stogowe
void QuickSort( int* ntab, int nSize );      //szybkie


#endif

