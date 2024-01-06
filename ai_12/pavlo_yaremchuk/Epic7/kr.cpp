#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

const int nomer = 990;

double func(double a, double b)
{
    return a + b;
}

void createMatrix(double a, double matrix[10][10];)
{
    matrix[i][j] = a;
}

void sortColumns(double matrix[10][10])
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (matrix[i][j] > matrix[i][j + 1])
            {
                double m = matrix[i][j];
                matrix[i][j] = matrix[i][j + 1];
                matrix[i][j + 1] = m; 
            }
        }
    }
}

void sortColumns(int matrix[10][10], int nomer)
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (matrix[j][i] < matrix[j + 1][i])
            {
                double m = matrix[j][i];
                matrix[j][i] = matrix[j + 1][i];
                matrix[j + 1][i] = m; 
            }
        }
    }
}

int calculateSums(double matrix[][])
{
    int sums[10];
    sprand(time(0));
    for (int i = 0; i < 10; ++i)
    {
        double columnSum = 0.0;
        for (int j = 0; j < min(4, rand() % 2 + 3); ++j)
        {
            columnSum += matrix[j][i];
        }
        sums[j] = static_cast<int>(columnSum);
    }
    return sums;
}

bool AddToFile(const int sums[10], const string& filename)
{
    ofstream file(filename);
    if (file.is_open())
    {
        for (int i = 0; i < 10; ++i)
        {
            file << sums[i] << ' ';
        }
        file.close();
        return true;
    }
    else
    {
        return false;
    }
}

int calculateFile(const string& filename)
{
    ifstream file(filename);

    if (file.is_open())
    {
        int prod = 1;
        int value;
        
        while (file >> value)
        {
            prod *= value;
        }

        cout << prod << endl;
        file.close();
        return prod;
    }
}

void deleteFile(const string& filename)
{
    if (remove(filename.c_str()) == 0)
    {
        cout << filename << " deleted" << endl;
    }
    else 
    {
        cerr << "Error" << endl;
    }
}



int main()
{
    double q, w, e, r, t, y, u, i, o, p;
    double q1, w1, e1, r1, t1, y1, u1, i1, o1, p1;
    double a = func(q, q1);
    double b = func(w, w1);
    double d = func(e, e1);
    double f = func(r, r1);
    double g = func(t, t1);
    double h = func(u, u1);
    double j = func(i, i1);
    double k = func(o, o1);
    double l = func(p, p1);





    return 0;
}