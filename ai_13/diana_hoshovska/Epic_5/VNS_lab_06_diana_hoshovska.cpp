#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char token[], int start, int end);
void isWord(char wrd[], string& palindrome_words);

int main(){
    string palindrome_words;
    char str[256];
    cout << "Input text: ";
    cin.getline(str, 256);

    isWord(str, palindrome_words);
    return 0;
}

bool isPalindrome(char token[], int start, int end){
    if (start>=end){
        return true;
    }
    if (token[start]==token[end]){
        return isPalindrome(token, start+1, end-1);
    }
    return false;
}

void isWord(char wrd[], string& palindrome_words){
    char *token;
    token = strtok(wrd, " ");

    while (token != NULL){
        if(isPalindrome(token, 0, strlen(token)-1)==true) {
            palindrome_words+=token;
            palindrome_words+=" ";
        }
        token = strtok(NULL, " ");
    }
    cout << "Words with palindrome: " << palindrome_words;
}