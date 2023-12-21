#include <iostream>
#include <cmath>
using namespace std;


int factorial(int m) {
    if (m == 0 || m == 1) {
        return 1;
    } else {
        return m * factorial(m - 1);
    }
}


int main() {
    double a = 0.1, b = 1, eps = 0.0001;
    int n = 25, k = 10;
   
    for (int i=0; i<=k; ++i) {
        double x=a+ i*(b-a)/k;
        double sumN=1;
        double termN=1;
       
        for(int h=1; h<=n; ++h)
        {
            termN*= pow(x,h)*cos(M_PI*h/4)/factorial(h);
            sumN += termN;
        }


        double sumEps = 1;
        double termEps = 1;
        int h = 1;


        while(true)
        {
            termEps *= pow(x,h)*cos(M_PI*h/4)/factorial(h);
            if (termEps < eps)
                break;
            sumEps += termEps;
            ++h;
        }


        double y=exp(x*cos(M_PI/4))*cos(x * sin(M_PI / 4));




        cout
            << "X: " << x
            << "SN: " << sumN
            << "SE: " << sumEps
            << "Y: " << y
                << endl;


    }


    return 0;
}
