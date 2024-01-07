#include <iostream>
#include <cmath>

using namespace std;

int main() {
double a, b, shi;
cout << "Введіть значення a: ";
cin >> a;
cout << "Введіть значення b: ";
cin >> b;
shi = pow((a - b), 4) - ((pow(a, 4) - (4 * pow(a, 3) * b) + 6 * pow(a, 2) * pow(b, 2)) / pow(b, 4)) - 4 * a * pow(b, 3);
cout << "Результат обчислення: " << shi << endl;

    return 0;
}
