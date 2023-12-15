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

    vector<int> arr;
    for (int i = 0; i < N; ++i) {
        if (r[i] != a && r[i] != b && r[i] != c) {
            arr.push_back(r[i]);
        }
    }

    if (arr.size() > 1) {
        vector<int> sums(arr.size() - 1);
        for (int i = 0; i < arr.size() - 1; ++i) {
            sums[i] = arr[i] + arr[i + 1];
        }

  
        cout << arr.size() - 1 << endl;
        for (int i = 0; i < arr.size() - 1; ++i) {
            cout << sums[i] << " ";
        }
    } else {
        cout << 0 << endl;
    }

    return 0;
}
