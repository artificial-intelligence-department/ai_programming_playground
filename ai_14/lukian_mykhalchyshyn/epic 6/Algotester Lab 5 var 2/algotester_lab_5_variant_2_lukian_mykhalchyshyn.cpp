#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M; // Зчитування розмірів печери

    cin >> N;
    cin >> M;

    vector <vector <char>> cave (N, vector <char> (M)); // Ініціалізація двовимірного вектора для представлення печери

    for (int i = 0; i < N; i++) // Зчитування конфігурації печери
    {
        for (int j = 0; j < M; j++)
        {
            cin >> cave[i][j];
        }
    }

    for (int j = 0; j < M; j++) // Зсув піску униз, якщо під ними є пустий простір
    {
        for (int i = N - 1; i >= 0; i--)
        {
            if (i + 1 < N)
            {
                if (cave[i][j] == 'S' && cave[i + 1][j] == 'O') // Перевірка, чи можна зсунути пісок вниз
                {
                    swap(cave[i][j], cave[i + 1][j]); 
                    i = N - 1; // Переведення індексу в кінцевий стан для перевірки відповідних елементів
                }
            }
        }
    }
    cout << endl;

    for (int i = 0; i < N; ++i) // Виведення нового стану печери
    {
        for (int j = 0; j < M; ++j)
        {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}