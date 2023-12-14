#include <iostream>
#include <cmath>
#include <fstream>

void current(double vol, double res);
int main()
{
    // Вимога 3 - в коді використана як мінімум одна дійсний з подвійною точністю змінна.
    double way, gas, gasPrice;
    std::cout << "Введіть відстань до дачі (км): " << std::endl;
    std::cin >> way;
    std::cout << "Введіть витрату бензину (літрів на 100 км пробігу): " << std::endl;
    std::cin >> gas;
    std::cout << "Введіть ціну літра бензину (грн): " << std::endl;
    std::cin >> gasPrice;

    double result = 2 * ((gas / 100) * way * gasPrice);
    result = round(result * 100) / 100;

    // Вимога 19 - в коді використано функції роботи з файлами, для того, щоб зчитати у файл.
    std::ofstream file_1("Price.txt");
    file_1 << result << std::endl;
    file_1.close();

    // Вимога 20 - в коді використано функції роботи з файлами, для того, щоб зчитати з файлу.
    std::ifstream file_2("Price.txt");
    double result2;
    file_2 >> result2;
    std::cout << "Поїздка на дачу обійдеться в: " << result2 << " грн" << std::endl;

    // 2 TASK

    double voltage, resistance;
    // Вимога 21 - в коді використано оператори введення та виведення даних.
    std::cout << "Введіть напругу (в вольтах): ";
    std::cin >> voltage;
    std::cout << "Введіть опір (в омах): ";
    std::cin >> resistance;
    current(voltage, resistance);
}

// Вимога 16 - в коді використано параметри та аргументи функції.
void current(double vol, double res)
{
    double result = vol / res;
    std::cout << "Струм в ланцюгу: " << result << " Ампер(a)" << std::endl;
}