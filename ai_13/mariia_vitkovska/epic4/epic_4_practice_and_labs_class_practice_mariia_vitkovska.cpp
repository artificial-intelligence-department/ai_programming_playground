#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }

    return (str[start] == str[end]) && isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int num) {
    string strNum = to_string(num);

    return isPalindrome(strNum, 0, strNum.length() - 1);
}

int main() {
    string word;
    int number;
    string choice;
    cout << "What do u want to check, a word or a number?" << endl;
    cin >> choice;
    if(choice == "word"){
        cout << "The word u want to check:" <<endl;
        cin >> word;
        if (isPalindrome(word, 0, word.length() - 1)) {
        cout << word << " is a palindrome" << endl;
        } 
        else {
        cout << word << " is not a palindrome" << endl;
        }
    }
    if(choice == "number"){
        cout << "The number u want to check:" <<endl;
        cin >> number;
        if (isPalindrome(number)) {
            cout << number << " is a palindrome" << endl;
        } 
        else {
        cout << number << " is not a palindrome" << endl;
        }
    }
    return 0;
}
