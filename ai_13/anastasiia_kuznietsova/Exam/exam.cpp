#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

float **matrix()
{
    float **matrix = new float *[10];
    for (int i = 0; i < 10; ++i)
    {
        matrix[i] = new float[10];
    }

    for (int i = 0; i < 10; i++)//Вимога 10: в коді використаний for цикл 
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = sin(i * j);//Вимога 7: в коді використаний двовимірний масив 
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix;
}

float perev(float **matrix, const int &a)
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            for (int k = 0; k < 9 - j; ++k)
            {
                if (matrix[i][k] < matrix[i][k + 1])
                {
                    float temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }
    return matrixp[][];
}

int perev(int **matrix, int &number)
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            for (int k = 9; k < 9 - j; ++k)
            {
                if (matrix[k][i] < matrix[k + 1][i])
                {
                    float temp = matrix[k][i];
                    matrix[k][i] = matrix[k + 1][i];
                    matrix[k + 1][i] = temp;
                }
            }
        }
    }
    return matrix[][];
}

int *calculateSums(float **matrix)
{
    int *sums = new int[10];
    srand(time(nullptr));

    for (int i = 0; i < 10; ++i)
    {
        sums[i] = 0;
        for (int j = 0; j < 10; ++j) 
        {
            int randomRow = rand() % 10;
            sums[i] += static_cast<int>(matrix[randomRow][i]);
        }
        sums[i] = static_cast<int>(sums[i]);
    }

    return sums;
}

bool createfile(int *sums, const string &filename)
{
    ofstream file(filename);
    if (!file) // Вимога 5: в коді використані умовні оператори та розгалуження
    {
        cerr << "Error opening file";
        return false;
    }

    for (int i = 0; i < 10; ++i)
    {
        file << sums[i] << " ";
    }

    file.close();
    return true;
}

void openfile(const string &filename)
{
    int a, b, multiply = 1;
    ifstream infile(filename);
    if (!infile)
    {
        cerr << "Error opening file";
        exit(1);
    }

    while (infile >> a)
    {
        multiply *= a;
    }

    cout << "Product of elements in the file: " << multiply << endl;
    infile.close();
}

void deletefile(const string &filename)
{
    if (remove(filename.c_str()) == 0)
    {
        cout << "File '" << filename << "' has been successfully deleted." << endl;
    }
    else
    {
        cerr << "Error deleting file '" << filename << "'" << endl;
    }
}

int main()
{
    const int a = 964; //Вимога 4: цілочисельна константа
    int number; //Вимога 1: використана цілочисельна змінна
    cin >> number;
    number *= a;
    const string filename = "File.txt";

    float **matrixPtr = matrix();
    perev(matrixPtr, a);
    int *sums = calculateSums(matrixPtr);
    createfile(sums, filename);
    openfile(filename);
    deletefile(filename);

    return 0;
}
