#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string word, int start, int end)
{

    if (start >= end)
    {
        return true;
    }

    if (word[start] == word[end])
    {
        return isPalindrome(word, start + 1, end - 1);
    }
    else
    {
        return false;
    }
}

bool isPalindrome(int num)
{
    string numString = to_string(num);
    return isPalindrome(numString, 0, numString.length() - 1);
}

int main()
{
    string word;
    int num;

    cout << "Enter word you want to check" << endl;
    cin >> word;

    cout << "Enter a number you want to check" << endl;
    cin >> num;

    if (isPalindrome(word, 0, word.length() - 1))
    {
        cout << word << " - це паліндром." << endl;
    }
    else
    {
        cout << word << " - не є паліндромом." << endl;
    }

    if (isPalindrome(num))
    {
        cout << num << " - це паліндром." << endl;
    }
    else
    {
        cout << num << " - не є паліндромом." << endl;
    }

    return 0;
}
