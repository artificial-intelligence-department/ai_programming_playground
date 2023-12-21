#include <iostream>
using namespace std;

int main() {
    
   long long H, M;
    bool usedB = false;
    cin >> H >> M;

    unsigned long long usedH[3], usedM[3];

    for (int i = 0; i < 3; i++) {
        cin >> usedH[i] >> usedM[i];

        if (usedH[i] > 0 && usedM[i] > 0) {
            usedB = true;
        }
        H -= usedH[i];
        M -= usedM[i];
    }

    if (usedB) {
        cout << "NO" << endl;
    } else if (H > 0 && M > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
