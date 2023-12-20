#include <iostream>
#include <vector>
using namespace std;

// check if the point (x, y) is within the map
bool check_offsets(int x, int y, int m, int p) {
    return x >= 0 && x < m && y >= 0 && y < p;
}

void fill_in_from_pinnacle(vector<vector<int>>& map, int x, int y) {
    int n = map.size(), m = map[0].size();
    int max_by_x = (x > n - x) ? x - 1 : n - x,
        max_by_y = (y > m - y) ? y - 1 : m - y;

    int max = max_by_x + max_by_y;

    map[--x][--y] = max;

    // fill in the map starting from the pinnacle
    for(int i = 0; i <= max_by_x; i++) {
        for (int j = 0; j <= max_by_y; j++) {
            // top left
            if (check_offsets(x - i, y - j, n, m))
                map[x - i][y - j] = max - i - j;
            // top right
            if (check_offsets(x - i, y + j, n, m))
                map[x - i][y + j] = max - i - j;
            // bottom left
            if (check_offsets(x + i, y - j, n, m))
                map[x + i][y - j] = max - i - j;
            // bottom right
            if (check_offsets(x + i, y + j, n, m))
                map[x + i][y + j] = max - i - j;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m, 0));

    // Point of the pinnacle
    int x, y;
    cin >> x >> y;

    fill_in_from_pinnacle(map, x, y);

    for (const vector<int> &row: map) {
        for (int cell: row)
            cout << cell << " ";
        cout << endl;
    }

    return 0;
}
