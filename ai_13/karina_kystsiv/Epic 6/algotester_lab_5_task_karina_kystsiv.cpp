#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int x, y;
    cin >> x >> y;
    int x1 = x - 1; int x2 = x - 2;
    int y1 = y - 1; int y2 = y - 2;

    vector<int> v;
    v.push_back((N - x) + (M - y));
    v.push_back(x1 + y1);
    v.push_back((N - x1) + y2);
    v.push_back((M - y1) + x2);

    int peak;
    peak = *max_element(v.begin(), v.end());

    for (int i = 0; i < N; ++i) {
        int xi = abs(x1 - i);
        for (int j = 0; j < M; ++j) {
            int yj = abs(y1 - j);
            int r = xi + yj;
            int result = peak - r;
            cout << result << " ";
        }
        cout << endl;
    }
    return 0;
}