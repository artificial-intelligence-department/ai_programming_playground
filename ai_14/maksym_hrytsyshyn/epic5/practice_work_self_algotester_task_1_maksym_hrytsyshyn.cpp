#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> remainder0, remainder1, remainder2;
    for (int i=0; i<N; i++) {
        if (a[i] % 3 == 0) {
            remainder0.push_back(a[i]);
        } else if (a[i] % 3 == 1) {
            remainder1.push_back(a[i]);
        } else {
            remainder2.push_back(a[i]);
        }
    }

    sort(remainder0.begin(), remainder0.end());
    sort(remainder1.begin(), remainder1.end(), greater<int>());
    sort(remainder2.begin(), remainder2.end());

    vector<int> anew;
    anew.insert(anew.end(), remainder0.begin(), remainder0.end());
    anew.insert(anew.end(), remainder1.begin(), remainder1.end());
    anew.insert(anew.end(), remainder2.begin(), remainder2.end());

    auto forerase = unique(anew.begin(), anew.end());
    anew.erase(forerase, anew.end());

    cout << anew.size() << endl;
    for (int each : anew) {
        cout << each << " ";
    }
    cout << endl;

    return 0;
}