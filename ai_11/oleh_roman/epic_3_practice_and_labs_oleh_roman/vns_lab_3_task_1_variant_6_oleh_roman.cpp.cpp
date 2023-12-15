#include <iostream>
#include <cmath>
using namespace std;

long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return static_cast<long long>(n) * factorial(n - 1);
}

int main(){
    double y, eps = 0.0001, se, result,sn;
    int nse = 1;
    for(double x = 0.1; x <= 0.81; x += 0.07){
        result = 1.0;
        se = 0.0;
        nse=1;
        sn = 0.0;

        y = pow(exp(1.0), x * cos(M_PI/4)) *cos(x * sin(M_PI/4));
    
        do
        {
            se += result;
            result = (( cos((nse*M_PI)/4) * pow(x, nse)) / factorial(nse));
            nse++;
        } while (result > eps);
        

        result = 1.0;
        for(int n = 1; n <= 25; n++){
        sn += result;
        result = (( cos((n*M_PI)/4) * pow(x, n)) / factorial(n));
        }

        cout << "X=" << x << " SN="<< sn << " SE=" << se << " Y=" << y <<endl;
    }
    return 0;
}