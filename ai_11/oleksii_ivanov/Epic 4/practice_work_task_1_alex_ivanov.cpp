#include <iostream>
using namespace std;

bool isPalindrome(const string&str, const size_t start, const size_t end) {
    if (start >= end) return true;
    return str[start] == str[end] && isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(const string& str) {
    return isPalindrome(str, 0, str.length() - 1);
}

bool isPalindrome(const long long& num) {
    return isPalindrome(to_string(num));
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << str << " is " << (isPalindrome(str) ? "" : "not ") << "a palindrome." << endl;

    return 0;
}
