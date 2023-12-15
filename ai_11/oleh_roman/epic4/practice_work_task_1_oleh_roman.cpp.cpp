#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string word, int start, int end){
    if (start >= end) {
        return true; 
    }
    if (word[start] != word[end])
        return false;
    
    return isPalindrome(word, start + 1, end - 1);
}

int main(){
    string word;
    cout << "Enter the word or numbers" << endl;
    cin >> word;
    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << "This word is a palindrome.\n";
    } else {
        cout << "This word isn't a palindrome.\n";
    }
    return 0;
}