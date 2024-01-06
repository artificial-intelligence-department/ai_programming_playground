//Імпортуєм потрібні бібліотеки
#include <iostream>
#include <cmath>

// Функція для обчислення виразу Y = sin(|a * x + b^a|)
double processing(double a , double x, double b)
{
    return sin(std::abs(a * x + pow(b, a)));// Повертаємо обчислений результат,з бібліотеки cmath ,беремо функції синус та степінь
}
// Функція для обчислення виразу Y = cos(|a * x - b^a|)
double processing1(double a , double x, double b)
{
    return cos(std::abs(a * x - pow(b, a)));// Повертаємо обчислений результат,з бібліотеки cmath ,беремо функції косинус та степінь
}
int main()
{
    double b = 1.5;
    //За допомогою циклу for перебираємо всі необхідні нам значення
for(double i = 0.5, j = -0.1; i <= 3.1 && j >= -1.4; i+=0.21, j-=0.1)
{
    if(i < b)// Перевірка умови: якщо i < b, використовується функція обчислюється перший вираз, інакше виконується другий вираз
    {
        std::cout<< "X = "<< i<<"\nA = "<< j<<"\nY =" <<processing(j,i,b)<<std::endl;// Виведення результату функції processing яка обчислює результат виразу Y = sin(|a * x + b^a|)
    }
    else
    {
        std::cout<< "X = "<< i<<"\nA = "<< j<<"\nY =" <<processing1(j,i,b)<<std::endl;// Виведення результату функції processing яка обчислює результат виразу Y = cos(|a * x - b^a|)
    }
}
return 0;// Повертаємо 0 для позначення успішного виконання програми
}