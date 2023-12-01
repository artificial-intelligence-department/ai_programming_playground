#include <iostream>
#include <cmath>

using namespace std;

bool isPalindrome(const string& str, int start, int end);
bool isPalindrome(const int& x);
bool isInt(string str);

int main()
{
    string string;
    int number;

    cout << "Enter a word or number to check if it's a palindrome:\n";

    if (!(cin >> string))
    {
        cout << "Wrong input.\n";
        return 1;
    }

    if(isInt(string))
    {
        number = stoi(string);

        cout << number << (isPalindrome(number) ? " is" : " is not") << " a palindrome.\n";
    }
    else
    {
        cout << string << (isPalindrome(string, 0, string.length() - 1) ? " is" : " is not") << " a palindrome.\n";
    }

    return 0;
}

bool isPalindrome(const string& str, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    
    if(str[start] !=  str[end])
    {
        return false;
    }

    return isPalindrome(str, start + 1, end - 1);
}
bool isPalindrome(const int& x)
{
    return isPalindrome(to_string(x), 0, to_string(x).length() - 1);
}
bool isInt(string str)
{
    for (const auto &element : str)
    {
        if(!isdigit(element))
        {
            return false;
        }
    }

    return true;
}
