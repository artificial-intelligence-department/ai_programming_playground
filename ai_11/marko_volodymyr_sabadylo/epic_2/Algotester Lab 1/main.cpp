#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    long long heights[4];
    long long d;
    for (long long &el: heights) {
        cin >> el;
    }

    bool will_stand = true;
    for (long long &height: heights) {
        cin >> d;
        if (d > height) {
            cout << "ERROR";
            return 0;
        }

        height -= d;

        long long max = *max_element(heights, heights + 4);
        long long min = *min_element(heights, heights + 4);
        if (max >= 2 * min) will_stand = false;
    }

    cout << (will_stand  ? "YES" : "NO");
    return 0;
}
