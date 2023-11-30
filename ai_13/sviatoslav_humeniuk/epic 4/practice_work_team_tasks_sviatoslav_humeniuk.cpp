// Перевірка слова чи числа на паліндром
#include <iostream>
#include <string>

using namespace std;


bool isPalindrome(const string &value, int start, int end) { // Функція для перевірки, чи є рядок паліндромом
    if (start >= end) {
        return true;
    }
    if (value[start] != value[end]) {
        return false;
    }
    return isPalindrome(value, start + 1, end - 1);
}


bool isPalindrome(int num) { // Перевантажена функція для перевірки, чи є ціле число паліндромом
    string str = to_string(num); // Перетворення числа в рядок
    return isPalindrome(str, 0, str.length() - 1); //Віднімаємо одиничку, оскільки індексація починається від 0
}

int main() {
    string value;
    cout << "Enter a value (word or number): ";
    cin >> value;
    if (value.find_first_not_of("0123456789") == string::npos) {    // Перевірка, чи введене значення є числом

        // Якщо це число, використовуємо перевантажену версію функції isPalindrome
        int num = stoi(value);
        if (isPalindrome(num)) {
            cout << num << " is a palindrome." << endl;
        } else {
            cout << num << " is not a palindrome." << endl;
        }
    } else {
        if (isPalindrome(value, 0, value.length() - 1)) {        // Якщо це рядок, використовуємо оригінальну версію функції isPalindrome

            cout << value << " is a palindrome." << endl;
        } else {
            cout << value << " is not a palindrome." << endl;
        }
    }
    return 0;
}
