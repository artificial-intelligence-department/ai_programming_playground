#include <iostream>

using namespace std;

bool findMinElemAndSet(int *matrix, const int N, const int j, const int shouldBeGreaterThan)
{

    int max = matrix[0 * N + j];
    int indexMaxEl = 0;
    for (int i = 1; i < N; i++)
    {
        int value = matrix[i * N + j];
        if (value > max)
        {
            max = value;
            indexMaxEl = i;
        }
    }

    if (j > 0 && max <= shouldBeGreaterThan)
    {
        return false;
    }

    int min = max;
    int indexMinEl = indexMaxEl;

    for (int i = 0; i < N; i++)
    {
        int value = matrix[i * N + j];
        if (value < min && (j == 0 || value > shouldBeGreaterThan))
        {
            min = value;
            indexMinEl = i;
        }
    }

    int temp = matrix[(N - j - 1) * N + j];
    matrix[(N - j - 1) * N + j] = min;
    matrix[indexMinEl * N + j] = temp;
    return true;
}

int main()
{
    int N;
    cout << "Input N:\n";
    cin >> N;
    cout << endl;
    cout << "Input matrix " << N << "x " << N << ": \n";

    int matrix[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }

    bool possible = true;

    int previousColumnDiagonalElem = 0;
    for (int j = 0; j < N; j++)
    {
        bool elementWasFound = findMinElemAndSet(&matrix[0][0], N, j, previousColumnDiagonalElem);
        if (!elementWasFound)
        {
            possible = false;
            break;
        }
        else
        {
            previousColumnDiagonalElem = matrix[N - j - 1][j];
        }
    }

    cout << endl;
    cout << "Result:\n";
    if (possible)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%3d ", matrix[i][j]);
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "Elements of matrix couldn't be placed in required order!";
    }

    return 0;
}