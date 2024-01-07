#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string input;
    cout << "Введіть рядок: ";
    getline(cin, input);

    string onlyNumbers;
    string onlyLetters;
    string lettersWithNumbers;

    for (char ch : input) {
        if (isdigit(ch)) {
            onlyNumbers += ch;
            lettersWithNumbers += ch;
        } else if (isalpha(ch)) {
            onlyLetters += ch;
            lettersWithNumbers += ch;
        }
    }
    cout << onlyNumbers << " " << onlyLetters << " " << lettersWithNumbers << " " << endl;
    return 0;
}