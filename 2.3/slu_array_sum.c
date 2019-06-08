#include <stdio.h>
#define MAX_N 100000
/*  A的位数最大可能为10万，故涉及大整数，
    此题考虑用字符数组存储大整数各位
*/
int main(void){
    int A, N, i, tempSum, remainder=0;
    int arr[MAX_N+1];
    scanf("%d%d", &A, &N);
    if(N==0){
        printf("0");
        return 0;
    }
    for(i=0; i<N; i++){ /*所有加数中权值相同的位求和，低位向高位进位*/
        printf("%d:tempSum=%d,remainder=\n", i, tempSum, remainder); 
        tempSum = A*(N-i)+remainder;
        /*  tempSum会越来越大，直到超过整型最大值?
            不会，因A*(N-i)<100,0000，remainder<10,0000,
            所以tempSum<110,0000
        */
        arr[i] = tempSum%10;
        remainder = tempSum/10;
    }
    if(remainder)
        arr[i] = remainder;
    else
        i--;
    for(;i>=0; i--){
        printf("%d", arr[i]);
    }

    return 0;
}