#include <iostream>
#include <random>
#include <fstream>
using namespace std;

int** intarr()
{
    int** arr = new int*[10];
    int num = 0; //вимога 1

    for(int i = 0; i < 10; i++)
    {
        arr[i] = new int[10];
        for(int j = 0; j < 10; j++)
        {
            arr[i][j] = num;
            num++;
        }
    }

    return arr;
}

double** doublearr()
{
    double** arr = new double*[10]; //вимога 3
    double num = 0.0;

    for(int i = 0; i < 10; i++)
    {
        arr[i] = new double[10];
        for(int j = 0; j < 10; j++)
        {
            arr[i][j] = num;
            num++;
        }
    }

    return arr;
}

double** sort1(double** arr)
{
    double temp;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(arr[i+1][j] > arr[i][j])
            {
                temp = arr[i][j];
                arr[i+1][j] = arr[i][j];
                arr[i+1][j] = temp;
            }
        }
    }

    return arr;
}

int** sort1(int** arr, int n) //вимога 11 //вимога 14
{
    int temp;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(arr[i][j] < arr[i+1][j])
            {
                temp = arr[i][j];
                arr[i+1][j] = arr[i][j];
                arr[i+1][j] = temp;
            }
        }
    }

    return arr;
}

int* function3(int** arr) //вимога 7
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 9);

    int* output = new int[10]; //вимога 6
    for(int i = 0; i < 10; i++) //вимога 10
    {
        output[i] = arr[dis(gen)][dis(gen)] + arr[dis(gen)][dis(gen)] + arr[dis(gen)][dis(gen)];
    }

    return output;
}

bool function4(int* arr, const string filename)
{
    ofstream file(filename); //вимога 16

    if(!file.is_open()) //вимога 5
    {
        return false;
    }

    for(int i = 0; i < 10; i++)
    {
        file << arr[i] << endl;
    }

    file.close();
    return true;
}

int function5(const string filename)
{
    ifstream file(filename); //вимога 17

    if(!file.is_open())
    {
        return -1;
    }

    int num;
    int sum = 0;
    while(file >> num)
    {
        sum *= num;
    }

    file.close();

    cout << sum << endl;  //вимога 18
    return sum;
}

void deleteFile(string filename)
{
    remove(filename.c_str());
    cout << "File deleted" << endl;
}

int main()
{
    float a = 0.0; //вимога 2
    const int num = 788; //вимога 4

    int** arr1 = intarr();
    double** arr2 = doublearr();

    cout << endl;
    cout << endl;

    arr1 = sort1(arr1, num);

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
//    arr2 = sort1(arr2);
//
//    int* arr3 = function3(arr1);
//
//    const string filename = "output.txt";
//    function4(arr3, filename);
//    function5(filename);

    return 0;
}