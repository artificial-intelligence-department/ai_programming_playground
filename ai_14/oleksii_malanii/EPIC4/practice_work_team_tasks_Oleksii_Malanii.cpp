#include <iostream>
#include <string>
using namespace std;
bool ispalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] == str[end]) {
        return ispalindrome(str, start + 1, end - 1);
    } else {
        return false;
    }
}
bool ispalindrome(int num) {
    string numStr = to_string(num);
    return ispalindrome(numStr, 0, numStr.length() - 1);
}
int main() {
    string word = "stats";
    int number = 45454;
    if (ispalindrome(word, 0, word.length() - 1)) {
        cout << word << " - palindrome." << endl;
    } else {
        cout << word << " - not palinrome." << endl;
    }
    if (ispalindrome(number)) {
        cout << number << " - palindrome." << endl;
    } else {
        cout << number << " - not palinrome." << endl;
    }
    return 0;
}
