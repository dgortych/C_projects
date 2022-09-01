#ifndef FQUEUE_H
#define FQUEUE_H 

 #include "GLOBAL.H"

 #include <stdio.h>
 #include <stdlib.h>

typedef struct 
{
   int nMaxElem;  // maksymalny rozmiar kolejki
   QFITEM** pFQItems;   // dynamiczna tablica wskaznikow do informacji
   int nHead; // indeks pierwszego elementu w kolejce
   int nTail; // indeks pierwszego wolnego miejsca w kolejce (po ostatnim zajetym)
   int nNoElem;  // ilosc elementow w kolejce  
} QFIFO;

// kreowanie dynamiczne kolejki (struktury i tablicy)
QFIFO* QFCreate( int nSize );  // nSize  - rozmiar tablicy

// zwraca 1 gdy kolejka pusta, w przeciwnym wypadku 0
int QFEmpty( QFIFO* q );

// wstawienie elementu do kolejki
int QFEnqueue( QFIFO* q, QFITEM* pItem );

// usuniecie elementu z kolejki i zwrocenie wskaznika do tego elementu
QFITEM* QFDequeue( QFIFO* q );

// czyszczenie kolejki, kolejke mozna uzywac
void QFClear( QFIFO* q, void( __cdecl* freeInfo )( const void* ) );

// czyszczenie kolejki i usuniecie wszystkich struktur danych, wyzerowanie wskaznika
void QFRemove( QFIFO** q, void( __cdecl* freeInfo )( const void* ) );

#endif

