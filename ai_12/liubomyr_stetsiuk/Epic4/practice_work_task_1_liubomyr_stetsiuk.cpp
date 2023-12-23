#include <iostream>
#include <string>

using namespace std;

bool checkPalindrome(const string &str, int left, int right)
{
    if (left >= right)
    {
        return true;
    }
    if (str[left] != str[right])
    {
        return false;
    }
    return checkPalindrome(str, left + 1, right - 1);
}

bool isPalindrome(int n)
{
    string intString = to_string(n);
    return checkPalindrome(intString, 0, intString.length() - 1);
}

int main()
{
    cout << "Enter a word to check whether it's a palindrome: " << endl;
    string userInput;
    cin >> userInput;

    int start = 0, end = userInput.length() - 1;

    if (checkPalindrome(userInput, start, end))
    {
        cout << userInput << " is a palindrome.";
    }
    else
    {
        cout << userInput << " is not a palindrome.";
    }

    cout << endl
         << endl
         << "Enter a number to check whether it's a palindrome: " << endl;
    int numInput;
    cin >> numInput;

    if (isPalindrome(numInput))
    {
        cout << numInput << " is a palindrome.";
    }
    else
    {
        cout << numInput << " is not a palindrome.";
    }

    return 0;
}
