#include <iostream>

using namespace std;

int main()
{
    const int rows = 4;
    const int columns = 6;
    int array[rows][columns] =
        {
            {1, -7, -9, 4, 5},
            {8, -44, 3, 0, 0, -1},
            {0, -20, 77, 8, 0},
            {-22, 10, 20, 6, 8, 7}};

    // Вивід простого масиву
    cout << "Array:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }

    // Заміна від'ємних чисел на нулі
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (array[i][j] < 0)
            {
                array[i][j] = 0;
            }
        }
    }

    // Вивід масиву з нулями
    cout << "\nArray with 0:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }

// Переміщення нулів на кінець кожного рядка
for (int i = 0; i < rows; i++)
{
    int nonZero = 0;
    for (int j = 0; j < columns; j++)
    {
        if (array[i][j] != 0)
        {
            swap(array[i][j], array[i][nonZero]);
            nonZero++;
        }
    }
    
}

// Вивід масиву з нулями, де нулі знаходяться на кінці кожного рядка
    cout << "\nArray with 0 at the End:\n";
    for (int i = 0; i < rows; i++)
        {
    for (int j = 0; j < columns; j++)
        {
        cout << array[i][j] << "\t";
        }
        cout << endl;
        }
}