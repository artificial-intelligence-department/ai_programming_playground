// ConsoleApplication60.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, M;
    cin >> N;
    double* array1 = new double[N];
    for (int i = 0; i < N; i++)
    {
        cin >> array1[i];
    }
    cin >> M;
    double* array2 = new double[M];
    for (int i = 0; i < M; i++)
    {
        cin >> array2[i];
    }
    
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (array1[i] == array2[j])
            {
                k++;
            }
        }
    }
    int f = N + M - k;
    cout << k << endl;
    cout << f;
        
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
