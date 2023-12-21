#include<iostream>
#include<cmath>
#include <iomanip>

using namespace std;

int main() {
    long long n, i, fact;
    long double a;

    cout << "Enter n: ";
    cin >> n;
    fact = n;
    for(i=1 ; i<=n; i++){
        fact = fact * i;
    }

    a = fact / pow(n, sqrt(n));
    cout << "Answer: " << a;
    return 0;
}

