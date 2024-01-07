#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

float** create_float_matrix()
{
    float** matrix = new float * [10]; //3 в коді використана як мінімум одна дійсний з подвійною точністю змінна 
    for (int i =0; i < 10; ++i)
    {
        matrix[i]  = new float[10];
        for (int j = 0; j < 10; ++j) // 10 в коді використаний for цикл
        {
            matrix[i][j] = cos(j) - i; // 15 в коді використано математичні операції та математичні функції
        }
    }
    return matrix;
}

int** create_int_matrix()
{
    int** matrix = new int * [10]; // 7 в коді використаний двовимірний масив
    for (int i = 0; i < 10; ++i) // 10 в коді використаний for цикл
    {
        matrix[i] = new int[10];
    
        for (int j = 0; j < 10; ++j)
        {
            matrix[i][j] = pow(j,2) - i; // 15 в коді використано математичні операції та математичні функції
        }
    }
    return matrix;
}

void sort_col(float** matrix)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; ++j)
        {
            for (int k = 0; k < 9 - j; ++k)
            {
                if (matrix[k][i] < matrix[k + 1][i]) // 5 в коді використані умовні оператори та розгалуження
                {
                    swap (matrix[k][i], matrix[k + 1][i]);
                }
            }
        }
    }
}

void sort_row(int** matrix)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; ++j)
        {
            for (int k = 0; k < 9 - j; ++k)
            {
                if (matrix[i][k] < matrix[i][k + 1])
                {
                    swap (matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

int* Sum_arr (int* sum)
{
    for (int i = 0; i < 10; ++i)
    {
        cout << sum[i] << " ";
    }
    return sum;
}

void print_matrix (float** float_matrix)
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << float_matrix[i][j] << " ";
        }
     cout << endl;
    }
}

void print_matrix (int** int_matrix) // 12 в коді використано перевантаження функції
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << int_matrix[i][j] << " ";
        }
     cout << endl;
    }
}

int* calculate_sum_create_arr (float** matrix)
{
    int* sums_arr = new int[10]; // 6 в коді використаний одновимірний масив
    srand(time(0));
    for (int i = 0; i < 10; ++i)
    {
        int sum = 0; // 2 в коді використана як мінімум одна дійсна змінна
        for (int j = 0; j < 4; ++j)
        {
            int random_index = rand() % 10;
            sum += static_cast <int> (matrix [random_index][i]);
        }
        sums_arr[i] = sum;
    }
    return sums_arr;
}

int* calculate_sum_create_arr (int** matrix)
{
    int* sums_arr = new int[10]; // 6 в коді використаний одновимірний масив
    srand(time(0));
    for (int i = 0; i < 10; ++i)
    {
        int sum = 0; // 2 в коді використана як мінімум одна дійсна змінна
        for (int j = 0; j < 4; ++j)
        {
            int random_index = rand() % 10;
            sum += static_cast <int> (matrix [random_index][i]);
        }
        sums_arr[i] = sum;
    }
    return sums_arr;
} 

bool write_to_file (const int* arr, const string filename)
{
    ofstream output_file (filename); // 16 в коді використано функції роботи з файлами, для того, щоб записати у файл

    if (!output_file.is_open())
    {
       cout << "Помилка відкриття файлу\n";
       return false;
    }
    for (int i = 0; i < 10; ++i)
    {
        output_file << arr[i] << " ";
    }
    output_file.close();
    return true;
}

long long calculate_from_file (const string & filename)
{
    ifstream input_file (filename); // 17 в коді використано функції роботи з файлами, для того, щоб зчитати з файлу

    if (!input_file.is_open())
    {
        cout << "Помилка відкриття файлу\n";
        return 0;
    }
    long long product = 1;
    int value;

    while (input_file >> value)
    {
        product *= value;
    }

    input_file.close();
    return product;
}

void delete_file (const string & filename)
{
    if (remove (filename.c_str()) !=0)
    {
        cout << "Помилка видалення файлу\n";
    }
    else
    {
        cout << "Файл збережено\n";
    }
}


int main()
{
    const int number_PR = 767; // 4 в коді використана як мінімум одна цілочисельна константа
    const string filename = "file.txt";

    if (number_PR % 2 == 0) // 5 в коді використані умовні оператори та розгалуження
    {
        float** float_matrix = create_float_matrix();
        cout << "Початкова матриця\n"; // 18 в коді використано оператори виведення та введення даних
        print_matrix (float_matrix);
        sort_col (float_matrix);
        cout << "Відсортована матриця\n";
        print_matrix (float_matrix);
        int* sum = calculate_sum_create_arr (float_matrix);
        cout << "Сума масивів:\n";
        Sum_arr (sum); // 14 в коді використано параметри та аргументи функції
        cout << endl;

        if (write_to_file(sum, filename))
        {
            cout << "масив записано в файл\n";
        }
        else
        {
            cout << "Помилка записання масиву в файл\n";
        }

        long long product = calculate_from_file (filename);
        cout << "Добуток елементів з файлу: " << product << endl;

    }
    else
    {
        int** int_matrix = create_int_matrix();
        cout << "Початкова матриця\n";
        print_matrix (int_matrix);
        sort_row (int_matrix);
        cout << "Відсортована матриця\n";
        print_matrix (int_matrix);
        int* sum = calculate_sum_create_arr (int_matrix);
        cout << "Сума масивів:\n";
        for (int i = 0; i < 10; ++i)
        {
            cout << sum[i] << "";
        }
            cout << endl;

        if (write_to_file (sum, filename))
        {
            cout << "масив записано в файл\n";
        }
        else
        {
            cout << "Помилка записання масиву в файл\n"; 
        }
        long long product = calculate_from_file (filename);
        cout << "Добуток елементів з файлу: " << product << endl;
        delete_file (filename);
    }
    return 0;
}