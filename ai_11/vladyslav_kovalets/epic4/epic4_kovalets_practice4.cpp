#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str, int start, int end) 
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

bool isPalindrome(const string& str)
{
    return isPalindrome(str, 0, str.length() - 1);
}

int main() 
{
    cout << "Enter a word or number to check if it's a palindrome:" << endl;

    string input;
    cin >> input;

    if (isPalindrome(input))
    {
        cout << input << " is palindrome";
    }
    else
    {
        cout << input << " isn`t palindrome";
    }

    return 0;
}
