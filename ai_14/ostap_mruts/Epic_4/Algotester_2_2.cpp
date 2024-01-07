#include <iostream>
#include <vector>
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

    for (int i = 0; i < N; ++i) {
        if (r[i] == a || r[i] == b || r[i] == c) {
            r.erase(r.begin() + i);
            N--;
            i--;
        }
    }

    vector<int> sums;
    for (int i = 0; i < N - 1; ++i) {
        sums.push_back(r[i] + r[i + 1]);
    }

    cout << sums.size() << endl;

    for (int sum : sums) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
