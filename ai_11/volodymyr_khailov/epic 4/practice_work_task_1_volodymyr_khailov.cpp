#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    // початок більше або дорівнює кінцю, то це паліндром
    if (start >= end) {
        return true;
    }

    // Порівнюємо символи на поточних позиціях
    if (str[start] != str[end]) {
        return false;
    }

    // Рекурсивний виклик для наступних позицій
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int num) {
    string strNum = to_string(num);

    return isPalindrome(strNum, 0, strNum.length() - 1);
}

void printIsPalidrome(bool flag){
    if (flag)
        cout << "Це паліндром." << endl;
    else 
        cout << "Це не паліндром." << endl;
}
int main() {
    string str;
    cout << "Введіть слово: ";
    cin >> str;
    printIsPalidrome(isPalindrome(str, 0, str.length()-1));

    int num;
    cout << "Введіть ціле число: ";
    cin >> num;
    printIsPalidrome(isPalindrome(num));

    return 0;
}
