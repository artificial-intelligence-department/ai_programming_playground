#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str, int start, int end)
{
    if (start <= end)
    {
        if (str[start] == str[end])
        {
            return isPalindrome(str, start + 1, end - 1);
        }
        else return false;
    }
    else return true;
}

bool isPalindrome(long long num, int start, int end)
{
    return isPalindrome(to_string(num), start, end);
}

int main()
{
    string str;
    long long num;
    cout << "Enter your string: ";
    cin >> str;
    cout << "Enter your number: ";
    cin >> num;
    if (isPalindrome(str, 0, str.length() - 1))
    {
        cout << "Your string is a palindrome\n";
    }
    else cout << "Your string is not a palindrome\n";

    if (isPalindrome(num, 0, to_string(num).length() - 1))
    {
        cout << "Your number is a palindrome\n";
    }
    else cout << "Your number is not a palindrome\n";
}    