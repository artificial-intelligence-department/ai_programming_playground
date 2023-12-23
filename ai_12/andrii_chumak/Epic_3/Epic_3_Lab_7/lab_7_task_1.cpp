#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include <cstdarg>

using namespace std;

// Розв’язати зазначене у варіанті завдання, використовуючи функції зі змінною кількістю параметрів.
/*
Написати функцію kvadr зі змінною кількістю параметрів, що визначає
кількість чисел, що є точними квадратами (2, 4, 9, 16,. . . ) типу int. Написати
викликаючу функцію main, що звертається до функції kvadr не менше трьох
разів з кількістю параметрів 3, 7, 11.
*/

int kvadr(int num, ...) {
    va_list args;
    va_start(args, num);

    int count = 0;
    for (int i = 0; i < num; ++i) {
        int currentNum = va_arg(args, int);
        if (sqrt(currentNum) == floor(sqrt(currentNum))) {
            count++;
        }
    }

    va_end(args);

    return count;
}

int main() {
    // Виклик функції kvadr з різною кількістю параметрів
    int result1 = kvadr(3, 2, 4, 9);
    int result2 = kvadr(7, 1, 3, 5, 7, 9, 11, 13);
    int result3 = kvadr(11, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196);

    // Виведення результатів
    cout << "Для набору чисел (2, 4, 9): " << result1 << " точних квадратів" << endl;
    cout << "Для набору чисел (1, 3, 5, 7, 9, 11, 13): " << result2 << " точних квадратів" << endl;
    cout << "Для набору чисел (16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196): " << result3 << " точних квадратів" << endl;
}