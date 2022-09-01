#ifndef FQUEUE_H
#define FQUEUE_H 

 #include <stdio.h>
 #include <stdlib.h>

typedef struct 
{ 
    int n_Key;
} QInfo;

typedef struct tagQFItem
{
    QInfo* pInfo;       //wskaznik na informacje
    tagQFItem* pNext;   //wskaznik na kolejny element
} QFItem;

typedef struct 
{
   QFItem*  pHead;      //wskaznik na pierwszy element
   QFItem*  pTail;      //wskaznik na ostatni element
} QFIFO;


// kreowanie dynamiczne kolejki                                  
QFIFO* QFCreate();

// zwraca 1 gdy kolejka pusta, w przeciwnym wypadku 0
int QFEmpty( QFIFO* q );

// wstawienie elementu do kolejki i zwrocenie 1 gdy OK i 0 gduy blad alokacji
int QFEnqueue( QFIFO* q, QInfo* pInfo );

// usuniecie elementu z kolejki i zwrocenie wskaznika do tego elementu (NULL - kolejka pusta)
QInfo* QFDequeue( QFIFO* q );  // ma wywolac QFDel() 

// czyszczenie kolejki, kolejke mozna uzywac dalej
void QFClear( QFIFO* q );

// czyszczenie kolejki i usuniecie wszystkich struktur danych, wyzerowanie kolejki
void QFRemove( QFIFO** q );

#endif
