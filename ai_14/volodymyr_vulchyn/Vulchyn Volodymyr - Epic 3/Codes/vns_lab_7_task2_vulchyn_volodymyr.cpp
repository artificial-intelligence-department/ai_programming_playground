#include <iostream>
#include <cmath>

using namespace std;

// Функція яка обчислює (НСД) для двох цілих чисел а і b
int calculateGCD(int a, int b) { // 
    while (b != 0) { // Цикл з використанням алгоритму Евкілда для обчислення (НСД)
        int temp = b;
        b = a % b; // Обчислення нового значення b як залишку від ділення a на b.
        a = temp; //  Присвоєння a значення змінної temp.
    }
    return a;
}

// Функція для перетворення десяткового дробу у звичайний
void convertDecToFraction(double dec) {
    cout << "a) Перетворення десяткового дробу у звичайний: ";

    
    cout << dec << " = "; // Виводить десятковий дріб перед перетворенням.

    // Визначення знаменника
    int precision = 1000000;  // Встановлює точність для апроксимації при перетворенні десяткового дробу.
    int num = round(dec * precision); // Обчислює чисельник десяткового дробу.
    int denom = precision; // Задає знаменник десяткового дробу.

    // Скорочення дробу
    int gcd = calculateGCD(num, denom);
    num /= gcd;
    denom /= gcd;

    // Виведення результату
    cout << num << "/" << denom << endl;
}

// Функція для перетворення звичайного дробу у десятковий
void convertFractionToDec(int num, int denom) {
    cout << "б) Перетворення звичайного дробу у десятковий: ";

    // Виведення звичайного дробу
    cout << num << "/" << denom << " = ";

    // Перетворення у десятковий дріб
    double dec = static_cast<double>(num) / denom;

    // Виведення результату
    cout << dec << endl;
}

int main() {
    // a) Перетворення десяткового дробу у звичайний
    convertDecToFraction(9.1240);

    // b) Перетворення звичайного дробу у десятковий
    convertFractionToDec(1, 5);

    return 0;
}
