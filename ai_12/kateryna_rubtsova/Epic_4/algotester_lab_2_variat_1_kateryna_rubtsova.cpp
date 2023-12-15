#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    int r[n];
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    int min_fatigue_1 = INT_MAX;

    for (int i = 0; i < n; i++) {
        int max_r = INT_MIN;
        int min_r = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (j != i) {
                max_r = max(max_r, r[j]);
                min_r = min(min_r, r[j]);
            }
        }

        int fatigue = max_r - min_r;
        min_fatigue_1 = min(min_fatigue_1, fatigue);
    }

    int min_fatigue_2 = INT_MAX;

    int max_val = r[0];
    int min_val = r[0];
    for (int i = 0; i < n; ++i) {
        if (r[i] > max_val) {
            max_val = r[i];
        }
        if (r[i] < min_val) {
            min_val = r[i];
        }
    }

    bool number_removed = false;
    for (int i = 0; i < n; i++) {
        if (r[i] == max_val) {
            r[i] = min_val;
            number_removed = true;
            break;
        }
    }

    if (!number_removed) {
        for (int i = 0; i < n; i++) {
            if (r[i] == min_val) {
                r[i] = max_val;
                break;
            }
        }
    }

    int new_max = r[0];
    int new_min = r[0];
    for (int i = 0; i < n; ++i) {
        if (r[i] > new_max) {
            new_max = r[i];
        }
        if (r[i] < new_min) {
            new_min = r[i];
        }
    }

    min_fatigue_2 = new_max - new_min;

    int result = min(min_fatigue_1, min_fatigue_2);

    cout << result << endl;

    return 0;
}