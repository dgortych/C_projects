#include "FQUEUE.H"

// funkcja prywatna modulu  - tylko usuniecie elemenu z listy (nie info)
void  QFDel( QFIFO* q ); 

QFIFO* QFCreate() 
{
	QFIFO* FIFO = (QFIFO*)calloc( 1, sizeof(QFIFO) );
	if( !FIFO )	
	{
		perror( "ERROR: Allocation Error (QFCreate)" );
	    return NULL;
	}
	QFItem* nHead = (QFItem*)calloc( 1, sizeof(QFItem) );   //glowa
	if( !nHead )
	{
		perror( "ERROR: Allocation Error (QFCreate)" );
	    return NULL;
	}
	FIFO->pHead = FIFO->pTail = nHead;	
	return FIFO;
}

int QFEmpty( QFIFO* q )
{
	return !q || !q->pHead->pNext;   // jeœli kolejka istnieje i nie ma elementu to zwraca 1                                         
}                                       // w przeciwnym wypadku 0

int QFEnqueue( QFIFO* q, QInfo* pInfo )
{		  
	if( !q )
	{
	   perror( "ERROR: Allocation Error (QFEnqueue)" );
	   return 0;
	}

    QFItem* p = (QFItem*)calloc( 1, sizeof(QFItem) );
	if( !p )
	{
		perror( "ERROR: Allocation Error (QFEnqueue)" );
	    return 0;
	}
	
	p->pInfo = pInfo;	
							
	q->pTail->pNext = p;
	q->pTail = p;

	return 1;
}               

QInfo* QFDequeue( QFIFO* q )
{
    if( q )
    {
		if( !QFEmpty(q) )
		{
			QInfo* tmp = q->pHead->pNext->pInfo;
			QFDel(q);
			return tmp;
		}		
	    perror( "ERROR: Stack underflow ( QFDequeue )" );	
		return NULL;
    }				 
    perror( "ERROR: Allocation Error ( QFDequeue )" );
	return NULL;
}

void QFClear( QFIFO* q )
{
	if( !q )
	{
	   perror( "ERROR: Queue does not exist" );
	   return;
	}
	while( !QFEmpty(q) )	
		free( QFDequeue(q) );	
}

void QFRemove( QFIFO** q ) 
{
	if( !q || !*q )
	{
	   perror( "ERROR: Queue does not exist" );
	   return;
	}
	QFClear(*q);
	free( (*q)->pHead );
	free(*q);	
	*q = NULL;
}

void QFDel( QFIFO* q )
{
	if( !q ||  QFEmpty(q) )
	{
		perror( "ERROR: Allocation Error ( QFDel ) or Queue underflow " );
	    return;
	}

	QFItem* tmp = q->pHead->pNext;
    q->pHead->pNext = tmp->pNext;		
	free( tmp );

    if( QFEmpty(q) )
	q->pTail = q->pHead; 	
}




