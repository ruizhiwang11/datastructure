#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Position;
typedef int ELementType;
typedef struct SNode *PtrToSNode;



struct SNode
{
    ELementType *Data;
    Position Top;
    int MaxSize;
};

typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize){
    Stack S=(Stack)malloc(sizeof(struct SNode));
    S->Data=(ELementType)malloc(MaxSize *sizeof(ELementType));
    S->Top = -1;
    S->MaxSize=MaxSize;
    return S;
}
bool isFull(Stack S){
    return (S->Top ==S->MaxSize-1);
}
bool Push(Stack S, ELementType x){
    if(isFull(S)){
        printf("Stack is full");
        return false;
    }
    else
    {
        S->Data[++(S->Top)]=x;
        return true;
    }
    
}
bool IsEmpty(Stack S){
    return(S->Top==-1);
}

ELementType Pop(Stack S){
    if(IsEmpty==true){
        printf("Stack is Empty");
        return false;

    }
    else
    {
        return(S->Data[(S->Top)--]);
        return true;
    }
    
}