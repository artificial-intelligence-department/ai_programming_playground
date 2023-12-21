#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& word, int start, int end);
bool isPalindrome(const int& number);

int main() {
    string input;
    cout << "Enter a word or number to check if it's a palindrome: ";
    cin >> input;
    // Перевірка, чи введено слово або число
    //isdigit-перевірка чи введення є числом
    if (isdigit(input[0])) {
        //stoi-перетворення стрінги в число 
        int number = stoi(input);
        if (isPalindrome(number)) {
            cout << "Word or number is a palindrome";
        } else {
            cout << "Word or number is not a palindrome";
        }
    } else {
        if (isPalindrome(input, 0, input.length() - 1)) {
            cout << "Word or number is a palindrome";
        } else {
            cout << "Word or number is not a palindrome";
        }
    }
    return 0;
}

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(const int& number) {
    string strNumber = to_string(number);
    int start = 0;
    int end = strNumber.length() - 1;
    while (start <= end) {
        if (strNumber[start] != strNumber[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}






