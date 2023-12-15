#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const double pi = 3.14;
    const long double e = 0.0001; 
    double a = pi / 5;
    double b = 9 * pi / 5;
    double krok = (b - a) / 10;
    long double S = 0;
    int n = 40;
    long double r = (b - a) / krok;
    int precision = -log10(e);


    //Task 1
        
        
    cout << "Task 1: " << endl;
    for (double x = a; x <= b; x += krok) {
        double y = -log(fabs(2 * sin(x / 2)));
        cout << "Pry x = " << x << ", to y = " << y << endl;
    }


    //Task 2


    cout << "Task 2: " << endl;
    for (long double x = a; x <= b + r / 2; x += r) 
    {
        for (int j=1; j<=n; j++) 
        {
            long double term = cos(j*x)/j;
            if (abs(term) >= e) 
            {
                S += term;
            } else 
            {
                break;
            }
        }
        cout.precision(precision);
        cout << "S(" << x << ") = " << S << endl;
    }


    return 0;
}