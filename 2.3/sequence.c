#include<stdio.h>
#define MAXSIZE 100
void print_array(int arr[],int length);
void swap(int *a,int *b);
void perm(int arr[],int index,int length);

int main(){
    int array[MAXSIZE];
    int length=0;
    scanf("%d",&length);

    for(int i=1;i<=length;i++){
        array[i-1]=i;
    }
    perm(array,0,length);
    return 0;


}

void print_array(int arr[],int length){
    for(int i=0;i<length;i++){
        printf("%d",arr[i]);

    }
    printf("\n");

}

void swap(int *a,int *b){
    int temp=*a;
    *a= *b;
    *b= temp;
}
void perm(int arr[],int index,int length){
    int j=0;
    if(index==length){
        print_array(arr,length);
    }
    else{
        for(j=index;j<length;j++){
        swap(&arr[j],&arr[index]);
        perm(arr,index+1,length);
        swap(&arr[j],&arr[index]);
    }

    }

}
