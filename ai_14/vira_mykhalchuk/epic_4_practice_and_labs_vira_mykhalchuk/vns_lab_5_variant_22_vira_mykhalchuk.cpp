#include <iostream>
using namespace std;

const int maxRow = 100;
const int maxCol = 100; 

void findAvg(int matrix[maxRow][maxCol], int rows, int cols) 
{
    
    int firstColumnSum = 0;

    for (int row = 0; row < rows; ++row) 
    {
        firstColumnSum += matrix[row][0];
    }
    double firstColumnAvg = static_cast<double>(firstColumnSum) / rows;

    
    cout << "The arithmetical mean of the first column: " << firstColumnAvg << "\n";

    int countAboveAvg[maxCol - 1] = {0};

    for (int col = 1; col < cols; ++col) 
    {
        for (int row = 0; row < rows; ++row) 
        {
            if (matrix[row][col] > firstColumnAvg) 
            {
                countAboveAvg[col - 1]++;
            }
        }
    }

    for (int col = 1; col < cols; ++col) 
    {
        cout << "Column №" << col << ": " << countAboveAvg[col - 1] << " elements are above the arithmetical mean of the first column\n";
    }
}

int main() 
{
    int matrix[maxRow][maxCol] = 
    {
        {100, 1, 3, 63},
        {75, 107, 78, 62},
        {50, 76, 77, 99},
        {25, 51, 6, 2}
    };

    findAvg(matrix, 4, 4);

    return 0;
}