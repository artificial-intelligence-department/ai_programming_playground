#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;



double func(const int pr, int a)
{
    double R, b = 0.05;
    R = ((pow(pr, 2)) * (pr + 1)) / b - pow( sin(pr - a), 2);
    return R;
}

double* matrix_double (double pr)
{
    double matrix[10][10];
    int a = 1;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {   
            a++;
            matrix[i][j] = func(pr, a);
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return *matrix;
}
int *matrix_int (int pr)
{
    int matrix[10][10];
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            matrix[i][j] = func(pr);
            cout << func(pr) << " ";
        }
        cout << endl;
    }
    return *matrix;
}

int* sort(double* matrix, double n)
{
    for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 9; j++)
            {
               if (matrix[i][j] > matrix[i][j + 1])
               {
                    swap(matrix[i][j], matrix[i][j + 1]);
               }
                
            }


        }
    return matrix;
}

int* sort(int* matrix, int n)
{
     for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 9; j++)
            {
               if (matrix[i][j] > matrix[i][j + 1])
               {
                    swap(matrix[i][j], matrix[i][j + 1]);
               }
                
            }

        }
        return matrix;
}

int* sum(int* matrix)
{
    static int newmatrix[10];
    
    for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                newmatrix[i] += matrix[i][j];
            }
            
        }
    return newmatrix;
}

bool write(int* matrix, string path)
{
    ifstream file;
    file.open(path);
    if(!file.is_open())
    {
        return false;
    }
    else

    {
        int res;
        for(int i = 0; i < 10; i++)
        {
                int v;
                v >> matrix[i];
                res *= v;
        }
        cout << res;
        file.close();
    }
    return true;

}
bool read(int* matrix, string path)
{
    ofstream file;
    file.open(path);
    if(!file.is_open())
    {
        return false;
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                file << matrix[i][j];
            }
            
        }
        file.close();
    }
    return true;

}
void deleteFile( string path)
{

}
int main()
{
    const string path = "pract.txt";
    int p;
    cin >> p;
    const int pr = p;
    int matrix[10];
    if (pr %2 == 0)
        sum( sort (matrix_double(pr), pr));
    else sum(sort (matrix_int(pr), pr));
    

    return 0;
}
