#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
#include <fstream>

using namespace std;

const int number = 861;  // Константа для ініціалізації елементів матриці
const string filename = "output.txt";  // Ім'я файлу для збереження даних

// Функція для створення та ініціалізації статичного масиву
int* CreateStaticArray()
{
    int* staticArray = new int[10];

    for (int i = 0; i < 10; i++)
    {
        staticArray[i] = number + i;
    }

    return staticArray;
}

// Функція для передачі статичного масиву та запису його у файл
bool WriteArrayToFile(const int* staticArray)
{
    ofstream outputFile(filename);

    if (!outputFile.is_open())
    {
        cerr << "Error opening file for writing." << endl;
        return false;
    }

    for (int i = 0; i < 10; i++)
    {
        outputFile << staticArray[i] << " ";
    }

    outputFile.close();
    return true;
}

// Функція для обчислення добутку елементів з файлу та виведення результату
int CalculateProductFromFile()
{
    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cerr << "Error opening file for reading." << endl;
        return 0;  // Повертаємо 0 в разі невдачі відкриття файлу
    }

    int product = 1;
    int value;

    while (inputFile >> value)
    {
        product *= value;
    }

    inputFile.close();
    return product;
}

// Функція для виведення значень матриці на екран
void PrintMatrix(int** matrix)
{
    for (int i = 0; i < 10; i++)
    {
        for (int l = 0; l < 10; l++)
        {
            cout << matrix[i][l] << " ";
        }
        cout << endl;
    }
}

// Функція для обробки матриці та запису результату у файл
bool Processing(int** matrix, int element)
{
    // Сортування матриці
    for (int i = 0; i < 10; i++)
    {
        for (int l = 0; l < 10; l++)
        {
            for (int p = 0; p < 10 - 1; p++)
            {
                for (int q = 0; q < 10 - 1 - p; q++)
                {
                    if (matrix[i][q] < matrix[i][q + 1])
                    {
                        swap(matrix[i][q], matrix[i][q + 1]);
                    }
                }
            }
        }
    }

    // Вивід відсортованої матриці
    cout << "Sorted matrix: " << endl;
    PrintMatrix(matrix);
    cout << endl;

    // Обробка значення
    cout << "Processed element: " << element << endl;

    int sums[10] = {0};
    default_random_engine rng(random_device{}());

    // Підрахунок сум для кожного стовпця матриці
    for (int column = 0; column < 10; column++)
    {
        for (int i = 0; i < 10; i++)
        {
            sums[column] += matrix[i][column];
        }

        // Перемішування значень у стовпці матриці
        shuffle(&matrix[0][column], &matrix[0][column] + 10, rng);

        // Додавання перших 4 елементів після перемішування до суми
        for (int i = 0; i < min(4, 10); i++)
        {
            sums[column] += matrix[i][column];
        }

        sums[column] = static_cast<int>(sums[column]);
    }

    // Вивід сум для кожного стовпця
    cout << "Sums for each column: ";
    for (int i = 0; i < 10; i++)
    {
        cout << sums[i] << " ";
    }
    cout << endl;

    // Запис у файл та перевірка на успішність
    if (WriteArrayToFile(sums))
    {
        cout << "Data written to file successfully." << endl;
        return true;
    }
    else
    {
        cout << "Failed to write data to file." << endl;
        return false;
    }
}

// Основна функція програми
int main()
{
    // Створення та ініціалізація початкової матриці
    int** newMatrix = new int*[10];
    for (int i = 0; i < 10; i++)
    {
        newMatrix[i] = new int[10];
    }

    // Заповнення матриці значеннями згідно вказаного шаблону
    for (int i = 0; i < 10; i++)
    {
        for (int l = 0; l < 10; l++)
        {
            newMatrix[i][l] = number + i * 10 + l;
        }
    }

    // Вивід початкової матриці на екран
    cout << "Matrix before sorting: " << endl;
    PrintMatrix(newMatrix);

    // Зчитування значення для обробки введеного користувачем елемента
    cout << "Enter the pull request element: ";
    int PR;
    cin >> PR;

    // Обробка матриці та запис результату у файл
    Processing(newMatrix, PR);

    // Звільнення пам'яті, що була виділена для матриці
    for (int i = 0; i < 10; i++)
    {
        delete[] newMatrix[i];
    }
    delete[] newMatrix;

    return 0;
}