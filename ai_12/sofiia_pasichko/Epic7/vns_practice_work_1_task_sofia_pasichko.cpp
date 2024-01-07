#include <iostream> // підключення бібліотеки для вводу та виводу
#include <cmath> // підключення бібліотеки для математичних операцій
using namespace std;

int main() {
    float x=0.25, y=0.79, z=0.81; // ініцілізація змінних
    float P, Q;
    P=(1 + pow(sin(x+1), 2))/(2 + abs(x - 2*pow(x, 3)/((1 + pow(x, 2)*pow(y, 3))))) + pow(x, 4); // обчислення значення P за формулою
    Q=pow(cos(atan(1 / z)), 2); // обчислення значення Q за формулою

    cout << P << endl;
    cout << Q << endl; // ввиведення обчислених значень
    return 0;
}