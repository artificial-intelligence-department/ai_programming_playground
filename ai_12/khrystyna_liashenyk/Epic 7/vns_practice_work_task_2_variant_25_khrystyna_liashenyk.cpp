#include <iostream>
#include <cmath>
using namespace std;// Підключення необхідних бібліотек для вводу/виводу та математичних операцій.

double calculateSeriesSum(double x) {// Функція для обчислення суми ряду відповідно до вхідного значення 'x'.
    double sum = 0.0; // Ініціалізація змінної 'sum' для збереження суми ряду.
    for (int i = 1; i <= 10; ++i) { // Цикл для обчислення суми ряду з десяти елементів від 1 до 10.
     sum += pow(x, i) / i; // Додавання до суми виразу x^i / i.
     cout<<"Sum of "<<i<<" = "<<sum<<endl;
    }

    return sum; // Повернення обчисленої суми ряду.
}

int main() {
    double x;
    cout << "Enter the value of x: ";
    cin >> x; // Введення значення 'x' користувачем.

     // Перевірка на введення від'ємного числа
    if (x < 0) {
        cout << "This is a non-negative number." << endl;
    } else {
        double seriesSum = calculateSeriesSum(x);
        cout << "Sum of the series = " << seriesSum << endl;// Виведення обчисленої суми ряду.
    }
    

    return 0;
}
