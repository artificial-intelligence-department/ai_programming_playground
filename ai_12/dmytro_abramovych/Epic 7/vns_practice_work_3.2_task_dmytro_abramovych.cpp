// 1
#include <iostream>
using namespace std;

int main() {
    double pounds;
    cout << "Enter pounds: ";
    cin >> pounds;

    const double kg = pounds * 0.453592;
    cout << "Kilograms: " << kg << "\n";

    return 0;
}
