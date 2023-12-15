// ConsoleApplication87.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;
int** modifier(int array[], int size)
{
    srand(time(nullptr));
    int** array2 = new int* [size];
    for (int i = 0; i < size; i++)
    {
        array2[i] = new int[size];
    }
    int** random = new int*[size-1];
    for (int i = 0; i < size-1; i++)
    {
        random[i] = new int[size];
    }
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size; j++)
        {
            random[i][j] = rand() % 20 - 10;
            if (random[i][j] == 0)
            {
                random[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size; j++)
        {
            array2[i][j] = random[i][j];
        }
        
    }
    
    int* sumarray = new int[size];
    for (int k = 0; k < size; k++)
    {
        sumarray[k] = 0;
    }
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            sumarray[j] = sumarray[j] + array2[i][j];
        }

    }
    for (int k = 0; k < size; k++)
    {
        array2[size - 1][k] = array[k] - sumarray[k];
    }
    return array2;
}

int main()
{
    
    int N;
    cin >> N;
    int* input = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
    }
    int** ourarray = new int* [N];
    for (int i = 0; i < N; i++)
    {
        ourarray[i] = new int[N];
    }
    ourarray = modifier(input, N);
    cout << "THE MATRIX IS:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (ourarray[i][j] > 0)
            {
                cout << "+";
            }
            cout << ourarray[i][j] << " ";
        }
        cout << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
