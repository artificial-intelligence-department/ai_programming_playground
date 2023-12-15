#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (k * 3 < n ||k > n) {
        cout << "Impossible" << endl;
    } else {
        int students = n;
        int size[k] = {0};

        for (int i = 0; i < k - 1; ++i) {
            int team = min(3, students - (k - i - 1));
            size[i] = team;
            students -= team;
        }

        size[k - 1] = students;

        for (int i = 0; i < k; ++i) {
            cout << size[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
