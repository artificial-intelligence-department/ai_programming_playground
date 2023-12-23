#include <iostream>
#include <ctime>
#include <cstdlib>

// 10 Варіант

using namespace std;

int main()
{
    srand(time(0)); // команда для рандомного запавнення команди rand
    int Long = 10;  // встановлення розміря масиву

    int mas[Long];

    for (int i = 0; i < Long; ++i) // цикл повторення
    {
        mas[i] = rand() % 101; // генерація чисел від 1 до 100
    }

    cout << "Базовий масив: ";
    for (int i = 0; i < Long; ++i)
    {
        cout << mas[i] << " ";
    }

    int del = 5;

    for (int i = 0; i < del; i++)
    {
        mas[i] = mas[i + del]; // заміна del(5) елементів на попередніх del(5)
    }

    Long -= del; // видалення з масиву перших del(5) елементів

    int add = 3; // cтворення масиву 
    int mas2[add];
    mas2[0] = 777; // додавання до масиву елементів
    mas2[1] = 555;
    mas2[2] = 333;

    Long += add; // додавання до масиву addd(3) мусорних елементів

    cout << endl;

    for (int i = 0; i < 8; i++)
    {
        mas[i + del] = mas2[i]; //заміна мусорних елеменів на еленти з 2 масиву
        cout << mas[i] << " ";
    }

    return 0;
}