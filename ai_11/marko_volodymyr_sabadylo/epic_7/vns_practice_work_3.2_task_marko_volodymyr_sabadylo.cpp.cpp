#include <iostream>
using namespace std;
int main() {
    // Оголошення змінних для зберігання значень a, b, c і d
    double a, b, c, d;

    // Введення значень з клавіатури
    cout << "Enter the value for a: ";
    cin >> a;

    cout << "Enter the value for b: ";
    cin >> b;

    cout << "Enter the value for c: ";
    cin >> c;

    cout << "Enter the value for d: ";
    cin >> d;

    // Обчислення різниці творів (a * b) і (c * d)
    double result = (a * b) - (c * d);

    // Виведення результату
    cout << "The difference of products (a * b) and (c * d): " << result << endl;

    return 0;
}