#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> r(N);
    for (int i = 0; i < N; ++i) {
        cin >> r[i];
    }

    int a, b, c;
    cin >> a >> b >> c;

    r.erase(remove_if(r.begin(), r.end(),
            [a, b, c](int x) { return x == a ||  x == b || x == c; }), r.end());

    int M = r.size();

    vector<int> sums;
    for (int i = 0; i < M - 1; ++i) {
        sums.push_back(r[i] + r[i + 1]);
    }

    if (sums.empty()) {
        cout << 0 << endl;
    } else {
        cout << M - 1 << endl;
        for (int i = 0; i < M - 1; ++i) {
            cout << sums[i] << " ";
        }
        cout << endl;
    }

    return 0;
}