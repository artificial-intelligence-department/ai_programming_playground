#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& word, int start, int end);

int main(){
    string word, n;
    cout << "Enter a number or word to check if it's a palindrome: ";
    cin >> word;

    if (isPalindrome(word, 0, word.length()-1)){
        cout << "It's a palindrome";
    }
    else{
        cout << "It's not a palindrome";
    }
    return 0;
}

bool isPalindrome(const string& word, int start, int end){
    if (start>=end){
        return true;
    }

    if (word[start]==word[end]){
        return isPalindrome(word, start+1, end-1);}
    return false;
}