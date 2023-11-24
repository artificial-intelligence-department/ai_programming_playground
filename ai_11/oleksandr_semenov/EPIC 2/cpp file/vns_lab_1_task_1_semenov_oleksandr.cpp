#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a_float, b_float;
    cout << "Введіть значення a (float): ";
    cin >> a_float;
    cout << "Введіть значення b (float): ";
    cin >> b_float;

    float result_float;
    float numerator_float = pow(a_float + b_float, 3) - (pow(a_float, 3) + 3 * pow(a_float, 2) * b_float);
    float denominator_float = 3 * a_float * pow(b_float, 2) + pow(b_float, 3) + 3 * pow(a_float, 2) * b_float;

    if (denominator_float != 0) {
        result_float = numerator_float / denominator_float;
        cout << "Результат (float): " << result_float << endl;
    } else {
        cout << "Помилка: Ділення на нуль" << endl;
    }

    double a_double, b_double;
    cout << "Введіть значення a (double): ";
    cin >> a_double;
    cout << "Введіть значення b (double): ";
    cin >> b_double;

    double result_double;
    double numerator_double = pow(a_double + b_double, 3) - (pow(a_double, 3) + 3 * pow(a_double, 2) * b_double);
    double denominator_double = 3 * a_double * pow(b_double, 2) + pow(b_double, 3) + 3 * pow(a_double, 2) * b_double;

    if (denominator_double != 0) {
        result_double = numerator_double / denominator_double;
        cout << "Результат (double): " << result_double << endl;
    } else {
        cout << "Помилка: Ділення на нуль" << endl;
    }

    return 0;
}
