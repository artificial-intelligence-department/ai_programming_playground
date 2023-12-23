#include <iostream>
#include <cmath>
using namespace std;

bool sort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void M(int arr[], int size) {
    int sqr = sqrt(size);
    if (!sort(arr, size)) {
        cout << "Error" << endl;
        return;
    }

    int matrix[sqr][sqr];
    int index = 0;
    for (int i = 0; i < sqr; ++i) {
        for (int j = 0; j < sqr; ++j) {
            matrix[j][i] = arr[index++];
        }
    }

    for (int i = 0; i < sqr; ++i) {
        for (int j = 0; j < sqr; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr_ordered[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size_ordered = sizeof(arr_ordered) / sizeof(arr_ordered[0]);

    cout << "Matrix:" << endl;
    M(arr_ordered, size_ordered);

    return 0;
}
