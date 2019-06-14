#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};

typedef int bool;
typedef PtrToLNode Position;
typedef PtrToLNode List;
#define true 0
#define false 1


bool Delete(List L,int i)
{
    Position tem, pre;
    int cnt=0;
}