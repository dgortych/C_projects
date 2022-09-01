#pragma once

#include "GLOBAL.H"

typedef struct tagListItem
{
    LISTINFO* pInfo;
    tagListItem* pNext;
} ListItem;

ListItem * CreateList(); 

// inserts new elem at the front of the list, returns 0 if fails else 1
int InsertFront( ListItem* pList,  LISTINFO* pInfo ); // pList - the List, pInfo - wsk do info

// inserts new elem to the list after pointer pAfter, returns 0 if fails else 1
int Insert( ListItem* pAfter, LISTINFO* pInfo ); // pInfo - wsk do informacji

// removes first elem from the list and returns user info,
// if list is empty returns NULL
LISTINFO* RemoveFront( ListItem* pList );

// removes elem after the pointer pAfter from the list and returns user info,
// if list is empty returns NULL
LISTINFO* Remove( ListItem* pAfter );

// returns the user info from the first elem on the list
LISTINFO* Front( ListItem* pList ); // pList - the List

// returns 1 if list is empty else returns 0
int IsEmpty( ListItem* pList ); // pList - the List

// clears list, so list is empty and ready to father use
// uses user releasing memory function to free the user info
void ClearList( ListItem* pList, void(__cdecl* freeInfo)(const void*) );
/* ptr to function of void type with one param const void* */

// clears list and removes guard and sets the list to the NULL ptr
// uses user releasing memory function to free the user info
void RemoveList( ListItem** pList , void( __cdecl* freeInfo )( const void* ) );

// sorts the list elems using the user comparing function (compares user info)
void SortList( ListItem* pList, int(__cdecl* compareInfo)(const void*, const void*) );
/* ptr to the function with two parameters const void*
and which returns int value */ 


// finds and returns ptr to elem containing the same info as in the second param
// and returns by parameter pPrev the pointer to the previous elem at the list
ListItem* Find( ListItem* pList, const void* info, ListItem** pPrev, int(__cdecl* compareInfo)(const void*, const void*) );
/*pointer to search info - const void* */
/*pPrev pointer to previous to found*/
/* ptr to function with two parameters const void*
and which returns int value */ 


