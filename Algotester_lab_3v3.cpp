#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, s_compressed;
    cin >> s;

    if (s.size() > 0 && s.size() <= 100000) {
        int number = 1;

        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && s[i] == s[i + 1]) {
                number++;
            } else {
                s_compressed += s[i];
                if (number > 1) {
                    s_compressed += to_string(number);
                }
                number = 1;
            }
        }

        cout << s_compressed << endl;
    }

    return 0;
}
