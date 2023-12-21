#include <iostream>
using namespace std;

int transpose(int s, int array[][4], int m, int n);

int main()
{
    bool symmetrical = true;
    const int size = 4;
    cout << "Enter your matrix:\n";
    int matrix[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] != transpose(size, matrix, i, j))
            {
                symmetrical = false;
                break;
            }
            
        }
    }
    if (symmetrical == true)
            {
                cout << "Your matrix is symmetrical\n";
            }
            else cout << "Your matrix isn't symmetrical\n";
}

int transpose(int s, int array[][4], int m, int n)
{
    int tp_matrix[s][s];
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            tp_matrix[i][j] = array[j][i];
        }
    }
    return tp_matrix[m][n];
}