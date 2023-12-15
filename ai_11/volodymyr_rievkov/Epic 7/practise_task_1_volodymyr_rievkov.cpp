#include<iostream>
#include<cmath>
using namespace std;

const int size_m = 10;
double matrix_d[size_m][size_m];
int matrix_i[size_m][size_m];

bool is_pair(int number)
{
    if(number % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double calculate_function(double x)
{
    double z = abs(x) + pow(x, 2);
    return z * pow(sin(2 + x), 2) / (2 + x);
}

void fill_double_matrix()
{
    for(int i = 0; i < size_m; i++)
    {
        for(int y = 0; y < size_m; y++)
        {
            matrix_d[i][y] = calculate_function(i + y);
        }
    }
}

void fill_int_matrix()
{
    for(int i = 0; i < size_m; i++)
    {
        for(int y = 0; y < size_m; y++)
        {
            matrix_i[i][y] = calculate_function(i + y);
        }
    }
}

void print_double_matrix()
{
    cout << "----Double matrix----" << endl;
    for(int i = 0; i < size_m; i++)
    {
        for(int y = 0; y < size_m; y++)
        {
            cout << "[" << matrix_d[i][y] << "] ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_int_matrix()
{
    cout << "----Int matrix----" << endl;
    for(int i = 0; i < size_m; i++)
    {
        for(int y = 0; y < size_m; y++)
        {
            cout << "[" << matrix_i[i][y] << "] ";
        }
        cout << endl;
    }
    cout << endl;
}

void sort_double_matrix_asc(double matrix[][size_m])
{
    cout << "----Sorted double matrix----" << endl;
    for(int z = 0; z < size_m; z++)
    {
        for (int i = 0; i < size_m; i++)
        {
            for (int y = 0; y < size_m; y++)
            {
                if (matrix[y][i] < matrix[y + 1][i])
                {
                    int temp = matrix[i][y];
                    matrix[i][y] = matrix[i + 1][y];
                    matrix[i + 1][y] = temp;
                }
            }
        }
    }
}

void sort_int_matrix_desc()
{

}

int main()
{
    const int number_pr = 956;
    if(is_pair(number_pr))
    {
        fill_double_matrix();
        print_double_matrix();
        sort_double_matrix_asc(matrix_d);
        print_double_matrix();
    }
    else
    {
        fill_int_matrix();
        print_int_matrix();
    }
}