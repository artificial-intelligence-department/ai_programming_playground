#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end)
        return true;
    if (str[start] != str[end])
        return false;
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int num) {
    string str = to_string(num);
    return isPalindrome(str, 0, str.length() - 1);
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    if (isPalindrome(str, 0, str.length() - 1))
        cout << str << " is a palindrome.\n";
    else
        cout << str << " is not a palindrome.\n";

    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (isPalindrome(num))
        cout << num << " is a palindrome.\n";
    else
        cout << num << " is not a palindrome.\n";

    return 0;
}