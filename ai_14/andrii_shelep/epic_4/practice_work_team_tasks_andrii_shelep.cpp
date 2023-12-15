#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str, int start, int end);
bool isPalindrome(int number);

int main(){
    string str;
    int start, end;

    cout << "enter a word or number:" << endl;
    cin >> str;
    if(str[0] == '0' || str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5' || str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9'){
        int number = stoi(str);
        bool res = isPalindrome(number);
        if (res == true){
            cout << number << " is palindrome" << endl;
        } else {
            cout << number << " is not palindrome" << endl;
        }
    } else{
        start = 0;
        end = str.size() - 1;
        bool res = isPalindrome(str, start, end);
        if (res == true){
            cout << "\"" << str << "\"" << " is palindrome" << endl;
        } else {
            cout << "\"" << str << "\"" << " is not palindrome" << endl;
        }
    }
    return 0;
}

bool isPalindrome(string str, int start, int end){
    if (start >= end){
        return true;
    } else if (str[start] != str[end]){
        return false;
    } else {
        return isPalindrome(str, start + 1, end - 1);
    } 
}

bool isPalindrome(int number){
    string s_number = to_string(number);
    int start = 0;
    int end = s_number.size() - 1;
    return isPalindrome(s_number, start, end);
}