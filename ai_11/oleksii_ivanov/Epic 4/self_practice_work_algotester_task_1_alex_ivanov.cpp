#include <iostream>
using std::cin, std::cout;

// Lab 3v2

int main() {
    int n, m;
    int* arr1, *arr2;

    cin >> n;
    arr1 = new int[n];
    for (int i = 0; i < n; ++i) cin >> arr1[i];

    cin >> m;
    arr2 = new int[m];
    for (int i = 0; i < m; ++i) cin >> arr2[i];

    int unique_count = 0, common_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            if (arr1[i] == arr2[j]) {
                common_count++;
                break;
            }
        }
    }

    unique_count = n + m - common_count;

    cout << common_count << '\n' << unique_count << '\n';

    delete[] arr1;
    delete[] arr2;
    return 0;
}

