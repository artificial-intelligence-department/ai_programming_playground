#include <iostream>
#include<string>
using namespace std;

int main() {
    string input_string = "Hello 123 World 456";
    cin >> input_string;
    string current_word;

    for (size_t i = 0; i <= input_string.length(); i++) {
        char c = (i < input_string.length()) ? input_string[i] : ' ';

        if (isdigit(c) || isspace(c)) {
            if (!current_word.empty()) {
                bool isDigitOnly = true;
                for (char wc : current_word) {
                    if (!isdigit(wc)) {
                        isDigitOnly = false;
                        break;
                    }
                }
                if (!isDigitOnly) {
                    cout << current_word << " ";
                }
            }
            current_word = "";  
        } 
        else {

            current_word += c;
        }
    }

    return 0;
}
