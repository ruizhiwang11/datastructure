#include <stdio.h>

int main(){
    int length=0;
    int input=0;
    int temp=0;
    int move=0;
    int space=40;

    scanf("%d %d",&length,&input);
    int array[length];
    int array_mo[length];
    move=input%length;
    for(int i=0;i<length;i++){
        scanf("%d",&array[i]);
    }
    for(int j=0;j<length;j++){
        temp=j-move;
        if(temp<0){
            temp=temp+length;
        }
        array_mo[temp]=array[j];
    }
    for(int i=0;i<length;i++){
        printf("%d\t",array_mo[i]);
    }
    
 
}



