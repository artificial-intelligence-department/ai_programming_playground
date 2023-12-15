#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return(fibonacci(n - 1) + fibonacci(n - 2));
}

int main() {
    int n;
    cout << "enter count of first elements" << endl;
    cin >> n;
    cout << "Fibonacci values: ";
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int fib = fibonacci(i);
        cout << fib << " ";
        sum += fib;
    }
    cout << endl << "sum of fibonacci series: " << sum << endl;
    return 0;
}