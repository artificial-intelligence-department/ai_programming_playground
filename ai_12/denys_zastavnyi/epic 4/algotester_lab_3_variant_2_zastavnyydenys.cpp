#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arrayA(N);

    for (int i = 0; i < N; ++i) {
        cin >> arrayA[i];
    }

    int M;
    cin >> M;
    vector<int> arrayB(M);

    for (int i = 0; i < M; ++i) {
        cin >> arrayB[i];
    }

    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());

    int commonElements = 0;
    int i = 0, j = 0;
    while (i < N && j < M) {
        if (arrayA[i] == arrayB[j]) {
            commonElements++;
            i++;
            j++;
        } else if (arrayA[i] < arrayB[j]) {
            i++;
        } else {
            j++;
        }
    }

    int uniqueElements = N + M - commonElements;

    cout << commonElements << endl;
    cout << uniqueElements << endl;

    return 0;
}
