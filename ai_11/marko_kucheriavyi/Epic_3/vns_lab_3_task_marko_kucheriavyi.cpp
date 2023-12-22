#include <iostream>
#include <cmath>
using namespace std;
double factorial(int n){
    double factorial = 1;
    for (int i = 0; i < n; i++){
        factorial*=(i + 1);
    }
    return factorial;
}
int main(){
    const double E = 0.0001, e = 2.71828;
    double  element;
    for (double x = 0.1; x <= 1; x += 0.1){
        double SumE = 0, SumN = 0, Y;
        Y = pow(e, cos(x)) * cos(sin(x));
        for (int n = 0; n <= 20; n++){
            SumN += cos(n*x) / factorial(n);
        }
        int m = 0;
        element = cos(m*x) / factorial(m);
        while (abs(element) > E){
            element = cos(m*x) / factorial(m);
            SumE += element;
            m++;
        }
        printf("x = %-3.1lf SN = %-8.5lf SE = %-8.5lf Y = %-8.5lf \n", x, SumN, SumE, Y);
    }
    return 0;
}