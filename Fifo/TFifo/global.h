#ifndef GLOBAL_H
#define GLOBAL_H

 #include <stdio.h>
 #include <stdlib.h>

#define QFITEM QInfo

typedef struct
{
  int n_Key;  // klucz (informacja)
  int* pTab;  // ma byc tablica 2 elementowa - mozna do pTab[0] wstawiac to samo co klucz
} QInfo;

void freeInfo( const void* );

#endif
