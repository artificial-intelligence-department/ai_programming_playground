#include <iostream>
#include <sstream>

using namespace std;

int countEvenNumbers(const int *arr, int size)
{
    int sumOfEvenNumbers = 0;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] % 2 == 0)
        {
            sumOfEvenNumbers++;
        }
    }
    return sumOfEvenNumbers;
}

int countWordsStartingWithA(const string &str)
{
    int sumofAwords = 0;
    istringstream stream(str);
    string word;
    while (stream >> word)
    {
        if (!word.empty() && (word[0] == 'a' || word[0] == 'A'))
        {
            sumofAwords++;
        }
    }
    return sumofAwords;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arraySize = sizeof(intArray) / sizeof(int);
    int sumOfNumbers = countEvenNumbers(intArray, arraySize);
    cout << "Sum of Even nubmers: " << sumOfNumbers << endl;

    string randomStrings = "car Bike acomodation Apropriate jacket appple";
    int wordsStartingWithA = countWordsStartingWithA(randomStrings);
    cout << "Sum of words start with A: " << wordsStartingWithA << endl;

    return 0;
}
