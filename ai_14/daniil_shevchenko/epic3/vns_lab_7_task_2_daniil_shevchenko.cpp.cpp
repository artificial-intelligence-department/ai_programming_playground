// ConsoleApplication83.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int function(int array[], int size)
{
    int max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}
int function(string input, int size)
{
    int maxlength = 0;
    int k = 0;
    input[size] = ' ';
    for (int i = 0; i <= size; i++)
    {
        if (input[i] != ' ')
        {
            k++;
        }
        if (input[i] == ' ' )
        {
            if (k > maxlength)
            {
                maxlength = k;
            }
            k = 0;
        }


    }
    return maxlength;
}

int main()
{
    int N;
    cout << "N=";
    cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cin.ignore(30000, '\n');
    cout << "The max value of an array is " << function(arr, N) << endl;
    string test;
    getline(cin, test);
    int b = test.size();
    cout << "The longest word of the string has " << function(test, b) << " letters";
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
