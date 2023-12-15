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
    const double a=0.1;
    const double b=1;
    const int n=25;
    const int k=10;
    const double eps=0.0001;

    for (int i=0; i<=k; ++i) {
        double x=a+ i*(b-a)/k;
        double sumN=1;
        double termN=1;
        
        for(int h=1; h<=n; ++h) {
        termN*= pow(x,h)*cos(M_PI*h/4)/factorial(h);
        sumN += termN;
        }

        double sumEps = 1;
        double termEps = 1;
        int h = 1;

        while(true) {
            termEps *= pow(x,h)*cos(M_PI*h/4)/factorial(h);
            if (termEps < eps) break;
            sumEps += termEps;
            ++h;
        }

        double y=exp(x*cos(M_PI/4))*cos(x * sin(M_PI / 4));


        cout << "x=" << x << "   Series at n = " << sumN << "    Series with epsilon = " << sumEps << "   y = " << y << endl;

    }

    return 0;
}