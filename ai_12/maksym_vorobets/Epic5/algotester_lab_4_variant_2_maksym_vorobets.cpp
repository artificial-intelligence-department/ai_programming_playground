#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, k;
    cin >> N >> k;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    unordered_set<int> uniqueSet(a.begin(), a.end());
    a.assign(uniqueSet.begin(), uniqueSet.end());
    sort(a.begin(), a.end());
    int len = a.size();
    cout << len << endl;
    rotate(a.begin(), a.begin() + k%len, a.end());
    for (auto i : a) {
        cout << i <<' ';
    }

    return 0;
}



