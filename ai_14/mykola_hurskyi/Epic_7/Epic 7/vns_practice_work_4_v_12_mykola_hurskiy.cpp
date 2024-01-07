#include <iostream>         //Підключаю бібліотеку С++
using namespace std;

int main() {
    // Оголошення змінних
    double num1, num2, num3, num4, num5;
    
    // Введення дробових чисел з клавіатури
    cout << "Enter the 1 decimal number: ";
    cin >> num1;
    
    cout << "Enter the 2 decimal number: ";
    cin >> num2;
    
    cout << "Enter the 3 decimal number: ";
    cin >> num3;
    
    cout << "Enter the 4 decimal number: ";
    cin >> num4;
    
    cout << "Enter the 5 decimal number: ";
    cin >> num5;
    
    // Обчислення середнього арифметичного
    double average = (num1 + num2 + num3 + num4 + num5) / 5.0;
    
    // Виведення результату
    cout << "Middle arifmetic is: " << average << endl;
    
    return 0;
}
