#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int l = n;
    int *a = new int[n];
    int *r = new int[3];
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> r[0] >> r[1] >> r[2];
    int *k = new int[l];
    for (int i = 0, j = 0; i < n; i++) {
        if (a[i] == r[0]) {
            r[0] = -1;
            l--;
        }
        else if (a[i] == r[1]) {
            r[1] = -1;
            l--;
        }
        else if (a[i] == r[2]) {
            r[2] = -1;
            l--;
        }
        else {
            k[j] = a[i];
            j++;
        }
    }
    if (l == 0) cout << 0;
    else {
        cout << --l << '\n';
        for (int i = 0; i < l; i++) cout << k[i] + k[i + 1] << ' ';
        return 0;
    }
}