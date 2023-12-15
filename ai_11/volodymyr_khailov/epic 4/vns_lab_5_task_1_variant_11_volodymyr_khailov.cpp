#include <iostream>
using namespace std;

bool isSorted(const int* row, int length) {
    for (int i = 1; i < length; ++i) {
        if (row[i - 1] > row[i]) {
            return false;
        }
    }
    return true;
}

void customSort(int* row, int length) {
    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (row[j] > row[j + 1]) {
                swap(row[j], row[j + 1]);
            }
        }
    }
}

int main() { 
    const int M = 3;
    const int N = 5;
    int array[M][N] = {
        {3, 5, 7, 9, 11},
        {6, 4, 2, 0, -2},
        {1, 4, 3, 4, 5}
    };

    for (int i = 0; i < M; ++i) {
        if (!isSorted(array[i], N)) {
            customSort(array[i], N);
        }
    }

    cout << "Відсортований двовимірний масив:" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
