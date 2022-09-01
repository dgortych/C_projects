#include "FQUEUE.H"
#define SIZE 4

int main()
{	
	QFIFO* TFIFO = QFCreate(SIZE);

	QFITEM* a1 = (QFITEM*)calloc(1, sizeof(QFITEM));
	QFITEM* a2 = (QFITEM*)calloc(1, sizeof(QFITEM));
	QFITEM* a3 = (QFITEM*)calloc(1, sizeof(QFITEM));
	QFITEM* a4 = (QFITEM*)calloc(1, sizeof(QFITEM));
	QFITEM* a5 = (QFITEM*)calloc(1, sizeof(QFITEM));
	QFITEM* a6 = (QFITEM*)calloc(1, sizeof(QFITEM));
	QFITEM* a7 = (QFITEM*)calloc(1, sizeof(QFITEM));
	QFITEM* a8 = (QFITEM*)calloc(1, sizeof(QFITEM));
	QFITEM* a9 = (QFITEM*)calloc(1, sizeof(QFITEM));
	
	if( !( a1 && a2 && a3 && a4 && a5 && a6 && a7 && a8 && a9 ) )
    {
        perror( "Allocation Error ") ;
        return 1;         
    }

	a1->pTab = (int*)calloc(2, sizeof(int));
	a2->pTab = (int*)calloc(2, sizeof(int));
	a3->pTab = (int*)calloc(2, sizeof(int));
	a4->pTab = (int*)calloc(2, sizeof(int));
	a5->pTab = (int*)calloc(2, sizeof(int));
	a6->pTab = (int*)calloc(2, sizeof(int));
	a7->pTab = (int*)calloc(2, sizeof(int));
	a8->pTab = (int*)calloc(2, sizeof(int));
	a9->pTab = (int*)calloc(2, sizeof(int));
	
	if( !( a1->pTab && a2->pTab && a3->pTab && a4->pTab && a5->pTab && a6->pTab && a7->pTab && a8->pTab && a9->pTab ) )
     {
        perror( "Allocation Error ") ;
        return 2;         
     }

	*a1->pTab = 1;
	*a2->pTab = 2;
	*a3->pTab = 3;
	*a4->pTab = 4;
	*a5->pTab = 5;
	*a6->pTab = 6;
	*a7->pTab = 7;
	*a8->pTab = 8;
	*a9->pTab = 9;
		
	QFEnqueue( TFIFO, a1 );   // 1
	QFEnqueue( TFIFO, a2 );   // 2
	QFEnqueue( TFIFO, a3 );   // 3
	QFEnqueue( TFIFO, a4 );   // 4
	
	printf( "%d\n", *QFDequeue(TFIFO)->pTab );   //pTab[0] = 1	
	printf( "%d\n", *QFDequeue(TFIFO)->pTab );   //pTab[0] = 2	
	printf( "%d\n\n", *QFDequeue(TFIFO)->pTab );  //pTab[0] = 3

	QFEnqueue( TFIFO, a5 );   // 5
	QFEnqueue( TFIFO, a6 );   // 6

	QFClear( TFIFO, freeInfo ); // 4,5,6

	QFEnqueue( TFIFO, a7 );   // 7
	QFEnqueue( TFIFO, a8 );   // 8
	QFEnqueue( TFIFO, a9 );   // 9

	printf( "%d\n", *QFDequeue(TFIFO)->pTab );   //pTab[0] = 7

	QFRemove( &TFIFO, freeInfo );
	
	return  3;
}

void freeInfo( const void* p )
{
	if( !p )
	{
	    perror( "ERROR: Allocation Error (freeInfo)" );
	    return;
	}	
	free( ( (QFITEM*)p )->pTab );
	free( (QFITEM*)p );	
}