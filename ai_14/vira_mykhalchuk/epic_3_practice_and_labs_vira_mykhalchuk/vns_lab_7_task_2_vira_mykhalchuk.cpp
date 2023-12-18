#include <iostream>
#include <string>
using namespace std;

int countOddElements(const int arr[], int size)
{
    int oddCount = 0;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] % 2 != 0)
        {
            oddCount++;
        }
    }

    return oddCount;
}

int countWords(const string& words)
{
    int wordCount = 0;
    bool inWord = false;

    for(char ch : words)
    {
        if(ch == ' ' || ch == '\t' || ch == '\n')
        {
            inWord = false;
        }
        else
        {
            if(!inWord)
            {
                wordCount++;
                inWord = true;
            }
        }
    }

    return wordCount;
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int array[size];
    cout << "Enter the numbers of array: ";
    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    cin.ignore();

    string inputString;
    cout << "Enter the words: ";
    getline(cin, inputString);

    int oddNumCount = countOddElements(array, size);
    cout << "The amount of odd numbers is: " << oddNumCount << "\n";

    int wordCount = countWords(inputString);
    cout << "The amount of words is: " << wordCount << "\n";

    return 0;
}