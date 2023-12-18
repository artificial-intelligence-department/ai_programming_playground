#include <iostream>
using namespace std;

int main() {
    long long H, M;
    cin >> H >> M;
    long long spell_costs[3][2];

    for (int i = 0; i < 3; i++) {
        cin >> spell_costs[i][0] >> spell_costs[i][1];
    }

    for (int i = 0; i < 3; i++) {
        if ((spell_costs[i][0] <= H && spell_costs[i][1] <= M) &&
            (spell_costs[i][0] > 0 && spell_costs[i][1] == 0) || (spell_costs[i][0] == 0 && spell_costs[i][1] > 0)) {
            H -= spell_costs[i][0];
            M -= spell_costs[i][1];
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (H > 0 && M > 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}