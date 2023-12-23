#include <iostream>

using namespace std;

//функція сортування за зростанням
void SortNuz(int mas[], int L) {
    for (int i = 0; i < L - 1; i++) {
        for (int j = 0; j < L - i - 1; j++) {
            if (mas[j] < mas[j + 1]) {
                int temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }
}

void SortVerh(int mas[], int L) {
    for (int i = 0; i < L - 1; i++) {
        for (int j = 0; j < L - i - 1; j++) {
            if (mas[j] > mas[j + 1]) {
                int temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }
}

void Del(int mas[], int &L) {
    for (int i = 0; i < L; ++i) {
        for (int j = i + 1; j < L; ) {
            if (mas[i] == mas[j]) {
                mas[j] = mas[--L];
            } else {
                ++j;
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;
    int mas[N];
    //введення даних
    for (int i = 0; i < N; i++)
    {
        cin >> mas[i];
    }

    int a1 = 0, a2 = 0, a3 = 0;

    // Рахуємо кількість елементів для кожної остачі від ділення на 3
    for (int i = 0; i < N; i++)
    {
        int rem = mas[i] % 3;
        if (rem == 0)
        {
            a1++;
        }
        else if (rem == 1)
        {
            a2++;
        }
        else if (rem == 2)
        {
            a3++;
        }
    }

    int dil1[a1], dil2[a2], dil3[a3];
    int d1 = 0, d2 = 0, d3 = 0;

    // Розподіляємо елементи за остачею від ділення на 3
    for (int i = 0; i < N; i++)
    {
        int rem = mas[i] % 3;
        if (rem == 0)
        {
            dil1[d1] = mas[i];
            d1++;
        }
        else if (rem == 1)
        {
            dil2[d2] = mas[i];
            d2++;
        }
        else
        {
            dil3[d3] = mas[i];
            d3++;
        }
    }

    SortVerh(dil1, a1);
    SortNuz(dil2, a2);
    SortVerh(dil3, a3);
    
    Del(dil1, a1);
    Del(dil2, a2);
    Del(dil3, a3);

    int size = a1 + a2 + a3;
    cout << size << endl;

    // Виведення відсортованих масивів
    for (int i = 0; i < a1; i++) {
        cout << dil1[i] << " ";
    }

    for (int i = 0; i < a2; i++) {
        cout << dil2[i] << " ";
    }

    for (int i = 0; i < a3; i++) {
        cout << dil3[i] << " ";
    }
    return 0;
}
