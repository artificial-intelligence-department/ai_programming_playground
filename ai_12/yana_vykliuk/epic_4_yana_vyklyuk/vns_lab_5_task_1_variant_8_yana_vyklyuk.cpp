#include <iostream>

using namespace std;

const int m = 4;
const int n = 4; 

void transposition (int matrix[m][n])
{
    int new_matrix[n][m];
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            new_matrix[j][i] = matrix[i][j];
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            matrix[i][j] = new_matrix[i][j];
        }
    }
};

bool symmetric (int matrix[m][n])
{   
    transposition (matrix);
    
    if(m != n)
    {
        return false;
    }
    else
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] != matrix[j][i])
                {
                    return false;
                }
            }
        }
    }

    return true;
};

int main()
{
    int matrix [m][n];

    cout << "Enter your " << m << "x" << n << " matrix: " << endl;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    transposition(matrix);
    
    cout << "New matrix: " << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    if(symmetric(matrix) == true)
    {
        cout << "The matrix is symmetric" << endl;
    }
    else
    {
        cout << "The matrix is not symmetric" << endl;
    }

    return 0;
}
