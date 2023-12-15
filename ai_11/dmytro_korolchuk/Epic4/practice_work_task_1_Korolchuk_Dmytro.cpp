#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str, int start, int end) 
{
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int num) {
    string strNum = to_string(num);
    return isPalindrome(strNum, 0, strNum.length() - 1);
}

int main()
{
    string smth;
    int num;
    
    cin>>smth;
    
    if(isPalindrome(smth, 0, smth.length()-1)){
        cout<<"Is a palindrome";
    }
    else{
        cout<<"Not a palindrome";
    }

    cout<<endl;
    cin>>num;

    if (isPalindrome(num)) {
        cout << "Is a palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }
}