#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a = 3.2;  // Критерій 2: використана як мінімум одна дійсна змінна
    double b = 17.5;
    double x = -4.8;

    double Y = pow(b, 3) * pow(tan(x), 2)  - (a / pow(sin(x / a), 2));// Критерій 15: використано математичні операції та математичні функції

    double sqrt3 = sqrt(3);
    double Z = a * exp(-sqrt3) * cos(b * x / a);// Критерій 3: використана як мінімум одна дійсна з подвійною точністю змінна

    cout << "Y = " << Y << endl; 
    cout << "Z = " << Z << endl;

    return 0;
}
