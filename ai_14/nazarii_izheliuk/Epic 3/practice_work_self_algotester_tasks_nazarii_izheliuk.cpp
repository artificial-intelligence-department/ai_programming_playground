#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int total_distance = 0;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        total_distance += distance;
    }

    cout << total_distance << endl;

    return 0;
}