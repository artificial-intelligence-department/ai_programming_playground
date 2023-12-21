#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;

    int b[m];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int common = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                common++;
                break;
            }
        }
    }

int unique = n + m - common;

    cout << common << endl << unique << endl;

    return 0;
}
