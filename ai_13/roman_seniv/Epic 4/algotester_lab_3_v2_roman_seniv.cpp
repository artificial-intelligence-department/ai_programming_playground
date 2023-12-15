#include <iostream>
using namespace std;

int main() {
    int N;
    int M;
    int a[N];
    int b[M];

 cin >> N;
for(int i=0; i<N; i++) {
    cin >> a[i];
}
cin >> M;
for(int i=0; i<M; i++) {
    cin >> b[i];
}



    int H = 0;
    int L = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i] == b[j]) {
                H++;
                break;
            }
        }
    }

    L = N - H;

    cout << H << endl;
    cout << L << endl;

    return 0;
}