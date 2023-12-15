#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int money[9] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    int amount = 0;

    for (int i = 8; i >= 0; i--) {
        if(n/money[i] >= 1) {
            int perm = n/money[i];
            amount += perm;
            n = n-(money[i]*perm);
        }
    }
    cout << amount;

    return 0;
}
