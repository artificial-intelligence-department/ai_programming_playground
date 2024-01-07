#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

const int YOUR_PULL_REQUEST_NUMBER = 1000;
const std::string FILENAME = "output.txt"; // Назва файлу для збереження масиву
// Код компілювати через термінал (./kr "n")
bool writeToFile(int array[10])
{
    // Запис масиву у файл
    std::ofstream file(FILENAME);
    if (file.is_open())
    {
        for (int i = 0; i < 10; ++i)
        {
            file << array[i] << " ";
        }
        file.close();
        return true; // Запис відбувся успішно
    }
    else
    {
        return false; // Помилка запису у файл
    }
}

void floatMatrix(int pr_number)
{
    // Заповнення матриці значеннями з плаваючою крапкою
    float matrix[10][10];
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            matrix[i][j] = rand() % 100;
        }
    }

    // Сортування стовпців по зростанню
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10 - 1; ++j)
        {
            for (int k = 0; k < 10 - j - 1; ++k)
            {
                if (!std::isnan(matrix[k][i]) && !std::isnan(matrix[k + 1][i]))
                {
                    if (matrix[k][i] > matrix[k + 1][i])
                    {
                        std::swap(matrix[k][i], matrix[k + 1][i]);
                    }
                }
            }
        }
    }

    // Розрахунок сум для 3-4 рандомних елементів у кожному стовпці
    int sums[10] = {0};
    for (int i = 0; i < 10; ++i)
    {
        int randomElements = rand() % 2 + 3;
        for (int j = 0; j < randomElements; ++j)
        {
            int randomRow = rand() % 10;
            if (!std::isnan(matrix[randomRow][i]))
            {
                sums[i] += matrix[randomRow][i];
            }
        }
    }

    // Запис масиву сум у файл
    writeToFile(sums);

    // Обчислення добутку елементів у файлі
    int product = 1;
    for (int i = 0; i < 10; ++i)
    {
        if (!std::isnan(sums[i]))
        {
            product *= sums[i];
        }
    }

    // Виведення добутку в консоль
    std::cout << "Добуток елементів у файлі: " << product << std::endl;
}

void intMatrix(int pr_number)
{
    // Заповнення матриці цілими числами
    int matrix[10][10];
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            matrix[i][j] = rand() % 100;
        }
    }

    // Сортування рядків по спаданню
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10 - 1; ++j)
        {
            for (int k = 0; k < 10 - j - 1; ++k)
            {
                if (!std::isnan(matrix[i][k]) && !std::isnan(matrix[i][k + 1]))
                {
                    if (matrix[i][k] < matrix[i][k + 1])
                    {
                        std::swap(matrix[i][k], matrix[i][k + 1]);
                    }
                }
            }
        }
    }

    // Розрахунок сум для 3-4 рандомних елементів у кожному стовпці
    int sums[10] = {0};
    for (int i = 0; i < 10; ++i)
    {
        int randomElements = rand() % 2 + 3;
        for (int j = 0; j < randomElements; ++j)
        {
            int randomRow = rand() % 10;
            if (!std::isnan(matrix[randomRow][i]))
            {
                sums[i] += matrix[randomRow][i];
            }
        }
    }

    // Запис масиву сум у файл
    writeToFile(sums);

    // Обчислення добутку елементів у файлі
    int product = 1;
    for (int i = 0; i < 10; ++i)
    {
        if (!std::isnan(sums[i]))
        {
            product *= sums[i];
        }
    }

    // Виведення добутку в консоль
    std::cout << "Добуток елементів у файлі: " << product << std::endl;
}
int main(int argc, char **argv, char **envp)
{
    // Перевірка кількості аргументів командного рядка
    if (argc != 2)
    {
        std::cerr << "Необхідно вказати номер PR у командному рядку" << std::endl;
        return 1;
    }

    // Отримання номера PR
    int pr_number = std::stoi(argv[1]);

    // Виклик функцій, які реалізують алгоритм
    floatMatrix(pr_number);
    intMatrix(pr_number);

    return 0;
}
