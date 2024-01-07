#include <iostream>

using namespace std;

int main()
{
    const int stowp = 3; //кількість стовпів масиву
    const int rad = 4; // кількість рядів масиву

    int mas1[stowp][rad] = { //двохвимірний масив
        {1, 2, -3, 4},
        {5, -2, 3, -4},
        {5, 6, 7, 8}};

    cout << "Початковий масив:\n";

    for (int i = 0; i < stowp; ++i)
    {
        for (int j = 0; j < rad; ++j)
        {
            cout << mas1[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < stowp; ++i)
    {
        for (int j = 0; j < rad; ++j)
        {
            if (mas1[i][j] < 0) //знаходження - масиву
            {
                mas1[i][j] = 0; //перетворення - в 0
                cout << "Знайдено від’ємні елемент\n";
            }
        }
    }

    cout << endl;

    for (int i = 0; i < stowp; ++i)
    {
        int o = 0; // Індекс, до якого будемо пересувати нулі

        for (int j = 0; j < rad; ++j) // Пересування 0 вправо
        {
            if (mas1[i][j] != 0)
            {
                mas1[i][o++] = mas1[i][j];
            }
        }
        while (o < rad)
        {
            mas1[i][o++] = 0;
        }
    }

    for (int i = 0; i < stowp; ++i) // вивід нового масиву
    {
        for (int j = 0; j < rad; ++j)
        {
            cout << mas1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
