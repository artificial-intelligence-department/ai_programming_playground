// 21 Варіант
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{

    int stowp = 5;
    int rad = 3;
    // cтворення двохвимірного масиву
    int mas1[stowp][rad];

    // цикл заповнення даних в двохвимірний масив
    for (int i = 0; i < stowp; ++i)
    {
        for (int j = 0; j < rad; ++j)
        {
            cin >> mas1[i][j];
        }
    }

    // cтворення одновимірного масиву
    int h[stowp];
    // додання змінної (для майбутнього знайдення елементів з найбільшою висотою)
    int maxh = 0;

    // цикл заповнення одновимірного масиву
    for (int i = 0; i < stowp; ++i)
    {
        // p = a+b+c
        int p = mas1[i][0] + mas1[i][1] + mas1[i][2];
        // h = (2/a)sqrt(p(p-a)(p-c))
        h[i] = (2 / mas1[i][0]) * sqrt(p * (p - mas1[i][0]) * (p - mas1[i][2]));
        // умовний оператор розгалудженн якщо для пошуку ряду і задання змінній номеру ряду з найбільшою висотою
        if (h[i] > h[maxh])
        {
            maxh = i;
        }
    }

    // вивід тексту
    cout << "Висота h буде найбільщою для сторін:";

    // цикл виводу значенб з найбільшою висотою
    for (int i = 0; i < rad; i++)
    {
        cout << mas1[maxh][i] << " ";
    }

    return 0;
}