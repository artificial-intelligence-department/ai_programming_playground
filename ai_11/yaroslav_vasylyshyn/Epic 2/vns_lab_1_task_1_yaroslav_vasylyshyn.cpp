#include <iostream>
#include <math.h>
using namespace std;


int main(){
    //Task 1
    double a=100,b=0.001;
    double q=pow((a-b), 4);
    double w=pow(a, 4);
    double e=(4*pow(a, 3)*b);
    double r=(6*pow(a, 2)*pow(b, 2));
    double t=(4*a*pow(b, 3));
    double y=(pow(b, 4));
    double res=((q-(w-e))/(r-t+y));
    printf("%.8lf", res);
    cout<<'\n';

    return 0;
}