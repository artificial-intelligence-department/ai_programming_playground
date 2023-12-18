#include <iostream>

using namespace std;

int main() {

int M, N;


cin >> M;
if (M < 0 || M > 100) return 0;
int mass1[M];
for (int i = 0; i < M; i++) {
    cin >> mass1[i];
    if (mass1[i]<0 || mass1[i]>100) return 0;
}


cin >> N;
if (N < 0 || N > 100) return 0;
int mass2[N];
for (int i = 0; i < N; i++) {
    cin >> mass2[i];
    if (mass2[i]<0 || mass2[i]>100) return 0;
}

int similar = 0;
for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++){
        if (mass1[i]==mass2[j]) similar++;
    }
}
int different = M + N - similar;
cout << similar << endl << different;
}