#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string &str, int start, int end)
{
    int length = str.length();

    if (str[start] == str[end])
    {
        int new_start = start + 1;
        int new_end = end - 1;
        if (new_start == new_end || new_end < new_start)
        {
            return true;
        }
        else
        {
            return isPalindrome(str, new_start, new_end);
        }
    }
    else
    {
        return false;
    }
}

bool isPalindrome(int number)
{
    string str = to_string(number);
    return isPalindrome(str, 0, str.length() - 1);
}

int main()
{
    string palindrom;
    cin >> palindrom;
    cout << (isPalindrome(palindrom, 0, palindrom.length() - 1) ? "yes" : "no") << endl;
    int palindrom_n;
    cin >> palindrom_n;
    cout << (isPalindrome(palindrom_n) ? "yes" : "no");
    return 0;
}