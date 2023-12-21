#include <iostream>
#include<math.h>

using namespace std;

int factorial(int k) {
    if (k <= 1) {
        return 1;

    }
    else {

        return k * factorial(k - 1);
    }
}


int main()
{
    double e = 0.0001;
    double sum = 0.0;
    double a = 0.0;
    int k = 1;

    do {
        a = log10(factorial(k)) * exp(-k * sqrt(k));
        sum += a;
        k++;
    } while ((log10(factorial(k)) * exp(-k * sqrt(k))) >= e);

    cout << sum;
}
