#include "FQUEUE.H"

int main()
{
    QFIFO* FIFO = QFCreate();
   
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
    
    QFEnqueue( FIFO, p1 );  // 1
    QFEnqueue( FIFO, p2 );  // 2                        
    QFEnqueue( FIFO, p3 );  // 3
    QFEnqueue( FIFO, p4 );  // 4
    
    printf( "%d\n", QFDequeue(FIFO)->n_Key );    // 1
    printf( "%d\n", QFDequeue(FIFO)->n_Key );    // 2        
    printf( "%d\n\n", QFDequeue(FIFO)->n_Key );  // 3
        
    QFEnqueue( FIFO, p5 );   // 5
    QFEnqueue( FIFO, p6 );   // 6
           
    QFClear( FIFO );     // 4,5,6
      
    QFEnqueue( FIFO, p7 );   // 7
    QFEnqueue( FIFO, p8 );   // 8
    QFEnqueue( FIFO, p9 );   // 9

    printf( "%d\n", QFDequeue(FIFO)->n_Key );  //  7

    QFRemove( &FIFO );

    return 2;
}

