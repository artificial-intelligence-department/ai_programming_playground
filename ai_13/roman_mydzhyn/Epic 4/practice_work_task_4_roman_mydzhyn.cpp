#include <iostream>
#include <string>

using namespace std;


bool isPalindrome(const string& str, int start, int end) 
{
    if (start >= end) 
    {
        return true;
    }

    if (str[start] == str[end]) 
    {
        return isPalindrome(str, start + 1, end - 1);
    }

    return false;
}

bool isPalindrome(int num) 
{
    string numStr = to_string(num);
    return isPalindrome(numStr, 0, numStr.length() - 1);
}

int main() 
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str, 0, str.length() - 1)) 
    {
        cout << str << " is a palindrome.\n";
    } else 
    {
        cout << str << " is not a palindrome.\n";
    }

    return 0;
}