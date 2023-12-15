#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

const int number = 975; // Цілочисельна константа

const char *intFilename = "integer_matrix.txt";
const char *floatFilename = "float_matrix.txt";

void printMatrix(int matr[10][10])
{
    // Одновимірний масив (індекс - i)
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << matr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void floatprintMatrix(float matr[10][10])
{
    // Одновимірний масив (індекс - i)
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << matr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void bubbleSort(float matrix[10][10])
{
    // Двовимірний масив (індекси - k, j)
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int k = 0; k < 9 - i; k++)
            {
                if (matrix[k][j] > matrix[k + 1][j])
                {
                    // Дійсна змінна (temp)
                    float temp = matrix[k][j];
                    matrix[k][j] = matrix[k + 1][j];
                    matrix[k + 1][j] = temp;
                }
            }
        }
    }
}

void bubbleSort(int matrix[10][10])
{
    // Двовимірний масив (індекси - i, k)
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = 0; k < 9 - j; k++)
            {
                if (matrix[i][k] < matrix[i][k + 1])
                {
                    // Дійсна змінна (temp)
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }
}

int *calculateColumnSums(float matrix[10][10])
{
    int *sumArray = new int[10]; // Цілочисельна динамічна змінна

    for (int j = 0; j < 10; j++)
    {
        int sum = 0;
        for (int i = 0; i < 4; i++)
        {
            int randomRowIndex = rand() % 10;
            sum += static_cast<int>(matrix[randomRowIndex][j]);
        }

        sumArray[j] = sum;
    }

    return sumArray;
}

int *intcalculateColumnSums(int matrix[10][10])
{
    int *sumArray = new int[10]; // Цілочисельна динамічна змінна

    for (int j = 0; j < 10; j++)
    {
        int sum = 0;
        for (int i = 0; i < 4; i++)
        {
            int randomRowIndex = rand() % 10;
            sum += static_cast<int>(matrix[randomRowIndex][j]);
        }

        sumArray[j] = sum;
    }

    return sumArray;
}

bool writeArrayToFile(int array[10], const char *filename)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return false;
    }

    for (int i = 0; i < 10; i++)
    {
        file << array[i] << ' '; // Оператор виведення
    }

    file.close();
    return true;
}

long long calculateProductFromFile(const char *filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return -1;
    }

    long long product = 1;
    int value;
    while (file >> value)
    {
        product *= value;
    }

    file.close();
    return product;
}

bool deleteFile(const char *filename)
{
    if (std::remove(filename) == 0)
    {
        std::cout << "File '" << filename << "' has been deleted." << std::endl;
        return true;
    }
    else
    {
        std::cerr << "Failed to delete file '" << filename << "'." << std::endl;
        return false;
    }
}

void processMatrix(float matrix[10][10], float value)
{
    bubbleSort(matrix);
    std::cout << "Sorted Matrix with float values:" << std::endl;
    floatprintMatrix(matrix);

    float result = value * number; // Дійсна змінна
    std::cout << "Result: " << result << std::endl;

    int *columnSums = calculateColumnSums(matrix);
    std::cout << "Column Sums:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << columnSums[i] << ' '; // Оператор виведення
    }
    std::cout << std::endl;

    if (writeArrayToFile(columnSums, floatFilename))
    {
        std::cout << "Values written to float matrix file successfully." << std::endl;
    }
    else
    {
        std::cerr << "Failed to write values to float matrix file." << std::endl;
    }

    delete[] columnSums;

    long long product = calculateProductFromFile(floatFilename);
    if (product != -1)
    {
        std::cout << "Product of values from float matrix file: " << product << std::endl;
    }
    else
    {
        std::cerr << "Failed to calculate product from float matrix file." << std::endl;
    }

    deleteFile(floatFilename);
}

void processMatrix(int matrix[10][10], int value)
{
    bubbleSort(matrix);
    std::cout << "Sorted Matrix with integer values:" << std::endl;
    printMatrix(matrix);

    int result = value * number; // Цілочисельна змінна
    std::cout << "Result: " << result << std::endl;

    int *columnSums = intcalculateColumnSums(matrix);
    std::cout << "Column Sums:" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << columnSums[i] << ' '; // Оператор виведення
    }
    std::cout << std::endl;

    if (writeArrayToFile(columnSums, intFilename))
    {
        std::cout << "Values written to integer matrix file successfully." << std::endl;
    }
    else
    {
        std::cerr << "Failed to write values to integer matrix file." << std::endl;
    }

    delete[] columnSums;

    long long product = calculateProductFromFile(intFilename);
    if (product != -1)
    {
        std::cout << "Product of values from integer matrix file: " << product << std::endl;
    }
    else
    {
        std::cerr << "Failed to calculate product from integer matrix file." << std::endl;
    }

    deleteFile(intFilename);
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    float floatMatrix[10][10];
    int intMatrix[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            floatMatrix[i][j] = pow(i, 2) / 3.0 + pow(cos(pow((i + j), 3)), 2);
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            intMatrix[i][j] = pow(i, 2) / 3 + pow(cos(pow((i + j), 3)), 2);
        }
    }

    processMatrix(floatMatrix, number * 2.5);
    std::cout << std::endl;
    processMatrix(intMatrix, number * 2);

    return 0;
}
