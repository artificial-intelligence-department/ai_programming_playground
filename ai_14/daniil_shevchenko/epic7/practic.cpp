

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
int randomnumber()
{
    srand(time(nullptr));
    int x = rand() % 10;
    return x;
}
void bubblesort(int** array, int size, int extra = 889)
{
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (array[k][j] < array[k][j + 1])
                {
                    swap(array[k][j], array[k][j + 1]);
                }
            }
        }
    }
}
void bubblesort(double** array, int size, double extra = 889)
{
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (array[k][j] > array[k][j + 1])
                {
                    swap(array[k][j], array[k][j + 1]);
                }
            }
        }
    }
}
int** matrix_create()
{
    int** matrix = new int* [10];
    for (int i = 0; i < 10; i++)
    {
        matrix[i] = new int[10];
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = 1000 * (sin(pow(i, 3)) + pow(cos(j), 2));
        }
    }
    return matrix;

}
int* sumcount(int** array)
{

    int sum[10];
    for (int i = 0; i < 10; i++)
    {

        int index1 = randomnumber();
        int index2 = randomnumber();
        int index3 = randomnumber();
        int index4 = randomnumber();


        sum[i] = array[i][index1] + array[i][index2] + array[i][index3] + array[i][index4];
    }
    return sum;
}
bool createfile(int array[10])
{
    ofstream out("new.txt");
    if (!out)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < 10; i++)
            out << array[i] << endl;
    }
}
int openfile()
{
    ifstream in("new.txt");
    string str;
    int multiply = 1;
    while (getline(in,str))
    {
        cin >> str;
        int z = stoi(str);
        multiply = multiply *z ;
    }
    return multiply;
}
void removefile()
{
    remove("new.txt");
    cout << "File was successfully removed";
}

int main()
{
    srand(time(nullptr));
    const int a = 889;
    int** testarray = matrix_create();
    cout << "Our new handmade matrix is: " << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << testarray[i][j] << " ";
        }
        cout << endl;
    }
    bubblesort(testarray, 10);
    cout << endl;
    cout << "Sorted array is: " << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << testarray[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int sumarray[10];
    for (int i = 0; i < 10; i++)
    {

        int index1 = randomnumber();
        int index2 = randomnumber();
        int index3 = randomnumber();
        int index4 = randomnumber();


        sumarray[i] = testarray[i][index1] + testarray[i][index2] + testarray[i][index3] + testarray[i][index4];
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "The sum of row " << i + 1 << " is " << sumarray[i] << endl;
    }
    createfile(sumarray);
    if (createfile)
    {
        cout << "File was successfulle created" << endl;
    }
    else
    {
        cout << "Error while creating" << endl;
    }
    int mul = openfile();
    cout << "The multiply is" << mul;
    removefile();


}