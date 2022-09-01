#include "FQUEUE.H"

void  QFDel( QFIFO* q );
//  - wstawia NULL do pozycji tablicy, skad pobierany jest element
//  - przesuwa cyklinie indeks glowy kolejki
//  - zmniejsza ilosc elementow w kolejce

QFIFO* QFCreate( int nSize )
{
	if( nSize < 1 ) return NULL;

	QFIFO* TFfifo = (QFIFO*)calloc( 1, sizeof(QFIFO) );
	if( !TFfifo )
	{
		perror( "Allocation Error ( QFCreate )" );
		return NULL;
	}

	TFfifo->pFQItems = (QFITEM**)calloc( nSize, sizeof(QFITEM*) );
	if( !TFfifo->pFQItems )
	{
		perror( "Allocation Error ( QFCreate )" );
		return NULL;
	}
 
	TFfifo->nMaxElem = nSize;	
	return  TFfifo;
}

int QFEmpty( QFIFO* q )
{
	return !q || !q->nNoElem;
}

int QFEnqueue( QFIFO* q, QFITEM* pItem )
{	 
	if( !q )
	{
	   perror( "ERROR: Allocation Error (QFEnqueue)" );
	   return 0;
	}
	if( q->nNoElem == q->nMaxElem )
	{
	   perror( "Queue is full" );
	   return 0;
	}
	
	q->pFQItems[q->nTail] = pItem;
	q->nTail = ( q->nTail + 1 ) % q->nMaxElem;
	q->nNoElem++;		 
	return 1;
}

QFITEM* QFDequeue( QFIFO* q )
{	
	if( q )
	{
		if( !QFEmpty(q) )
		{
			QFITEM* tmp = q->pFQItems[q->nHead];
			QFDel(q);
			return tmp;
		}
		perror( "ERROR: Stack underflow ( QFDequeue )" );	
		return NULL;
	}	
	perror( "ERROR: Allocation Error ( QFDequeue )" );
	return NULL;
}

void QFClear( QFIFO* q , void( __cdecl* freeInfo )( const void* ) )
{
	if( !q )
	{
	   perror( "ERROR: Allocation Error (QFClear)" );
	   return;
	}

	while( !QFEmpty(q) )	
		freeInfo( QFDequeue(q) );	
	q->nHead = 0;
	q->nTail = 0;	
}

void QFRemove( QFIFO** q , void( __cdecl* freeInfo )( const void* ) )
{
	if( !q || !*q )
	{
	   perror( "ERROR: Allocation Error (QFRemove)" );
	   return;
	}
	QFClear( *q, freeInfo );
	free( ( *q )->pFQItems );
	free( *q );	
	*q = NULL;
}

void QFDel( QFIFO* q )
{
	if( !q ||  QFEmpty(q) )
	{
		perror( "ERROR: Allocation Error ( QFDel ) or Queue underflow " );
	    return;
	}
						
	q->pFQItems[q->nHead] = NULL; 
	q->nHead = ( q->nHead + 1 ) % q->nMaxElem;
	q->nNoElem--; 	
}