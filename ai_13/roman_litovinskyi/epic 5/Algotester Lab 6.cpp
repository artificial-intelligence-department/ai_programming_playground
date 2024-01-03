#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// Структура для зберігання координат
struct Coord
{
    int x;
    int y;
};

int N; // Розмір судоку (NxN)
int Q; // Кількість запитів
vector<vector<int>> Sudoky; // Вектор для зберігання судоку

// Функція для визначення можливих відповідей для конкретної клітинки судоку
void possibilityAndAnswer(Coord c)
{
    vector<int> possibleAnswer; // Вектор для зберігання можливих відповідей

    // Перевірка, чи вже є значення в клітинці судоку
    if (Sudoky[c.y - 1][c.x - 1] != 0)
    {
        cout << 1 << "\n" << Sudoky[c.y - 1][c.x - 1] << "\n"; // Якщо є, вивести його
        return;
    }

    // Заповнення вектора можливих відповідей від 1 до N
    for (int i = 0; i < N; i++)
    {
        possibleAnswer.push_back(i + 1);
    }

    // Перевірка чисел у рядку та стовпці для визначення можливих відповідей
    for (int i = 0; i < N; i++)
    {
        if (Sudoky[c.y - 1][i] != 0 && i != (c.x - 1))
        {
            int value = Sudoky[c.y - 1][i];
            possibleAnswer[value - 1] = 0;
        }
    }

    for (int j = 0; j < N; j++)
    {
        if (Sudoky[j][c.x - 1] != 0 && j != (c.y - 1))
        {
            int value = Sudoky[j][c.x - 1];
            possibleAnswer[value - 1] = 0;
        }
    }

    int answers = 0;
    for (int i = 0; i < possibleAnswer.size(); i++)
    {
        if (possibleAnswer[i] != 0)
        {
            answers++;
        }
    }

    // Виведення кількості та можливих відповідей
    cout << answers << endl;
    for (int i = 0; i < possibleAnswer.size(); i++)
    {
        if (possibleAnswer[i] != 0)
        {
            cout << possibleAnswer[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    cin >> N; // Введення розміру судоку
    string numbers;

    // Цикл для зчитування введення судоку
    for (int i = 0; i < N; i++)
    {
        vector<int> sudoky1;
        for (int j = 0; j < N; j++)
        {
            sudoky1.push_back(0);
        }

        cin >> numbers;

        // Запис чисел судоку в вектор
        for (int i = 0; i < numbers.length(); i++)
        {
            char ch = numbers.c_str()[i];
            int elem = atoi(&ch);
            sudoky1[i] = elem;
        }

        Sudoky.push_back(sudoky1); // Додавання рядка судоку до вектора
    }

    cin >> Q; // Введення кількості запитів
    vector<Coord> coords;

    // Зчитування координат для кожного запиту
    for (int i = 0; i < Q; i++)
    {
        Coord c;
        cin >> c.y >> c.x;
        coords.push_back(c);
    }

    // Виклик функції для кожного запиту
    for (int i = 0; i < Q; i++)
    {
        possibilityAndAnswer(coords[i]);
    }

    return 0;
}
