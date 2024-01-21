#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long H, M, hi, mi;

    cin >> H >> M;

    if (H >= 1 && H <= pow(10, 12) && M >= 1 && M <= pow(10, 12)) {
        for (int i = 0; i < 3; i++) {
            cin >> hi >> mi;

            if ((hi >= 0 && hi <= pow(10, 12)) && (mi >= 0 && mi <= pow(10, 12)) && !(hi > 0 && mi > 0)) {
                H -= hi;
                M -= mi;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }

        if (H > 0 && M > 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

