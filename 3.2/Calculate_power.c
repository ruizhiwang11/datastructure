#include <stdio.h>
#include <math.h>

double fn( double x, int n );

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.2f\n", fn(x,n));

    return 0;
}
double fn( double x, int n ){
    if(n==1){
        return x;
    }
    else{
        return fn(x,n-1)+pow(-1,n-1)*pow(x,n);
    }
}