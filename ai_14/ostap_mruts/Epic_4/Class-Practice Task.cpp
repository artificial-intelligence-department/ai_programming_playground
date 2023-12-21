#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &word) {
    int length = word.length();
    for (int i = 0; i < length / 2; ++i) {
    if (word[i] != word[length - 1 - i]) {
    return false;
    }
    }
    return true;
}

int main() {
    string inputWord;
    cout << "Введіть слово: ";
    cin >> inputWord;

    if (isPalindrome(inputWord)) {
    cout << "паліндром." << endl;
    } else {
    cout << "не паліндром." << endl;
    }

    return 0;
}
