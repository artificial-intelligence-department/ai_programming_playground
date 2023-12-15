#include <iostream>
#include <string>

using namespace std;

string compression(string S) {
    string result;
    bool compressed = true;
    int j = 1;
    char currentSymb;
    for (int i = 0; i < S.length(); i++) {
        if (compressed) {
            result += S[i];
            currentSymb = S[i];
            compressed = false;
        }
        else {
            if (currentSymb == S[i]) {
                j++;
            }
            else {
                compressed = true;
                if (j != 1) {
                    result += to_string(j);
                }
                j = 1;
                i--;
            }
        }
    }
    if (j != 1) {
        result += to_string(j);
    }
    return result;
}

int main() {
    string S;
    cin >> S;
    cout << compression(S);
    return 0;
}