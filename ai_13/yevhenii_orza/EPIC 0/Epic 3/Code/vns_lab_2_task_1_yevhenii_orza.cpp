#include <iostream>
#include <cmath>
using namespace std;
unsigned long long Factorial(int n){
unsigned long long factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }

    return factorial;
}
int main (){
    int n;
    cin >> n;
    double num1 = pow(2, n) * Factorial(n);
    double num2 = pow(n, n);
    double result = num1 / num2;
    cout << result;
    return 0;
}