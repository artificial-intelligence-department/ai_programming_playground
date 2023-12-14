#include<iostream>
#include<string>
using namespace std;

string get_string()
{
    string str;
    cout << "Enter string: ";
    cin >> str;
    return str;
}

int get_int()
{
    int number;
    cout << "Enter number: ";
    cin >> number;
    return number;
}

string check_lever(bool lever)
{
    if( lever == 1)
    {
        return "Palindrome";
    }
    else
    {
        return "not Palindrome";
    }
}

bool is_palindrome(const string &str, int start, int end)
{
    bool palindrome = true;
    int tail = end;
    int head = start;
    if(start == end || start > tail && end < head)
    {
        return palindrome;
    }
    if(str[start] == str[end])
    {
        palindrome = true;
    }
    else
    {
        palindrome = false;
        return palindrome; 
    }
    return is_palindrome(str, ++start, --end);
}

bool is_palindrome(const int &number, int start, int end)
{
    const string str = to_string(number);
    return is_palindrome(str, start, end);
}

int main()
{
    const string str = get_string();
    const int number = get_int();
    cout << str << " is " << check_lever(is_palindrome(str, 0, str.length() - 1)) << endl;
    cout << number <<" is " << check_lever(is_palindrome(number, 0, to_string(number).length() - 1)) << endl;
}