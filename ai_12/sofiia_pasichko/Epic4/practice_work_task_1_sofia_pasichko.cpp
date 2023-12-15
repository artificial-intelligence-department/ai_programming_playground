#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isPalindrome(string word) {
    if (word.length()==1) {
        return true;
    }
    else if (word[0]!=word.back()) {
        return false;
    } 
    else{
        return true;
    }
}
bool isPalindrome(int number) {
    string Number = to_string(number);
    if (Number.length()==1) {
        return true;
    }
    else if (Number[0]!=Number.back()) {
        return false;
    } 
    else{
        return true;
    }
}


 int main() {
    string a;
    cin >> a;
    if (isPalindrome(a)==true) {
        cout << "It's a palindrome!";
    } else if (isPalindrome(a)==false) {
        cout << "It's not a palindrome!";
    }
    return 0;
} 

