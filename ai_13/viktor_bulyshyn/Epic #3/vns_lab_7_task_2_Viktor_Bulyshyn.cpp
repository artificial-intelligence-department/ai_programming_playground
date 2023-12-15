#include <iostream>
#include <cmath> // Use cmath for C++ standard functions

using namespace std;

// обчислення натурального логарифму
double NLog(double x) {
    return log(x);
}

// обчислення десяткового логарифму
double DLog(double x, int base) {
    return log(x) / log(base);
}

int main() {
    char c; // вибір

    cout << "What Logarithm do you want to calculate? (D-Decimal, N-Natural)" << endl;
    cin >> c;

    if (c == 'N' || c == 'n') {
        double arg;
        // використання для натурального логарифму
        cout << "Enter a value for natural logarithm: ";
        cin >> arg;
        double NLogR = NLog(arg);
        cout << "Natural Logarithm: " << NLogR << endl;
    } else {
        double arg;
        cout << "Enter a value for decimal logarithm: ";
        cin >> arg;
        int base;
        cout << "Enter the base for decimal logarithm: ";
        cin >> base;
        double DLogR = DLog(arg, base);
        cout << "Decimal Logarithm: " << DLogR << endl;
    }

    return 0;
}
