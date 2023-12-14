#include <iostream>
#include <cmath>
using namespace std;
int main() {
    // Задані значення
    double a = -0.5;
    double b = 1.7;
    double t = 0.44;

    // Обчислення виразу y
    double y = exp(-b * t) * sin(a * t + b) - sqrt(fabs(b * t + a));

    // Обчислення виразу s
    double s = b * sin(a * pow(t, 2) * cos(2 * t)) - 1;

    // Вивід результатів
    cout << "y = " << y << endl;
    cout << "s = " << s << endl;
    return 0;
}