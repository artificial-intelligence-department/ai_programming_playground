#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end)
        return true;
    if (tolower(str[start]) != tolower(str[end]))
        return false;
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int number) {
    string strNumber = to_string(number);
    return isPalindrome(strNumber, 0, strNumber.length() - 1);
}

int main(){
    string s;
    int a;
    cin >> s;
    cin >> a;
    cout << "String ";
    (isPalindrome(s, 0, s.length() - 1)) ? cout << "is a palindrome\n" : cout << "is not a palindrome\n";
    cout << "Number ";
    (isPalindrome(a)) ? cout << "is a palindrome\n" : cout << "is not a palindrome\n";
    return 0;
}