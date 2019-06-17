#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct PolyNode
{
    int coef;
    int expon;
    struct PolyNode *link;
};
typedef struct PolyNode *Polynomial;

int compare (int e1,int e2){
    if(e1>e2) return 1;
    else if(e1<e2) return -1;
    else return 0;
}
void Attach(int coef,int expon,Polynomial *PtrRear){
    Polynomial P;
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    P->coef=coef;
    P->expon=expon;
    P->link=NULL;
    (*PtrRear)->link=P;
    *PtrRear=P;
}
Polynomial PolyAdd(Polynomial P1, Polynomial P2){
    Polynomial front, rear,temp;
    int sum;
    rear=(Polynomial)malloc(sizeof(struct PolyNode));
    front=rear;
    while (P1&&P2)
    {   
        switch (Compare(P1->expon,P2->expon))
        {
        case 1:
                Attach(P1->coef,P2->coef,&rear);
                P1=P1->link;
            /* code */
            break;
        case -1:
                Attach(P2->coef,P2->coef,&rear);
                P2=P2->link;
                break;
        case 0:
                sum=P1->coef+P2->coef;
                if(sum) Attach(sum,P1->expon,&rear);
                P1=P1->link;
                P2=P2->link;
                break;

        default:
            break;
        }
        for(;P1;P1=P1->link) Attach(P1->coef, P1->expon,&rear);
        for(;P2;P2=P2->link) Attach(P2->coef, P2->expon,&rear);
        rear -> link =NULL;
        temp=front;
        front=front->link;
        free(temp);
        return front;

    }
    
}
Polynomial Mult(Polynomial P1,Polynomial P2){
    Polynomial t1,t2,P,Rear,t;
    int c,e;
    P=(Polynomial)malloc(sizeof(struct PolyNode)); P->link=NULL;
    Rear=P;
    while (t2){
        Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
        t2=t2->link;
    }
    t1=t1->link;
    while(t1){
        t2=P2;
        Rear=P;
        while(t2){
            e=t1->expon+t2->expon;
            c=t1->coef*t2->coef;
            while(Rear->link&&Rear->link->expon>e)
            {
                Rear=Rear->link;

            }
            if(Rear->link&&Rear->link->expon==e){
                if(Rear->link->coef+c)
                    Rear->link->coef+=c;
                else{
                    t=Rear->link;
                    Rear->link=t->link;
                    free(t);
                }

                

            }
            else{
                t=(Polynomial)malloc(sizeof(struct PolyNode));
                t->coef=c;
                t->expon=e;
                t->link=Rear->link;
                Rear->link=t;
                Rear=Rear->link;
            }
            t2=t2->link;
        }
        t1=t1->link;
    }
    t2=P;
    P=P->link;
    free(t2);
    return P;

}
void PrintPoly(Polynomial P){
    int flag=0;
    if(!P){
        printf("0 0\n");
        return;
    }
    while (P)
    {
        if(!flag)
            flag=1;
        else
            printf("");
        printf("%d %d",P->coef,P->expon);
        P=P->link;

        
    }
    
}