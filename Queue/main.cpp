#include "PQUEUE.H"
#define SIZE 20

void freeInfo( const void* p );  // funkcja czyszcz¹ca
void printInfo( const void* p);  // funkcja drukujaca
int compareInfo( const void* p , const void* q );  // funkcja porownoj¹ca

int main()
{
    PQueue* QUEUE = PQInit(SIZE);

    PQINFO* p1 = (PQINFO*)calloc(1, sizeof(PQINFO));
    PQINFO* p2 = (PQINFO*)calloc(1, sizeof(PQINFO));
    PQINFO* p3 = (PQINFO*)calloc(1, sizeof(PQINFO));
    PQINFO* p4 = (PQINFO*)calloc(1, sizeof(PQINFO));
    PQINFO* p5 = (PQINFO*)calloc(1, sizeof(PQINFO));
    PQINFO* p6 = (PQINFO*)calloc(1, sizeof(PQINFO));
    PQINFO* p7 = (PQINFO*)calloc(1, sizeof(PQINFO));
    PQINFO* p8 = (PQINFO*)calloc(1, sizeof(PQINFO));

    p1->pTab = (int*)calloc(2, sizeof(int));
    p2->pTab = (int*)calloc(2, sizeof(int));
    p3->pTab = (int*)calloc(2, sizeof(int));
    p4->pTab = (int*)calloc(2, sizeof(int));
    p5->pTab = (int*)calloc(2, sizeof(int));
    p6->pTab = (int*)calloc(2, sizeof(int));
    p7->pTab = (int*)calloc(2, sizeof(int));
    p8->pTab = (int*)calloc(2, sizeof(int));

    p1->pTab[0] = 1;
    p2->pTab[0] = 2;
    p3->pTab[0] = 3;
    p4->pTab[0] = 4;
    p5->pTab[0] = 5;
    p6->pTab[0] = 6;
    p7->pTab[0] = 7;
    p8->pTab[0] = 8;
 
    PQEnqueue(QUEUE, 1, p1);
    PQEnqueue(QUEUE, 2, p2);
    PQEnqueue(QUEUE, 3, p3);
    PQEnqueue(QUEUE, 4, p4);
    PQEnqueue(QUEUE, 5, p5);
    PQEnqueue(QUEUE, 6, p6);

    PQPrint( QUEUE, 0, printInfo ); 
    printf("\n");

    printf("%d\n\n", PQDequeue(QUEUE)->pTab[0] );
    
    PQPrint( QUEUE, 0, printInfo );
    printf("\n");

    PQEnqueue(QUEUE, 7, p7);
    PQEnqueue(QUEUE, 8, p8);

    PQPrint( QUEUE, 0, printInfo );
    printf("\n");
   

    int p = PQFind( QUEUE, p1, compareInfo );
    printf( "%d\n\n",PQsetPrior( QUEUE, p, 10 ) );
    PQPrint( QUEUE, 0, printInfo ); 
    printf("\n");

    printf("%d\n\n", PQSetPrior(QUEUE, p2, 20, compareInfo));
    
    PQPrint( QUEUE, 0, printInfo ); 

   // PQRelease(&QUEUE, freeInfo);

    return 0;
}

void freeInfo( const void* p )
{	
    if( !p )
	{
		perror( "Allocation Error ( freeInfo )" );
		return;
	}
    free( ( (PQINFO*)p )->pTab );
	free( (PQINFO*)p );
}

void printInfo( const void* p )
{   
    if( !p )
	{
		perror( "Allocation Error ( printInfo )" );
		return;
	}
    printf( "%d", ( (PQINFO*)p )->pTab[0] );
}

int compareInfo( const void* p , const void* q )
{
    if( !p && q ) return -1;
    else if( p && !q ) return 1;
    else if( !p && !q ) return 0;
      
    if( ( (PQINFO*)p )->pTab[0] < ( (PQINFO*)q )->pTab[0] )  return -1;
    else if( ( (PQINFO*)p )->pTab[0] > ( (PQINFO*)q )->pTab[0] ) return 1;
    else return 0;
}