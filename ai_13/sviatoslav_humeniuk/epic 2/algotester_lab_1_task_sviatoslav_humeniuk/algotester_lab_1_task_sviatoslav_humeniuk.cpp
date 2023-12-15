#include <iostream>

using namespace std;

int main() {

    long long int H, M;
    cin >> H >> M;

    if (H > 1e12 || M > 1e12) {
        return 0;
    }

    long long int h[3], m[3];
    for(int i = 0; i < 3; i++) {
        cin >> h[i] >> m[i];
    }


    for(int i = 0; i < 3; i++) {
        H -= h[i];
        M -= m[i];
    }

    for(int i = 0; i < 3; i++) {
        if (h[i] > 0 && m[i] > 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (H > 0 && M > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}