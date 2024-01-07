#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long legs[4];

    for (int i = 0; i < 4; i++) {
        cin >> legs[i];
    }
        

    long long distants;
    bool stands = true;
    for (int i = 0; i < 4; i++) {
        cin >> distants;
        if (distants > legs[i]) {
            cout << "ERROR";
            return 0;
        }

        legs[i] -= distants;

        if (*max_element(legs, legs + 4)
            >= 2 * *min_element(legs, legs + 4)) {
            stands = false;
        }
    }

    cout << (stands ? "YES" : "NO");
    return 0;
}
