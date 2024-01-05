#include <stdio.h>  
#include <math.h>

double side_length(int x1, int y1, int x2, int y2)
{
    double length = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    return length;
}

double square(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return fabs(x1*y2 + x2*y3 + x2*y1 - y1*x2 - y2*x3 - y3*x1)/2;
}

double squaren(int count, ...)
{
    va_list args;
    va_start(args, count);
    int x[(int) count/2];
    int y[(int) count/2];
    for(int i, i<(int) count/2, i+=2)
    {
        x[i] =  va_arg(args, int);
        y[i+1] = va_arg(args, int);
    }

    return (x1*y2 + x2*y3 + x2*y1 - y1*x2 - y2*x3 - y3*x1)/2;
}

int main()
{
    //int
    //scanf()
    double l = side_length(1,2,3,4);
    double s = square(1,2,3,4,5,6);
    double sn = squaren();
    printf("%f", l);
    printf("%f", s);
}