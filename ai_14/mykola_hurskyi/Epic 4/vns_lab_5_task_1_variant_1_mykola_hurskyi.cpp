#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {
    if (n == 1  n == 0)
        return true;

    if (arr[n - 1] < arr[n - 2])
        return false;

    return isSorted(arr, n - 1);
}

bool isSortedDesc(int arr[], int n) {
    if (n == 1  n == 0)
        return true;

    if (arr[n - 1] > arr[n - 2])
        return false;

    return isSortedDesc(arr, n - 1);
}

void printRow(int arr[], int n) {
    cout << "Checking row: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[2][4] = {{1, 2, 3, 4}, {5, 4, 3, 2}};

    for (int i = 0; i < 2; i++) {
        printRow(arr[i], 4);
        if (isSorted(arr[i], 4)) {
            cout << "Row " << i << " is sorted in ascending order.\n";
        } else if (isSortedDesc(arr[i], 4)) {
            cout << "Row " << i << " is sorted in descending order.\n";
        }
    }

    return 0;
}