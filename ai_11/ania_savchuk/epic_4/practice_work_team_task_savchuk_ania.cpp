#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str, int start, int end){
      if (start >= end) {
        return true;
    }

    if (str[start] != str[end]) {
        return false;
    } else {
        return isPalindrome(str, start + 1, end - 1);
    }
}

bool isPalindrome(int number){
    string numstr = to_string(number);

    return isPalindrome(numstr, 0, numstr.length() - 1); 
}

int main(){
    string input;
    cout << "Enter a word or number: ";
    cin >> input;

    bool result = isPalindrome(input, 0, input.length() - 1);

    cout << "This " << (result ? "is" : "isn't") << " palindrom." << endl;
    return 0;
}







