#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct  Node 
{
    ElementType Data;
    PtrToNode Next;
    
};
typedef PtrToNode Position;

typedef struct QNode * PtrToQNode;

struct QNode
{
    Position Front;
    Position Rear;
    int MaxSize;
};

typedef PtrToQNode Queue;

bool IsEmpty(Queue Q)
{
    return (Q->Front == NULL);
}

ElementType DeleteQ(Queue Q){
    Position FrontCell;
    ElementType FrontElem;
    if(IsEmpty(Q)){
    printf("Queue is empty");
    return -1;
    }
    else
    {
        FrontCell =Q->Front;
        if(Q->Front == Q->Rear)
        Q->Front=Q->Rear=NULL;
        else 
        Q->Front=Q->Front->Next;
        FrontElem=FrontCell->Data;
        free(FrontCell);
        return FrontElem;
    }
    
}
