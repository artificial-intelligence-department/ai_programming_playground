#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
    double a = -1.0; 
    double b = 1.0;
    int k = 10;
    double epsilon = 0.0001;

    int taylorElements = 0;

    cout << "Enter count of taylor elements: ";
    cin >> taylorElements;

    cout << "Function calculation:\n";
    for (int step = 0; step <= k; ++step) {
        double x = a + step * (b - a) / k;
        double exact = (exp(x) + exp(-x)) / 2.0;


        double resultWithN = 1.0;
        double term = 1.0;

        for (int i = 1; i <= taylorElements; ++i) {
            term *= x / i;
            resultWithN += term;
        }
        double approximationN = resultWithN;

        double resultWithE = 1.0;
        term = 1.0;
        int i = 1;

        while (abs(term) > epsilon) {
            term *= x / i;
            resultWithE += term;
            i++;
        }
        double approximationEpsilon = resultWithE;

        
        cout << "X=" << setw(6) << x << " ";
        cout << "SN=" << setw(10) << approximationN << " ";
        cout << "SE=" << setw(10) << approximationEpsilon << " ";
        cout << "Y=" << setw(10) << exact << "\n";
    }

    return 0;
}