#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

ElementType Find( List L, int m );

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L,m));
    Print(L);
    return 0;
}
ElementType Find( List L, int m ){
    int Count=1;
    List P, tmp;
    P=L;
    while(L->Next){
        Count++;
    }
    int Po=Count-m+1;
    while(Po--){
        tmp=P;
        P=tmp->Next;
        
    }
    return P->Data;

}