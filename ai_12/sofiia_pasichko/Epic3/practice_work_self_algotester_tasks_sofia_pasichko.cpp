#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int* a = new int[n];
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }

    int maxTooth=0;
    int currentTooth=0;

    for (int i=0; i<n; ++i) {
        if (a[i]>=k) {
            currentTooth++;
        } else {
            currentTooth=0;
        }

        maxTooth = max(maxTooth, currentTooth);
    }
    cout << maxTooth;

    delete[] a;
    return 0;
}

