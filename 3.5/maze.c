#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXMATRIXSIZE 100
#define MAXSTACKSIZE 100

struct Offsets{
    short int Vert;
    short int Horiz;

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

void Path(int Maze[][MAXMATRIXSIZE],int EXITROW,int EXITCOL){
    struct Offsets Move[8]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    int Mark[MAXMATRIXSIZE][MAXMATRIXSIZE];
    Stack S;
    struct MazePosition P;
    short int Row ,Col, NextRow, NextCol, Dir;
    bool Found=false;

    S=CreateStack(MAXSTACKSIZE);
    Mark[EXITROW][EXITCOL]=1;
    P.Row=EXITROW;
    P.Col=EXITCOL;
    P.Dir=0;
    Push(S,P);

    while (!IsEmpty(S)&&!Found){
        P=Pop(S);
        Row=P.Row;
        Col=P.Col;
        Dir=P.Dir;
        while ((Dir<8 &&!Found))
        {
            NextRow=Row+Move[Dir].Vert;
            NextCol=Row+Move[Dir].Horiz;

            if(NextRow==1&&NextCol==1)
                Found=true;
            else
                if(!Maze[NextRow][NextCol] && !Mark[NextRow][NextCol]){


                }
                
            /* code */
        }
        
    }

}