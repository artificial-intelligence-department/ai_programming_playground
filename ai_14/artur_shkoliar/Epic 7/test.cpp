#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int matrixSize = 10;
const int numberOfPR = 922;



float valueOfMatrix(int rows, int cols)
{
    if((rows + cols) % 2 == 0)
    {
        return sqrt(static_cast<float>(rows* cols));
    }

    else {
        return static_cast<float>(rows + cols);
    }
}

void outputMatrix(float matrix[matrixSize][matrixSize])
{
    for(int i =0; i < matrixSize; i++)
    {
        for(int j = 0; j < matrixSize; j++)
        {
            cout << setprecision(2) << matrix[i][j] << " ";
        }
        cout << endl;
    }


}

void randNumbs(float matrix[matrixSize][matrixSize])
{
    for(int i =0; i < matrixSize; i++)
    {
        for(int j = 0; j < matrixSize; j++)
        {
            matrix[i][j] = valueOfMatrix(i,j);
        }
    }
}

void sortcolumns(float matrix[matrixSize][matrixSize])
{
    for(int j =0; j < matrixSize; j++)
    {
        for(int i = 0; i < matrixSize; i++)
        {
            for(int k = 0; k < matrixSize - i - 1; ++k)
            {
                if(matrix[k][j] > matrix[k+1][j])
                {
                    swap(matrix[k][j], matrix[k+1][j]);
                }
            }
        }
    }
}

void sortRows(float matrix[matrixSize][matrixSize], int mnozhnyk)
{
    mnozhnyk = static_cast<float>(numberOfPR);
    for(int j =0; j < matrixSize; j++)
    {
        for(int i = 0; i < matrixSize; i++)
        {
            for(int k = 0; k < matrixSize - i - 1; ++k)
            {
                if(matrix[i][k] > matrix[i][k+1])
                {
                    swap(matrix[i][k], matrix[i][k+1]);
                }
            }
        }
    }

    for(int i = 0; i < matrixSize; i++)
    {
        for(int j = 0 ; j < matrixSize; j++)
        {
            matrix[i][j] *= mnozhnyk;
        }
    }

}



int main()
{
    float result[matrixSize][matrixSize];
    randNumbs(result);
    

    cout << "Matrix: " << endl;
    outputMatrix(result);

    sortcolumns(result);
    cout << "Matrix after sorting columns: " << endl;
    outputMatrix(result);

    sortRows(result, numberOfPR);

    cout << "Matrix afteer sorting rows: " << endl;
    outputMatrix(result);

}
