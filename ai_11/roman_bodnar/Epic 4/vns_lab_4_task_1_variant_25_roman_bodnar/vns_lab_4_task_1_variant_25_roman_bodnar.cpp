#include <iostream>

using namespace std;

int main() {
    int ring[] = {1, 2, 3, 4, 5};
    int n = sizeof(ring) / sizeof(ring[0]);

    int from = 0;
    int to = from + 1;
    for (int i = from; i < n; i++) {
        cout << ring[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ring[j] < ring[j + 1]) {
                int temp = ring[j];
                ring[j] = ring[j + 1];
                ring[j + 1] = temp;
            }
        }
    }

    for (int i = from; i < n; i++) {
        cout << ring[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        if (ring[i] % 2 != 0) {
            for (int j = i; j < n - 1; j++) {
                ring[j] = ring[j + 1];
            }
            n--;
        }
    }

    for (int i = from; i < n; i++) {
        cout << ring[i] << " ";
    }
    cout << endl;

    return 0;
}
