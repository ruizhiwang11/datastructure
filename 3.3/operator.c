#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.c"

#define MAXOP 100
#define INFINTY 1e9

typedef double ElementType;
typedef enum {num,opr,end } Type;

Type GetOp(char * Expr, int *start, char *str){
    int i=0;
    while((str[0]=Expr[(*start)++])==' ');
    while (str[i]!=' '&&str[i]!='\0')
    {
    str[++i]=Expr[(*start)++];
    }//jump the expression's space

    if(str[i]=='\0')
        (*start)--;     //read tile the end of the input , *start point to the end
    str[i]='\0';

    if(i==0) return end;
    else if(isdigit(str[0])||isdigit(str[1]))
    return num;
    else 
    return opr;    

}

ElementType PostFixExp(char *Expr){
    Stack S;
    Type T;
    ElementType Op1, Op2;
    char str[MAXOP];
    int start;

    S=CreateStack(MAXOP);
    Op1=Op2=0;
    while ((T=GetOp(Expr,&start,str))!=end)
    {
        if(T==num)
        Push(S,atof(str));
        else{
            if(!IsEmpty(S)) Op2=Pop(S);
            else Op2=INFINTY;
            if(!IsEmpty(S)) Op1=Pop(S);
            else Op2=INFINTY;
            switch (str[0])
            {
            case '+': Push(S,Op1+Op2); 
                
                break;
            case '*': Push(S,Op1*Op2);break;
            case '-': Push(S,Op1-Op2);break;
            case '/':
                    if(Op2!=0.0)
                    Push(S,Op1/Op2);
                    else{
                        printf("Error");
                        Op2=INFINTY;
                    }
                    break;
            
            default:
                printf("Cannot find operator");
                Op2=INFINTY;
                break;
            }
            if(Op2>=INFINTY) break;
        }
    }
    if(Op2<INFINTY)
        if(!IsEmpty(S))
            Op2=Pop(S);
        else
        {
            Op2=INFINTY;
        }

    free(S);
    return Op2;
            

}
int main(){
    char Expr[MAXOP];
    ElementType f;
    gets(Expr);
    f=PostFixExp(Expr);
    if(f<INFINTY){
        printf("%.4f\n",f);
    }
    else{
        printf("Error");
    }
    return 0;
}