#include <iostream>
#include <math.h>
using namespace std;

int main() {
    //float a, b, c, d, e,f; 
    //float ans;
    double a, b, c, d, e, f;
    double ans;

    a = 1000;
    b = 0.0001;

    c = pow((a-b), 2); // (a-b)^2
    d = pow(a, 2);     // a^2
    e = 2*a*b;         // 2ab
    f = pow(b, 2);     // b^2
    ans = (c-(d-e))/f;

    printf("; c= %lf; d= %lf; e= %lf; f= %lf; ans= %lf", c, d, e, f, ans);
    
    return 0;
}