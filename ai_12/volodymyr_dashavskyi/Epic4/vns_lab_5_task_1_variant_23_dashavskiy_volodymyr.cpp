#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int N;
    cout << "type array size N: ";
    cin >> N;

    int arr[N];
    cout << "type elements of array:\n";
    for (int i = 0; i < N; ++i)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    int matrix[N][N];

    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            matrix[i][j] = rand() % 10 + 1;
        }
    }

    for (int j = 0; j < N; ++j)
    {
        int columnSum = 0;
        for (int i = 0; i < N - 1; ++i)
        {
            columnSum += matrix[i][j];
        }
        matrix[N - 1][j] = arr[j] - columnSum;
    }

    cout << "two dimentional array N x N:\n";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }

    return 0;
}