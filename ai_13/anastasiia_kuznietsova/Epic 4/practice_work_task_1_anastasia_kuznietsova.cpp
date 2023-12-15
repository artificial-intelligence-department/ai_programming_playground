#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string& str, int start, int end)
{
    if (start>end)
        return false;
    if (start==end)
        return true;

return isPalindrome(str, start+1, end-1);
}

bool isPalindrome(int number)
{
    string str=to_string(number);

return isPalindrome(str, 0, str.size()-1);
}

int main()
{
    string str = "level";
    if (isPalindrome(str, 0, str.size()-1))
    {
        cout<<"\nThe word is palindrome";
    }
    else
    {
        cout<<"\nThe word isn't palindrome";
    }
    int number = 263962;
    if (isPalindrome(number))
    {
        cout<<"\nThe number is palindrome";
    }
    else
    {
        cout<<"\nThe number isn't palindrome";
    }

    return 0;
}