#include <iostream>
#include <math.h>
using namespace std;

main()
{
    double a=100;
    double b=0.001;
    double c=pow(a-b, 4);
    double d=(pow(a,4)-4*pow(a,3)*b+6*pow(a,2)*pow(b,2));
    double e=(pow(b,4)-4*a*pow(b,3));
    double result=((c-d)/e);

    cout << result << endl;

    float a1=100.0;
    float b1=0.001;
    float c1=pow(a1-b1, 4);
    float d1=(pow(a1,4)-4*pow(a1,3)*b1+6*pow(a1,2)*pow(b1,2));
    float e1=(pow(b1,4)-4*a1*pow(b1,3));
    float result_01=((c1-d1)/e1);

    cout << result_01 << endl;


    return 0;
}