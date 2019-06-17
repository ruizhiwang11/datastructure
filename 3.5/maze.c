#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXMATRIXSIZE 100
#define MAXSTACKSIZE 100

struct Offsets{
    short int Vert;
    short int Horize;

};
struct MazePosition{
    short int Row;
    short int Col;
    short int Dir;
};
typedef struct MazePosition ElementType;
typedef int Position;
typedef struct SNode *PtrToSNode;



struct SNode
{
    ElementType *Data;
    Position Top;
    int MaxSize;
};

typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize){
    Stack S=(Stack)malloc(sizeof(struct SNode));
    S->Data=malloc(MaxSize *sizeof(ElementType));
    S->Top = -1;
    S->MaxSize=MaxSize;
    return S;
}
bool isFull(Stack S){
    return (S->Top ==S->MaxSize-1);
}
bool Push(Stack S, ElementType x){
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

ElementType Pop(Stack S){
    ElementType ERROR={-1,-1,-1};
    if(IsEmpty(S)==true){
        printf("Stack is Empty");
        return ERROR;

    }
    else
    {
        return (S->Data[(S->Top)--]);
        
    }
    
}

int main(){
    printf("haha");
}