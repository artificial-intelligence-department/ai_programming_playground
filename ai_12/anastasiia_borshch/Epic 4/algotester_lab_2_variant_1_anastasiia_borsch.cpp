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
    sort(r.begin(), r.end());
    int minFatigue;

    if (N == 1) {
        minFatigue = 0;
    } else if (N == 2) {
        minFatigue = r[1] - r[0];
    } else {
        int option1 = r[N - 2] - r[0];
        int option2 = r[N - 1] - r[1];
        minFatigue = min(option1, option2);
    }

    cout << minFatigue;
    return 0;
}
