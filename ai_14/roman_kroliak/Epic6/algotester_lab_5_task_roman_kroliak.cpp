#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int x, y;
    cin >> x >> y;
    int maxHeight = max({x-1+y-1, n-x+m-y, x-1+m-y, n-x+y-1});
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = maxHeight - abs(x-1-i) - abs(y-1-j);
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
