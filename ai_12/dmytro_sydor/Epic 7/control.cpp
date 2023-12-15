#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;

// Оголошення функції для обчислення добутку з файлу
float calculateProductFromFile(const string &fileName);

// Константа для числа, що використовується в матриці
const int pullnumber = 945;

// Функція для заповнення матриці
void matrixFunc(int matrix[10][10]);

// Функції для сортування матриці
void sortMatrix(float matrix[10][10], float value);
void sortMatrix(int matrix[10][10], int value);

// Функції для обчислення та запису сум в файл
void funcForSum(int matrix[10][10]);
void funcForSum(float matrix[10][10]);

// Функції для перевірки створення файлів зі сумами
bool isCreated(float sumsFloat[10]);
bool isCreated(int sumsInt[10]);

int main()
{
    // Ініціалізація генератора випадкових чисел
    srand(time(nullptr));

    // Оголошення та ініціалізація матриці
    int matrix[10][10];
    matrixFunc(matrix);

    // Виведення оригінальної матриці
    cout << "Original Matrix:" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Створення та сортування матриці з дійсними числами
    float matrixFloat[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrixFloat[i][j] = static_cast<float>(matrix[i][j]);
        }
    }

    sortMatrix(matrixFloat, 945.0f);
    sortMatrix(matrix, 945);

    // Обчислення та запис сум в файл для цілих та дійсних чисел
    funcForSum(matrix);
    funcForSum(matrixFloat);

    // Оголошення констант для імен файлів
    const string intSumFileName = "sumOutputInt.txt";
    const string floatSumFileName = "sumOutputFloat.txt";

    // Обчислення та виведення добутку елементів з файлів
    float intProduct = calculateProductFromFile(intSumFileName);
    float floatProduct = calculateProductFromFile(floatSumFileName);

    cout << "Product of integers in the file: " << intProduct << endl;
    cout << "Product of floats in the file: " << floatProduct << endl;

    return 0;
}

// Реалізація функції для заповнення матриці
void matrixFunc(int matrix[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = static_cast<int>(i * cos(j * pullnumber + sin(i)) + pow(j, 3));
        }
    }
}

// Реалізація функції для сортування матриці з дійсними числами
void sortMatrix(float matrix[10][10], float value)
{
    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            if (matrix[i][j] > matrix[i + 1][j])
            {
                for (int k = 0; k < 10; k++)
                {
                    float temp = matrix[i][k];
                    matrix[i][k] = matrix[i + 1][k];
                    matrix[i + 1][k] = temp;
                }
            }
        }
    }

    cout << "\nSorted Matrix (float):" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Реалізація функції для сортування матриці з цілими числами
void sortMatrix(int matrix[10][10], int value)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (matrix[j][0] < matrix[j + 1][0])
            {
                for (int k = 0; k < 10; k++)
                {
                    int temp = matrix[j][k];
                    matrix[j][k] = matrix[j + 1][k];
                    matrix[j + 1][k] = temp;
                }
            }
        }
    }

    cout << "\nSorted Matrix (int):" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Реалізація функції для обчислення та запису сум в файл для цілих чисел
void funcForSum(int matrix[10][10])
{
    int *sums = new int[10];

    for (int i = 0; i < 10; i++)
    {
        int sum = 0;

        int numElements = rand() % 2 + 3; // 3 or 4
        for (int k = 0; k < numElements; k++)
        {
            int row = rand() % 10; // Random row index
            sum += matrix[row][i];
        }

        sums[i] = static_cast<int>(sum);
    }

    int arrofSumInt[10];
    for (int i = 0; i < 10; i++)
    {
        arrofSumInt[i] = sums[i];
    }
    cout << endl;

    // Check if file creation was successful
    if (isCreated(arrofSumInt))
    {
        cout << "File with sums of integers created successfully." << endl;
    }
    else
    {
        cout << "Error creating file with sums of integers." << endl;
    }

    delete[] sums;
}

// Реалізація функції для обчислення та запису сум в файл для дійсних чисел
void funcForSum(float matrix[10][10])
{
    float *sums = new float[10];

    for (int i = 0; i < 10; i++)
    {
        float sum = 0.0f;

        int numElements = rand() % 2 + 3;
        for (int k = 0; k < numElements; k++)
        {
            int row = rand() % 10;
            sum += matrix[row][i];
        }

        sums[i] = sum;
    }
    float arrofSumFloat[10];

    for (int i = 0; i < 10; i++)
    {
        arrofSumFloat[i] = sums[i];
    }
    cout << endl;

    // Check if file creation was successful
    if (isCreated(arrofSumFloat))
    {
        cout << "File with sums of floats created successfully." << endl;
    }
    else
    {
        cout << "Error creating file with sums of floats." << endl;
    }

    delete[] sums;
}

// Реалізація функції для перевірки створення файлу для дійсних чисел
bool isCreated(float sumsFloat[10])
{
    ofstream file("sumOutputFloat.txt");
    if (!file.is_open())
    {
        return false;
    }

    for (int i = 0; i < 10; i++)
    {
        file << sumsFloat[i] << " ";
    }
    file << endl;

    file.close();
    return true;
}

// Реалізація функції для перевірки створення файлу для цілих чисел
bool isCreated(int sumsInt[10])
{
    ofstream file("sumOutputInt.txt");
    if (!file.is_open())
    {
        return false;
    }

    for (int i = 0; i < 10; i++)
    {
        file << sumsInt[i] << " ";
    }
    file << endl;

    file.close();
    return true;
}

// Реалізація функції для обчислення добутку елементів з файлу
float calculateProductFromFile(const string &fileName)
{
    ifstream file(fileName);

    if (!file.is_open())
    {
        cerr << "Error opening file: " << fileName << endl;
        return 0.0f; // Повертаємо 0 у випадку помилки
    }

    float product = 1.0f;
    float value;

    while (file >> value)
    {
        product *= value;
    }

    file.close();

    return product;
}
