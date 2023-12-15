#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string word) {
    if (word.length() == 1) {
        return true;
    }
    else if (word[0] == word.back()) {
        word.erase(word.begin());
        word.erase(word.end() - 1);
        return isPalindrome(word);
    }

    return false;
}

bool isPalindrome(int number) {
    string number_s = to_string(number);
    return isPalindrome(number_s);
}

int main() {
    cout << isPalindrome("radar") << endl;
    cout << isPalindrome("apples") << endl;

    cout << isPalindrome(100) << endl;
    cout << isPalindrome(15151) << endl;
    return 0;
}
