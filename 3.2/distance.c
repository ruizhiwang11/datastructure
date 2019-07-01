#include <stdio.h>
#define TOL 1E-2

double dist( double h, double p );

int main()
{
    double h, p, d;
    scanf("%lf %lf", &h, &p);
    d = dist(h, p);
    printf("%.6f\n", d);
    return 0;
}

double dist( double h, double p )
{
    double result;
    result=h;
    
    while (h>TOL){
        result=result+2*p*h;
        printf("%.6f\n",result);
        h=p*h;
        printf("%.6f\n",h);
        

        
    }
    return result;


}