#include <iostream>
#include <string>

using namespace std;


string compressString(const string& s) {
    string compressed;
    int count = 1;

    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            compressed += s[i - 1];
            if (count > 1) {
                compressed += to_string(count);
            }
            count = 1;
        }
    }

    compressed += s.back();
    if (count > 1) {
        compressed += to_string(count);
    }

    return compressed;
}

int main() {
    string s;
    cin >> s;

    string result = compressString(s);

    cout << result << endl;

    return 0;
}
