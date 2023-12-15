#include<iostream>
#include<string>
using namespace std;

bool PalindromeOrNot(int number) {
    int original = number;
    int backwards = 0;

    while (number > 0) {
        int digit = number % 10;
            backwards = backwards * 10 + digit;
            number = number/10;
    }

    return original == backwards;
}

bool PalindromeOrNot(const string& input, int n = 0){
    int lengthOfString = size(input);
    while(n<lengthOfString){
        if(input[n]==input[lengthOfString-1-n]){
            return PalindromeOrNot(input,n+1);
        } return 0;
    }
    return 1;
}

int main(){
string input;

cin>>input;

if(isdigit(input[0])){
    int number = stoi(input);
        PalindromeOrNot(number);
        if(PalindromeOrNot(input)){
            cout<<"this is palindrome";
            return 0;
        }
            cout<< "this is not palindrome";
            return 0;
}

if(PalindromeOrNot(input)){
    cout<<"this is palindrome";
    return 0;
}
    cout<< "this is not palindrome";
    return 0;

}