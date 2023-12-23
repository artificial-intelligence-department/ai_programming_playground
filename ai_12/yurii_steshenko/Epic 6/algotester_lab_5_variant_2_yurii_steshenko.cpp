#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int row, col;
    cin >> row >> col;

    vector<string> matrix(row);
    for (int i = 0; i < row; i++)
        cin >> matrix[i];

    for (int rowInd = row - 1; rowInd >= 0; rowInd--)
        for (int colInd = 0; colInd < col; colInd++)
            if (matrix[rowInd][colInd] == 'S')
            {
                int newRow = rowInd;
                while (newRow + 1 < row &&
                       matrix[newRow + 1][colInd] == 'O')
                    newRow++;

                swap(matrix[rowInd][colInd], matrix[newRow][colInd]);
            }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << matrix[i][j];

        cout << "\n";
    }

    return 0;
}