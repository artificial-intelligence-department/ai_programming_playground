#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 1, factorial = 1;
    double e = 0.0001, a, a1 = 1, sum = 0;

    while(a1 >= e){

        factorial *= n;
        
        a = pow(factorial, 2) / pow(2, pow(n, 2));

        a1 = a*(pow(n+1, 2)/ pow(2, 2*n + 1));

        sum += a;
        n++;
    }
    cout << sum << endl;
} 