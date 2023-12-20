#include <iostream>
using namespace std;

int main() {
    long long int M, H;
    cin >> M >> H;

    long long int all[6];
    for (int i = 0; i < 6; i++) {
        cin >> all[i];
    }

    bool cs = false;

    for (int i = 0; i < 3; i++) {
        if (all[2 * i] <= 0 || all[1 + 2 * i] <= 0) {
            H -= all[1 + 2 * i];
            M -= all[2 * i];
        } else {
            cs = true;
            break;
        }
    }

    if (cs) {
        cout << "NO";
    } else if (H > 0 && M > 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}