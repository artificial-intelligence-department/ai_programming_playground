#include <iostream>  // Підключення бібліотеки введення/виведення
using namespace std;  // Використання простору імен std

int main () {    // Початок визначення функції main - головної функції програми
    cout << "Enter the number (press ctrl+d to stop input): ";  // Виведення повідомлення для вводу числа користувачем
    int number, N, sqr;  // Оголошення змінних для числа, лічильника та квадрату числа
    N = 1;  // Ініціалізація лічильника

    cout << "\nTable of squares of the first five positive odd integers" << endl;  // Виведення заголовка таблиці
    cout << "-------------------------------------" << endl;  // Виведення розділювача таблиці
    cout << "|   Number  |   Square   |" << endl;  // Виведення заголовку стовпців таблиці

    while (N <= 5 && cin >> number) {  // Цикл для обробки введених чисел, доки не досягнуто 5 позитивних непарних чисел
        if (number % 2 != 0 && number > 0) {  // Перевірка, чи число є позитивним і непарним
            sqr = number * number;  // Обчислення квадрату числа
            cout << "|     " << number << "     |     " << sqr << "     |" << endl;  // Виведення числа та його квадрату у відповідний стовпець таблиці
            ++N;  // Збільшення лічильника на 1
        }
    }

    cout << "-------------------------------------" << endl;  // Виведення розділювача таблиці

    return 0;  // Повернення значення 0, що вказує на успішне завершення програми
}
