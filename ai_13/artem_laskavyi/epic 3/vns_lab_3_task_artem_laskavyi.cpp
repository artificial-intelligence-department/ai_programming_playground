#include <cmath>
#include <stdio.h>
using namespace std;

const double epsilon = 0.0001;
double e =  exp(1.0);

// recursive formula: a(n+1) = a(n) * x^2/(4n^2+6n+2)
double Calc (double a, double x, int n){
    double result = a*(pow(x, 2) / (4*pow(n, 2) + 6*n + 2));
    return result;
} 

int main(){

    for (double x = 0.1; x < 1; x += 0.09){
        printf("X = %.2lf   ", x);

        double a = 1.0, y;
        int n = 1;
        double SN = a, SE = a;

        for (int n = 1; n <= 10; n++){
            a = Calc(a, x, n);
            SN += a;
            n++;
        }
        printf("SN = %.5lf   ", SN);

        a = 1.0;
        n = 1;

        while (a > epsilon){
            a = Calc(a, x, n);
            SE += a;
            n++;
        }
        y = (pow(e, x) + pow(e, -x))/2;
        printf("SE = %.5lf   ", SE);
        printf("Y = %.5lf \n", y);
    }

    return 0;
}