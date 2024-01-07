#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> row(n);
    for (int i = 0; i < n; i++) {
        cin >> row[i];
    }
    for (int j = 0; j < m; j++) {
        int i = n - 1;
        int count = 0;
        while (i >= 0) {
            if (row[i][j] == 'O') {
                count = 0;
                int pos = i - 1;
                while (pos >= 0) {
                    if (row[pos][j] == 'S') {
                        row[i-count][j] = 'S';
                        row[pos][j] = 'O';
                        count++;
                    } else if(row[pos][j] == 'X') {
                        break;
                    }
                    pos--;
                }
            }
            i--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << row[i] << endl;
    }
    return 0;
}
