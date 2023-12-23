#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

// Перевірка чи слово або число є паліндромом
bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    } 

    if(str[start] == str[end]) {
        return isPalindrome(str, start + 1, end - 1);
    } else {
        return false;
    }
}

int main() {
    string value;
    cout << "Please, enter your value" << endl;
    cin >> value;
    if (isPalindrome(value, 0, value.length() - 1)) {
        cout << "It's palindrome" << endl;
    } else {
        cout << "It's not palindrome" << endl;
    }
}
