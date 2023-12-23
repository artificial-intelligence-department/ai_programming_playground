#include <iostream>
#include <cstdarg>
#include <fstream>
#include <string>

using namespace std;

//13. в коді використано рекурсивну функцію
double average(int amount, ...) {
    va_list list;
    va_start(list, amount);
    double sum = 0;
    
    for (int i = 0; i < amount; i++) {
        double x = va_arg(list, double);
        sum += x;
    }
    
    va_end(list);
    return sum / amount;
}

int main() {
    double numbers[5];
    
    // Введення чисел з клавіатури
    for (int i = 0; i < 5; i++) {
        cout << "Enter the number # " << i + 1 << " : ";
        cin >> numbers[i];
    }

    // Знаходження та виведення середнього арифметичного
    double averageValue = average(5, numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
    cout << "The average value is " << averageValue << endl;
    return 0;
}
