#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }

    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());

    if (K > a.size()) {
        K = K % a.size();
    }

    rotate(a.begin(), a.begin() + K, a.end());

    cout  << a.size() << endl;

    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
