#include <iostream> 

using namespace std;

int main()
{
    int a1 = 0;
    int L1, L2;
    cin >> L1; // ввід розміру 1 масиву

    int r1[L1]; // 1 масивs
    for (int i = 0; i < L1; i++)
    {
        cin >> r1[i]; // заповнення кожного елементу 1 масиву
    }

    cin >> L2; // ввід розміру 2 масиву

    int r2[L2]; // 2 масив

    for (int i = 0; i < L2; i++)
    {
        cin >> r2[i]; // заповнення кожного елементу 2 масиву
    }

    for (int a = 0; a < L1; a++) // перевірка кожного числа масиву на одинаковість
    {
        for (int i = 0; i < L2; i++)
        {
            if (r1[a] == r2[i])
            {
                a1++; // розрахунок кількості одинакових чисел
            }
        }
    }

    int a2 = L1+L2-a1; // розрахунок кількості не одинакових чисел

    cout << a1 << endl; // вивід загальної кількості одинакових чисел
    cout << a2 << endl; // вивід загальної кількості не одинакових чисел

    return 0;
}
/* Вам дано 2 масиви розміром N та M. Значення у цих масивах унікальні.
Ваше завдання вивести у першому рядку кількість елементів, які наявні в обох масивах одночасно,
у другому кількість унікальних елементів в обох масивах разом.*/
