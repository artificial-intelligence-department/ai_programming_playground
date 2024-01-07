#include <iostream>
#include <algorithm>
using namespace std;

const int ROWS = 3;  
const int COLS = 3;  

void swapRows(int arr[ROWS][COLS], int row1, int row2) 
{
    for (int i = 0; i < COLS; ++i) 
    {
        swap(arr[row1][i], arr[row2][i]);
    }
}

void arrSort(int arr[ROWS][COLS]) 
{
    for (int i = 0; i < ROWS - 1; ++i) 
    {
        for (int j = 0; j < ROWS - i - 1; ++j) 
        {
            if (arr[j][2] > arr[j + 1][2])
            {
                swapRows(arr, j, j + 1);
            }
        }
    }
}

void print(int arr[ROWS][COLS]) 
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j) 
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int arr[ROWS][COLS] = 
    {
        {32, 1, 4},
        {6, 7, 5},
        {2, 3, 6}
    };

    cout << "До сортування:" << endl;
    print(arr);

    arrSort(arr);

    cout << "\nПісля сортування за третім стовпцем:" << endl;
    print(arr);

    return 0;
}
