#include <iostream>

using namespace std;

int main() {
    int n, l, r;

    cin >> n;

    int *a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    l = 0;
    r = n-1;

    while (true) {

        if (l == r) {
            cout << l + 1 << " " << r + 1 << endl;
            cout << "Collision" << endl;
            break;
        } else if (l + 1 == r) {
            cout << l + 1 << " " << r + 1 << endl;
            cout << "Stopped" << endl;
            break;
        } else if (l > r) {
            cout << l + 1 << " " << r + 1 << endl;
            cout << "Miss" << endl;
            break;
        }

        l += a[l];
        r -= a[r];
    }

    delete[] a;
    return 0;
}
