#include <iostream>
#include <string>
using namespace std;

int COUNT(int arr[], int size)
{
    int count = 0;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 1)
        {
            count ++;
        }
    }

    return count;
}

int COUNT(const string& words)
{
    int count = 0;
    bool inWord = false;

    for(char ch : words)
    {
        if(ch == ' ' || ch == '\t' || ch == '\n')
        {
            inWord = false;
        }
        else
        {
            if(inWord == false)
            {
            count++;
            inWord = true;
            }
        }
    }

    return count;
}


int main()
{
    int Size;
    int Arr[Size];
    string someWords;

    cout << "Enter the size of array: ";
    cin >> Size;

    cout << "Enter the numbers of array: ";
    for(int i = 0; i < Size; i++)
    {
        cin >> Arr[i];
    }

    cout << "Enter the words: ";
    cin.ignore();
    getline(cin, someWords);

    int wordcount = COUNT(someWords);
    cout << "The amount of words is: " << wordcount << endl;

    int oddNumCount = COUNT(Arr, Size);
    cout << "The amount of odd numbers is: " << oddNumCount << endl;

    return 0;
}
