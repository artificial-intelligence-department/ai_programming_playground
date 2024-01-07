#include <iostream>
#include <cstdarg>

double resistance_calculation(int count, ...) {
    //Вимога #13 - в коді використано еліпсис
    double final_resistance = 0;
    va_list list;
    va_start(list, count);
    while (count) {
        //Вимога #9 - в коді використаний while цикл
        final_resistance += 1/va_arg(list, double);
        --count;
    }
    va_end(list);
    return final_resistance;
}

int calculate_volume(int a) {
    int volume = a*a*a;
    //Вимога #1 - в коді використана як мінімум одна цілочисельна змінна
    return volume;
}
//Вимога #12 - в коді використано перевантаження функції
double calculate_volume(double a) {return a*a*a;}

int main() {
    double edge;
    std::cout << "Enter the length of the edge of the cube(cm) and press <Enter>: ";
    //Вимога #21 - в коді використано оператори виведення та введення даних
    std::cin >> edge;
    std::cout << "Volume of the cube: " << calculate_volume(edge) << std::endl;
    double resistance[2] = {10, 2};
    //Вимога #6 - в коді використаний одновимірний масив
    std::cout << "The resistance of an electric circuit consisting of two parallel connected resistors: " << resistance_calculation(2, resistance[0], resistance[1]);
    return 0;
}