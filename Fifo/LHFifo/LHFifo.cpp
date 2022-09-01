#include "FQUEUE.H"

int main()
{
    QFIFO* LHFIFO = QFCreate();
       
    QInfo* p1 = (QInfo*)calloc(1, sizeof(QInfo));
    QInfo* p2 = (QInfo*)calloc(1, sizeof(QInfo));
    QInfo* p3 = (QInfo*)calloc(1, sizeof(QInfo));
    QInfo* p4 = (QInfo*)calloc(1, sizeof(QInfo));
    QInfo* p5 = (QInfo*)calloc(1, sizeof(QInfo));
    QInfo* p6 = (QInfo*)calloc(1, sizeof(QInfo));
    QInfo* p7 = (QInfo*)calloc(1, sizeof(QInfo));
    QInfo* p8 = (QInfo*)calloc(1, sizeof(QInfo));
    QInfo* p9 = (QInfo*)calloc(1, sizeof(QInfo));

    if( !( p1 && p2 && p3 && p4 && p5 && p6 && p7 && p8 && p9 ) )
     {
        perror( "Allocation Error ") ;
        return 1;         
     }

    p1->n_Key = 1;
    p2->n_Key = 2;
    p3->n_Key = 3;
    p4->n_Key = 4;
    p5->n_Key = 5;
    p6->n_Key = 6;
    p7->n_Key = 7;
    p8->n_Key = 8;
    p9->n_Key = 9;
    
    QFEnqueue( LHFIFO, p1 );  // 1
    QFEnqueue( LHFIFO, p2 );  // 2                        
    QFEnqueue( LHFIFO, p3 );  // 3
    QFEnqueue( LHFIFO, p4 );  // 4
    
    printf( "%d\n", QFDequeue(LHFIFO)->n_Key );    // 1
    printf( "%d\n", QFDequeue(LHFIFO)->n_Key );    // 2        
    printf( "%d\n\n", QFDequeue(LHFIFO)->n_Key );  // 3
        
    QFEnqueue( LHFIFO, p5 );   // 5
    QFEnqueue( LHFIFO, p6 );   // 6
           
    QFClear( LHFIFO );     // 4,5,6
      
    QFEnqueue( LHFIFO, p7 );   // 7
    QFEnqueue( LHFIFO, p8 );   // 8
    QFEnqueue( LHFIFO, p9 );   // 9

    printf( "%d\n", QFDequeue(LHFIFO)->n_Key );  //  7

    QFRemove( &LHFIFO );

    return 2;
}