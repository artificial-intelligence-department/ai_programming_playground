#include <iostream>
using namespace std;
int main() {
// Визначення змінних
double x, y;
// Виведення заголовка таблиці
cout << "x | y\n";
// Цикл для обчислення значень функції
for (x = -2; x <= 2; x += 0.5) {
// Обчислення значення функції
    y = -2.4 * x + 5 * x - 3;
// Виведення значень x і y
    cout << x << " | " << y << endl;
}
return 0;
}