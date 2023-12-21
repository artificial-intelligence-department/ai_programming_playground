#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
  
    if (start >= end) {
        return true;
    }

    return (str[start] == str[end]) && isPalindrome(str, start + 1, end - 1);
}


bool isPalindrome(int num) {

    string numStr = to_string(num);


    return isPalindrome(numStr, 0, numStr.length() - 1);
}

int main(){

    string word;


    cout << "Введіть ваше слово:";
    cin >> word;

    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << word << " паліндром" << endl;
    } else {
        cout << word << " не паліндром" << endl;
    }
    int num;

    cout << "Введіть ваше число:";
    cin >> num;

    if (isPalindrome(num)) {
        cout << num << " паліндром" << endl;
    } else {
        cout << num << " не паліндромі" << endl;
    }

    return 0;
}