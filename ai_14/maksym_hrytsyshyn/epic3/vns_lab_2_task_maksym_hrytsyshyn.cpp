#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double epsilon = 0.0001;
    double An; 
    int n=0;
    double sum=0;

    while (true) {
        An=1/pow(2,n) + 1/pow(3,n);
        if (An < epsilon) break;
        sum += An;
        n++;
    }

    cout << "The sum of the series with precision to epsilon=0.0001 is equal to " << sum << endl;
}