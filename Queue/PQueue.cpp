#include "PQUEUE.H"

void UpdateDown( PQItem** ntab, int l, int p ); // update heap down between index l and p
void UpdateUp( PQItem** ntab, int l, int p ); // update heap up between index l and p

PQueue* PQInit( int nSize )
{
	if( nSize < 1 )
	{
		perror( "Size is smaller than 1" );
		return NULL;
	}

	PQueue* QUEUE = (PQueue*)calloc( 1, sizeof(PQueue) );
	if( !QUEUE )
	{
		perror( "Allocation Error ( PQInit )" );
		return NULL;
	}

    QUEUE->pPQueue = ( PQItem**)calloc( nSize, sizeof( PQItem*) );
	if( !QUEUE->pPQueue )
	{
		perror( "Allocation Error ( PQInit )" );
		return NULL;
	}
		
	QUEUE->nPQSize = nSize;
	return QUEUE;
}

int PQisEmpty( PQueue* q )
{
	return !q || !q->nPQCurrSize;			
}

int PQSize( PQueue* q )
{				
	return (q)? q->nPQCurrSize : PRIOR_ERROR;
}

int PGMaxPrior( PQueue* q )
{
	return ( q && !PQisEmpty(q) )? q->pPQueue[0]->nPrior : PRIOR_ERROR;	
}

int PQEnqueue( PQueue* q,int prior, PQINFO* p )
{
	if( !q )
	{
		perror( "Allocation Error ( PQEnqueue )" );
		return 0;
	}	                                                             
	if( PQSize(q) >= q->nPQSize )
	{
		perror( "Przekorczono limit kolejki" );
		return 0;
	}
	 
	PQItem* Item = (PQItem*)calloc( 1, sizeof(PQItem) );
	if( !Item )
	{
		perror( "Allocation Error ( PQEnqueue )" );
		return 0;
	}

	Item->nPrior = prior;     // ustawienie priorytetu dla Item
	Item->pInfo = p;          // ustawienie Info dla Item 

	
	int ix = PQSize( q );
	q->pPQueue[ix] = Item;
	if( ix > 0 )
		UpdateUp( q->pPQueue, 0 , PQSize(q) - 1 ); 
	q->nPQCurrSize++;

	return 1;
}

PQINFO* PQDequeue( PQueue* q )
{
	if( !q )
	{
		perror( "Allocation Error ( PQDequeue )" );
		return NULL;
	}
	if( PQisEmpty(q) )
	{
		perror( "ERROR: Stack underflow ( PQDequeue )" );
		return NULL;
	}

	PQINFO* tmp = q->pPQueue[0]->pInfo;           //zapisanie informacji w tmp
	int ix = --q->nPQCurrSize;

	free( q->pPQueue[0] );                        //usuniecie elementu
	
	if( ix )
	q->pPQueue[0] = q->pPQueue[ix]; 
	q->pPQueue[ix] = NULL;                        //wpisanie ostatniego elementu w miejsce usunietego
	      
	if( ix > 1 )
    UpdateDown( q->pPQueue, 0 , ix-1 );

	return tmp;
}

void PQClear( PQueue* q, void(__cdecl* freeInfo)(const void*) )
{
	if( !q || !freeInfo )
	{
		perror( "Allocation Error ( PQClear )" );
		return;
	}
	while( !PQisEmpty(q) )	
		freeInfo( PQDequeue(q) );		
}

int PQRelease( PQueue** q,void(__cdecl* freeInfo)(const void*) )
{
	if( !q || !*q )
	{
		perror( "Allocation Error ( PQRelease )" );
		return NULL;
	}
	PQClear( *q, freeInfo );
	free( (*q)->pPQueue );
	free( *q );	
	return NULL;
}

void PQPrint( PQueue* q, int nPos, void(__cdecl* printInfo)(const void*) )
{
	if( !q || PQisEmpty(q) )
	{
		perror( "Allocation Error ( PQPrint ) or queue is empty" );
		return;
	}
	if( nPos < 0 )
	{
		perror( "Position is lower than 0" );
		return;
	}
	
	if( nPos >= PQSize(q) )	// warunek koñca wywo³añ rekuencyjnych
	return;

	if( printInfo )				
	printInfo( q->pPQueue[nPos]->pInfo );

	printf( " (%d) [%d]\n", q->pPQueue[nPos]->nPrior, nPos );

	PQPrint( q, (nPos * 2 + 1), printInfo );

	PQPrint( q, (nPos * 2 + 2), printInfo );		
}

int PQSetPrior( PQueue* q, const void * pInfo , int newPrior, int(__cdecl* compareInfo)(const void*, const void*) )
{
	return PQsetPrior( q, PQFind( q, pInfo, compareInfo ), newPrior );	
}

int PQsetPrior( PQueue* q, int nPos, int newPrior )
{
	if( !q )
	{
		perror( "Allocation Error ( PQsetPrior )" );
		return PRIOR_ERROR;
	}
		 	
	int tmp = PQgetPrior( q, nPos );                 // zampamietanie starego priorytetu
	
	if( tmp != PRIOR_ERROR && tmp != POS_ERROR )
    { 
		q->pPQueue[nPos]->nPrior = newPrior;
	    if( tmp < newPrior )
		UpdateUp( q->pPQueue, 0, nPos );                  // przywrocenie warunku stogu  
		else
		UpdateDown( q->pPQueue, nPos, PQSize(q) - 1 );		
	}	
	return tmp;
}

int PQGetPrior( PQueue* q, const void* pInfo, int(__cdecl* compareInfo)(const void*, const void*) )
{
	return PQgetPrior( q, PQFind( q, pInfo, compareInfo ) );	
}

int PQgetPrior( PQueue* q, int nPos )
{
	if( !q || PQisEmpty(q) )
	{
		perror( "Allocation Error ( PQgetPrior ) or queue is empty" );
		return PRIOR_ERROR;
	}
	
	if( nPos < 0 || nPos >= PQSize(q) )
	{
		perror( "Out of queue range ( PQgetPrior )" );
		return  POS_ERROR;
	}
		
	return q->pPQueue[nPos]->nPrior;
}

int PQFind( PQueue* q, const void* pInfo, int(__cdecl* compareInfo)(const void*, const void*) )
{
	if( !q || !compareInfo )
	{
		perror( "Allocation Error ( PQFind )" );
		return PRIOR_ERROR;
	}
	
	for( int i=0; i < PQSize( q ); i++ )
      if( compareInfo( q->pPQueue[i]->pInfo , pInfo ) == 0 )
      return i;

	return POS_ERROR;
}

void UpdateDown( PQItem** ntab, int l, int p )
{
	if( !ntab || l >= p )			
		return;
	    
    int i = l;
    int j = 2 * i + 1;
	PQItem* tmp = ntab[i];

    while( j <= p )
    {
        if( j < p )
            if( ntab[j]->nPrior < ntab[j + 1]->nPrior ) j++;
        if( tmp->nPrior >= ntab[j]->nPrior ) break;
        ntab[i] = ntab[j];
        i = j;
        j = 2 * i + 1;
    }
    ntab[i] = tmp;
}

  void UpdateUp( PQItem** ntab, int l, int p )
{
	if( !ntab || l >= p )			
		return;

	int i = p;
	int parent = (i - 1) / 2;
	PQItem* tmp = ntab[i];

	while( parent >= l && ntab[parent]->nPrior < tmp->nPrior )
	{				
			ntab[i] = ntab[parent];
			i = parent;
			parent = (i + 1) / 2 - 1;						
    }
	ntab[i] = tmp;
} 





	
