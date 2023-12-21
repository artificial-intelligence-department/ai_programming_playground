#include <iostream>
#include <string>

using namespace std;

int main() {
    int amount = 1;

    string s, compressedS;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == s[i + 1]) {
            amount++;
        }
        else {
            compressedS += s[i];
            if (amount > 1) {
                compressedS += to_string(amount);
            }
            amount = 1;
        }
    }
    cout << compressedS << endl;
    return 0;
}