#include "LIST.H"

ListItem* CreateList()
{
	ListItem* GUARD = (ListItem*)calloc( 1, sizeof(ListItem) );	
	return GUARD;
}

int InsertFront( ListItem* pList,  LISTINFO* pInfo )
{
	return Insert( pList, pInfo );
}

int Insert( ListItem* pAfter, LISTINFO* pInfo )
{
	if( !pAfter )	
		return 0;
		
	ListItem* NewItem = (ListItem*)calloc( 1, sizeof(ListItem) );
	if( !NewItem )		  
	   return 0;
    
	NewItem->pInfo = pInfo;

	NewItem->pNext = pAfter->pNext;
	pAfter->pNext = NewItem;
	
	return 1;
}

LISTINFO* RemoveFront( ListItem* pList )
{	
	return Remove(pList);	
}

LISTINFO* Remove( ListItem* pAfter )
{
	if( !pAfter || IsEmpty( pAfter ) )		  
	   return NULL;	

	ListItem* DEL = pAfter->pNext;
	LISTINFO* Info = DEL->pInfo;	
	pAfter->pNext = DEL->pNext;
	free( DEL );

	return Info;
}

LISTINFO* Front( ListItem* pList )
{
	if( !pList || IsEmpty( pList ) )		   
	   return NULL;
		
	return pList->pNext->pInfo;
}

int IsEmpty( ListItem* pList )
{
	return !pList || !pList->pNext;
}

void ClearList( ListItem* pList, void(__cdecl* freeInfo)(const void*) )
{
	if( !pList || !freeInfo )
	{
	   perror( "ERROR: Allocation Error ( ClearList )" );
	   return;
	}

	while( !IsEmpty( pList ) )	
		freeInfo( RemoveFront( pList ) );	
}

void RemoveList( ListItem** pList, void(__cdecl* freeInfo)(const void*) )
{
   if( !pList || !*pList )
   {
	   perror( "ERROR: Allocation Error (RemoveList)" );
	   return;
   }
   ClearList( *pList, freeInfo );  
   free( (*pList)->pNext );  
   free( *pList ); 

}

void SortList( ListItem* pList, int(__cdecl* compareInfo)(const void*, const void*) )
{
	if( !pList )
	{
	   perror( "ERROR: Allocation Error ( SortList )" );
	   return;
	}

	ListItem* pFirst = pList;
	
	while( pFirst->pNext )
	{
		ListItem* pCurr = pFirst->pNext;
		ListItem* pMin = pList;
		while( pCurr->pNext )
		{
			if( compareInfo( pMin->pNext->pInfo, pCurr->pNext->pInfo ) == 1 ) pMin = pCurr;
			pCurr = pCurr->pNext;
		}
		if( pMin != pFirst )
		{
			pCurr = pMin->pNext->pNext;
			pMin->pNext->pNext = pFirst->pNext;
			pFirst->pNext = pMin->pNext;
			pMin->pNext = pCurr;
		}
		pFirst = pFirst->pNext;		
	}
}

ListItem* Find( ListItem* pList, const void* info, ListItem** pPrev, int(__cdecl* compareInfo)(const void*, const void*) )
{
	if( !pList || !compareInfo )
	{
	   perror( "ERROR: Allocation Error ( Find )" );
	   return NULL;
	}

	*pPrev = pList;

	while( (*pPrev)->pNext )
	{
		if( compareInfo( (*pPrev)->pNext->pInfo, info ) == 0 )		
			return (*pPrev)->pNext;				
		*pPrev = (*pPrev)->pNext;
	}	
	return *pPrev = NULL;
}
