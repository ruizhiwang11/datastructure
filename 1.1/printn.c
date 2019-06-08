#include <stdio.h>
void PrintN1(int N);
void PrintN2(int N);

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d",&N);
    PrintN1(N);

    /* code */
    return 0;
}

void PrintN1(int N){
    int i;
    for(i=1;i<N;i++){
        printf("%d\n",i);

    }
    return;
}
void PrintN2(int N){
    if(N>0){
        PrintN1(N-1);
        printf("%d\n",N);
    }
}
