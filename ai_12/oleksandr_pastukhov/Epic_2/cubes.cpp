#include <iostream>
#include <algorithm>

int main() {
    using namespace std;
    long long sides[5];
    for (int i = 0; i < 5; ++i) {
        cin >> sides[i];

        if (sides[i] <= 0) {
            cout << "ERROR" << endl;
            return 0;
        }
        if (sides[i - 1] < sides[i]) {
            cout << "LOSS" << endl;
            return 0;
    }
    }
    cout << "WIN" << endl;

    return 0;
}
