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
        string numStr = to_string(number);

        return isPalindrome(numStr, 0, numStr.length() - 1);
    }

    int main() {

        string word;
        cout << "Enter word: ";
        cin >> word;

        if (isPalindrome(word, 0, word.length() - 1)) {
            cout << word << "This IS palindrom" << endl;
        } else {
            cout << word << "This IS NOT palindrom" << endl;
        }


        int number;
        cout << "Enter number: ";
        cin >> number;

        if (isPalindrome(number)) {
            cout << word << "This IS palindrom" << endl;

        } else {
            cout << word << "This IS NOT palindrom" << endl;
        }

        return 0;
    }
