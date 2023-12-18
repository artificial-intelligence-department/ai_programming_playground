#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int n;
vector<string> grid;
vector<int> possible[MAXN][MAXN];

void init() {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            if (grid[i][j] == '0') {
               
                for (int k = 1; k <= n; k++) {
                    bool valid = true;
                   
                    for (int l = 0; l < n; l++) {
                        if (grid[i][l] == k + '0' || grid[l][j] == k + '0') {
                            valid = false;
                            break;
                        }
                    }
                    
                    if (valid) {
                        possible[i][j].push_back(k);
                    }
                }
            }
        }
    }
}

void solve() {
    int q;
    cin >> q;

    
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--; 
        y--; 

        
        if (grid[x][y] != '0') {
            cout << "1\n" << grid[x][y] << "\n";
        } else {
            
            cout << possible[x][y].size() << "\n";
            for (int j = 0; j < possible[x][y].size(); j++) {
                cout << possible[x][y][j] << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    
    cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    
    init();

    
    solve();

    return 0;
}

/*3
000
100
003
3
1 1
2 3
2 1*/