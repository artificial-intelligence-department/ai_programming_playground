#include <iostream>
#include <sstream>

using namespace std;


int parniChusla(const int* arr, int size) 
{
    int count = 0;
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] % 2 == 0) 
        {
            count++;
        }
    }
    return count;
}


int slovaA(const string& str) 
{
    int count = 0;
    string word;
    istringstream stream(str);
    while (stream >> word) 
    {
        if (!word.empty() && (word[0] == 'a' || word[0] == 'A')) 
        {
            count++;
        }
    }
    return count;
}

int main() 
{
    
    int intArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arraySize = sizeof(intArray) / sizeof(int);
    int kilkistchusel = parniChusla(intArray, arraySize);
    cout << "Кількість парних елементів у масиві: " << kilkistchusel << endl;

    string inputString = "acribatics people pineapple aunt apple";
    int wordsA = slovaA(inputString);
    cout << "Кількість слів, що починаються на 'а': " << wordsA << endl;

    return 0;
}
