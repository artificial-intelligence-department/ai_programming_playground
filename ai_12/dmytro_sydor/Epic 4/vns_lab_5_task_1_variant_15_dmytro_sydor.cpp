#include <iostream>
using namespace std;

int sumOneColumn(int rows, int arr[][5], int collumnIndex, int numElements);

void sumOfCols(int rows, int cols, int arr[][5]);

int main()
{
    int cols = 5;
    int rows = 5;

    int arr[5][5];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 20;
        }
    }

    // Display the array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    sumOfCols(rows, cols, arr);

    return 0;
}

void sumOfCols(int rows, int cols, int arr[][5])
{
    int maxSum = 0;

    for (int i = 0; i < cols - 1; i++)
    {
        int numElements = cols - i - 1;
        int sumOneCol = sumOneColumn(rows, arr, i, numElements);

        cout << "Sum of " << i + 1 << " collumn, and " << numElements << " of it`s elements in column " << i + 1 << ": " << sumOneCol << endl;

        if (sumOneCol > maxSum)
        {
            maxSum = sumOneCol;
        }
    }

    cout << "Max Sum : " << maxSum << endl;
}

int sumOneColumn(int rows, int arr[][5], int collumnIndex, int numElements)
{
    int sumOneCol = 0;
    for (int i = 0; i < numElements; i++)
    {
        sumOneCol += arr[i][collumnIndex];
    }

    return sumOneCol;
}
