#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool palindrome(const string &smth, int start, int end)
{
    if (start >= end)
        return true;
    if (smth[start] == smth[end])
        return palindrome(smth, start + 1, end - 1);
    else
        return false;
}

bool palindrome(int number)
{
    string strNumber = to_string(number);
    return palindrome(strNumber, 0, strNumber.length() - 1);
}

int main()
{
    string smth;
    cout << "Enter smth: ";
    cin >> smth;

    if (palindrome(smth, 0, smth.length() - 1))
        cout << smth << " is a palindrome." << endl;
    else
        cout << smth << " is not a palindrome." << endl;

    return 0;
}
