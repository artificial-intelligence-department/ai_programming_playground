#include <iostream>
#include <cmath>
using namespace std;

double Factorial(int i) {
    double f=1;
    for (int j=1; j<=i; j++) {
        f*=j;
    }
    return f;
}

int main () {
    double x, sn=0, se=0, y=0, a=0.1, b=1, eps=0.0001;
    int n=10, k=10;
    double e = exp(1.0) ;

    for (x=a; x<=b; x+=((b-a)/k)) {

        for (int i=0; i<n; i++) {
            sn += ((2*i+1)/(Factorial(i))*pow(x,2*i));
        }

        int l=0;
        double t=1;
        while (abs(t)>= eps) {
            se += t;
            t -= ((2*l+1)/(Factorial(l))*pow(x,2*l));
            l++;
        }

        y = (1+2*pow(x,2))*pow(e,pow(x,2));

        

        cout << "X = " << x << " SN = " << sn << " SE = " << se << " Y = " << y << endl;

        
    }

    return 0;
    
}