#include <iostream>
#include <string>
using namespace std;

int main() {
    string input, result;
    getline(cin, input);

    char prevChar = input[0];
    int count = 1;

    for (int i = 1; i <= input.size(); ++i) {
        if (input[i] == prevChar) {
            ++count;
        } else {
            result += prevChar;
            if (count > 1) {
                result += to_string(count);
            }
            prevChar = input[i];
            count = 1;
        }
    }

    cout << result;
    return 0;
}
