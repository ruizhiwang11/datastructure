#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );


List Merge(List L1,List L2){
    List MergeList, MergeListHead;
    MergeList=(List)malloc(sizeof(struct Node));
    MergeListHead=MergeList;
    while(L1&&L2){
        if(L1->Data>L2->Data){
            MergeList->Data=L2->Data;
            L2=L2->Next;
            MergeList=MergeList->Next;
            
        }

        else if(L1->Data<L2->Data)
        {
            MergeList->Data=L1->Data;
            L1=L1->Next;
            MergeList=MergeList->Next;
        }
        else{
            MergeList->Data=L1->Data;
            L1=L1->Next;
            L2=L2->Next;
            MergeList=MergeList->Next;

        }
    }
    for(;L1;L1=L1->Next){
        L1=L1->Next;
        MergeList=MergeList->Next;
    } 
    for(;L2;L2=L2->Next){
        L2=L2->Next;
        MergeList=MergeList->Next;
    } 
    MergeListHead=MergeListHead->Next;
    
}
List Read() /* 细节在此不表 */
{
    List p, tail, head;
    head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    p = head;
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        tail = (List)malloc(sizeof(struct Node));
        scanf("%d", &tail->Data);
        p->Next = tail;
        p = tail;
    }
    p->Next = NULL;
    return head;
}
void Print(List L)
{
    int f = 1;
    L = L->Next;
    while (L)
    {
        if (f)
        {
            printf("%d", L->Data);
            f = 0;
        }
        else
        {
            printf(" %d", L->Data);
        }
        L = L->Next;
    }
    puts("");

}
int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
