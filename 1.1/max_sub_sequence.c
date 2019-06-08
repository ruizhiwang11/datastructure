#include <stdio.h>

int max_sub_sequence2(int a[],int n );
int main(int argc, char const *argv[])
{
    int num=0;
    scanf("%d",&num);
    int *array;
    for(int i =0;i<num;i++)
        scanf("%d",&array[i]);
        
    printf("%d",max_sub_sequence2(array,num));
    
    return 0;
}
int max_sub_sequence2(int a[] , int n){
    int i;
    int ThisSum, MaxSum;
    ThisSum=MaxSum=0;
    for(i=0;i<n;i++){
        ThisSum+=a[i];
        if(ThisSum>MaxSum)
        MaxSum=ThisSum;
        else if(ThisSum<0)
        ThisSum=0;
    }
    return MaxSum;
}

