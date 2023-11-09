#include <iostream>

using namespace std;

int main() {
    double s_down, s_up, v;
    cin >> s_down >> s_up >> v;

    double time_down = (s_down) / (2 * v);
    double time_up = (s_up) / (v / 2.0);

    if (time_down < time_up) {
        cout << "Down";
    } else if (time_down > time_up) {
        cout << "Up";
    } else {
        cout << "Never mind";
    }

    return 0;
}
