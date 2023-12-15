#include <iostream>
#include <string>
using namespace std;

    string compressString(const string& s) {
    string compressed = "";
    int count = 1;
    for (int i = 0; i < s.length(); ++i) {
        if (i + 1 < s.length() && s[i] == s[i + 1]) {
            count++;
        } else {
            compressed += s[i];
            if (count > 1) {
                compressed += to_string(count);
            }
            count = 1;
        }
    }
    return compressed;
}

int main() {
    string input;
    getline(cin, input);

    string compressedOutput = compressString(input);
    cout << compressedOutput << endl;

    return 0;
}
