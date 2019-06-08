#include <stdio.h>

typedef struct Node *PtrToNode;
struct Node{
    int Data;
    PtrToNode Next;
};