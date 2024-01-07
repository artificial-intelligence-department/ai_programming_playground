#include <iostream>
using namespace std;

int main() {
    long long sides[5];

    for (int i = 0; i < 5; ++i) {
        cin >> sides[i];

        if (sides[i] <= 0) {
            cout << "ERROR" << endl;
            return 0;
        }

        if (i > 0 && sides[i] > sides[i - 1]) {
            cout << "LOSS" << endl;
            return 0;
        }
    }

    cout << "WIN" << endl;

    return 0;
}