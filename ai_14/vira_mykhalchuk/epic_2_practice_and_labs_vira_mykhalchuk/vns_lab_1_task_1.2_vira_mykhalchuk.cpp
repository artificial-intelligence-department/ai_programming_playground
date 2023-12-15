#include <iostream>
#include <math.h>

using namespace std;

int main(){
    double a=1000, b=0.0001, c, d, e, f;

    c = pow(a+b,2);
    d = pow(a,2);
    e=2*a*b;
    f=pow(b,2);

    double g = (c-(d+e))/f; 

    cout << "double: " << g << endl;

    return 0;
} 