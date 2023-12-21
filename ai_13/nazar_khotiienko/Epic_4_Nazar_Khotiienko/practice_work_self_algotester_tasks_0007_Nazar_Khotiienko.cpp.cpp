#include <iostream>

using namespace std;

int main()
{
    int L, Z;
    int a, b, c;

    cin >> L; // розмір масиву
    cin >> Z; // кількість запитів
    int mas[L];
    int sum[Z];

    for (int i = 0; i < Z; ++i) // заповнення мусорного масиву sum нулями
    {
        sum[i] = 0;
    }

    for (int i = 0; i < L; ++i) // введення даних в масив mas
    {
        cin >> mas[i];
    }

    int siz = 0; 
    int q = 0; // змінна для правильного заповнення масиву sum

    for (int i = 0; i < Z; ++i)
    {
        cin >> a; // введення запиту
        cin >> b; // введення запиту
        cin >> c; // введення запиту

        if (a == 1) // перевірка запиту 
        {
            while (b <= c) // якщо 1 то ми шукаєм сумк з b до c
            {
                sum[q] += mas[b - 1];
                b++;
            }
            q++;
        }
        else if (a == 2) // якщо 2 то додаєм до елемнта b c
        {
            mas[b - 1] = mas[b - 1] + c;
            siz++;
        }
    }

    for (int i = 0; i < Z - siz; ++i) // виводим суму
    {
        cout << sum[i] << endl;
    }

    return 0;
}
