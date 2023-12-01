#include <iostream>
#include <math.h>
using namespace std;

int main () {
    double x, a, b, k, eps, n, sn, se, temp, y;
    n = 20;
    eps = 0.0001;
    k = 10;
    a = 0.1;
    b = 1;
    sn = se = y = 0;


    for(x = a; x <= b; x += (b-a)/k){

        sn = x;
        temp = x;
        se = 0;

        for(int i = 1; i <= n; i++){
            sn += sn * ((x * x)/((2*i) * (2*i + 1)));
        }

        int i = 1;
        while(abs(temp) > eps){
            se += temp;
            temp = temp * ((x * x)/((2*i) * (2*i + 1)));
            ++i;
        }

        y = (exp(x) - exp(-x)) / 2.0;
        
        cout << "X = " << x << " SN = " << sn << " SE = " << se << " Y = " << y << endl;

    }

    return 0;
}