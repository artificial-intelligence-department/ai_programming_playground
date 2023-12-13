#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &str, int start, int end)
{

    if (start >= end)
    {
        return true;
    }

    if (str[start] != str[end])
    {
        return false;
    }

    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int num)
{

    string str = to_string(num);
    return isPalindrome(str, 0, str.length() - 1);
}

int main()
{

    string word;
    cout << "type a word: ";
    cin >> word;
    if (isPalindrome(word, 0, word.length() - 1))
    {
        cout << "it's a palindrom." << endl;
    }
    else
    {
        cout << "it's not a palindrom." << endl;
    }

    int number;
    cout << "type in a number: ";
    cin >> number;
    if (isPalindrome(number))
    {
        cout << "it's a palindrom." << endl;
    }
    else
    {
        cout << "it's not a palindrom." << endl;
    }

    return 0;
}