#ifndef MATRIX_H
#define MATRIX_H

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int CreateMatrix( double*** pTab, int nSize );     //!!!!!  0 error  1 -ok
void DeleteMatrix( double*** pTab, int nSize );    // *pTab==NULL
void TransMatrix( double** pTab, int nDim );      //transponowanie macierzy
void InverseMatrix( double** pInv, double** pTab, int nSize, double det );    // macierz odwrotna , na we obliczony wczesniej w main() det
double Det( double** pTab, int nSize );     // wyznacznik rekurencyjnie 
void LayoutEqu( double** pInv, double* pB, double* pRes, int nSize );    // rozwiazuje ukl rownan
void PrintMatrix( double** pTab, int nSize );    // drukuje macierz 

#endif
