#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode * PtrToLNode;
typedef int ElementType;

struct LNode
{
    ElementType data;
    PtrToLNode Next;

    
};

typedef PtrToLNode Position;
typedef PtrToLNode List;

ElementType Reverse_list(List L, int m){

    while(L->Next)

}

