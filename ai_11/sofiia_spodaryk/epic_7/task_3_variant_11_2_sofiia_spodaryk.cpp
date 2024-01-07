#include <iostream>

using namespace std;

double voltage;    // Напруга в вольтах
double resistance; // Опір в омах
double current;    // Струм в амперах

int main()
{

    // Введення даних
    cout << "Напруга (V) = ";
    cin >> voltage;

    cout << "Опір (Ω) > ";
    cin >> resistance;

    // формула для обчислення струму за законом Ома
    current = voltage / resistance;

    // Виведення результату
    cout << "Струм в електричному ланцюгу: " << current << " A" << endl;

    return 0;
}