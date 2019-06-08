#include <stdio.h>
#include <time.h>
#include <math.h>

clock_t start , stop;
double duration;
#define MAXN 10
#define MAXK 1e7

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

double f1 (int n ,double a[] , double x){

int i;
double p=a[0];
for (i=1;i<=n;i++){
p+=(a[i]*pow(x,i));
return p;    
}
}
double f2()