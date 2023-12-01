#include <iostream>

using namespace std;

bool isPalindrome(const string& str, int start, int end)
{
    
    if(start >= end)
    {
        return true;
    }
    
    if(str[start] == str[end])
    {
        return(isPalindrome(str, start + 1, end - 1));
    }
    else
    {
        return false;
    }

    return true;
};

bool isPalindrome(int number)
{
    string str = to_string(number);
    int start = 0;
    int end = str.length() - 1;
    
    return isPalindrome(str, start, end);
};

int main()
{
    string str;
    int number;

    cout << "Enter your word: ";
    cin >> str;
    
    cout << "Enter your number: ";
    cin >> number;

    int start = 0;
    int end = str.length() - 1;

    if(isPalindrome(str, start, end) == true)
    {
        cout << "This is a palindrome" << endl;
    }
    else
    {
        cout << "This is not a palindrome" << endl;
    }

    if(isPalindrome(number) == true)
    {
        cout << "This is a palindrome" << endl;
    }
    else
    {
        cout << "This is not a palindrome" << endl;
    }
    
    return 0;
}
