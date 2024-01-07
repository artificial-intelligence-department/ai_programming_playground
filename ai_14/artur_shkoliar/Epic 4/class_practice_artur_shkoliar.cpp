#include <iostream>
#include <string>
#include <algorithm>

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

bool isPalindrome(int num) {
    
    string numStr = to_string(num);

    
    return isPalindrome(numStr, 0, numStr.length() - 1);
}

int main() {
    
    string word;
    cout << "Введіть слово: ";
    cin >> word;

    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << word << " це паліндром." << endl;
    } else {
        cout << word << " це не піліндром." << endl;
    }

   
    int number;
    cout << "Введіть ціле число: ";
    cin >> number;

    if (isPalindrome(number)) {
        cout << number << " це паліндром" << endl;
    } else {
        cout << number << " це не паліндром" << endl;
    }

    return 0;
}
