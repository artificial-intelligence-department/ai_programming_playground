#include <iostream>
#include <cmath>

#include <Windows.h> 
using namespace std;

int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    //1
    double a, b, c;
    cout << "Обчислення; об'єму паралелепіпеда.";
    cout << "\nВведіть початкові дані:";
    cout << "Довжина (см) > ";
    cin >> a;
    cout << "Ширина(см)> ";
    cin >> b;
    cout << "Висота(см)> ";
    cin >> c;
    double obiem = a * b * c;
    cout << "Об'єм: " << obiem << "куб.см.";
    //2
    cout << "\nenter funts: ";
    double funts;
    cin >> funts;
    double kg = funts * 0.4059;
    cout << "kg: " << kg;

    return 0; 
}