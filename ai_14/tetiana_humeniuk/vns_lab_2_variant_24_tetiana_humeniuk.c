#include <stdio.h>  
#include<math.h>
int main()
{
    int n=9;
    double a=exp(-1);
    double sum=a;
    for(int i=2; i<n; ++i)
    {
        a = a*exp(-sqrt(n+1)+sqrt(n));
        sum += a;
    }
    printf("sum = %lf", sum);
}