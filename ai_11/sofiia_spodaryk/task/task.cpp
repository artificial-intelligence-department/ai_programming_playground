#include <iostream>
#include <cstdlib> // Для використання rand()
#include <ctime>
#include <fstream> // Для використання файлів

using namespace std;

const int PR_NUMBER = 897; //цілочисельна змінна
const char FILENAME[] = "evaluation.txt";

int calculateResult(int distance, int consumption, int price)
{
    return distance * consumption * price * 2 / 100;
}

int **createAndFillIntMatrix()
{ // динамічна матриця - завдання 1b
    int **matrix = new int *[10];
    for (int i = 0; i < 10; ++i)
    {
        matrix[i] = new int[10];
        for (int j = 0; j < 10; ++j)
        {
            matrix[i][j] = calculateResult(i + PR_NUMBER, j + PR_NUMBER, PR_NUMBER);
        }
    }
    return matrix;
}

//  сортування стовпців по зростанню для матриці з числами з плаваючою крапкою методом бульбашки - завдання 2а
void sortColumns(double **matrix, int cols)
{
    for (int j = 0; j < cols; ++j)
    {
        for (int i = 0; i < 10 - 1; ++i)
        {
            for (int k = 0; k < 10 - i - 1; ++k)
            {
                if (matrix[k][j] > matrix[k + 1][j])
                {
                    swap(matrix[k][j], matrix[k + 1][j]);
                }
            }
        }
    }
}

// сортування рядків по спаданню для матриці з цілими числами методом бульбашки - завдання 2b
void sortRows(int **matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < 10 - 1; ++j)
        {
            for (int k = 0; k < 10 - j - 1; ++k)
            {
                if (matrix[i][k] < matrix[i][k + 1])
                {
                    swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

// виведення матриці на екран.
void printMatrix(int **matrix)
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//  генератор випадкових чисел для вибору рандомних елементів у кожному стовпці та обчислення їхньої суми - завдання 3
int *calculateColumnSums(int **matrix)
{
    int *sums = new int[10];
    for (int j = 0; j < 10; ++j)
    {
        int sum = 0;
        for (int k = 0; k < 10; ++k)
        {
            // Беремо 3-4 рандомні елементи у кожному стовпці.
            int randomIndex = rand() % 10;
            sum += matrix[randomIndex][j];
        }
        sums[j] = sum;
    }
    return sums;
}

bool writeArrayToFile(int *array) // завданя 4
{
    ofstream outputFile("evaluation.txt"); // Створюємо об'єкт для запису у файл

    if (outputFile.is_open())
    {
        for (int i = 0; i < 10; ++i)
        {
            outputFile << array[i] << " "; // Записуємо кожен елемент у файл
        }

        outputFile.close(); // Закриваємо файл
        return true;        // Повертаємо true, якщо запис відбувся успішно
    }

    return false; // Якщо файл не вдалося відкрити, повертаємо false
}

long long calculateProductFromFile() // читання з файлу та обчислення добутку - завдання 5
{
    long long product = 1;
    ifstream inputFile(FILENAME);

    if (inputFile.is_open())
    {
        int value;
        while (inputFile >> value)
        {
            product *= value;
        }

        inputFile.close();
    }
    return product;
}

void deleteFile() // видалення файлу - завдання 6
{
    if (remove(FILENAME) == 0)
    {
        cout << "\nFile successfully deleted.\n";
    }
    else
    {
        cerr << "\nError deleting file.\n";
    }
}

int main()
{
    srand(time(nullptr)); // встановлює початкове значення для генератора випадкових чисел

    // Викликаємо функцію для матриці з цілими числами за вказаною математичною функцією.
    int **intMatrix = createAndFillIntMatrix();
    printMatrix(intMatrix);

    // Сортуємо рядки за спаданням для матриці з цілими числами.
    sortRows(intMatrix, 10);

    cout << "\nSorted Rows :\n";
    printMatrix(intMatrix);

    // виведення сум стовпців матриці
    int *columnSums = calculateColumnSums(intMatrix);
    cout << "\nColumn Sums:\n";
    for (int i = 0; i < 10; ++i)
    {
        cout << columnSums[i] << " ";
    }
    cout << endl;

    // запис у файл
    bool writeSuccess = writeArrayToFile(columnSums);
    if (writeSuccess)
        cout << "\nArray successfully written to file.\n";

    // читання з файлу та обчислення добутку
    long long product = calculateProductFromFile();
    cout << "\nProduct of array elements from file: " << product << endl;

    deleteFile(); // видалення файлу

    // Звільнюємо пам'ять для того, щоб уникнути утечок пам'яті
    for (int i = 0; i < 10; ++i)
    {
        delete[] intMatrix[i];
    }
    delete[] intMatrix;

    return 0;
}