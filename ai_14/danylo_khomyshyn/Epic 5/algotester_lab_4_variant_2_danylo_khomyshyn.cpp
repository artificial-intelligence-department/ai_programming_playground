#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N, K;

    cin >> N >> K;

    if (N < 1 || N > 1000 || K < 1 || K > 1000) {
        cout << "ERROR" << endl;
        return 1;
    }

    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] < 0 || a[i] > 100) {
            cout << "ERROR" << endl;
            return 1;
        }
    }

    set<int> uniqueNumbers(a.begin(), a.end());
    vector<int> b(uniqueNumbers.begin(), uniqueNumbers.end());

    rotate(b.begin(), b.begin() + K % b.size(), b.end());

    cout << b.size() << endl;

    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }

    return 0;
}