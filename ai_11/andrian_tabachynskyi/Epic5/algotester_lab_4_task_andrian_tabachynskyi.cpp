#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    vector<int> r(N);

    for (int i = 0; i < N; ++i) {
        cin >> r[i];
    }
    sort(r.begin(), r.end());
    auto news = unique(r.begin(), r.end());

    r.erase(news, r.end());
    rotate(r.begin(), r.begin() + (K % r.size()), r.end());

    cout << r.size() << endl;

    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << " ";
    }

    return 0;
}