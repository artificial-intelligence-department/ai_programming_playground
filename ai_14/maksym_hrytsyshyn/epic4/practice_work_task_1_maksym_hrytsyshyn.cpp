#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool palindrome(string& word, int first, int last) {
    if (first >= last) {
        return true;
    }
    if (word[first] != word[last]) {
        return false;
    
    }
    return palindrome(word, first+1, last-1);
}

bool palindrome(int number) {
    string numberString = to_string(number);
    return palindrome(numberString, 0, numberString.length()-1);
}

int main() {
    string symbols;
    cout << "Enter a word or a number: ";
    cin >>  symbols;

    bool containLetter = true;
    bool containDigit = true;

    for (char i : symbols) {
        if (!isalpha(i)) {
            containLetter = false;
        }
        if (!isdigit(i)) {
            containDigit = false;
        }
    }

    if(containLetter == true) {
        if (palindrome(symbols, 0, symbols.length() - 1)) {
            cout << symbols << " is palindrome" << endl;
        } else {
            cout << symbols << " is not palindrome" << endl;
        }
    } else if (containDigit == true) {
        if (palindrome(stoi(symbols))) {
            cout << symbols << " is palindrome" << endl;
        } else {
           cout << symbols << " is not palindrome" << endl; 
        }
    } 
    return 0;
}