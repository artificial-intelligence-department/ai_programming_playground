#include <iostream>
#include <string>
using namespace std;

string c_string(const string& s) {
    if (s.empty()) {
        return ""; 
    }
    string comp;
    char c_c = s[0];
    int count = 1;
    for (int i = 1; i <= s.length(); i++) {
        if (s[i] == c_c) {
            count++;
        } else {
            comp += c_c;
            if (count > 1) {
                comp += to_string(count);
            }
            c_c = s[i];
            count = 1;
        }
    }
    return comp;
}
int main() {
    string input;
    getline(cin, input);
    string result = c_string(input);
    cout << result << endl;
    return 0;
}
