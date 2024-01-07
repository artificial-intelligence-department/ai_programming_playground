//Завдання 10. Написати рекурсивну функцію
//знаходження степеня числа.
#include <iostream>
using namespace std;

int power(int a, int b)
{
    if (b == 0)
        return 1;
    return a * power(a, b - 1);
}

int main()
{
    int a, b;
    cout << "Enter number: ";
    cin >> a;
    cout << "Enter power: ";
    cin >> b;

    cout << power(a, b);

    return 0;
}