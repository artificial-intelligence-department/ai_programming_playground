#include <iostream>

using namespace std;

const int points = 10;        // незмінна кількість точок задана умовою
int pointsInQuarter[4] = {0}; // масив розміром 4 для підрахунку точок у кожній чверті

int main()
{

    for (int i = 1; i <= points; i++)
    {
        double x, y; // ввід координат точки
        cout << "Введіть координати точки " << i << " (x y): ";
        cin >> x >> y;

        // шукаємо в котрій чверті знаходиться точка
        if (x > 0 && y > 0)
        {
            pointsInQuarter[0]++; // перша чверть
        }
        else if (x < 0 && y > 0)
        {
            pointsInQuarter[1]++; // друга
        }
        else if (x < 0 && y < 0)
        {
            pointsInQuarter[2]++; // третя
        }
        else if (x > 0 && y < 0)
        {
            pointsInQuarter[3]++; // четверта
        }
    }

    // знаходимо чверті з найбільшою кількістю точок і присвоїмо їй значення максимум
    int max = 0;
    for (int i = 1; i < 4; i++)
    {
        if (pointsInQuarter[i] > pointsInQuarter[max])
            max = i;
    }

    // Виведення результатів
    cout << "Чверть з найбільшою кількістю точок: " << max + 1 << endl;

    return 0;
}
