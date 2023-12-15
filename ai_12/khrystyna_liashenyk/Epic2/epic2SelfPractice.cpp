#include <iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    int teeth[n];
    for (int i = 0; i < n; ++i) {
        cin >> teeth[i];
    }

    int max_cons_teeth = 0;
    int cons_teeth = 0;

    for (int i = 0; i < n; i++) {
        if (teeth[i] >= k) {
            cons_teeth++;
            max_cons_teeth = max(max_cons_teeth, cons_teeth);
        } else {
            cons_teeth = 0;
        }
    }

    cout << max_cons_teeth << endl;

    return 0;
}
