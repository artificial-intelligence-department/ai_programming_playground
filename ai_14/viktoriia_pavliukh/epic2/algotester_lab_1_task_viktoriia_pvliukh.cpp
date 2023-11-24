#include <iostream>

using namespace std;

int main() {
    string result = "-";
    long long h[4], d[4], hmax, hmin;

    for (int i = 0; i < 4; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < 4; i++) {
        if (h[i] < d[i]) {
            result = "ERROR";
            cout << result;
            return 0;
        }
    }
        for (int i = 0; i < 4; i++) {
            h[i] -= d[i];
            hmax = h[0];
            hmin = h[0];
            for (int j = 0; j < 4; j++) {
                if (h[j] > hmax) { hmax = h[j]; }
                if (h[j] < hmin) { hmin = h[j]; }
            }
            if (hmax >= 2 * hmin) {
                result = "NO";
            }
        }
        if (hmin==hmax && hmin != 0 && result == "-") {
            result = "YES";
        } else result = "NO";
        cout << result;
        return 0;
    }