#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int r[N];
    for (int a = 0; a < N; ++a) {
        cin >> r[a];
    }

    int a, b, c;
    cin >> a >> b >> c;
    for(int i = 0; i < N; ++i) {
        if (r[i] == a || r[i] == b || r[i] == c) {
            for (int k = i; k < N - 1; ++k) {
                r[k] = r[k+1];
            }
            --N;
            --i;
        }
    }

    int M=N-1;
    if (M<0) {
        M = 0;
    }
    cout << M << endl;
    int sum[M];
    for(int i=0; i<M; ++i) {
        sum[i] = r[i] + r[i+1];
        cout << sum[i] << " ";
    }

    return 0;

}