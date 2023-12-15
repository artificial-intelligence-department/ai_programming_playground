#include <iostream>
using namespace std;

double calculateFunction(double x) {
    return (-2.4) * x + 5 * x - 3;//В коді використано математичні операції та математичні функції 
}

int main() {
    double start = -2.0;
    double end = 2.0;
    double step = 0.5;//В коді використана як мінімум одна дійсна з подвійною точністю змінна

    cout << "x        y" << endl;
    cout << "----------------" << endl;

    for (double x = start; x <= end; x += step) {//В коді використаний for цикл
        double y = calculateFunction(x);
        cout << x << "     " << y << endl;
    }

    return 0;
}