#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Coordinates {
    int x;
    int y;
};

void defineHeight(const Coordinates& coordinates, vector<vector<int>>& map);

int main() {
    int N, M;
    cin >> N >> M;

    Coordinates coordinates;
    cin >> coordinates.x >> coordinates.y;

    vector<vector<int>> map(N, vector<int>(M, 0));

    defineHeight(coordinates, map);

    for (const auto& row : map) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}

void defineHeight(const Coordinates& coordinates, vector<vector<int>>& map) {
    int N = map.size();
    int M = map[0].size();
    int vershyna = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = abs(coordinates.x - 1 - i) + abs(coordinates.y - 1 - j);
            vershyna = max(vershyna, map[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = vershyna - map[i][j];
        }
    }
}


