#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n = 2; // Початкове значення n для початку ряду
    double a, sum = 1, e = 0.0001;
    a = n / pow((n - 1), 2);

    while (a >= e) {
        sum += a;
        n++;
        a = n / pow((n - 1), 2);
    }

    cout << "Сума: " << sum << endl;

    return 0;
}
