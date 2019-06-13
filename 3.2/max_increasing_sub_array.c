#include <stdio.h>
typedef int Position;
typedef struct LNode *PtrToLNode;
typedef int ElementType;
typedef int bool;
#define MAXSIZE 100
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last;
    
};

typedef PtrToLNode List;
List Read(List L);
void PrintSeq(List L);

int main(void){

    List L;
    int n=0, i=0;
    scanf("%d", &n);
    L->Last = n;
    for(i=0; i<n; i++){
        scanf("%d", &L->Data[i]);
    }
    PrintSeq(L);
    return 0;
}

void PrintSeq(List L){
    int maxL, maxR, maxLen, l, r, len;
    int i;
    if(L->Last==0)
        return;
    else{
        maxL=maxR=0;
        maxLen = 1;
    }
    l=r=0;
    len = 1;
    for(i=1; i<L->Last; i++){
        if(L->Data[i]>L->Data[i-1]){
            r++;
            len++;
        }
        else{ 
            if(len>maxLen){
                maxL = l;
                maxR = r;
                maxLen = len;
            }
            l=r=i;
            len = 1;
        }
    }
    if(len>maxLen){ 
        maxL = l;
        maxR = r;
        maxLen = len;
    }

    for(i=maxL; i<=maxR; i++){
        if(i==maxL)
            printf("%d", L->Data[i]);
        else
            printf(" %d", L->Data[i]);
    }
}

