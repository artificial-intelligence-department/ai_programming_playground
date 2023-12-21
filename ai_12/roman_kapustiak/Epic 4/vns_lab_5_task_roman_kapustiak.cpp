#include <iostream>

using namespace std;

#define ROWS 5
#define COLUMNS 5
#define COLUMN_TO_SORT 3

void genAr(int ar[][COLUMNS]);
void rowsSwap(int ar[][COLUMNS], int firstIndex, int secondIndex);
void intSwap(int &a, int &b);
void printAr(int ar[][COLUMNS]);

int main()
{
    int a[ROWS][COLUMNS];
    srand (time(NULL));

    genAr(a);

    // Sorting the array by 3 column.
    // Bubble sort
    for(int i = 0; i < ROWS - 1; i++)
    {
        for(int j = 0; j < ROWS - i - 1; j++)
        {
            if(a[j][COLUMN_TO_SORT - 1] > a[j + 1][COLUMN_TO_SORT - 1])
            {
                rowsSwap(a, j, j + 1);
            }
        }
    }

    printAr(a);

    return 0;
}
void genAr(int ar[][COLUMNS])
{
    // Generating and printing an array.
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            ar[i][j] = rand() % 10;
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}
void rowsSwap(int ar[][COLUMNS], int firstIndex, int secondIndex)
{
    for(int i = 0; i < COLUMNS; i++)
    {
        intSwap(ar[firstIndex][i], ar[secondIndex][i]);
    }

    return;
}
void intSwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}
void printAr(int ar[][COLUMNS])
{
    // Print an array.
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}
