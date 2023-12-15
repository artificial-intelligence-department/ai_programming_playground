#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>

using namespace std;
const int rows = 10;
const int cols = 10;

// створення і повернення матриці 10 на 10

void createFunctionMatrix(double matrix[rows][cols])
{

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            double x = i * cols + j;
            matrix[i][j] = (sin(pow(2 + x, 2))) / (2 + x);
        }
    }
}
// функція для виведення матриці в термінал

void printMatrix(const double matrix[rows][cols])
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
// бабл сорт
void bubbleSortColumns(double matrix[rows][cols])
{
    for (int j = 0; j < cols; ++j)
    {
        for (int i = 0; i < rows - 1; ++i)
        {
            for (int k = 0; k < rows - i - 1; ++k)
            {
                if (matrix[k][j] > matrix[k + 1][j])
                {
                    // Обмін елементів, якщо потрібно
                    double temp = matrix[k][j];
                    matrix[k][j] = matrix[k + 1][j];
                    matrix[k + 1][j] = temp;
                }
            }
        }
    }
}
// розрахунок сум
int *calculateSums(const double matrix[rows][cols])
{
    static int sums[10];

    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned int>(time(0)));

    for (int j = 0; j < cols; ++j)
    {
        double columnSum = 0.0;
        for (int k = 0; k < 4; ++k)
        {
            int randomIndex = rand() % rows; // Генерація рандомного індексу рядка
            columnSum += matrix[randomIndex][j];
        }

        // Перевірка, чи сума має дробову частину та додавання до масиву
        sums[j] = static_cast<int>(columnSum);
    }

    return sums;
}

void printArray(const int array[10])
{
    for (int i = 0; i < 10; ++i)
    {
        cout << array[i] << "\t";
    }
    cout << std::endl;
}

bool writeArrayToFile(const int array[10], const string &filename)
{
    ofstream outFile(filename);

    if (!outFile.is_open())
    {
        cerr << "couldn't find file" << endl;
        return false;
    }

    for (int i = 0; i < 10; ++i)
    {
        outFile << array[i] << " ";
    }

    outFile.close();
    return true;
}

int main()
{
    double resultMatrix[rows][cols];

    const int X = 998;

    createFunctionMatrix(resultMatrix);

    if (X % 2 == 0)
    {
        printMatrix(resultMatrix);

        cout << "  " << endl;

        bubbleSortColumns(resultMatrix);

        cout << "  " << endl;

        printMatrix(resultMatrix);

        int *sums = calculateSums(resultMatrix);
        cout << "\n Sum array:" << endl;
        printArray(sums);

        if (writeArrayToFile(sums, "output.txt"))
        {
            std::cout << "Array has been succesfully inputed in file." << std::endl;
        }
        else
        {
            std::cerr << "error." << std::endl;
        }
    }
    else
    {

        printMatrix(resultMatrix);

        // видає нулі, тому що всі значення від 0 до 1

        cout << "  " << endl;

        bubbleSortColumns(resultMatrix);

        cout << "  " << endl;

        printMatrix(resultMatrix);

        int *sums = calculateSums(resultMatrix);
        cout << "\n Sum array:" << endl;
        printArray(sums);

        if (writeArrayToFile(sums, "output.txt"))
        {
            cout << "Array has been succesfully inputed in file." << endl;
        }
        else
        {
            cerr << "error" << endl;
        }
    }
}
