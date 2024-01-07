#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &word, int start, int end) {
    if (start >= end) {            
        return true;
    }

    if (word[start] != word[end]) {
        return false;
    }
    return isPalindrome(word, start + 1, end - 1);
}

bool isPalindrome(int number) {
    string word = to_string(number);        
    int start = 0;                             
    int end = word.length() - 1;

    return isPalindrome(word, start, end);
}

int main() {
    string input;
    cout << "Enter a word or number to check whether it is a palindrome: ";
    cin >> input;

   if (isPalindrome(input, 0, input.length() - 1)) {
        cout << "'" << input << "' is a palindrome.";
    } else {
        cout << "'" << input << "' is not a palindrome.";
    }

    return 0;
}