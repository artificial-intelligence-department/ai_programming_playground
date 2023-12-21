#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    long long int H, M;
    cin >> H >> M;

    for (int i = 0; i < 3; i++) {
        long long int hi, mi;
        cin >> hi >> mi;

        if (hi > 0 && mi > 0) {
            cout << "NO" << endl;
            return 0;
        }
        // if a character uses hit points and mana at the same time

        if (hi > 0) {
            H -= hi;
        } else if (mi > 0) {
            M -= mi;
        }
    }

    if (H > 0 && M > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

