#include <iostream>
#include <string>

using namespace std;

bool Palindrome(const string slovo, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (slovo[start] != slovo[end])
        return false;

    return Palindrome(slovo, start + 1, end - 1);
}

int main() {
    string slovo;
    cout << "Enter the word" << endl;
    cin >> slovo;
    if (Palindrome(slovo, 0, slovo.length() - 1)) {
        cout << "This word is a palindrome.\n";
    }
    else {
        cout << "This word isn't a palindrome.\n";
    }
    return 0;
}