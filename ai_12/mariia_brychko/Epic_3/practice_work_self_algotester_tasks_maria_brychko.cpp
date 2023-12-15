#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> team(k, 0);
    int sum = k;

    for (int i = 0; sum < n; ++i) {
        if (i == k) {
            i = 0;
        }
        if (team[k - 1] == 2) {
            break;
        }
        ++sum;
        ++team[i];
    }

    if (sum != n) {
        cout << "Impossible" << endl;
    } else {
        for (int t : team) {
            cout << t + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
