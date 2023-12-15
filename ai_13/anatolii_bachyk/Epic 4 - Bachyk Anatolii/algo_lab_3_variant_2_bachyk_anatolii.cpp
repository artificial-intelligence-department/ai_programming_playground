#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> M;
    vector<int> B(M);
    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }

    vector<int> countU(101, 0), countS(101, 0);
    for(int i = 0; i < N; i++) {
        countU[A[i]]++;
    }
    for(int i = 0; i < M; i++) {
        countS[B[i]]++;
    }

    int common = 0, unique = 0;
    for(int i = 0; i <= 100; i++) {
        if(countU[i] > 0 && countS[i] > 0) {
            common++;
        }
        if(countU[i] > 0 || countS[i] > 0) {
            unique++;
        }
    }

    cout << common << endl;
    cout << unique << endl;

    return 0;
}