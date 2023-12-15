#include <iostream>
using namespace std;

int cable(int k) {
    return max(k - 1,0);
}

int repeater(int k) {
    if (k >= 1) {
        return 15;
    } else {
        return 0;
    }
}

int changer(int k) {
    if (k >= 1) {
        return 0;
    } else {
        return 15;
    }
}

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int signal = 15; 

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'k') {
            signal = cable(signal);
        } else if (s[i] == 'p') {
            signal = repeater(signal);
        } else if (s[i] == 'z') {
            signal = changer(signal);
        }
    }

    cout << signal << endl; 

    return 0;
}

