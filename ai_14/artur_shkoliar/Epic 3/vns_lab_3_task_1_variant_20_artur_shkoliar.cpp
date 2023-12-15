#include <iostream>
#include <cmath>

using namespace std;

int factorial(int l)
 {
    if (l == 0 || l == 1) 
    {
        return 1;
    } 
    else 
    {
        return l * factorial(l - 1);
    }
}

int main() {
    double epsilon = 0.0001;
    double e = 2.71;
    double a = 0.1;
    double b = 1;
    double sumE = 0;
    double sumN = 0;
    int iterN = 30;

    for (double x = a; x <= b; x += (b - a) / 10) {
        sumE = 0;
        sumN = 0;

        
        for (int k = 0; k < iterN; k++) 
        {
            double term = 1;
            for (int i = 1; i <= k; ++i) 
            {
                term *= (x / 2);
            }
            double n = ((pow(k, 2) + 1) / factorial(k)) * term;
            sumN += n;
        }

       
        int k = 0;
        double n = 1; 
        do
        {
            double term = 1;
            for (int i = 1; i <= k; ++i) 
            {
                term *= (x / 2);
            }
            n = ((pow(k, 2) + 1) / factorial(k)) * term;
            sumE += n;
            ++k;
        } 
        while (abs(n) >= epsilon);

        cout << "X: " << x << " SumE: " << sumE << " SumN: " << sumN << " Y: " << (pow(x, 2) / 4 + x / 2 + 1) * pow(e, x / 2) << endl;
    }

    return 0;
}
