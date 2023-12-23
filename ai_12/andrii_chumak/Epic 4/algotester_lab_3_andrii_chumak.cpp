#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

string compressString(const string& s) {
    string compressed;

    if (s.empty()) {
        return compressed;
    }

    char currentChar = s[0];
    int count = 1;

    for (size_t i = 1; i < s.length(); ++i) { // size_t зберігає розмір масивів
        if (s[i] == currentChar) {
            count++;
        } else {
            compressed.push_back(currentChar);
            if (count > 1) {
                compressed.append(to_string(count));
            }
            currentChar = s[i];
            count = 1;
        }
    }

    compressed.push_back(currentChar);
    if (count > 1) {
        compressed.append(to_string(count));
    }

    return compressed;
}

int main() {
    string s;
    cin >> s;

    string result = compressString(s);

    for (char c : result) {
        cout << c << endl;
    }

    return 0;
}
