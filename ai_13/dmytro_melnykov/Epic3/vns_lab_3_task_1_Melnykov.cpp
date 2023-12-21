#include <iostream>
#include <cmath>
using namespace std;


unsigned long long Factorial(int n)
{
unsigned long long factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }

    return factorial;
}

double func_for_y(double x) {
    double y = exp(x) - exp(-x) / 2.0;
    return y;
}

double func_for_sum(int n, double x) {
    double firstnumber = 1.0; 
    double sum = 1.0;

    for (int i = 1; i <= 20; i++) {
       double sum = pow(x,2*i+1)/Factorial(2*i+1);

        firstnumber += sum;
        
    }

    return firstnumber;
}

double SEpsilon(double epsilon, double x) {
    double result = 1.0;
    double term = 1.0;
    int i = 0;

    while (fabs(term) > epsilon) {
        term *= -1; 
        term *= (2 * i + 1) * (2 * i + 2);
        term /= (2 * i + 1) * (2 * i + 2); 
        term *= x * x; 
        term /= (2 * i + 2); 
        
        result += term;
        ++i;
    }

    return result;
}


int main() {

    for (double x = 0.1; x <= 1.0; x += 0.045) {
        cout << "x = " << x;
        double epsilon = 0.0001;
        

        cout << " SN = ";
        for (int i = 0; i < 20; i++) {
            double sum = func_for_sum(i, x);
            printf("%0.4f ", sum);
            break;
        }
         double resultEps = SEpsilon(epsilon, x);
         cout << "SE = " << resultEps;

        cout << " y = ";
        double y = func_for_y(x);
        printf("%0.4f\n", y);


    }

    return 0;
}
