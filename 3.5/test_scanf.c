#include <stdio.h>

int main () {
   int a=0;
   int b=0;
    int length=0;
    scanf("%d",&length);
   
   for(int i=0;i<length;i++){
       scanf("%d %d",&a,&b);
        printf("%d,%d ",a,b);
   }
   

   return(0);
}