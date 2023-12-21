#include <iostream>
#include <algorithm>
using namespace std;

void deleteRowFromMatrix(int **matrix, int n, int m, int startInd, int endInd);

int main()
{
    int **arr;
    int n, m;
    int a, b;

    cout << "Enter size of matrix: ";
    cin >> n >> m;

    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            int input;
            cin >> input;
            arr[i][j] = input;
        }
    }
    cout << "Enter rows from a to b: ";
    cin >> a >> b;

    cout << "- - - -"
         << "\n";

    deleteRowFromMatrix(arr, n, m, a, b);

    return 0;
}

void deleteRowFromMatrix(int **arr, int n, int m, int start, int end)
{
    int **newArr;
    newArr = new int *[n];

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        newArr[i] = new int[m];

        if (i >= start && i < end)
        {
            index++;
        }

        for (int j = 0; j < m; j++)
        {
            if (index > end - start || index + i > n - 1)
            {
                newArr[i][j] = 0;
            }
            else
            {
                newArr[i][j] = arr[index + i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << newArr[i][j] << " ";
        }
        cout << "\n";
    }
}