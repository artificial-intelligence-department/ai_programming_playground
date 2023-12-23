#include <iostream>
using namespace std;

int main() {
    int an[100];
    int bm[100];
    int n, m, amin, bmin, sum;
    cin >> n >> m;

    for (int i = 0; i<n; i++) {
        cin >> an[i];
    }
    for (int j = 0; j<m; j++) {
        cin >> bm[j];
    }

    amin = an[0];
    for (int y = 0; y<n; y++) {
        if (amin>an[y]) {
            amin = an[y];
        }
    }

    bmin = bm[0];
    for (int u = 0; u<m; u++) {
        if (bmin > bm[u]) {
            bmin = bm[u];
        }
    }

    sum = amin + bmin;
    cout << sum;
    
}
