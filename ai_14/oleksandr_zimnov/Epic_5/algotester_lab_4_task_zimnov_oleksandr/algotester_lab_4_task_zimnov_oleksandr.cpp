#include <iostream>
#include <string>
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

    int* a_new = new int[N];
    int N_new = 0;

    for (int i = 0; i < N; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < N_new; j++) {
            if (a[i] == a_new[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            a_new[N_new] = a[i];
            N_new++;
        }
    }

    for (int i = 0; i < N_new - 1; i++) {
        for (int j = 0; j < N_new - i - 1; j++) {
            if (a_new[j] > a_new[j + 1]) {
                int temp = a_new[j];
                a_new[j] = a_new[j + 1];
                a_new[j + 1] = temp;
            }
        }
    }

    if (K != 0) {
        K = K % N_new;
        int* temp = new int[N_new];
        for (int i = 0; i < N_new; i++) {
            temp[i] = a_new[i];
        }
        for (int i = 0; i < N_new - K; i++) {
            a_new[i] = temp[i + K];
        }
        for (int i = 0; i < K; i++) {
            a_new[N_new - K + i] = temp[i];
        }
    }

    cout << "Your new size of the array: " << N_new << endl;
    for (int i = 0; i < N_new; i++) {
        cout << "Your new element[" << i + 1 << "]: " << a_new[i] << endl;
    }
    return 0;
}
