#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SNode * PtrToSNode;
typedef 
struct SNode
{
    char *Data;
    int Top;
    int Maxsize;
    
};

typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize){
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data=(char *)malloc(MaxSize*sizeof(char));
    S->Top=-1;
    S->Maxsize=MaxSize;
    return S;
}
bool isFull(Stack S){
    return (S->Top ==S->Maxsize-1);
}
bool Push(Stack S, char x){
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

char Pop(Stack S){
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