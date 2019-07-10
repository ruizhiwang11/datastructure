#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../3.3/stack.c"
#include "../3.4/queue.c"

typedef int ElementType;
typedef struct TNode  *PtrToTNode;
typedef PtrToTNode BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;

};

void InorderTraversal(BinTree BT){
    if(BT){
        InorderTraversal (BT->Left);
        printf("%d",BT->Data);
        InorderTraversal(BT->Right);   //traversal from middle of the tree 

        // Sequence Left child -> root -> right child
    }
}

void InorderTraversal(BinTree BT){
    typedef BinTree ELementType;
    BinTree T;
    Stack S=CreateStack(100);
    
    T=BT;
    while(T||isEmpty(S)){
        while (T)
        {
            Push(S,T);
            T=T->Left;

            /* code */
        }
        T=Pop(S);
        printf("%d",T->Data);
        T=T->Right;
        
    }

}

#define NoInfo 0

BinTree CreatBinTree(){
    ElementType Data;
    BinTree BT,T;
    Queue Q=CreateQueue(100);

    scanf("%d",Data);
    if(Data !=NoInfo){
        BT=(BinTree)malloc(sizeof(struct TNode));
        BT->Data=Data;
        BT->Left=BT->Right=NULL;
        AddQ(Q,BT);
        
    }
    else return NULL;
    while (! IsEmpty(Q))
    {
        T=DeleteQ(Q);
        scanf("%d",&Data);
        if(Data==NoInfo) T->Left=NULL;
        else{
            T->Left=(BinTree)malloc(sizeof(struct TNode));
            T->Left->Data=Data;
            T->Left->Left=T->Left->Right=NULL;
            AddQ(Q,T->Left);
        }
        scanf("%d",&Data);
        if(Data==NoInfo) T->Right=NULL;
        else
        {
            T->Right=(BinTree)malloc(sizeof(struct TNode));
            T->Right->Data=Data;
            T->Right->Left=T->Right->Right=NULL;
            AddQ(Q,T->Right);
        }

        return BT;
        
        
        /* code */
    }
    
}


// Binary Search Tree!!!!


typedef BinTree Position;
Position Find(BinTree BST,ElementType X){
    if(!BST) return NULL;
    if(X>BST->Data)
    return Find(BST->Right,X);
    else if (X<BST->Data)
    return Find(BST->Left,X);
    else
        return BST;
    
}