#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int maxTeeth = 0;
    int currentTeeth = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] >= k) {
            currentTeeth++;
            maxTeeth = max(maxTeeth, currentTeeth);
        } else {
            currentTeeth = 0;
        }
    }

    cout << maxTeeth << endl;

    return 0;
}

