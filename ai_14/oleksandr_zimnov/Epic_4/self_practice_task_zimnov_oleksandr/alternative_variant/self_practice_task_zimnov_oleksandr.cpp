#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    do {
        cout << "Enter size of the array: ";
        cin >> N;
        cout << "Enter K: ";
        cin >> K;
    } while (N < 1 || N > 1000 || K < 1 || K > 1000);

    int* a = new int[N];
    for (int i = 0; i < N; i++) {
        cout << "Enter element[" << i + 1 << "]: ";
        cin >> a[i];
    }
    int N_new = 0;
    sort(a, a + N);
    auto newEnd = unique(a, a + N);
    N_new = distance(a, newEnd);

    sort(a, a + N_new);

    if (K != 0) {
        K = K % N_new;
        rotate(a, a + K, a + N_new);
    }

    cout << "Your new size of the array: " << N_new << endl;
    for (int i = 0; i < N_new; i++) {
        cout << "Your new element[" << i + 1 << "]: " << a[i] << endl;
    }
    return 0;
}
