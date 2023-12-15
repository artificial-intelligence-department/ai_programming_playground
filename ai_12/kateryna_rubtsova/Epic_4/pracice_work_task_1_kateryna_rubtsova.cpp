#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }

    return isPalindrome(str, start + 1, end - 1);
}


bool isPalindrome(int number) {
    string numStr = to_string(number);
    return isPalindrome(numStr, 0, numStr.length() - 1);
}

int main() {
    string word;
    int num;
    int choise;
    cout << "1. Слово?\n";
    cout << "2. Число?\n";
    cin>>choise;
    switch(choise){
        case 1:
            cout << "Введіть слово для перевірки на паліндром: ";
            cin >> word;
            if (isPalindrome(word, 0, word.length() - 1)) {
                cout << "Це паліндром.\n";
            } else {
            cout << "Це не паліндром.\n";
            }
            break;
        case 2:
            cout << "Введіть ціле число для перевірки на паліндром: ";
            cin >> num;
            if (isPalindrome(num)) {
                cout << "Це паліндром.\n";
            } else {
                cout << "Це не паліндром.\n";
            }
            break;
        default:
            break;
    }
        
    

    return 0;
}