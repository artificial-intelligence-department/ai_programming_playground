#include <iostream>
#include <vector>

using namespace std;

int main() {
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString);

    vector<char> result;

    // Extract alphabetic characters
    for (char ch : inputString) {
        if (isalpha(ch)) {
            result.push_back(ch);
        }
    }

    // Extract numeric characters
    for (char ch : inputString) {
        if (isdigit(ch)) {
            result.push_back(ch);
        }
    }

    cout << "Formatted string: ";
    for (char ch : result) {
        cout << ch;
    }

    return 0;
}
