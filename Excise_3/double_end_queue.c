#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef enum { push, pop, inject, eject, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;      /* 存储元素的数组   */
    Position Front, Rear;   /* 队列的头、尾指针 */
    int MaxSize;            /* 队列最大容量     */
};
typedef PtrToQNode Deque; 

Deque CreateDeque( int MaxSize )
{   
    Deque D = (Deque)malloc(sizeof(struct QNode));
    MaxSize++;
    D->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    D->Front = D->Rear = 0;
    D->MaxSize = MaxSize;
    return D;
}

bool Push( ElementType X, Deque D );
bool isFull(Deque D);
bool isEmpty(Deque D);
ElementType Pop( Deque D );
bool Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

bool notFull(Deque D){
    return (D->Rear - D->Front + D->MaxSize)%D->MaxSize != (D->MaxSize - 1);
}
bool notEmpty(Deque D){
    return D->Rear != D->Front;
}
bool Push( ElementType X, Deque D )
{
    if(notFull(D))
    {
        D->Front = (D->Front - 1 + D->MaxSize)%D->MaxSize;
        D->Data[D->Front] = X;
        return true;
    }
    else return false;
    
}
ElementType Pop(Deque D){
    if(notEmpty(D)){
        ElementType a = D->Data[D->Front];
        D->Front = (D->Front + 1)%D->MaxSize;
        return a;
    }
}
