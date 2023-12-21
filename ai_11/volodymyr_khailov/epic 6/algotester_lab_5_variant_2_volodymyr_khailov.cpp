#include <iostream>
#include <vector>

using namespace std;

void earthquake(int n, int m, vector<vector<char>>& cave) {
    for (int j = 0; j < m; ++j) {
        for (int i = n - 1; i >= 0; --i) {
            if (cave[i][j] == 'S' && i + 1 < n && cave[i + 1][j] == 'O') {
                swap(cave[i + 1][j], cave[i][j]);
                i = n - 1;  
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> cave(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> cave[i][j];
        }
    }

    earthquake(n, m, cave);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}
