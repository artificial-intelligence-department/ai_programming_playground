#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

int findMinValue(int arr[], int size) 
{

    int minValue = arr[0]; 

    for (int i = 1; i < size; ++i) {
        if (arr[i] < minValue)
            minValue = arr[i];
    }

    return minValue;
}

int findMaxValue(int arr[], int size) 
{
    int maxValue = arr[0]; 

     for (int i = 1; i < size; ++i) {
        if (arr[i] > maxValue)
            maxValue = arr[i];
    }

    return maxValue;
}

int findMaxRow(int** arr, int size, int row)
{
    int mValue = arr[0][row];
    // cout << "maxrow: " << mValue;
    for (int i = 1; i < size; i++)
    {
        if (arr[i][row] > mValue)
            mValue = arr[i][row];
        // cout << " " << mValue;
    }

    return mValue;
}

int findMinRow(int** arr, int size, int row)
{
    int mValue = arr[0][row];
    // cout << "minrow: " << mValue;
    for (int i = 1; i < size; i++)
    {
        if (arr[i][row] < mValue)
            mValue = arr[i][row];
        // cout << " " << mValue;
    }

    return mValue;    
}


int main()
{
    random_device rd;  
    mt19937 gen(rd());
    
    uniform_int_distribution<int> distr2(0, 100);

    int mLines = 3, mRows = 4;//distr(gen);
    int** matrix = new int* [mLines];

    matrix[0] = new int[mRows]{7,1,5,3};
    matrix[1] = new int[mRows]{3,2,6,4};
    matrix[2] = new int[mRows]{5,2,8,6};

    for (int i = 0; i < mLines; i++)
    {
        matrix[i] = new int[mRows];
        for (int j = 0; j < mRows; j++)
        {
            matrix[i][j] = distr2(gen);
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // cout << matrix[3][1];

    // cout << matrix[1][0] << " " << matrix[2][0] << endl;

    cout << "saddle elements: ";
    for (int i = 0; i < mLines; i++)
    {
        int minLine = findMinValue(matrix[i], mLines);
        int maxLine = findMaxValue(matrix[i], mLines);

        for (int j = 0; j < mRows; j++)
        {
            int minRow = findMinRow((int**)matrix, mLines, j);
            int maxRow = findMaxRow((int**)matrix, mLines, j);
            // cout << "min/max: " << minRow << " " << maxRow << endl;
            
            if (matrix[i][j] == minLine && matrix[i][j] == maxRow
                || matrix[i][j] == maxLine && matrix[i][j] == minRow)
            {
                cout << matrix[i][j] << " ";
            }
            
        }
        // cout << endl << "all valules: " << minLine << ", " << maxLine << ", " << minRow << ", " << maxRow << endl;
    }
    
    return 0;

}