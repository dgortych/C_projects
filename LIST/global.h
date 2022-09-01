#pragma once

#include <stdio.h>
#include <stdlib.h>

#define LISTINFO ListInfo

typedef struct
{
  int nKey;
  int* p;
} ListInfo;


void freeInfo( const void* );
int compareInfo( const void* p , const void* q ); 
void printInfo( const void* p );