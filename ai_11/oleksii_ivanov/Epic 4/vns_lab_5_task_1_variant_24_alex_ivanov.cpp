#include <iostream>
using namespace std;

int main() {
    int m, n;

    cout << "Enter matrix size: ";
    cin >> m >> n;

    int **arr = new int *[m];
    for (int i = 0; i < m; i++) arr[i] = new int[n];

    cout << "Enter matrix elements: ";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int lesser = min(m, n);
    int *diag = new int[lesser];
    for (int i = 0; i < lesser; ++i) diag[i] = arr[i][i];

    int min_diag = diag[0];
    for (int i = 1; i < lesser; ++i)
        if (diag[i] < min_diag) min_diag = diag[i];

    int bigger_than_diag = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (arr[i][j] > min_diag) bigger_than_diag++;
        }

    cout << "Number of elements bigger than diagonal: " << bigger_than_diag << endl;

    for (int i = 0; i < m; i++) delete[] arr[i];
    delete[] arr;
    delete[] diag;

    return 0;
}
