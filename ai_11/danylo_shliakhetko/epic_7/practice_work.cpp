#include <iostream>
#include <cmath>
using namespace std;

void printArr(int **arr)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
}

void printArr(float **arr)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
}

int **getIntNumbersMatrix()
{
    int **arr = new int *[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = new int[10];

        for (int j = 0; j < 10; j++)
        {
            int y = floor(sqrt(abs((1 + i) * pow((1 + j), 2) * sin((1 + i) * (1 + j)) + pow((1 + i), -2 * (1 + j)) * (i + j + 1))));
            arr[i][j] = y;
        }
    }
    return arr;
}

float **getFloatNumbersMatrix()
{
    float **arr = new float *[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = new float[10];

        for (int j = 0; j < 10; j++)
        {
            float y = sqrt(abs((1 + i) * pow((1 + j), 2) * sin((1 + i) * (1 + j)) + pow((1 + i), -2 * (1 + j)) * (i + j + 1)));
            arr[i][j] = y;
        }
    }
    return arr;
}

float **sortArr(float **arr)
{
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (arr[j][i] > arr[j + 1][i])
                {
                    float buffer = arr[j][i];
                    arr[j][i] = arr[j + 1][i];
                    arr[j + 1][i] = buffer;
                }
            }
        }
    }
    return arr;
}

int **sortArr(int **arr)
{
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (arr[j][i] > arr[j + 1][i])
                {
                    int buffer = arr[j][i];
                    arr[j][i] = arr[j + 1][i];
                    arr[j + 1][i] = buffer;
                }
            }
        }
    }
    return arr;
}

int main()
{
    const int prNumber = 978;

    if (prNumber % 2 == 0)
    {
        float **arr = getFloatNumbersMatrix();
        printArr(arr);
        cout << "\n";
        float **sortedArr = sortArr(arr);
        printArr(sortedArr);
    }
    else
    {
        int **arr = getIntNumbersMatrix();
        printArr(arr);
        cout << "\n";
        int **sortedArr = sortArr(arr);
        printArr(sortedArr);
    }
    return 0;
}