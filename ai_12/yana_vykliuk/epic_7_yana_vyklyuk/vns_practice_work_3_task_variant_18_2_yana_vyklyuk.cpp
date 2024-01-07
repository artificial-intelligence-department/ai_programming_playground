#include <iostream>

using namespace std;

// Функція для обчислення кількості виготовлених шайб за одну зміну
int shift(int KOL)
{
    int eight_hour_shift = 7 * KOL;

    return eight_hour_shift;
}

// Функція для обчислення кількості виготовлених шайб за робочий день при двозмінній роботі
int day(int KOL)
{
    int day_work = shift(KOL) * 2;

    return day_work;
}

// Функція для обчислення кількості виготовлених шайб за 30-ти денний місяць
int month(int KOL)
{
    int month_work = day(KOL) * 26;

    return month_work;
}

int main()
{
    int KOL; // Ініціалізація змінної
    cout << "Введіть кількість шайб, яка виготовляється за годину: "; // Запит користувача на введення кількості шайбd
    cin >> KOL;

    // Виведення результатів
    cout << "Кількість виготовлених шайб: " << endl;
    cout << "За одну зміну - " << shift(KOL) << endl;
    cout << "За робочий день при двозмінній роботі - " << day(KOL) << endl;
    cout << "За 30-ти денний місяць - " << month(KOL) << endl;

    return 0;
}
