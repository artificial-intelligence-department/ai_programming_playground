#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    int N, M, x, y, heighestPoint = 0;
    cin >> N >> M >> x >> y;
    vector<vector<int>> map(N, vector<int>(M, 0));
    x -= 1;
    y -= 1;

    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[0].size(); ++j){
            map[i][j] = abs(i - x) + abs(j - y);
            if (map[i][j] > heighestPoint)
                heighestPoint = map[i][j];
        }
    }
    
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            cout << heighestPoint - map[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
