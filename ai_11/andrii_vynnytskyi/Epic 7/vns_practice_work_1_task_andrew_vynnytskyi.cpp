#include <iostream>
#include <cmath>

// Функція для обчислення виразу Y = b^3 * tg^2(x) - a/(sin^2(x/a))
double processing(double b, double x, double a)
{
    // Обчислення результату за заданою формулою
    double result = pow(b , 3) * pow(tan(x), 2) - (a/ pow(sin(x/a), 2));
    return result;// Повертаємо обчислений результат
}
// Функція для обчислення виразу Z = a * e^(-(3^(1/2))) * cos(bx/a)
double processing1(double b, double x, double a)
{
    // Обчислення результату за заданою формулою
    double result = a*exp(-sqrt(3))*cos((b*x)/a);
    return result;// Повертаємо обчислений результат
}

int main() {
    // Ініціалізація значень для b, a і x
    double b = 17.5, a=3.2, x = -4.8;
    // Виведення інформації про вираз Y
    std::cout << "Y = b^3 * tg^2(x) - a/(sin^2(x/a))" << std::endl;
    std::cout<<"\na = "<<a<<"\nb = "<<b<<"\nx = "<<x<<std::endl;
    printf("Y = %lf", processing(b,x,a));// Виведення результату функції processing яка обчислює результат виразу Y
    // Виведення інформації про вираз Z
    std::cout << "\nZ = a * e^(-(3^(1/2))) * cos(bx/a)" << std::endl;
    std::cout<<"\na = "<<a<<"\nb = "<<b<<"\nx = "<<x<<std::endl;
    std::cout<< "Z = "<<processing1(b,x,a)<<std::endl;// Виведення результату функції processing1 яка обчислює результат виразу Z
    return 0;// Повертаємо 0 для позначення успішного виконання програми
}
