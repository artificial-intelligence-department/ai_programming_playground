#include <iostream>
#include <string>

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
    string strNumber = to_string(number);
    return isPalindrome(strNumber, 0, strNumber.length() - 1);
}

int main() {
    string word;
    cout << "Введіть слово: ";
    cin >> word;
    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << "Це паліндром." << endl;
    } else {
        cout << "Це не паліндром." << endl;
    }
    int num;
    cout << "Введіть ціле число: ";
    cin >> num;
    if (isPalindrome(num)) {
        cout << "Це паліндром." << endl;
    } else {
        cout << "Це не паліндром." << endl;
    }

    return 0;
}
