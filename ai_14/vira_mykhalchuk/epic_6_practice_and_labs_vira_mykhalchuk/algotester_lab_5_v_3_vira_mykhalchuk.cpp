#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, M, x, y;
    cin >> N >> M >> x >> y;

    int** heights = new int*[N];

    for (int i = 0; i < N; i++) {
        heights[i] = new int[M]();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            heights[i][j] = -abs(x - 1 - i) - abs(y - 1 - j);
        }
    }

    int min_height = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (min_height > heights[i][j]) {
                min_height = heights[i][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            heights[i][j] -= min_height;
            cout << heights[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        delete[] heights[i];
    }
    delete[] heights;

    return 0;
}
