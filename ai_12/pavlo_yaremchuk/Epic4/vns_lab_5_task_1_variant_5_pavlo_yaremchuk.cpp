#include <iostream>
using namespace std;

const int row = 5;
const int column = 5;
void DeleteRows(int matrix[row][column], int rowNum)
{
    for (int i = rowNum - 1; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            matrix[i][j] = matrix[i + 1][j];
        }
    }

    for (int j = 0; j < column; ++j)
    {
        matrix[row - 1][j] = 0;
    }
}

void printMatrix(int matrix[][column], int rowNum) 
{
    for (int i = 0; i < rowNum; ++i) 
    {
        for (int j = 0; j < column; ++j) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int mat[row][column]={{1, 2, 3, 4, 5},
                          {6, 7, 8, 9, 10},
                          {11, 12, 13, 14, 15},
                          {16, 17, 18, 19, 20},
                          {21, 22, 23, 24, 25}};
    cout << "Початкова матриця:" << endl;
    printMatrix(mat, row);
    int A, B;
    Again:
    cout << "Введіть від якого по який рядок потрібно знищити: ";
    cin >> A >> B;
    if (B > 5)
    {
        cout << "B матриці всього 5 рядків" << endl;
        goto Again;
    }
    for (int i = A; i <= B; ++i)
    {
        DeleteRows(mat, A);
    }
    cout << "Матриця після видалення " << B + 1 - A;
    int count = B + 1 - A;
    if ((count) == 1)
    {
        cout << " рядка:" << endl;
    }
    else
    {
        cout << " рядків:" << endl;
    }
    printMatrix(mat, row - (B + 1 - A));
    return 0;
}