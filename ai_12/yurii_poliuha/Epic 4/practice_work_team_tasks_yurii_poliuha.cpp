#include <iostream>
#include <string>
using namespace std;

void Review(bool review);

void isPalindrome(const string &str){
    char ch_start, ch_end;
    int count = 0;
    bool review = false;

    for(int i = 0, j = str.size() - 1; i < str.size(); i++, j--){
        ch_start = str[i];
        ch_end = str[j];
        if(ch_start == ch_end) count++;
        else break;    
    }
    if(count == str.size()) review = true;
    Review(review);
}

void isPalindrome(const int number){
    string str = to_string(number);
    isPalindrome(str);
}

void Review(bool review){
    if(review == true) cout << "Your word is palindrome" << endl;
    else cout << "Your word isn't palindrome" << endl;
}

int main(){
    string str;
    cout << "Enter your word" << endl;
    cin >> str;
    isPalindrome(str);
    cout << endl;
    int number;
    cout << "Enter your number" << endl;
    cin >> number;
    isPalindrome(number);
    return 0;
}