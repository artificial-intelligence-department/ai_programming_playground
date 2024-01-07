#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double sum = 0.0, e = 0.0001;
    int n = 0;

    do{
        sum += (2*n-1)/(pow(2,n));
        n++;
    }
    while (sum < e);

    cout << sum << endl;
    return 0;
}
