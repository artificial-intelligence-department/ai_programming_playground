#include<iostream>
using namespace std;

int main()
{
// Цикл для створення таблиці квадратів двозначних непарних чисел
        for(int i = 1; i < 10; i+=2)
    {
// Вкладений цикл для обчислення і виведення квадратів чисел у рядку
        for(int j = 1; j < 10; j+=2)
        {
            cout<< (i * 10 + j) * (i * 10 + j)<<' ';// Обчислення та виведення квадрату числа

        }
        cout<<endl;// Перехід на новий рядок після обчислення всіх чисел у рядку
    }
    return 0;// Повертаємо 0 для позначення успішного виконання програми

}