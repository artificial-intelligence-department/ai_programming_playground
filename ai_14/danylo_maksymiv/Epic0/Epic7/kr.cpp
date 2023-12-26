#include <iostream>
using namespace std;
#include<cstdlib>
#include <fstream>

double **createMatrix(int rows, int cols)
{
    double **arr = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new double[cols];
    }

   
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = -2.33 * (i + 1) * (j + 1);
        }
    }

    return arr;
}

void bubbleSortColumns(double **matrix, int rows, int cols)
{
    for (int col = 0; col < cols; col++)
        {
            for (int i = 0; i < rows - 1; i++)
            {
                for (int j = 0; j < rows - i - 1; j++)
                {
                    if (matrix[j][col] > matrix[j + 1][col])
                    {
                        
                        double temp = matrix[j][col];
                        matrix[j][col] = matrix[j + 1][col];
                        matrix[j + 1][col] = temp;
                    }
                }
            }
        }
}

void printMatrix(double **matrix, int rows, int cols)
{
 for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int *randomSumArray(double **matrix, int rows, int cols)
{
    int *sumArray = new int[cols];

    for (int col = 0; col < cols; col++)
    {
        int sum = 0;
        for (int k = 0; k < 4; k++)
        {
            int randRow = rand() % rows;
            sum += static_cast<int>(matrix[randRow][col]);
        }
        sumArray[col] = sum;
    }

    return sumArray;
}

bool writeArrayToFile(int *array, int size, const char *filename)
{
    ofstream outputFile(filename); // Відкриття файлу для запису

    if (!outputFile.is_open())
    {
        cerr << "Error opening file." << endl;
        return false; // Помилка при відкритті файлу
    }

    // Запис значень масиву у файл
    for (int i = 0; i < size; i++)
    {
        outputFile << array[i] << " ";
    }

    outputFile.close(); // Закриття файлу
    return true;        // Успішно виконана дія
}

int calculateProductFromFile(const char *filename)
{
    ifstream inputFile(filename); // Відкриття файлу для читання

    if (!inputFile.is_open())
    {
        cerr << "Error opening file." << endl;
        return 0; // Помилка при відкритті файлу, повертаємо 0
    }

    int product = 1;
    int value;

    // Читання значень з файлу та обчислення добутку
    while (inputFile >> value)
    {
        product *= value;
    }

    inputFile.close(); // Закриття файлу
    return product;
}

void deletearr()
{
    remove("output.txt");
}

int main()
{
    const int rows = 10;
    const int cols = 10;

    double **arr = createMatrix(rows, cols);

   
    cout << "Original Matrix:" << endl;
    printMatrix(arr, rows, cols);

    
    bubbleSortColumns(arr, rows, cols);

   
    cout << "\nMatrix After Sorting Columns:" << endl;
    printMatrix(arr, rows, cols);

   
    int *sumArray = randomSumArray(arr, rows, cols);


    cout << "\nRandom Sum Array:" << endl;
    for (int i = 0; i < cols; i++)
    {
        cout << sumArray[i] << " ";
    }
    cout << endl;

   
    if (writeArrayToFile(sumArray, 10, "output.txt"))
    {
        cout << "Array successfully written to file." << endl;
    }
    else
    {
        cout << "Failed to write array to file." << endl;
    }


// Обчислення добутку елементів з файлу
    int product = calculateProductFromFile("output.txt");

    // Виведення добутку елементів
    cout << "\nProduct of elements from file: " << product << endl;

   deletearr;
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] sumArray;


    return 0;
}
