#include <iostream>
using namespace std;

// S = 1/2 * a * ha
int main() {
    double a, ha;
    cout << "Сторона (см): ";
    cin >> a;
    cout << "Висота (см): ";
    cin >> ha;

    double S = 0.5 * a * ha;
    cout << "Площа: " << S << " см^2" << endl;

    return 0;
}