#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) 
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int number;

    cout << "enter: ";
    cin >> number;
    if (number < 0) 
        cout << "enter + number." << endl;
    else {
        int result = factorial(number);
        cout << "factorial of " << number << " is: " << result << endl;
    }

    return 0;
}
