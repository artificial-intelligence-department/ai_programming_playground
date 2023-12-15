#include <iostream>
#include <cmath>

using namespace std;

void sortMatrixFloat(float matrix[][10], int rows, int cols)
{
    for (int col = 0; col < cols; ++col)
    {
        for (int i = 0; i < rows - 1; ++i)
        {
            for (int j = 0; j < rows - i - 1; ++j)
            {
                if (matrix[j][col] > matrix[j + 1][col])
                {
                    swap(matrix[j][col], matrix[j + 1][col]);
                }
            }
        }
    }
}

void sortMatrixInt(int matrix[][10], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols - 1; ++j)
        {
            for (int k = 0; k < cols - j - 1; ++k)
            {
                if (matrix[i][k] < matrix[i][k + 1])
                {
                    swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

float fill(float mas[10][10])
{
    const int nomber = 967;
    if (nomber % 2 == 0)
    {
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                float x = 1;
                mas[i][j] = pow(j, x + 1.25);
            }
        }
    }
    else
    {
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                int x = 1;
                mas[i][j] = round(pow(j, x + 1.25));
            }
        }
    }
}

int main()
{
    float mas[10][10];
    fill(mas);

    cout << "Завдання 1:\n";
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }

    // Choose sorting function based on the parity of 'number'
    if (mas[0][0] == round(mas[0][0]))
    {
        sortMatrixInt(reinterpret_cast<int(*)[10]>(mas), 10, 10);
    }
    else
    {
        sortMatrixFloat(mas, 10, 10);
    }

    cout << "\nЗавдання 2:\n";
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
