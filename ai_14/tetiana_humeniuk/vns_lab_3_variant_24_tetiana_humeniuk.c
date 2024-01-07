#include <stdio.h>  
#include <math.h>
int main()
{
    int n=40;
    int k=10; 
    double e=0.0001; 
    double a=-2;
    double b=-0.1;
    double dx=(b-a)/k;
    double dS=1;
    double x=a;
    while(x<=b)
    {
        double a = -pow(1+x, 2);
        double sum_n = a;
        //for n
        for(int i=2; i<n; ++i)
        {
           a = a*(-n*(1+x)/n+1);
           sum_n += a; 
        }
        a = -pow(1+x, 2);
        double sum_e = a;
        //for е
        int i = 0;
        while(fabs(a)>e)
        {
            i++;
            a = a*(-n*(1+x)/n+1);
            sum_e += a;
            printf("a=%f\n", a);
        }
        double y = log(1/(2+2*x+x*x));
        printf("X=%f , SN=%f , SE=%f ,Y=%f, i= %f\n", x, sum_n, sum_e, y, i );
        x+=dx;
    }
}
