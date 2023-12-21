#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n = 20;
    double SN, SE, Y, epsilon = 0.0001;
    double a = 0.1, b = 1;

    for (double x = a; x <= b; x += 0.1) {
        SN = 0;
        SE = 0;
       
        for (int i = 0; i <= n; i++) {
            double term = pow(2 * x, i) / tgamma(i + 1); 
            SN += term;
        }

        
        int N = 0;
        double term = pow(2 * x, N) / tgamma(N + 1);
        while (abs(term) >= epsilon) {
            SE += term;
            N++;
            term = pow(2 * x, N) / tgamma(N + 1);
        }

        
        Y = exp(2 * x);

        
        cout << "X = " << x << "\tSN = " << SN << "\tSE = " << SE << "\tY = " << Y << endl;
    }

    return 0;
}
