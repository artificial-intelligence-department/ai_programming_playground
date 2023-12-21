#include<iostream>
using namespace std;

const int rows = 3;
const int columns = 4;
int matrix[rows][columns];
const int array_size = 2 * (rows * columns);
int matrix_array[array_size];

bool student_exists(int number)
{
    for(int i = 0; i < rows; i++)
    {
        for(int y = 0; y < columns; y++)
        {
            if(number == matrix[i][y])
            {
                return true;
            }
        }
    }
    return false;
}

void fill_matrix()
{
    cout << "------Enter number to fill matrix except zero------" << endl;

    int number;
    for(int i = 0; i < rows; i++)
    {
        for(int y = 0; y < columns; y++)
        {
            do
            {
                cout << "Element[" << i << "][" << y << "] = ";
                cin >> number;
            } while (student_exists(number));
            matrix[i][y] = number;
        }
    }
    cout << endl;
}

void print_matrix()
{
    cout << "Matrix[" << rows << "][" << columns << "]: " << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int y = 0; y < columns; y++)
        {
            cout << "[" << matrix[i][y] << "] ";
        }
        cout << endl;
    }
    cout << endl;
}

void convert_matrix_to_array()
{
    cout << "------Convertation matrix to array------" << endl;
    int index = 0;
    int i, y;
    for(i = 0; i < rows; i++)
    {
        for(y = 0; y < columns; y++)
        {
            matrix_array[index] = matrix[i][y];
            index++;
        }
    }
    for(i = 0; i < columns; i++)
    {
        for(y = 0; y < rows; y++)
        {
            matrix_array[index] = matrix[y][i];
            index++;
            matrix[y][i] = 0;
        }   
    }
    cout << endl;
}

void print_array()
{
    cout << "Array[" << array_size << "] = ";
    for(int i = 0; i < array_size; i++)
    {
        cout << "{" << matrix_array[i] << "}";
        if(i != array_size - 1)
        {
            cout << ", ";
        }
    }

    cout << endl << endl;
}

void convert_array_to_matrix()
{
    cout << "------Convertation array to matrix------" << endl;
    int index = 0; 
    int i, y;
    for(i = 0; i < rows; i++)
    {
        for(y = 0; y < columns; y++)
        {
            matrix[i][y] = matrix_array[index];
            matrix_array[index] = 0;
            index++;
        }
    }
    for(i = 0; i < columns; i++)
    {
        for(y = 0; y < rows; y++)
        {
            if(matrix[y][i] != matrix_array[index])
            {
                matrix[y][i] = matrix_array[index];
            }
            matrix_array[index] = 0;
            index++;
        }
    }
    cout << endl;
}

int main()
{
    fill_matrix();
    print_matrix();
    convert_matrix_to_array();
    print_array();
    print_matrix();
    convert_array_to_matrix();
    print_matrix();
}