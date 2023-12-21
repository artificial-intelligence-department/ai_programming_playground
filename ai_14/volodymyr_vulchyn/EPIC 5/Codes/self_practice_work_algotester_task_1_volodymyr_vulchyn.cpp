#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int signal = 15;
    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case 'k':
                signal = max(signal - 1, 0);
                break;
            case 'p':
                if (signal >= 1) {
                    signal = 15;
                } else {
                    signal = 0;
                }
                break;
            case 'z':
                if (signal >= 1) {
                    signal = 0;
                } else {
                    signal = 15;
                }
                break;
        }
    }

    cout << signal << endl;

    return 0;
}
