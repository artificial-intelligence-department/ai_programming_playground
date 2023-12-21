#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int N, k;
    cin >> N >> k;
    vector<int> s(N);
    for (int i = 0; i < N; ++i) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    auto new_end = unique(s.begin(), s.end());
    s.erase(new_end, s.end());
    rotate(s.begin(), s.begin() + (k % s.size()), s.end());
    cout << s.size() << endl;
    for (int i = 0; i < s.size(); ++i) {
        cout << s[i] << " ";
    }

    return 0;
}
