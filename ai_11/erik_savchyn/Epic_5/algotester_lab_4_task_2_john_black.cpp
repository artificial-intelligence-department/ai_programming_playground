#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N;
    cin >> K;
    int a[N];
    for (int i = 0; i < N; i++) { cin >> a[i]; }
    
    int na[N];
    int size=0;
    for (int i = 0; i < N; i++) {
        int temp = 101;
        int btemp;
        if (i == 0) { btemp = -1; }

        for (int j = 0; j < N; j++) {
            if (a[j] < temp && a[j] > btemp) {
                temp = a[j];
            }
        }
        if (btemp != temp && temp <= 100) {
            na[i] = temp;
            size++;
        }
        btemp = temp;
    }
    K %= size;
    int res[size];
    for (int i = 0; i < size; i++) {
        if (i < K) {
            res[size-K+i] = na[i];
        } else res[i-K] = na[i];
    }
    cout << size << endl;
    for (int i = 0; i < size; i++) {
        cout << res[i] << " ";
    }
    return 0;
}
