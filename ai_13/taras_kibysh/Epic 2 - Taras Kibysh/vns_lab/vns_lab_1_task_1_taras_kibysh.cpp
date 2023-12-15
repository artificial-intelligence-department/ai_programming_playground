#include <cmath>
#include <iostream>
int main(){

using namespace std;

double a = 1000;
double b = 0.0001;
double c,d,f,e,g;
double result;


    c = pow((a + b),3);
    d = pow(a,3);
    f = 3*pow(a,2)*b;
    e = 3*a*pow(b,2);
    g = pow(b,3);
    result = (c - (d+f))/(e+g);
    cout<<result;



    return 0;
}