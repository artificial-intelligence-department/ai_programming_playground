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
    string String_Number = to_string(number);
    return isPalindrome(String_Number, 0, String_Number.length() - 1);
}

int main() {
    string Input_Str;
    int Input_Int;
    cout << "Введіть рядок: ";
    cin >> Input_Str;

    if (isPalindrome(Input_Str, 0, Input_Str.length() - 1)) {
        cout << "Рядок є паліндромом." << endl;
    } else {
        cout << "Рядок не є паліндромом." << endl;
    }
    cout << "Введіть ціле число: ";
    cin >> Input_Int;

    if (isPalindrome(Input_Int)) {
        cout << "Число є паліндромом." << endl;
    } else {
        cout << "Число не є паліндромом." << endl;
    }

    return 0;
}
