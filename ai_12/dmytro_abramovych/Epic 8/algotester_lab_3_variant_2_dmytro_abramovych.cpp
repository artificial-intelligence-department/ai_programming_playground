#include <iostream>
using namespace std;

// Algotester Lab 3 Variant 2

int main() {
    int N, M, unique, common = 0;
    int* mas1, *mas2;

    cin >> N;
    mas1 = new int[N];
    for (int i = 0; i < N; ++i) cin >> mas1[i];
    cin >> M;
    mas2 = new int[M];
    for (int i = 0; i < M; ++i) cin >> mas2[i];

    for (int ind1 = 0; ind1 < N; ++ind1)
        for (int ind2 = 0; ind2 < M; ++ind2)
            if (mas1[ind1] == mas2[ind2]) {
                common++;
            }

    unique = N + M - common;
    cout << common << '\n' << unique << '\n';

    delete[] mas1;
    delete[] mas2;
    return 0;
}