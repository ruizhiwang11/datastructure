#include <stdio.h>
#include <stdlib.h>
typedef int Position;
typedef struct LNode *PtrToLNode;
typedef int ElementType;
typedef int bool;
#define true 0
#define false -1
#define MAXSIZE 10
#define ERROR -1
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last;
    
};

typedef PtrToLNode List;

List MakeEmpty(){
    List L;
    L=(List)malloc(sizeof(struct LNode));
    L->Last=-1;
    return L;
}
Position Find(List L,ElementType x){
    Position i=0;
    while(i<=L->Last &&L->Data[i]!=x)
        i++;
    if(i>L->Last) return ERROR;
    else
    {
         return L;
    }
    
}

bool Insert(List L, ElementType x, int i){
    Position j;
    if(L->Last==MAXSIZE-1){
        printf("List is full");
        return false;
    }
    if(i<1||i>L->Last+2){
        printf("Wrong Position");
        return false;
    }
    for(j=L->Last;j>=i-1;j--)
        L->Data[j+1]=L->Data[j];
    L->Data[i-1]=x;
    L->Last++;
    return true;
}
bool Delete(List L, int i){
    Position j;
    if(i<1||i>L->Last+1){
        printf("NUMBER %d not exist",i);
        return false;

    }
    for(j=i;j<L->Last;j++){
        L->Data[j-1]=L->Data[j];
    L->Last--;
    return true;
    }
}

