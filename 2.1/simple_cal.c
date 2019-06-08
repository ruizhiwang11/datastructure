#include <stdio.h>
#include <string.h>

int main(){
    int num=0;
    char operator='0';
    int temp=0;
    scanf("%d",&num);

    while (operator != '='){
        scanf("%c",&operator);
        if(operator=='=')
            break;
        scanf("%d",&temp);
        switch (operator){
            case '+': num=num+temp;
            break;
            case '-': num=num-temp;
            break;
            case '*': num=num*temp;
            break;
            case '/': 
                    if(temp==0){
                        printf("Error, divider cannot be 0");
                        return 0;
                    }
                    else{
                        num=num/temp;
                    }
            break;
            default:
                    printf("Wrong Operator");
                    return 0;

           operator=getchar();
        }

    }
    printf("%d",num);
    return 0;
}


