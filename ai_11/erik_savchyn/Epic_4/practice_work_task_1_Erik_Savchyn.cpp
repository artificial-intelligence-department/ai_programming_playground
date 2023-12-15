#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

bool isPalindrome(char str[], int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] == str[end]) {
        return isPalindrome(str, start + 1, end - 1);
    }
    return false;
}

bool isPalindmore(int num) {
    int res = num;
    int rNum[100];
    int i = -1;
    while (num != 0) {
        i++;
        rNum[i] = num % 10;
        num /= 10;
    }
    int j = 0;
    while (i >= 0) {
        num += rNum[j] * pow(10, i);
        i--;
        j++;
    }
    if (res == num) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char str[100];
    int num;

    cout << "enter word" << endl;
    cin >> str;
    cout << "enter number" << endl;
    cin >> num;

    int size = strlen(str);

    if (isPalindrome(str, 0, size - 1)) {
        cout << str << " is palindrome" << endl;
    } else {
        cout << str << " not a palindrome" << endl;
    }

    if (isPalindmore(num)) {
        cout << num << " is palindrome" << endl;
    } else {
        cout << num << " not a palindrome" << endl;
    }

    return 0;
}