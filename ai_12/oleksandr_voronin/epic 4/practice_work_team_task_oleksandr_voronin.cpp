#include <iostream>
#include <string>
using namespace std;

bool Palindrom(string word, int first, int last)
{

    if (first >= last)
    {
        return true;
    }

    if (word[first] == word[last])
    {
        return Palindrom(word, first + 1, last - 1);
    }
    else
    {
        return false;
    }
}

bool Palindrom(int number)
{
    string numberstring = to_string(number);
    return Palindrom(numberstring, 0, numberstring.length() - 1);
}

int main()
{
    string word;
    int number;

    cout << "Enter word: " << endl;
    cin >> word;

    cout << "Enter a number: " << endl;
    cin >> number;

    if (Palindrom(word, 0, word.length() - 1))
    {
        cout << word << " this is palindrom" << endl;
    }
    else
    {
        cout << word << " is not palindrom" << endl;
    }

    if (Palindrom(number))
    {
        cout << number << " this is palindrom" << endl;
    }
    else
    {
        cout << number << " is not palindrom" << endl;
    }

    return 0;
}