#include "LIST.H"
#include <time.h>

void PrintList( ListItem* pList, void(__cdecl* printInfo)(const void*) );

int main()
{
	ListItem* LIST = CreateList();
	srand(time(NULL));

	for( int i = 0; i < 20; i++ )
	{
		LISTINFO* INFO = (LISTINFO*)calloc(1, sizeof(LISTINFO));
		INFO->p = (int*)calloc(1, sizeof(int));
		INFO->p[0] = i;
		if( i == 9 ) INFO->nKey = 2000;
		else INFO->nKey = rand() % 50;		
		InsertFront( LIST, INFO );
	}

	PrintList( LIST, printInfo );

	SortList( LIST, compareInfo );

	PrintList( LIST, printInfo );

	LISTINFO* test1 =  (LISTINFO*)calloc(1, sizeof(LISTINFO));
	test1->p = (int*)calloc(1, sizeof(int));
	test1->p[0] = 9;
	
	LISTINFO* test2 = (LISTINFO*)calloc(1, sizeof(LISTINFO));
	test2->nKey = 3000;
	test2->p = (int*)calloc(1, sizeof(int));
	test2->p[0] = 30;

	ListItem* pPrev;
		
	Insert( Find( LIST, test1 ,&pPrev , compareInfo ) , test2);

	Remove(pPrev);

	PrintList( LIST, printInfo );

}

void freeInfo( const void* p )
{	
    if( !p )
	{
		perror( "Allocation Error ( freeInfo )" );
		return;
	}
    free( ( (LISTINFO*)p )->p );
	free( (LISTINFO*)p );
}

int compareInfo( const void* p , const void* q )
{
    if( !p && q ) return -1;
    else if( p && !q ) return 1;
    else if( !p && !q ) return 0;
      
    if( ( (LISTINFO*)p )->nKey < ( (LISTINFO*)q )->nKey )  return -1;
    else if( ( (LISTINFO*)p )->nKey > ( (LISTINFO*)q )->nKey ) return 1;
    else return 0;
}

void printInfo( const void* p )
{   
    if( !p )
	{
		perror( "Allocation Error ( printInfo )" );
		return;
	}
    printf( "%d", ( (LISTINFO*)p )->nKey );
}

void PrintList( ListItem* pList, void(__cdecl* printInfo)(const void*) )
{
	if( !pList || IsEmpty(pList) )
	{
		perror( "Allocation Error ( PrintList ) or queue is empty" );
		return;
	}

	while( pList->pNext )
	{
		printInfo( pList->pNext->pInfo );
		printf(" ");
		pList = pList->pNext;
	}
	printf("\n");
}