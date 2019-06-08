#include <stdio.h>
#include <math.h>
int sum_array(int num,int repeat);
int main(){
    int num=0;
    int repeat=0;
    int sum=0;
    scanf("%d %d",&num,&repeat);
    for(int i=1;i<=repeat;i++){

        sum=sum+sum_array(num,i);

    }
    printf("%d",sum);
}

int sum_array(int num,int re){    
    if(re==1){
        return num*pow(10,re-1);
    }
    else
    {
        return num*pow(10,re-1)+sum_array(num,re-1);
    }  
}