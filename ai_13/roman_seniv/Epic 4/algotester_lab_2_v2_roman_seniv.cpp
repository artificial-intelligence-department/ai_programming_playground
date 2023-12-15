#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> r(N);
    int a, b, c;

    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }

    cin >> a >> b >> c;

    vector<int> newR;
    for (int i = 0; i < N; i++) {
        if (r[i] != a && r[i] != b && r[i] != c) {
            newR.push_back(r[i]);
        }
    }

    int newN = newR.size();

    if (newN >= 2) {
        vector<int> M(newN - 1);
        for (int j = 0; j < newN - 1; j++) {
            M[j] = newR[j] + newR[j + 1];
        }

        cout << newN - 1 << endl;
        for (int j = 0; j < newN - 1; j++) {
            cout << " " << M[j];
        }
    } else {
        cout << "0" << endl;
    }

    return 0;
}
