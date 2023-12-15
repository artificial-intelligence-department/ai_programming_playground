#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool isPalindrome(const string &str, int start, int end) {
    if (start >= end) {
        return true;
    }

    if (str[start] != str[end]) {
        return false;
    }

    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(const vector<int> &vec, int start, int end) {
    if (start >= end) {
        return true;
    }

    if (vec[start] != vec[end]) {
        return false;
    }

    return isPalindrome(vec, start + 1, end - 1);
}

int main() {
    string inputStr;
    cout << "Enter a word: ";
    getline(cin >> ws, inputStr);

    if (isPalindrome(inputStr, 0, inputStr.length() - 1)) {
        cout << "The string is a palindrome.\n";
    } else {
        cout << "The string is not a palindrome.\n";
    }

    string inputNumbers;
    cout << "Enter numbers: ";
    getline(cin >> ws, inputNumbers);

    vector<int> numbers;
    istringstream iss(inputNumbers);
    int num;
    while (iss >> num) {
        numbers.push_back(num);
    }

    if (isPalindrome(numbers, 0, numbers.size() - 1)) {
        cout << "The vector of numbers is a palindrome.\n";
    } else {
        cout << "The vector of numbers is not a palindrome.\n";
    }

    return 0;
}
