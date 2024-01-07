#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

const int cols = 10;
const int rows = 10;
const char filename[] = "file.txt";

using namespace std;

int** create_matrix(const int number)
{
    int** matrix = new int*[10];
    for (int i = 0; i < 10; ++i)
    {
        matrix[i] = new int[10];
        for (int j = 0; j < 10; ++j)
        {
            int x = i;
            int y = j;
            int z = number;
            int fi;
            if (y - x != 0) 
            {
                fi = (x - y) * ((y - z) / (y - x)) / (1 + pow((y - x), 2));
            } 
            else 
            {
                fi = 0; // or some other suitable value
            }
            matrix[i][j] = fi;
        }
    }

    return matrix;
}

void sorting(int** matrix)
{
    for (int i = 0; i < 10; ++i) 
    {
        for (int j = 0; j < 10 - 1; ++j) 
        {
            for (int k = 0; k < 10 - j - 1; ++k) 
            {
                if (matrix[i][k] < matrix[i][k + 1]) 
                {
                    // Обмін елементів, якщо вони не відсортовані за спаданням
                    swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

void calculate_sums(int** matrix, int result[])
{
    srand(time(0));

    for(int j = 0; j < cols; ++j)
    {
        int sum = 0;
        int element = rand() % 2 + 3;

        for(int i = 0; i < element; ++i)
        {
            int rand_row = rand() % rows;
            sum += matrix[rand_row][j];
        }

        result[j] = sum;
    }
}

bool create_file(int result[])
{
    ofstream file(filename);

    if(file.is_open())
    {
        for(int i = 0; i < 10; ++i)
        {
            file << result[i] << " ";
        }

        file.close();
        return true;
    }

    return false;
}

void multiply()
{
    ifstream file(filename);

    int product = 1;
    int value;

    while (file >> value) 
    {
        product *= value;
    }

    cout << "Product of elements in the file: " << product << endl;

    file.close();    
}

void delete_file()
{
    if (remove(filename) == 0)
    {
        cout << "File deleted successfully." << endl;
    }
    else
    {
        cout << "Error deleting the file." << endl;
    }
}

int main()
{
    const int number = 981;
    int** matrix = create_matrix(number);
    sorting(matrix);

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int result[cols];
    calculate_sums(matrix, result);

    cout << "Sums of columns:" << endl;
    for (int j = 0; j < cols; ++j) {
        cout << result[j] << " ";
    }
    cout << endl;

    bool success = create_file(result);

    multiply();

    delete_file();

    // Видалення матриці
    for (int i = 0; i < 10; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
