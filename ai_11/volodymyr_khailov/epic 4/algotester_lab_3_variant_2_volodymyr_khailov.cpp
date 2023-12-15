#include <iostream>
#include <vector>

using namespace std;

void customSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n;
    vector<int> array1(n);
    for (int i = 0; i < n; ++i) {
        cin >> array1[i];
    }

    cin >> m;
    vector<int> array2(m);
    for (int i = 0; i < m; ++i) {
        cin >> array2[i];
    }
    customSort(array1, n);
    customSort(array2, m);

    // Знаходимо кількість спільних елементів
    int common = 0;

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (array1[i] == array2[j]) {
            ++common;
            ++i;
            ++j;
        } else if (array1[i] < array2[j]) {
            ++i;
        } else {
            ++j;
        }
    }
    // Знаходимо кількість унікальних елементів 
    int unique = n+m-common;

    cout << common << endl;
    cout << unique << endl;

    return 0;
}
