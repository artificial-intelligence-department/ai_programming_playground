#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int number) {
    string strNum = to_string(number); 
    return isPalindrome(strNum, 0, strNum.length() - 1); 
}

int main() {
    string verify;
    cout << "What do you want to verify, word or number? ";
    cin >> verify;
    if(verify=="word"){
        string input;
        cout<<"Enter a word: ";
        cin>>input;
         if (isPalindrome(input, 0, input.length() - 1)) {
        cout << "It's palindrom.\n";
    } else {
        cout << "It's not palindrom.\n";
    }
    }
    else{
        int input;
        cout<<"Enter a number:  ";
        cin>>input;
         if (isPalindrome(input)) {
        cout << "It's palindrom.\n";
    } else {
        cout << "It's not palindrom.\n";
    }
    }
    return 0;
}
