#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> r(N);
    for (int i = 0; i < N; ++i) {
        cin >> r[i];
    }

    int a, b, c;
    cin >> a >> b >> c;

    for (auto it = r.begin(); it != r.end();) {
        if (*it == a || *it == b || *it == c) {
            it = r.erase(it);
        } else {
            ++it;
        }
    }

    if (r.size() < 1) {
        cout << "0" << endl;
        return 0;
    }

    vector<int> result;
    for (int i = 0; i < r.size() - 1; ++i) {
        result.push_back(r[i] + r[i + 1]);
    }

    cout << result.size() << endl;
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
