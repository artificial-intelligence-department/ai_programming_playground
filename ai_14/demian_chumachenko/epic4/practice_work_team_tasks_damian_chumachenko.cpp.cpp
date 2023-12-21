#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPalindrome(string str, int start, int end){

    if(start >= end){
        return true;
    }

    if(str[start] != str[end]){
        return false;
    }
    
    return isPalindrome(str, start+1, end-1);
}

bool isPalindrome(int num){

    string strNum = to_string(num);

    return isPalindrome(strNum, 0, strNum.length()-1);
}

int main(){
    string str = "ALOLA";
    int num = 11213;

    if (isPalindrome(str, 0, str.length()-1)){
        cout << "Is palindrome" << endl;
    } else {
        cout << "Is not palindrome" << endl;
    }
    if (isPalindrome(num)){
        cout << "Is palindrome" << endl;
    } else {
        cout << "Is not palindrome" << endl;
    }

    return 0;
}