#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());

    rotate(a.begin(), a.begin() + (K % a.size()), a.end());

    cout << a.size() << endl;
    for (int i : a) {
        cout << i << " ";
    }

    return 0;
}