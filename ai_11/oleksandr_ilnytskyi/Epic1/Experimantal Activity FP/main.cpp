#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int number;
    int power;

    cout << "Enter number: ";
    cin >> number;

    cout << "Enter power: ";
    cin >> power;

    int result = number;

    for (int i = 1; i < power; i++) {
        result *= number;
    }

    cout << result << endl;
}