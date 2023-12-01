// ConsoleApplication92.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
bool presence(int x, int array[], int size)
{
    bool inarray = false;
    for (int i = 0; i < size; i++)
    {
        if (x == array[i])
        {
            inarray = true;
        }
       
    }
    return inarray;
}
int* erase(int array[], int n, int erasevalues[], int m, int& count)
{
    vector<int> newarray;
    newarray.resize(n);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (!presence(array[i], erasevalues, m))
        {
            newarray[j] = array[i];
            j++;
        }
    }
        newarray.resize(j);
        int* newarray2 = new int[j];
        for (int i = 0; i < j; i++)
        {
            newarray2[i] = newarray[i];
        }
        count = j;
        return newarray2;
    
}
int* modifiedarray(int array[], int n, int &count)
{
    vector<int> modified;
    modified.resize(2*n);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 == 0)
        {
            modified[j] = 0;
            modified[j + 1] = array[i];
            j = j + 2;
        }
        else
        {
            modified[j] = array[i];
            j++;
        }
    }
    modified.resize(j);
    int* newarray3 = new int[j];
    count = j;
    for (int i = 0; i < j; i++)
    {
        newarray3[i] = modified[i];
    }
    return newarray3;
}

int main()
{
    srand(time(nullptr));
    int N;
    cout << "Enter the length of an array: ";
    cin >> N;
    int* myarray = new int[N];
    for (int i = 0; i < N; i++)
    {
        myarray[i] = rand() % 100 - 50;
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << myarray[i] << " ";
    }
    cout << endl;
    int M;
    cout << "Enter the amount of elements you want to erase: ";
    cin >> M;
    int* erasearray = new int[M];
    for (int i = 0; i < M; i++)
    {
        cin >> erasearray[i];
    }
    int erasecount = 0;
    myarray = erase(myarray, N, erasearray, M, erasecount);
    cout << "The length of the new array is " << erasecount << endl;
    cout << "The new array with erased elements is: " << endl;
    for (int i = 0; i < erasecount; i++)
    {
        cout << myarray[i] << " ";
    }
    cout << endl;
    
    int modifiedcount = 0;
    myarray = modifiedarray(myarray, erasecount, modifiedcount);
    cout << "The length of the modified array is: " << modifiedcount << endl;
    cout << "The new array after adding 0 before even numbers: " << endl;
    for (int i = 0; i < modifiedcount; i++)
    {
        cout << myarray[i] << " ";
    }
    cout << endl;

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
