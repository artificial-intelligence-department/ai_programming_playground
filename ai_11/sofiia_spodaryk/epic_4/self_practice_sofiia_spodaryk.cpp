#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> colors(n, 0);

    for (int i = 0; i < m; ++i) {
        int l, r, c;
        cin >> l >> r >> c;

        for (int j = l - 1; j < r; ++j) {
            colors[j] = c;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << colors[i] << " ";
    }

    return 0;
}