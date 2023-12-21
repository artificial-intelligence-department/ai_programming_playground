#include <iostream>
#include <string>
using namespace std;

bool pal(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }

    if (str[start] != str[end]) {
        return false;
    }

    return pal(str, start + 1, end - 1);
}

int main() {
    string pali;
    cin >> pali;
    if (pal(pali, 0, pali.length() - 1)) {
        cout << pali << " is a palindrome." << endl;
    } else {
        cout << pali << " is not a palindrome." << endl;
    }

    return 0;
}



