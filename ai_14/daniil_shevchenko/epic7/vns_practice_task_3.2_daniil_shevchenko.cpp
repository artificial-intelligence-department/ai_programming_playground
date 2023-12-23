#include <iostream>
using namespace std;
struct box //використано структуру(умовно користувацький тип змінної з набором параметрів) для збереження довжини, ширини та висоти коробки(вимога 14)
{
    double length;
    double width;
    double height;
};
double volume(double a, double b, double c)
{
    double V = a * b * c;
    return V;
}

int main()
{
    const int v0 = 2;
    box test;
    cout << "Enter the sides of the box: ";
    cin >> test.length >> test.width >> test.height;
    double V = volume(test.length, test.width, test.height);
    int amount = V / v0; //спеціально створюємо цілочисельну змінну, щоб знайти цілу кількість болтів, які повністю вмістяться в коробці
    cout << "The amount is " << amount;

}

