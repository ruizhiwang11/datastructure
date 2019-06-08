#include <stdio.h>
#include <stdlib.h>

int main(){
    int length=0;
    int number_left=0;
    int *array;
    int array_temp[100];
    
    scanf("%d" "%d", &length,&number_left);
    for(int i=0;i<length;i++){
        scanf("%d",&array[i]);
        array_temp[i]=0;
    }
    printf("some bug");
    for(int i=0;i<length;i++){
         int temp=i-number_left;
         
         if(temp<0){
             temp=temp+length;
         }
        
       array_temp[i]=array[temp];
         
    }
   
    for(int j=0;j<length;j++){
        printf("%d ",array_temp[j]);
    }

}