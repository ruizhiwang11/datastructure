#include <stdio.h>
#define MAXSIZE 100

void Reverse(int *arr, int left, int right);
int main(void){
    int n, m, i; /*含n个元素数组循环左移m个位置*/
    int *arr;
    scanf("%d%d", &n, &m);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    m = m%n; /*m可能大于n*/
    if(m){ /*不同段翻转三次即相当于循环左移*/
        Reverse(arr, 0, m-1);
        Reverse(arr, m, n-1);
        Reverse(arr, 0, n-1);
    }
    for(i=0; i<n; i++){
        if(i==0)
            printf("%d", arr[i]);
        else
            printf(" %d", arr[i]);
    }

    return 0;
}

void Reverse(int *arr, int left, int right){
    int temp;
    while(left<right){
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}
