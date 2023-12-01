#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int row = a[i][j], col = a[i][j];
            for (int k = 0; k < m; k++) {
                if (a[i][k] < row ) {
                    row = a[i][k];
                }
            }
            for (int k = 0; k < n; k++) {
                if (a[k][j] > col) {
                    col = a[k][j];
                }
            }
            if (row == col) {
                cout << "Element at (" << i << ", " << j << ") is a saddle point." << endl;
            }
        }
    }
  for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int row = a[i][j], col = a[i][j];
            for (int k = 0; k < m; k++) {
                if (a[i][k] > row ) {
                    row = a[i][k];
                }
            }
            for (int k = 0; k < n; k++) {
                if (a[k][j] < col) {
                    col = a[k][j];
                }
            }
            if (row == col) {
                cout << "Element at (" << i << ", " << j << ") is a saddle point." << endl;
            }
        }
    }
    return 0;
}