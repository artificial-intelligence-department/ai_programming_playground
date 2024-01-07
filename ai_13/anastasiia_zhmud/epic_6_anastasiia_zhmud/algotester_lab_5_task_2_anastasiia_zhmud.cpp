#include <iostream>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    char **array = new char*[N];
    for (int i = 0; i < N; ++i) {
        array[i] = new char[M];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> array[i][j];
        }
    }
    for (int j = 0; j < M; ++j) {
        int k = N - 1;
        for (int i = N - 1; i >= 0; --i) {
            if (array[i][j] == 'S') {
                array[i][j] = 'O';
                if (k >= 0) {
                    array[k][j] = 'S';
                    k--;
                }
            } else if (array[i][j] == 'X') {
                k = i - 1;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << array[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < N; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
