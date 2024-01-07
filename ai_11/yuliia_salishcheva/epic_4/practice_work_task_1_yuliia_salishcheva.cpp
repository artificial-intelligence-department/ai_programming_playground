#include <iostream>
#include <string>

using namespace std;


bool isPalindrome(const string& str, int start, int end) {

    if (start >= end) {
        return true;
    }

    if (str[start] == str[end]) {
        return isPalindrome(str, start + 1, end - 1);
    }
    return false;
}


bool isPalindrome(int num) {
    string numStr = to_string(num);
    return isPalindrome(numStr, 0, numStr.length() - 1);
}

int main() {

    string strPalindrome = "anna";
    cout << strPalindrome << " is a palindrome - " << bool(isPalindrome(strPalindrome, 0, strPalindrome.length() - 1)) << endl;

    string strNotPalindrome = "hello";
    cout << strNotPalindrome << " is a palindrome - " << bool(isPalindrome(strNotPalindrome, 0, strNotPalindrome.length() - 1)) << endl;


    int numPalindrome = 3003;
    cout << numPalindrome << " is a palindrome - " << bool(isPalindrome(numPalindrome)) << endl;

    int numNotPalindrome = 12345;
    cout << numNotPalindrome << " is a palindrome: " << isPalindrome(numNotPalindrome) << endl;

    return 0;
}
