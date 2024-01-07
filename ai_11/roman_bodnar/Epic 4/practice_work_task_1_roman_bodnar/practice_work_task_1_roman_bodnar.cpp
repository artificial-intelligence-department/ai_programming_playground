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
    string str = to_string(number);

    return isPalindrome(str, 0, str.length() - 1);
}

int main() {
    cout << boolalpha;

    cout << isPalindrome("radar",0, 4) << endl; // true
    cout << isPalindrome("level",0, 4) << endl; // true
    cout << isPalindrome("12321",0, 4) << endl; // true
    cout << isPalindrome("1232",0, 3) << endl; // false
    cout << isPalindrome(112211); // true

    return 0;
}
