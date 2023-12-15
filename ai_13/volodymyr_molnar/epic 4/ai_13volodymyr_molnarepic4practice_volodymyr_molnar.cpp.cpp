#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str, int pochatok, int kinezz) {
    if (pochatok >= kinezz) 
        return true;
    if (str[pochatok] != str[kinezz]) 
        return false;
    return isPalindrome(str, pochatok + 1, kinezz - 1);
}

bool isPalindrome(int num) {
    string strNum = to_string(num);
    return isPalindrome(strNum, 0, strNum.length() - 1);
}

int main() {
    string word = "dad";
    int number = 445544;

    if (isPalindrome(word, 0, word.length() - 1)) 
        cout << word << " = palindrome." << endl;
    else 
        cout << word << " = not palindrome." << endl;
    if (isPalindrome(number)) 
        cout << number << " = palindrome." << endl;
    else
        cout << number << " = not palindrome." << endl;
    return 0;
}
