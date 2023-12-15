#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string str, int start, int end);
bool isPalindrome(int number);

int main()
{
    cout << boolalpha;

    cout << "If datatype is int enter 0: ";
    int input;
    cin >> input;

    bool isStr = (input == 0 ? false : true);

    if (isStr)
    {
        string str;
        cout << "Enter string: ";
        cin >> str;

        cout << "This string " << (isPalindrome(str, 0, str.length() - 1) ? "is" : "is not") << " a palidrome"
             << "\n";
    }
    else
    {
        int num;
        cout << "Enter int: ";
        cin >> num;

        cout << "This string " << (isPalindrome(num) ? "is" : "is not") << " a palidrome"
             << "\n";
    }

    return 0;
}

bool isPalindrome(const string str, int start, int end)
{
    if (end == 0 && start == str.length() - 1 && str[start] == str[end])
    {
        return true;
    }

    if (str[start] != str[end])
    {
        return false;
    }

    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int number)
{
    string str = to_string(number);
    return isPalindrome(str, 0, str.length() - 1);
}