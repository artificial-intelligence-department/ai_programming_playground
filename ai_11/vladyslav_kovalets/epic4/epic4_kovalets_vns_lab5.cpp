#include <iostream>
const int rows = 5;
const int columns = 3;
using namespace std;

void swapRows(int array[rows][columns], int row1, int row2, int columns) 
{
    for (int i = 0; i < columns; i++) 
    {
        int temp = array[row1][i];
        array[row1][i] = array[row2][i];
        array[row2][i] = temp;
    }
}

int main() 
{

    int array[rows][columns];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++) 
        {
            array[i][j] = rand() % 10; // Заповнюємо масив випадковими числами
        }
    }

    // Виведення початкового масиву
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
            std::cout << array[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    // Сортування по елементах третього стовпця
    for (int i = 0; i < rows - 1; i++) 
    {
        for (int j = 0; j < rows - i - 1; j++) 
        {
            if (array[j][2] > array[j + 1][2]) 
            {
                swapRows(array, j, j + 1, columns);
            }
        }
    }

    // Виведення відсортованого масиву
    cout << endl;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
            std::cout << array[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    return 0;
}
