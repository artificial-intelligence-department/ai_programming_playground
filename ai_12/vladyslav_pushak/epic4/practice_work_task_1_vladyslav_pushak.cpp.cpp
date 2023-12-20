#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool checkPalindrome(const string& str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        ++start;
        --end;
    }
    return true;
}

void printPalindromeStatus(bool isPalindrome){
    if (isPalindrome)
        cout << "It's a palindrome." << endl;
    else 
        cout << "It's not a palindrome." << endl;
}

int main() {
    string inputStr;
    cout << "Enter a word: ";
    cin >> inputStr;
    printPalindromeStatus(checkPalindrome(inputStr));

    int inputNum;
    cout << "Enter an integer: ";
    cin >> inputNum;
    printPalindromeStatus(checkPalindrome(to_string(inputNum)));

    return 0;
}
